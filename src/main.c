/*
 * main.c
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
#include "ccn.h"
#include "interest.h"
#include "content.h"


#define GOT_HERE printf("[%d] Got here\n", __LINE__);

int main()
{
	ccn_connect();

	//printf("Connected\n");
	return 0;
}
