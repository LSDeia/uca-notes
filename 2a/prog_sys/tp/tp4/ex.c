#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h> 
#include <sys/wait.h>

void father(int tabPipes[2])
{
  char buffer[1024];
  printf("Father send msg : ");
  while(fgets(buffer,1024,stdin) != NULL)
  {
    write(tabPipes[1],buffer,1024);
    sleep(1);
    printf("Father send msg : ");
  }  
  close(tabPipes[1]);
}

void child(int tabPipes[2])
{
  char buffer[1024];
  while(read(tabPipes[0],buffer,1024))
  {
    printf("Child repeat: %s",buffer);
  }
  close(tabPipes[0]);
}

int main ()
{
  int tabPipes[2];
   // array of pipes
  if(pipe(tabPipes) != 0)
  {
    perror("Pipe creation error");
  }

  pid_t pid;

  switch(pid=fork())
  {
    case -1:
        perror("error fork");
        exit(errno);
    case 0:
        close(tabPipes[1]);
        child(tabPipes);
        break;
    default:
        close(tabPipes[0]);
        father(tabPipes);
        break; // n'a pas tout les pipes dans le tableau
  }
  
  return 0;
}