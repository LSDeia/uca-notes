#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define SIZE_BUFFER 1024

void cutMsg(){
  // cut message
  // return index
}

void father(char* msg, int tabPipes[][2]){
  // function decoupe msg
  // recup int du msg
  // gestion d'erreur du int
  // ecriture dans la bonne pipe du msg
  // fermer pipe
}

void child(int num, int tabPipes[][2]){
  // fermer pipes dupliqués
  char buffer[SIZE_BUFFER]; 
  while(read(tabPipes[num][0], buffer, SIZE_BUFFER)){
    printf(buffer); // bizarre
  }
  // pas capté la fermeture des pipes
  return;
}

int main (int argc, char* argv[]){
  int nbChilds = atoi(argv[1]);
  int tabPipes[nbChilds][2]; // array of pipes
  
  // a mettre dans un fonction
  for(int i=0;i < nbChilds; i++){ // create all childs
    switch(fork()){
      case 1:
        perror("error fork");
        exit(1);
      case 0:
        pipe(tabPipes[i]);
        child(i, *tabPipes[2]); // n'a pas tout les pipes dans le tableau
    }
  }
  
  // a mettre dans une fonction
  while(1){ // take input from user
    char *msg;
    scanf("%s", msg);
    father(msg, *tabPipes[2]);
  }
  
  exit(0);
}
