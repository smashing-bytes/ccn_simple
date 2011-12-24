 /*
 * ccn.h
 * Main CCN definitions
 * Copyright (C) Haris Fokas 2011 <netharis@venus.cs.aueb.gr>
	 * 
 * ccn_simple is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
	 * 
 * ccn_simple is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "interest.h"
#include "content.h"

#define PACKET_SIZE 20000 //bytes


typedef struct interest interest;
typedef struct content content;
enum packet_type
{
	_CONNECT,     /*connect*/
	_INTEREST,    /*Interest*/
	_CONTENT      /*Content */
};

struct ccn_packet
{
	int pt;
	unsigned char *data; //Encapsulation
	
};

/*Function declarations*/
unsigned char *serialize_packet(struct ccn_packet *packet, int type);
static void ccn_connect();
static int express_interest(interest *_int);
static int send_content(content *_con);


