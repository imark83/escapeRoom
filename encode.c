#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[]) {

  printf("Size = %zi\n", sizeof(short int));

  int i;
  char *msg = "Seguro dental!!!";
  if(argc > 1) {
    msg = (char *) malloc (sizeof(argv[1])+1);
    strcpy(msg,argv[1]);
  }
  int password = 0xa673;
  if(argc > 2) password = (short int ) (atoi(argv[2]) & 0x0000FFFF);
  password |= password << 16;
  size_t len = strlen(msg)+1;
  printf("len = %zi\n", len);

  int *intMsg;
  intMsg = (int *) malloc(((len+3)/4)*sizeof(int)+1);
  memcpy(intMsg, msg, len*sizeof(char));
  *(((char *) intMsg) + len) = '\0';
  printf("copyed %zi into %zi bytes\n", len, ((len+3)/4)*sizeof(int));

  int n = (len+3)/4;
  for(i=0; i<n; ++i) *(intMsg+i) ^= password; 

  printf("Ecrypted:  %s\n", (char*) intMsg);
  printf("numbers:\n");
  for(i=0; i<n; ++i)
    printf("    %12i\n", *(intMsg+i));

  for(i=0; i<n; ++i) *(intMsg+i) ^= password; 

  printf("Decrypted: %s\n", (char*) intMsg);

  if(argc > 1) free(msg);
  free(intMsg);

  return 0;
}