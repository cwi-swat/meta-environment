/**
 *	mod_toolbus.c
 *
 *	Apache 2 module for interfacing with the CWI Discrete Time Toolbus
 *
 *	Erik Post
 *	epost@science.uva.nl
 *	Universiteit van Amsterdam
 *	
 *	This module revolves around two handlers. The main one is invoked by
 *	Apache to handle an HTTP request. This handler in turn sets up the 
 *	toolbus event handler. Communication between the two is achieved
 *	by global variables.
 *
 *	- in the handlers, stderr is redirected by Apache to the file error_log
 *	- control is implemented by (re)setting a flag indicating wheter we can
 *		leave the handler. 
 *
 *
 */

#define VERBOSE
 
 
/* Apache httpd */
#include "httpd.h"
#include "http_config.h"
#include "http_main.h"

/* ToolBus */
#include <stdlib.h>
#include <atb-tool.h>

/* homegrown encoders and decoders */
#include "aterm-html.h"
#include "utf8.h"

/* getpid() calls need these */
#include <sys/types.h>
#include <unistd.h>


/* 
 *	these define how different parts of the request URL should look
 */
#define MOD_TOOLBUS_NAME_URI "/mod_toolbus"		
#define SEND_COMMAND_STRING "snd-event"

/*
 *	toolbus-specific configuration variables
 */
#define TB_TOOL_NAME_VALUE "modToolbus"
#define TB_RESPONSE_TIMEOUT_SEC 10

/*
 *	misc constants
 */
#define HTML_BUF_SIZE 4000


/*
 *	global variables, necessary for communication among handler functions
 */
request_rec* global_http_req;


/*
 *	this flag is set/increased by toolbus_handler() to signal we're done 
 *	handling an event from the toolbus. The main loop checks this value
 *	and can disconnect and exit safely
 */
static int global_is_tb_session_done = 0;


ATerm toolbus_handler( int tb_conn, ATerm input );
int validate_tb_event( char* tb_event_content );
void mod_toolbus_fatal( char* errormessage );
int read_HTTP_GET_arg( char* args, char* key, char *value );


/**
 *	This function is registered as a handler for HTTP methods and will
 *	therefore be invoked for all GET requests (and others).
 *	In this type of request handler, stderr is redirected to a httpd log file
 *	(default: <apache_dir>/logs/error.log)
 *	TODO:
 *		- use apr_... functions (Apache Portable Runtime for Apache 2.0) 
 *			instead of ap_... ones where applicable
 */
static int http_req_handler( request_rec *http_req )
{
	/* toolbus initialization */
	ATerm BottomOfStack;					/* used by ATBinit(), don't move */
	char* tb_init_argv[] = 					/* used to set up TB connection */
		{
			"this_is_a_spacefiller_dummy", 
			"-TB_TOOL_NAME", TB_TOOL_NAME_VALUE 
		};
	int tb_init_argc = 4;
	int tb_conn;							/* set by ATBconnect() */
	
	/* toolbus communication */
	ATerm tb_event_to_send;
		
	#define SEND_BUF_SIZE 1000
	char send_buf[SEND_BUF_SIZE];			/* params to send to toolbus */
	char send_buf_ascii[SEND_BUF_SIZE];		/* same after UTF-8 decode */
	
	/* these are used for control flow in the toolbus section */
	int count;

	
	/* update global variable so the toolbus handler can use it too */
	global_http_req = http_req;
		
	/* print some debugging info to the log file */
	fprintf( stderr, "mod_toolbus: invoked with pid=%d, ppid=%d\n",
		  (int) getpid(), (int) getppid() );
	fflush( stderr );
	
	/* check if this is a toolbus request, otherwise we don't handle it */
	if( strcmp( global_http_req->uri, MOD_TOOLBUS_NAME_URI ) ) 
	{
		return DECLINED;
	}

    ap_set_content_type( global_http_req, "text/html" );
    if( global_http_req->header_only ) { return OK; }

	#ifdef VERBOSE
		dump_http_req_fields( global_http_req );
	#endif
	
	/*
	 *	read event to send from HTTP request arguments, validate
	 *	filter, and prepare it to be sent to the toolbus
	 */
	if( read_HTTP_GET_arg( global_http_req->args, SEND_COMMAND_STRING, send_buf ) )
	{
		ap_rprintf( global_http_req, 
			"missing \"%s\" argument exting.\n", SEND_COMMAND_STRING );	
		return OK;
	}
	utf8_to_ascii( send_buf_ascii, send_buf );
	fprintf( stderr, "send_buf: %s\n", send_buf );
	fprintf( stderr, "send_buf_ascii %s\n", send_buf_ascii );
	if( validate_tb_event( send_buf_ascii ) != 0 )
	{
		/*** disconnect and exit gracefully here! ***/
		ap_rprintf( global_http_req, 
			"malformed toolbus term \"<font color=\"red\">%s</font>\"<br>\n", 
			send_buf_ascii );	
		return OK;
	}
		
	/*
	 *	The toolbus part starts here.
	 *	We connect to the toolbus and send an event to it.
	 */		
	fprintf( stderr, "mod_toolbus: connecting to Toolbus...\n" );
	fflush( stderr );
	
	/*
	 *	Check if our flag is nonzero. It should only be set by our 
	 *	toolbus_handler(), which has not yet been called at this point. 
	 *	If it is nonzero, something is wrong, and we may have encountered some
	 *	race conditions (i.e. thread-unsafety).
	 */
	if( global_is_tb_session_done > 0 )
	{
		mod_toolbus_fatal( 
			"global_is_tb_session_done >0 before toolbus_handler() called." );	
	}
	
	/* init toolbus  module */
	ATBinit( tb_init_argc, tb_init_argv, &BottomOfStack );
	
	/* connect to toolbus and install our handler: toolbus_handler() */
	if( (tb_conn = ATBconnect( NULL, NULL, -1, toolbus_handler )) >= 0 )
	{
		count = 1;				/* send one event */
		while( global_is_tb_session_done == 0 )
		{
			/* check if data is waiting on the toolbus connection */
			if( ATBpeekOne( tb_conn ) )
			{
				fprintf( stderr, "mod_toolbus: received another event.\n" );
				fflush(stderr );
				/* invoke handler "toolbus_handler()" via ATBhandleOne() */
				if( ATBhandleOne( tb_conn ) < 0 )
				{
					fprintf( stderr, 
						"mod_toolbus: ATBhandleOne() returned error\n" );
					fflush(stderr );
					return -1;
				}
			}
			else	/* no data waiting on tb_conn so we can send some */
			{
				if( count ) /* send an event to the toolbus */
				{ 
					/* 
					 *	send term from HTTP GET to toolbus
					 */
					tb_event_to_send = ATreadFromString( send_buf_ascii );
					ATBwriteTerm( tb_conn, 
						ATmake( "snd-event(<term>)", tb_event_to_send ) );
					ATfprintf( stderr, "\nsending event to toolbus: %t\n",
						ATmake( "snd-event(<term>)", tb_event_to_send ) );
					fflush( stderr );
					count --;
				} 
			}
		}
		fprintf( stderr, "mod_toolbus: disconnecting from toolbus...\n" );
		fflush( stderr );
		ATBdisconnect( tb_conn );
		
	} 
	else
	{
		fprintf( stderr, "mod_toolbus: could not connect to toolbus\n" );
		fflush( stderr );
	}	
   	
	fprintf( stderr,"mod_toolbus: leaving handler\n");
	fflush( stderr );
	return OK;
}


