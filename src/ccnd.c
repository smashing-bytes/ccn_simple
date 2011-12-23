/*
 * ccnd.c
 * Main CCN daemon
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
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

/*Threading*/
#include <pthread.h>


#include "ccnd.h"
#include "content.h"
#include "interest.h"

/*Domain socket path*/
#define SOCK_PATH "/tmp/.tmpsock" 

typedef struct interest interest;
typedef struct content content;


/*fwd declarations*/
static int ccn_connect();
void *message_receiver(void *ptr); //in pthread
static int handle_incoming_interest(interest *msg);
static int handle_incoming_content(content *msg);


/*Entry point*/
int main(int argc, char **argv)
{
	pthread_t message_thread;
	int ret;
	long t;

	ret = pthread_create(&message_thread, NULL, message_receiver, (void*) t);


	
	pthread_join(message_thread, NULL);

	return 0;

	

}


void *message_receiver(void *ptr)
{
	int s, s2, t; 
	size_t len;
	struct sockaddr_un local, remote;
	if((s = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) 
	{
        	perror("Socket Error\n");
        	exit(1);
    	}

	local.sun_family = AF_UNIX;
    	strcpy(local.sun_path, SOCK_PATH);
    	unlink(local.sun_path);
    	len = strlen(local.sun_path) + sizeof(local.sun_family);


	if(bind(s, (struct sockaddr *)&local, len) == -1) 
	{
        	perror("Bind Error");
        	exit(1);
    	}

	if (listen(s, 5) == -1) 
	{
		perror("Listen Error");
		exit(1);
    	}
	return 0;
}























