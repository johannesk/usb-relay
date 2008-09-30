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
	printf("count relays on usb-Relay\n");
	printf("usage: ./count\n");
	exit(1);
}

int main (int argc, char *argv[])
{
	if (argc != 1)
		usage();
	
	if (usbrelay_init()!=0) {
		printf("%s\n", usbrelay_strerror());
		return 1;
	}
	printf("%i\n", usbrelay_count());
	return 0;
}
