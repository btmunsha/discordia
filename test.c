#include <stdio.h>
#include <stdlib.h>
#include "popen2.h"

int main()
{
	/* popen2.c popen2 */
	int in, out;
	char *buf[128] = {0};
	char *args[] = {"/bin/cat", NULL};
	popen2("/bin/cat", args, &in, &out);
	write(in, "Hello", 128);
	read(out, buf, 128);
	if (strcmp("Hello", buf) != 0) {
		perror("popen2 popen2 failed.");
		exit(1);
	}

	printf("All tests passed\n");
	
	return 0;
}

