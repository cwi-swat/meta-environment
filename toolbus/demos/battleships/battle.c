#include "battle.tif.c"



/*
 * Structure containing information on ships.
 */
typedef struct
{
	char * type;		/* Shiptype, lowercase, used by TclTk and TB.	*/
	int    length;		/* How many spaces ship occupies on grid.		*/
} ship_info;


ship_info ships[] =
{
	{"sweeper"    , 2},
	{"destroyer"  , 3},
	{"submarine"  , 3},
	{"cruiser"    , 4},
	{"carrier"    , 5},
	{"battleship" , 5},
	NULL
};

#define	MAX_LENGTH 5			/* Battleship */



/*
 * Structure defining a pair of (x,y) coordinates.
 */
typedef struct
{
	int		x;
	int		y;
} coord;



/*
 * Structure containing necessary info per ship.
 */
typedef struct
{
	char *	name;				/* Ship's unique name.	*/
	coord	loc[MAX_LENGTH];	/* Ship's Coordinates.	*/
	int     dam;				/* Damaged locations.	*/
} ship;


/*
 * Structure containing info per player.
 */
typedef struct player
{
	ship ** fleet;				/* Dynamically allocated array.		*/
	int     ships_left;			/* If !ships_left, player looses.	*/
} player;


/* Globals */
player	players[2];
int     fleetsize = 0;


/*
 * int GetLength(char *)
 *
 * Determines length of a ship, given it's type.
 */
int
GetLength(char *ship)
{
	ship_info *info;
	for(info = &ships[0]; info; info++)
		if(strstr(ship, info->type))
			break;
	return info->length;
}



/*
 * int Placeship(int, char *, coord, int)
 *
 * Actually places a ship on the grid, based on playernumber,
 * shipname, location of the ship's bow and whether or not the
 * ship must be placed horizontally.
 *
 * The player's fleet is checked to see if there is an empty slot.
 * This occurs when a player removes a ship during setup.
 * If a slot existed, the ship is put into that slot. Otherwise the
 * player's fleetsize is increased by one. The same is done with the
 * opponent's fleetsize, but there the new slot is left empty, so it
 * will be filled when his next ship is placed.
 */
int
PlaceShip(int pl, char *shipname, coord loc, int horizontal)
{
	int  lcv, len;
	ship *the_ship;
	char *type;

	--pl;	/* Player one is index zero!	*/

	/* Allocate and initialize new ship. */
	len = GetLength(shipname);
	the_ship = (ship *) malloc(sizeof(ship));
	the_ship->dam = 0;
	the_ship->name = strdup(shipname);

	/* Install all locations of the ship. */
	for(lcv=0; lcv < len; lcv++)
	{
		the_ship->loc[lcv] = loc;
		loc.x += horizontal ? 1 : 0;		/* Update coordinate according	*/
		loc.y += horizontal ? 0 : 1;		/* to status of horizontal.		*/
	}

	/* Check if a RemoveShip-call has left a free spot. */
	for(lcv=0; lcv<fleetsize; lcv++)
	{
		if(!(players[pl].fleet[lcv]))
		{
			players[pl].fleet[lcv] = the_ship;
			return 1;
		}
	}

	/* No free spot. Increase fleetsize for both players. */
	++fleetsize;
        if(!players[0].fleet)
          players[0].fleet = (ship **) malloc(sizeof(ship *) * fleetsize);
        else 
	  players[0].fleet = (ship **) realloc(players[0].fleet,
		  sizeof(ship *) * fleetsize);
	players[0].ships_left++;

        if(!players[1].fleet)
          players[1].fleet = (ship **) malloc(sizeof(ship *) * fleetsize);
        else
  	  players[1].fleet = (ship **) realloc(players[1].fleet,
		  sizeof(ship *) * fleetsize);
	players[1].ships_left++;

	players[pl].fleet[lcv]   = the_ship;
	players[1-pl].fleet[lcv] = NULL;
	return 1;
}


/*
 * int RemoveShip(int, char *)
 *
 * Removes a ship at player's request. 
 */
int
RemoveShip(int pl, char *shipname)
{
	int  lcv;

	--pl;
	for(lcv=0; lcv<fleetsize; lcv++)
	{
		if(!players[pl].fleet[lcv])
			continue;
		if(!(strcmp(players[pl].fleet[lcv]->name, shipname)))
		{
			free(players[pl].fleet[lcv]->name);
			free(players[pl].fleet[lcv]);
			players[pl].fleet[lcv] = NULL;
			break;
		}
	}
}

/*
 * int HitLocation(int, coord, char **)
 *
 * Hit a certain location. Check if there is a ship and if so
 * if this hit sinks the ship.
 *
 * Return value: -1  -> Miss
 *                0  -> Ship hit, but was already hit
 *                1  -> Ship hit, not yet sunk though.
 *                2  -> Ship hit and sunk, player has more ships.
 *                3  -> Ship hit and sunk, this was last ship.
 */
int
HitLocation(int pl, coord loc, char **name)
{
	int       num, lcv, len, dam;
	ship *    the_ship;

	--pl;

	for(num=0; num < fleetsize; num++)
	{
		if(!players[pl].fleet[num])
			continue;
		len = GetLength(players[pl].fleet[num]->name);
		the_ship = players[pl].fleet[num];
		for(lcv=0; lcv<len; lcv++)
		{
			if(coord_match(the_ship->loc[lcv], loc))
			{
				*name = the_ship->name;
				dam = the_ship->dam;
				the_ship->dam |= (1<<lcv);
				if(the_ship->dam <= dam)
					return 0;
				else
				{
					if(the_ship->dam < (1<<len)-1)
						return 1;
					else
						return --players[pl].ships_left ? 2 : 3;
				}
			}
		}
	}

	*name = "miss";
	return -1;				/* Miss */
}


/* Check if two coordinates are the same. */
int
coord_match(coord c1, coord c2)
{
	return ((c1.x == c2.x) && (c1.y == c2.y));
}

/* Determine how much hits a ship has sustained. */
int
calc_dam(int dam)
{
	int	count= dam ? 1 : 0;
	while(dam>>=1) count++;
	return count;
}



/*
 * ToolBus interface starts here.
 */

void
placeShip(int pl, char *name, int x, int y, int hor)
{
	coord	loc;

	loc.x = x; loc.y = y;
	PlaceShip(pl, name, loc, hor);
}

void
removeShip(int pl, char *name)
{
	RemoveShip(pl, name);
}

term *
hitLocation(int pl, int x, int y)
{
	coord	loc;
	int		res;
	char   *name;

	loc.x = x; loc.y = y;
	res = HitLocation( (pl==2 ? 1 : 2), loc, &name);

	return TBmake("snd-value(hitLocation(%d, %d, %s))", pl, res, name);
}

void
rec_terminate(term *t)
{
	exit(0);
}

void main(int argc, char *argv[])
{
	TBinit("battle", argc, argv, battle_handler, battle_check_in_sign);
	TBeventloop();
}
