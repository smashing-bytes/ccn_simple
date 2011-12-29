/*
 * ccn.c
 * Main CCN functions
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
#include "ccn.h"

void print_ip(int ip)
{
	unsigned char bytes[4];
	bytes[0] = ip & 0xFF;
	bytes[1] = (ip >> 8) & 0xFF;
	bytes[2] = (ip >> 16) & 0xFF;
	bytes[3] = (ip >> 24) & 0xFF;       
	printf("%d.%d.%d.%d\n", bytes[3], bytes[2], bytes[1], bytes[0]);        
}
/*
int char_to_ip(char *ip, size_t addrlen)
{
	unsigned *octets;
	unsigned char *bytes;
	int addr, tmp;
	unsigned short i, j;
	octets = malloc(4 * sizeof(unsigned int));
	bytes = malloc(32 * sizeof(unsigned char*));

	sscanf(ip, "%3u.%3u.%3u.%3u", &octets[0], &octets[1], &octets[2], &octets[3]);
	for(i = 0; i < 4; i++)
	{
		
		unsigned mask = ~(~0u >> 1);
		while (mask) 
		{					
			*bytes++ = octets[i] & mask ? '1' : '0';
			mask >>= 1;
			printf("%c", bytes);
		}
		*bytes = '\0';		
	}

	//printf("%c.%c.%c.%c", bytes[3], bytes[2], bytes[1], bytes[0]);
	addr = (addr << 8) +  bytes[3];
	addr = (addr << 8) +  bytes[2];
	addr = (addr << 8) +  bytes[1];
	addr = (addr << 8) +  bytes[0];
	//printf("%o\n", addr);
	return addr;
}
*/
int char_to_ip(const char *ip)
{

	return ntohl(inet_addr(ip));
}

/*Bad hack*/
int getmyip()
{
	int i;
	struct in_addr *inp;
	struct ifaddrs * ifaddrstruct = NULL;
	struct ifaddrs * ifa = NULL;
	void * tmpaddrptr = NULL;
	char addressbuffer[INET_ADDRSTRLEN];
	getifaddrs(&ifaddrstruct);

	for (ifa = ifaddrstruct; ifa != NULL; ifa = ifa->ifa_next)
	{
		if (ifa ->ifa_addr->sa_family==AF_INET)  
		{
			
			tmpaddrptr = &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
			
			inet_ntop(AF_INET, tmpaddrptr, addressbuffer, INET_ADDRSTRLEN);
			
			if(strcmp(addressbuffer, "127.0.0.1"))
			   break;
		}
		
	}
	/*Convert to int*/
	//for(i = 0; i < strlen(addressbuffer) + 1; i++)
	//	printf("%c|", addressbuffer[i]);
	//printf("%s\n", addressbuffer);
	print_ip(char_to_ip(addressbuffer));
	if (ifaddrstruct != NULL) 
		freeifaddrs(ifaddrstruct);
	return 0;

}
void ccn_connect()
{

	connect_packet *connect_pack;
	ccn_packet *ccn_pack;

	//connect_pack->ip = 0; //GET IP
	//connect_packet->pid = 0; //TODO: get pid
	getmyip();


}
unsigned char *serialize_packet(ccn_packet *packet, int type)
{
	unsigned char *pack;

	switch(type)
	{
	case 0: /*connect*/
	{


		break;
	}
	case 1: /*Interest*/
	{
		break;
	}
	case 2: /*Content*/
	{
		break;
	}
	}
}