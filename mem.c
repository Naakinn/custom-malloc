#include "mem.h"

#define BUFSIZE 128

static uint8_t buf[BUFSIZE]; 
static uint8_t* frptr = buf; 
static unsigned int frlen = BUFSIZE; 

static void LOG(char* msg) {
	printf("%s\n", msg);
	printf("Used: %u/%d\n", BUFSIZE - frlen, BUFSIZE);
	printf("Unsused: %u/%d\n", frlen, BUFSIZE);
	printf("Next free space: %p\n", frptr);
}

void* f_alloc(size_t size) {
	if (frlen < size) {
		return NULL;
	}
	uint8_t* tmp = frptr;
	frptr += size;
	frlen -= size; 
	LOG("Alloc");
	return tmp;
}

void f_free(void* ptr) {
	if ((uint8_t*)ptr >= buf && (uint8_t*)ptr < buf + BUFSIZE) {
		frlen += frptr - (uint8_t*)ptr;
		frptr = ptr;
		LOG("Free");
	} else {
		return;
	}
}
