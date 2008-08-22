# Name: Makefile
# Project: PowerSwitch
# Author: Christian Starkjohann
# Creation Date: 2005-01-16
# Tabsize: 4
# Copyright: (c) 2005 by OBJECTIVE DEVELOPMENT Software GmbH
# License: GNU GPL v2 (see License.txt) or proprietary (CommercialLicense.txt)
# This Revision: $Id: Makefile 276 2007-03-20 10:53:04Z cs $

CC		= gcc
CFLAGS	= -O -Wall
LIBS	= -L./lib -lusbrelay

DO= set count

all: $(DO)

libusbrelay:
	make -C lib

.c.o:
	$(CC) $(CFLAGS) -c $<

set: libusbrelay set.o
	$(CC) -o set $(LIBS) set.o

count: libusbrelay count.o
	$(CC) -o count $(LIBS) count.o

strip: $(PROGRAM)
	strip $(DO)

clean:
	rm -f *.o $(DO)
