#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[]) {

  int i;
  char *msg = "Seguro dental";
  if(argc > 1) msg = argv[1];
  int password = 0xa673bfc4;
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

  for(i=0; i<n; ++i) *(intMsg+i) ^= password; 

  printf("Decrypted: %s\n", (char*) intMsg);



  return 0;
}