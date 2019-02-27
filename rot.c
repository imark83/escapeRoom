#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int n=27;
char l[] = {
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
	164, 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int getPos(char c) {
	int rop = 0;
	while (rop < n && l[rop] != c) ++rop;
	return rop;
}

int main(int argc, char const *argv[]) {
	int i;
	if(argc<3) {
		fprintf(stderr,"Use:\n\t%s [rot] [input]\n",argv[0]);
		return 0;
	}
	int shift = atoi(argv[1]);
	for(i=0; i<strlen(argv[2]); ++i) {
		printf("%c", l[(getPos(argv[2][i])+shift)%n]);
	}
	printf("\n");
	return 0;
}