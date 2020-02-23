#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)

int main(int argc, char *argv[] ) {
	if( argc == 1) {
		fprintf(stdout, "Expected file location & default Delay\n\n");
		return 0;
	}
	for(int i = 0; i < 3; i++)
		printf("%s\n",argv[i]);

	FILE *frp, *fwp;
	char buff[255];

	char* p;
	long defDelay = strtol(argv[2], &p, 10);
	if (*p != '\0') // invalid char found b4 end of string
		return -1;

	frp = fopen(argv[1], "r");
	fwp = fopen("./output.txt", "w+");
/* */
	while( fgets(buff,255,frp) ) {
		if(strncmp(buff,"STRING", 6) == 0) { //STRING needs default delay

			for(int i = 7; i < 255; i++) {
				if(buff[i] == '\n')
					break;
				if(buff[i] == ' ') {
					fprintf(fwp,"SPACE\n");
				} else
					fprintf(fwp, "STRING %c\n", buff[i]);
				fprintf(fwp, "DELAY %ld\n", defDelay);
			}
			fprintf(fwp, "\n");

		} else {
//			fprintf(stdout, "%s", buff);
			fprintf(fwp, "%s", buff);
		}
	}
/**/

	fclose(frp);
	fclose(fwp);
}
