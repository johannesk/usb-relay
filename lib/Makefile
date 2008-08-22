CC= gcc -fpic
LIBS= -lusb

all: libusbrelay.so

libusbrelay.so: usbrelay.o obdev_usb.o
	$(CC) --shared $(LIBS) -o libusbrelay.so usbrelay.o obdev_usb.o

clean:
	rm *.o *.so
