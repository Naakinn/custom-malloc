#include <stdio.h>
#include "mem.h"

static int STATUS = 0;

int main(int argc, char** argv) {

	/* Allocate */
	unsigned int size = 16;
	char* str = f_alloc(size); 
	if (str == NULL) {
		STATUS = -1;
		goto exit;
	}
	/* Free */
	f_free(str); 
	
	exit:
	printf("Process finished with exit code %d\n", STATUS);
	return STATUS;
}
