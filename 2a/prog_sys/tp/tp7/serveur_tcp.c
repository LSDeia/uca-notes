/* 
 * Construire l'adresse d'attachement
 * Créer le socket d'écoute
 * Attacher la socket d'écoute
 * Définir la taille de la file des connexions
 * Répéter à l'infini
 * 	Socket_service=accepter une connexion
 * 	Tant que(message=lecture sur socket de service) est vrai faire
 * 		Passage en majuscules
 * 		Émission sur socket de service
 *	Fin tant que
 *	Fermer la socket de service
 * Fin répéter
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>     /* Pour read(2)/write(2) */
#include <netdb.h>      
#include <string.h>     /* Pour memset */
#include <ctype.h>      /* Pour toupper */
#include <arpa/inet.h>  /* Pour inet_ntop */

#define REQUEST_MAX 1024  /* Taille MAX en réception */
 
void usage() {
	fprintf(stderr,"Usage : serveur port\n"); 
	exit(1);
}

int main(int argc, char **argv) {
	int s, sock, ret;
 
	struct addrinfo hints, *result;
 
	struct sockaddr_storage src_addr;
	socklen_t len_src_addr;
 
	char request[REQUEST_MAX];
 
	/* Vérification des arguments */
	if(argc!=2) {
		fprintf(stderr,"Erreur : Nb args !\n");
		usage();
	}

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_flags = AI_PASSIVE; /* Equiv INADDR_ANY */
	hints.ai_family = AF_INET6; /* Allow IPv4 or IPv6 */
	hints.ai_socktype = SOCK_STREAM; /* Flux => TCP */
	hints.ai_protocol = 0;          /* Any protocol */
	hints.ai_canonname = NULL;
	hints.ai_addr = NULL;
	hints.ai_next = NULL;
 
	ret = getaddrinfo(NULL, argv[1], &hints, &result);
	if (ret != 0) {
    		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
		 exit(EXIT_FAILURE);
	}

	/* Création de la socket IPv4/IPv6 */
	if((s=socket(result->ai_family, result->ai_socktype,
        	result->ai_protocol))==-1) {
		perror("socket"); exit(1);
	}
 
	/* Attachement de la socket */
	if (bind(s, result->ai_addr, result->ai_addrlen) == -1) {
		perror("bind"); exit(1);
	}
 
	freeaddrinfo(result);
 
	/* Définition de la taille de la file d'attente */
 
	if(listen(s, 5)) {
		perror("listen"); exit(1);
	}

	while(1) { /* Boucle du serveur */
     		/* Attente d'une connexion */
		puts("En attente de connexion...");
 
		len_src_addr=sizeof src_addr;
		if((sock=accept(s, (struct sockaddr *)&src_addr, &len_src_addr))==-1) {
			perror("accept"); exit(1);
		}
 
		puts("Connexion acceptée !");

		/* prepare the file to send */
		FILE * file_to_send;
		struct stat file_info;
		char filename[] = "Makefile";
		file_to_send = fopen(filename,"r");

		if(stat(filename, &file_info) == -1){
    	perror("stat");
    	return;
  	}

		int file_size = file_info.st_size;
		
		/* Boucle de traitement du client */
 
			/* traitement de la requête(passage en majuscule) */
		fseek(file_to_send, 0, SEEK_SET);
		fread(request, file_size +1, 1, file_to_send);

		/* Émission de la réponse */
		if(send(sock, request, strlen(request)+1,0) != strlen(request)+1){
			perror("send"); exit(1);
		}	
		/* Fin de la boucle de traitement du client */
 
		if(close(sock)==-1) {
			perror("close"); exit(1);
		}
 
		fprintf(stderr, "Fin de connexion !\n");
		if(ret==-1) {
			perror("recv");
		}
 
	}
	/* Fin boucle principale du serveur */
 
	return 0;
}