/*
 *	This handler is invoked by the toolbus module whenever an event is received
 *	from the toolbus.
 */
ATerm toolbus_handler( int tb_conn, ATerm input )
{
	ATerm rv = NULL;	/* return value, gets sent back to the toolbus */
	ATerm myterm;		/* general purpose */
	ATerm myterm2;		/* general purpose */
	char html_buf[HTML_BUF_SIZE];

		
	ATfprintf( stderr, "mod_toolbus: toolbus_handler(): received: %t\n", 
		input );
	fflush( stderr );
	
	/*
	 *	match input from toolbus
	 */
	 
	/* toolbus asked for a signature check */ 
	if(ATmatch(input, "rec-do(signature(<term>,<term>))", &myterm, &myterm2))
	{
		ATfprintf( stderr, "mod_toolbus: toolbus_handler(): signature check\n" );
		fflush( stderr );
		rv =  NULL;                         /* we don't do a signature check */
	}
	/* receive ack of an event we sent (that's how we initiated our session) */
	else if( ATmatch( input, "rec-ack-event(<term>)", &myterm ) )
	{
		ATfprintf( stderr, "mod_toolbus: toolbus_handler(): rec-ack-event: %t\n",
			myterm );
		fflush( stderr );
		rv = NULL;
	}
	/* toolbus asked us to display an HTML page encoded as an ATerm  */
	else if( ATmatch( input, "rec-do(show-html(<term>))", &myterm ) )
	{
		ATfprintf( stderr, "mod_toolbus: toolbus_handler(): rec-do(show-html())\n" );
		ATparseHTML( myterm, html_buf, HTML_BUF_SIZE );
		ap_rprintf( global_http_req, html_buf );	
		global_is_tb_session_done ++;	/* after this we're done */
		rv = NULL;
	}
	else 	/* default response */
	{
		global_is_tb_session_done ++;
		ATfprintf( stderr, "mod_toolbus: toolbus_handler(): event: default\n" );
		fflush( stderr );
		rv = NULL;
	}
	ATfprintf( stderr, "mod_toolbus: toolbus_handler(): leaving...\n" );
	fflush( stderr );
	return rv;
}


/**
 *	send some info on the HTTP request back to the browser
 */
