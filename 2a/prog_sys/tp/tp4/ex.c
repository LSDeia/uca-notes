#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h> 
#include <sys/wait.h>

#define BUFFER_SIZE 4096

void father(int tabPipes[2])
{
  char buffer[BUFFER_SIZE];
  printf("Father send msg : ");
  while(fgets(buffer,BUFFER_SIZE,stdin) != NULL)
  {
    write(tabPipes[1],buffer,BUFFER_SIZE);
    sleep(1); // shit for good output
    printf("Father send msg : ");
  }  
  close(tabPipes[1]);
}

void child(int tabPipes[2])
{
  char buffer[BUFFER_SIZE];
  while(read(tabPipes[0],buffer,BUFFER_SIZE))
  {
    printf("Child repeat: %s",buffer);
  }
  close(tabPipes[0]);
}

int main ()
{
  int tabPipes[2]; // Index 0 = read; 1 = write
  pid_t pid;
  
  if(pipe(tabPipes) != 0)
  {
    perror("Pipe creation error");
  }

  switch(pid=fork())
  {
    case -1:
        perror("fork error");
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
  
  while((wait(NULL)) > 0);
  
  return 0;
}