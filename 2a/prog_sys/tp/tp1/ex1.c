#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// argc -> number of argument
// argv -> array of argument
int main(int argc, char* argv[]){

  for(int i = 0; i < argc; i++){
    printf("arg[%d]=%s\n",i,argv[i]);
  }
  printf("---------------------------------\n");
  system("echo \"PATH => $PATH\"");  
  
  return 0;
}
