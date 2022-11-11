#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
  // call to shell command
  system("ps -f");
  // execlp overwrite following code if successful
  // execlp(path of file, command, args, ..., NULL)
  execlp("/usr/bin/ps","ps","-f",NULL);
  // print if execlp failed
  printf("End!");
  
  exit(0);
}