#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <time.h> // for nanosleep()

int main(int argc, char* argv[]){
  pid_t pid;
  int status = 0;
  
  struct timespec rqtp; 
  rqtp.tv_sec = 0;
  rqtp.tv_nsec = 500000000;
  
  switch(pid=fork()){
    case -1:
      perror("fork\n");
      exit(errno);
    
    // Child's code
    case 0:
        for(int i = 0; i <= 9; i++){
          printf("%d\n",i);
          nanosleep(&rqtp, NULL);
        }
        system("ps -f");
        exit(2);
        break;
    
    // Father's code
    default:
      // Wait for specific child -> pid
      waitpid(pid, &status,0); // or you can wait for all child -> wait(&status);
      printf("Child return code is : %d\n",WEXITSTATUS(status));
      printf("Father with pid %d will die !\n",getpid());
  }
  
  exit(0);
}