all : client_tcp serveur_tcp

client_tcp : client_tcp.c
	gcc -Wall -pedantic -o client_tcp client_tcp.c

serveur_tcp : serveur_tcp.c
	gcc -Wall -pedantic -o serveur_tcp serveur_tcp.c

clean :
	rm -f client_tcp serveur_tcp
