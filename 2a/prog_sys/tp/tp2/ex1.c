#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

void showFileInfo(char* filename)
{
  struct stat buf;
  
  if(stat(filename, &buf) == -1){
    perror("stat");
    return;
  }
  
  printf("------INFO------\n");
  printf("Filename: %s\n",filename);
  printf("Total size (Octets): %jd\n",buf.st_size);
  printf("Last modification (since 01/01/1970): %ld\n",buf.st_mtime);
  
  return;
}

void showDir(char *dirname){
  DIR *dp;
  struct dirent *dirp;
  dp = opendir(dirname);
  char* path;
  
  while((dirp = readdir(dp)) != NULL){
    path = (char*)malloc(sizeof(dirname) + sizeof(dirp->d_name) +1);
    strcpy(path,dirname);
    strcat(path,"/");
    strcat(path, dirp->d_name);
    showFileInfo(path);
    free(path);
  }
  
  closedir(dp);
}

void listDirContent(char* dirname)
{
  DIR *dp;
  struct dirent *dirp;
  
  dp = opendir(dirname);
  
  while((dirp = readdir(dp)) != NULL){
    printf("%s\n",dirp->d_name);
  }
  
  closedir(dp);
 return;  
}

int main(int argc, char* argv[]){
  
  if(argc < 2){
    perror("Vous devez spécifier un argument: filename\n");
    exit(2);
  }
  showDir(argv[1]);
  //listDirContent(argv[1]);
  //showFileInfo(argv[1]);
  return 0;
}