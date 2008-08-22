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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <usb.h>

#include "obdev_usb.h"

#include "usbrelay.h"

#define USBDEV_SHARED_VENDOR    0xc016  /* VOTI */
#define USBDEV_SHARED_PRODUCT   0xdf05  /* Obdev's free shared PID */
/* Use obdev's generic shared VID/PID pair and follow the rules outlined
 * in firmware/usbdrv/USBID-License.txt.
 */

#define USB_TIMEOUT 1000

static usb_dev_handle  *usb_handle = NULL;
static char str_error[128]= {0};

int usbrelay_init()
{
	usb_init();
	if(usbOpenDevice(&usb_handle, USBDEV_SHARED_VENDOR, "johannes.krude.de", USBDEV_SHARED_PRODUCT, "usb-Relay") != 0){
		snprintf(str_error, sizeof(str_error), "Could not find USB device \"usb-Relay\" with vid=0x%x pid=0x%x", USBDEV_SHARED_VENDOR, USBDEV_SHARED_PRODUCT);
		return(1);
	}
}

char *usbrelay_strerror()
{
	return str_error;
}

static int usb_do(int direction, int request, char value, char *data, int len)
{
	int i;
	while (len > 254) {
		usb_do(direction, request, value, data, 254);
		data+= 254;
		len-= 254;
	}
	i= usb_control_msg(usb_handle, USB_TYPE_VENDOR | USB_RECIP_DEVICE | direction, request, value, 0, data, len, USB_TIMEOUT);
	if (i < 0) {
		snprintf(str_error, sizeof(str_error), "usb error: %s", usb_strerror());
		return i;
	}
	return 0;
}

int usbrelay_set(uchar set)
{
	return usb_do(USB_ENDPOINT_OUT, REQUEST_SET, set, 0, 0);
}

uchar usbrelay_count()
{
	uchar result;
	usb_do(USB_ENDPOINT_IN, REQUEST_COUNT, 0, &result, 1);
	return result;
}

