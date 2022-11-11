#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <time.h> // for nanosleep()

int main(int argc, char* argv[]){
  pid_t pid, wpid;
  int status = 0;
  int nb_loop = atoi(argv[1]); // convert char to int (need stdlib.h)
  
  struct timespec rqtp; // struct to use nanosleep()
  rqtp.tv_sec = 0; // seconds
  rqtp.tv_nsec = 500000000; // nanoseconds (0.5s)

  for(int i = 0; i < nb_loop; i++){
    switch(pid=fork()){
      case -1:
        perror("fork\n");
        exit(errno);
  
      // Child's code
      case 0:
          for(int j = 0; j <= 9; j++){
            printf("Child[%d] : %d\n",i,j);
            nanosleep(&rqtp, NULL);
          }
          exit(2);
          break;
    }
  }
  
  // wait for all child -> form of shitty parallelism
  while((wpid = wait(&status)) > 0);
  
  printf("Father with pid %d will die !\n",getpid());
  exit(0);
}