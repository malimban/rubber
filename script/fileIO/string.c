#include <stdio.h>
#include <stdlib.h>

int main() {
	File *fp;

	printf("Hello World\n");

	if((in_fp = fopen("input.txt", "r" == NULL) {
		printf("ERROR");
		return -1;
	] else {
		char cha;
		while (cha = getc(in_fp)) != EOF) {
			printf(cha);
		}
	}
	return 0;
}
