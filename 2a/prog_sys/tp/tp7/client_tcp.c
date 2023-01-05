/* s=créer un socket TCP
 * adr=construire l'adresse du serveur
 * Se connecter au serveur
 * Tant que (ligne=lire une ligne) est vrai faire
 * 	Émettre la ligne au serveur
 * 	Attendre sa réponse
 * 	Afficher la réponse
 * 	Fin tant que
 * Fermer la connexion
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>     /* Pour read(2)/write(2) */
#include <netdb.h>      /* Pour getaddrinfo*/
#include <string.h>     /* Pour memset */
#include <arpa/inet.h>  /* Pour inet_ntop */

#define LINE_MAX 1024  /* Taille MAX en réception */
 
void usage() {
	fprintf(stderr,"usage : client hostname port\n"); 
	exit(1);
}

int main(int argc, char **argv) {
	int s, ret;

	struct addrinfo hints, *result;

	char msg[LINE_MAX];
	char response[LINE_MAX];

	/* Vérification des arguments */
	if(argc!=3) {
		fprintf(stderr,"Erreur : Nb args !\n");
		usage();
	}

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_flags = 0;
	hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
	hints.ai_socktype = SOCK_STREAM; /* Datagram socket */
	hints.ai_protocol = 0;          /* Any protocol */
	hints.ai_canonname = NULL;
	hints.ai_addr = NULL;
	hints.ai_next = NULL;

	ret = getaddrinfo(argv[1], argv[2], &hints, &result);
	if (ret != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
		exit(EXIT_FAILURE);
	}

	/* Création de la socket IPv4/IPv6 */
	if((s=socket(result->ai_family, result->ai_socktype, result->ai_protocol))==-1) {
		perror("socket"); exit(1);
	}
 
	/* Connexion au serveur */
	if(connect(s, result->ai_addr, result->ai_addrlen)) {
		perror("connect"); exit(1);
	}
 
	freeaddrinfo(result); // si result ne sert plus

		/* Attente et lecture de la réponse */
		ret=recv(s, response, LINE_MAX, 0);

		if(ret==0){
				fprintf(stderr, "Déconnexion du serveur !\n");
	    	exit(1);
	  }
		else if(ret == -1){
				perror("recv"); exit(1);
		}
			/* Traitement de la réponse */
			FILE * downloaded_file;
			downloaded_file = fopen("download.txt", "w");

			if(downloaded_file == NULL){
					/* File not created hence exit */
					printf("Unable to create file.\n");
					exit(1);
			}

			fputs(response, downloaded_file);

			fclose(downloaded_file);
			puts("File downloaded !");

			if(close(s)==-1) {
						perror("close"); exit(1);
			}

	return 0;
}
