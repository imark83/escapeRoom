#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[]) {
  int i;
  char *msg = "Seguro dental!!!";
  if(argc > 1) {
    msg = (char *) malloc (strlen(argv[1])+1);
    strcpy(msg,argv[1]);
  }
  char *password = "palabra";
  if(argc > 2) {
  	password = (char*) malloc(strlen(argv[2])+1);
  	strcpy(password, argv[2]);
  }

  size_t len = strlen(msg)+1;
  size_t pwdLen = strlen(password);
  int n = (len+3)/4;

  printf("len = %zi\n", len);

  int *intMsg;
  intMsg = (int *) malloc(n*sizeof(int));
  memcpy(intMsg, msg, len*sizeof(char));

  for(i=0; i<n*4; ++i) *(((char*) intMsg)+i) ^= *(password+(i%pwdLen)); 

  printf("Ecrypted:  %s\n", (char*) intMsg);
  printf("numbers:\n");
  for(i=0; i<n; ++i)
    printf("    %12i\n", *(intMsg+i));
  printf("password:\n\t%s\n", password);

  for(i=0; i<n*4; ++i) *(((char*) intMsg)+i) ^= *(password + (i%pwdLen)); 

  printf("Decrypted: %s\n", (char*) intMsg);

  if(argc > 1) free(msg);
  free(intMsg);

  return 0;
}