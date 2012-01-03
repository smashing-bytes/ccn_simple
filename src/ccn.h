 #ifndef _CCN_H_
 #define _CCN_H_
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
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>  
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>    
#include <ifaddrs.h>
#include <string.h> 
#include <arpa/inet.h>


#include "interest.h"
#include "content.h"
#define PACKET_SIZE 20000 //bytes


int ccn_connect();

enum packet_type
{
	_CONNECT,     /*connect*/
	_INTEREST,    /*Interest*/
	_CONTENT      /*Content */
};

struct connect_packet
{
	unsigned short pid;
	int ip;
};

struct ccn_packet
{
	int pt; //type
	unsigned short len;
	unsigned char *data; //Encapsulation
	
};


/*typedefs*/
typedef struct ccn_packet ccn_packet;
typedef struct connect_packet connect_packet;

/*Forward declarations*/

int encapsulate_connect(connect_packet *packet, ccn_packet *pack);

//TODO: add other encapsulations
#endif

