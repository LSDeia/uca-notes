#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


void pere(int tab[2])
{
    while (1)
    {
        char msg[10];
        scanf("%s",msg);
        write(tab[1],msg,sizeof(msg));
    }
}

void fils(int tab[2])
{
    int res;
    int counter=0;
    char buffer[1024];
    while((res = read(tab[0],buffer,1024)>=0))
    {
        printf("Counter: %d\nContent: %s\n",counter,buffer);
        counter++;
    }
    if(res == -1)printf("Erreur pipe inexistant");
}


int main()
{
    int tab[2];
    pipe(tab);
    switch (fork())
        {
        case -1:
            perror("fork");
            exit(errno);
        case 0:
            // Code fils
            fils(tab);
        default:
            // code parent
            pere(tab);
        }
    // wait(stat);
    close(tab[0]);
    close(tab[1]);
    return 0;
}

