#ifndef uchar
#define uchar unsigned char
#endif

#define REQUEST_COUNT 0
#define REQUEST_SET   1

int usbrelay_init();
uchar usbrelay_count();
int usbrelay_set(uchar number, uchar value);
char *usbrelay_strerror();
