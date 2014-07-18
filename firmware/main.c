/*
 * © Johannes Krude 2008
 *
 * This file is part of usb-Relay.
 *
 * usb-Relay is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * usb-Relay is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with usb-Relay.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "main_obdev.c"

/*
Pin assignment:
PB0, PB2 = USB data lines
*/

#define BIT_SWITCH 3

#define REQUESTTYPE_D2H         0x80

#define REQUEST_DEVICE_COUNT 0
#define REQUEST_SET_RELAYS   1

/* ------------------------------------------------------------------------- */

uchar	usbFunctionSetup(uchar data[8])
{
	usbRequest_t *request= (usbRequest_t*) data;
	static uchar one= 1;
	switch (request->bRequest) {
	case REQUEST_DEVICE_COUNT:
		if (((request->bmRequestType & REQUESTTYPE_D2H) != 0) && (request->wLength.word == 1)) {
			usbMsgPtr= &one;
			return 1; // we want to send the requested data
		}
		break;
	case REQUEST_SET_RELAYS:
		if (request->wValue.bytes[1] != 0)
			return 0;
		if (request->wValue.bytes[0] & 0x01)
			PORTB|= (1<<BIT_SWITCH);
		else
			PORTB&= ~(1<<BIT_SWITCH);
	}
	return 0;
}

uchar main(void)
{
	DDRB= (1<<BIT_SWITCH);
	main_obdev();
}
