#include <stdbool.h>

typedef struct maillon{
    struct maillon *g;
    int v;
    struct maillon *d;
}Maillon, *Arbre;

typedef struct{
    Arbre a;
    Arbre b;
}Couple;

void afficherRacine(int v, int k);
void afficherArbre(Arbre a, int k);
Arbre arbnouv(void);
Arbre e(Arbre a, int x, Arbre b);
Arbre ag(Arbre a);
Arbre ad(Arbre a);
int r(Arbre a);
bool vide(Arbre a);
int max(int a, int b);
int h(Arbre a);
Arbre eg(Arbre a);
Arbre ed(Arbre a);
bool egarb(Arbre a, Arbre b);
int nn(Arbre a);
bool f(Arbre a);
int nf(Arbre a);
bool trie(Arbre a);
Arbre supr(Arbre a, int x);
Arbre rdg(Arbre a);
Arbre rgd(Arbre a);
Arbre rg(Arbre a);
Arbre rd(Arbre a);
Arbre reeq(Arbre a);
int deseq(Arbre a);
Arbre rech(Arbre a, int x);
Couple couper(Arbre a, int x);
Arbre otermax(Arbre a);
Arbre inserR(Arbre a, int x);
Arbre inserF(Arbre a, int x);