int dump_http_req_fields( request_rec *http_req )
{		
	int status;
	char ascii_uri[1000];
	
	utf8_to_ascii( ascii_uri, http_req->unparsed_uri );
	status = ap_rputs( "<h2>mod_toolbus</h2>\n", http_req );
	
	status = ap_rprintf( http_req, "(undef VERBOSE to suppress this info)\n" );
	status = ap_rprintf( http_req, "<table>\n" );
	status = ap_rprintf( http_req, "<tr><td><b>uri:</b></td>\n" );
	status = ap_rprintf( http_req, "<td>%s</td></tr>\n", http_req->uri );
	status = ap_rprintf( http_req, "<tr><td><b>plaintext uri:</b></td>\n" );
	status = ap_rprintf( http_req, "</td><td>%s</td></tr>\n", ascii_uri );
	status = ap_rprintf( http_req, "<tr><td><b>unparsed_uri:</b></td>\n" );
	status = ap_rprintf( http_req, "<td>%s</td></tr>\n", http_req->unparsed_uri );
	status = ap_rprintf( http_req, "<tr><td><b>filename:</b></td>\n" );
	status = ap_rprintf( http_req, "<td>%s</td></tr>\n", http_req->filename );
	status = ap_rprintf( http_req, "<tr><td><b>path_info:</b></td>\n" );
	status = ap_rprintf( http_req, "<td>%s</td></tr>\n", http_req->path_info );
	status = ap_rprintf( http_req, "<tr><td><b>args:</b></td>\n" );
	status = ap_rprintf( http_req, "<td>%s</td></tr>\n", http_req->args );
	status = ap_rprintf( http_req, "</table>\n" );
	
	return 0;
}


/*
 *	See if the argument is sufficiently well-formed to be sent to the 
 *	toolbus as snd-event(). (Perhaps we want to leave most of this up
 *	to the toolbus.)
 *	POST:
 *		returns 0 if the argument is well-formed
 */
int validate_tb_event( char* e )
{
	/* just return 0 for now */
	if( e == NULL || e[0] == '\0' )
	{
		return -1;
	}
	else
	{
		return 0;
	}
}


/*
 *	USE
 *		extract value from argument list
 *	PRE
 *		args	HTTP GET arguments (form: key=value1&key2e=value2&...)
 *		key		the name of the argument to extract
 *		value	a buffer with enough space to store the value
 *	POST
 *		returns 0 on success and -1 if not found
 *		if found, value contains the value of the argument requested
 *	NOTE
 *		well-formedness (occurences of '&' and '=' is not checked!
 */
int read_HTTP_GET_arg( char* args, char* key, char *value )
{
	char* value_start;
	char* key_start;					/* key-substring being evaluated */
	char* next_key_start;				/* holds value used in next iteration */
	
	int key_size;
	int value_size;
	int is_found = 0;					/* flag: key found? */
	int is_eos = 0;						/* flag: end of string encountered? */
	#ifdef DEBUG
		char key_buf [100];
	#endif
		
	key_start = args;
	while( !is_found && ! is_eos )
	{
		value_start = strchr( key_start, '=' );	/* find next equals sign */
		if( value_start == NULL )
		{	
			return -1;							/* not found */
		}
		value_start++;							/* skip '=' char itself */
		key_size = (int) value_start - (int) key_start;
		
		#ifdef DEBUG
			strncpy( key_buf, key_start, key_size-1 );
			key_buf[key_size-1]='\0';
			fprintf( stderr, "comparing %d chars in key \"%s\"\n", 
				key_size-1, key_buf );
			fflush( stderr );
		#endif
				
		next_key_start = strchr( value_start, '&' );	/* find next ampersand */
		if( next_key_start == NULL )					/* if no ampersand, find EOS */
		{
			next_key_start = strchr( value_start, '\0' );
			is_eos = 1;
			#ifdef DEBUG
				fprintf( stderr, "end of string\n" );
			#endif
		}
		next_key_start++;								/* skip '&' char itself */
		value_size = (int) next_key_start - (int) value_start;
		if( strncmp( key_start, key, key_size-1 ) == 0)
		{
			is_found = 1;
			strncpy( value, value_start, value_size-1 );
			value[value_size-1]='\0';
		}
		key_start = next_key_start;
	}
	if( is_found ) 
	{
		return 0;
	} 
	else
	{
		return -1;
	}
}

 
void mod_toolbus_fatal( char* errormessage )
{
	fprintf( stderr, "mod_toolbus fatal: %s.\n", errormessage );
	fflush( stderr );
}


/*
 * This function is a callback and it declares what other functions
 * should be called for request processing and configuration requests.
 * This callback function declares the handlers for other events.
 */
static void mod_toolbus_register_hooks (apr_pool_t *p)
{
	/*	This is the call to make to register a handler for method calls
	 *	(GET, PUT, etc.) We will ask to be last one so that the comment has a 
	 *	higher tendency to go at the end.
	 */
	ap_hook_handler( http_req_handler, NULL, NULL, APR_HOOK_LAST );
}


/*
 *	This struct is where Apache gets its info on our module from.
 *	(It has to have the same name as the module so don't change it).
 *	Only one callback function is provided. Additional callback functions 
 *	for server or directory configuration, configuration merging
 *	and other tasks may be declared here as well. 
 */
module AP_MODULE_DECLARE_DATA toolbus_module =
{
	STANDARD20_MODULE_STUFF,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	mod_toolbus_register_hooks,			/* callback for registering hooks */
};
