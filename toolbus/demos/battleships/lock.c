/*
 *     Hayco de Jong -- 9011439 -- jong@fwi.uva.nl -- Battleships
 */
#include "lock.tif.c"

#define MAX_LOCK 128

typedef struct lock
{
    char    *data;          /* Data describing the lock.    */
    int      user;          /* Who has the lock?            */
} lock;

lock    LOCKS[128];


int
TryLock(int the_user, char *the_data)
{
    int lcv;

    /* Must have a name and a user for a lock.  */
    if(the_user<0 || !the_data || !*the_data)
        return 0;

    /* If there already exists such a lock, we fail. */
    if(CheckByData(the_data))
        return 0;

    for(lcv=0; lcv<MAX_LOCK; lcv++)
    {
        if(LOCKS[lcv].user == -1)
        {
            LOCKS[lcv].user = the_user;
            LOCKS[lcv].data = (char *) strdup(the_data);
            return 1;
        }
    }

    return 0;       /* No more locks available. */
}

void
UnlockByData(char *the_data)
{
    int lcv;

    if(!the_data || !*the_data)
        return;
    
    for(lcv=0; lcv<MAX_LOCK; lcv++)
    {
        if(LOCKS[lcv].user>0 && !strcmp(LOCKS[lcv].data, the_data))
        {
            free(LOCKS[lcv].data);
            LOCKS[lcv].data = NULL;
            LOCKS[lcv].user = -1;
            return;
        }
    }
}

void
UnlockByUser(int the_user)
{
    int lcv;

    if(the_user < 0)
        return;
    
    for(lcv=0; lcv<MAX_LOCK; lcv++)
    {
        if(LOCKS[lcv].user == the_user)
        {
            if(LOCKS[lcv].data)
            {
                free(LOCKS[lcv].data);
                LOCKS[lcv].data = NULL;
            }
            LOCKS[lcv].user = -1;
            return;
        }
    }
}

int
CheckByUser(int the_user)
{
    int lcv;

    if(the_user < 0)
        return 0;
    
    for(lcv=0; lcv<MAX_LOCK; lcv++)
    {
        if(LOCKS[lcv].user = the_user)
            return 1;
    }

    return 0;
}

int
CheckByData(char *the_data)
{
    int lcv;

    if(!the_data || !*the_data)
        return 0;
    
    for(lcv=0; lcv<MAX_LOCK; lcv++)
    {
        if(LOCKS[lcv].user>0 && !strcmp(LOCKS[lcv].data, the_data))
            return 1;
    }

    return 0;
}



int
CheckLock(int the_user, char *the_data)
{
    int lcv;

    if(the_user < 0 || !the_data || !*the_data)
        return 0;

    for(lcv=0; lcv<MAX_LOCK; lcv++)
    {
        if(LOCKS[lcv].user == the_user && !strcmp(LOCKS[lcv].data, the_data))
            return 1;
    }

    return 0;
}


void
InitLocks(void)
{
    int lcv;
    for(lcv=0; lcv<MAX_LOCK; lcv++)
    {
        LOCKS[lcv].user = -1;
        LOCKS[lcv].data = NULL;
    }
}

/*
 * ToolBus interface starts here.
 */

#define TBTRUE  TBmake("true")
#define TBFALSE TBmake("false")

term *
tryLock(term *trm, char *data)
{
    int user;
    TBmatch(trm, "player(%d)", &user);

    return TBmake("snd-value(tryLock(%t, %s, %t))",
        trm, data, (TryLock(user, data) ? TBTRUE : TBFALSE));
}

void
doUserUnlock(term *trm)
{
    int user;
    TBmatch(trm, "player(%d)", &user);

    UnlockByUser(user);
}

void
doDataUnlock(char *data)
{
    UnlockByData(data);
}

term *
checkDataIsLocked(char *data)
{
    return TBmake("snd-value(checkDataIsLocked(%s, %t))",
        data, (CheckByData(data) ? TBTRUE : TBFALSE));
}

term *
checkUserIsLocked(term *trm)
{
    int user;
    TBmatch(trm, "player(%d)", &user);

    return TBmake("snd-value(checkUserIsLocked(%t, %t))",
        trm, (CheckByUser(user) ? TBTRUE : TBFALSE));
}

term *
checkLock(term *trm, char *data)
{
    int user;
    TBmatch(trm, "player(%d)", &user);

    return TBmake("snd-value(checkLock(%t, %s, %t))",
        trm, data, (CheckLock(user, data) ? TBTRUE : TBFALSE));
}

void
rec_terminate(term *t)
{
    exit(0);
}



void
main(int argc, char *argv[])
{
    InitLocks();
    TBinit("lock", argc, argv, lock_handler, lock_check_in_sign);
    TBeventloop();
}
