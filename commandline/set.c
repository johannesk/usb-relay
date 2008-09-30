/*
 * © Johannes Krude 2008
 *
 * This file is part of spi2usb.
 *
 * spi2usb is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * spi2usb is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with spi2usb.  If not, see <http://www.gnu.org/licenses/>.
 */

#define SPI_USB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/usbrelay.h"

void usage()
{
	printf("set usb-Relay\n");
	printf("usage: ./set [digit] [digit]\n");
	exit(1);
}

int main (int argc, char *argv[])
{
	if (argc != 3)
		usage();
	if (strlen(argv[2]) != 1)
		usage();
	if (strlen(argv[2]) != 1)
		usage();
	if ((argv[1][0] < '0') || (argv[1][0] > '9'))
		usage();
	if ((argv[2][0] < '0') || (argv[2][0] > '1'))
		usage();
	
	usbrelay_init();
	usbrelay_set(argv[1][0] - '0', argv[2][0] - '0');
	return 0;
}
