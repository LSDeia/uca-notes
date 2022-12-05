#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h> 
#include <sys/wait.h>

void father(int tabPipes[2])
{
  char buffer[1024];
  int res;
  while(1)
  {

    printf("Father send msg : ");
    scanf("%s", buffer);
    res = write(tabPipes[1],buffer,sizeof(buffer));
    printf("Write return code: %d\n",res);
  }  
  close(tabPipes[1]);
}

void child(int tabPipes[2])
{
  char buffer[1024];
  int res;
  res = read(tabPipes[0],buffer,sizeof(buffer));
  printf("Read return code: %d\n", res);
  printf("Buffer value: %s\n",buffer); 
  // while((res = read(tabPipes[0],buffer,sizeof(buffer))>=0))
  // {
  //   printf("CHILD REPEAT: %s",buffer);
  // }
  if(res == -1)printf("Erreur pipe inexistant");
  close(tabPipes[0]);
}

int main ()
{
  int tabPipes[2]; // array of pipes
  int res = pipe(tabPipes);
  printf("Pipe return code: %d\n",res);

  pid_t pid;
  pid_t wpid;
  int status = 0;

  switch(pid=fork())
  {
    case -1:
        perror("error fork");
        exit(errno);
    case 0:
        close(tabPipes[1]);  
        child(tabPipes);
    default:
        close(tabPipes[0]);
        father(tabPipes); // n'a pas tout les pipes dans le tableau
  }
  
  while((wpid = wait(&status)) > 0);
  return 0;
}