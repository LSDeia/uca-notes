#include "arbre.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

Arbre arbnouv(void){
	return NULL;
}

Arbre e(Arbre a, int x, Arbre b){
	Maillon *m;
	m=(Maillon*)malloc(sizeof(Maillon));
	
    if (m==NULL){
        printf("erreur malloc");
    };

	m->v=x;
	m->g=a;
	m->d=b;
	return m;
}

void afficherArbre(Arbre a, int k){
	if(vide(a)) return;
	afficherArbre(ad(a),k+1);
	afficherRacine(r(a),k);
    afficherArbre(ag(a),k+1);
}

void afficherRacine(int v, int k){
	for(int i=0; i<k; i++){
		printf("---");

	}
	printf("%d\n",v);
}

Arbre ag(Arbre a){
	return a->g;
}

Arbre ad(Arbre a){
	return a->d;
}

int r(Arbre a){
	if(vide(a)) printf("erreur");
	return a->v;
}

bool vide(Arbre a){
	return a==NULL;
}

int max(int a, int b){
	if(a>=b) return a;
	return b;
}

int h(Arbre a){
	if(vide(a)) return -1;
	return 1+max(h(ag(a)),h(ad(a)));
}

int nn(Arbre a){
    if (vide(a)) return 0;
	return 1+nn(ag(a))+nn(ad(a));
}

bool f(Arbre a){
	if(vide(a)) return false;
	return vide(ag(a)) && vide(ad(a));
}

int nf(Arbre a){
	if(vide(a)) return 0;
    if (f(a)) return 1;
	return nf(ag(a))+nf(ad(a));
}

Arbre eg(Arbre a){
	if(vide(a)) return a;
	if(vide(ag(a))) return e(arbnouv(),r(a),arbnouv());
	return eg(ag(a));
}

Arbre ed(Arbre a){
	if(vide(a)) return a;
	if(vide(ad(a))) return e(arbnouv(),r(a),arbnouv());
	return ed(ad(a));
}

bool egarb(Arbre a, Arbre b){
    if(vide(a) && vide(b)) return true;
    if(vide(a) || vide(b)) return false;

    return r(a)==r(b) && egarb(ag(a),ag(b)) && egarb(ad(a),ad(b));
}

Arbre inserF(Arbre a, int x){
	if(vide(a)) return e(arbnouv(),x,arbnouv());
	if(x==r(a)) return a;
	if(x<r(a)){
		a->g=inserF(a->g,x);
		return reeq(a);
	}
	a->d=inserF(a->d,x);
	return reeq(a);
}

Arbre inserR(Arbre a, int x){
	if(vide(a)) return e(arbnouv(),x,arbnouv());
	Couple c;
	c = couper(a,x);
	return reeq(e(c.a,x,c.b));
}

Arbre otermax(Arbre a){
	if(vide(ad(a))) return ag(a);
	a->d=otermax(a->d);	
	return a;
}

Couple couper(Arbre a, int x){
	Couple c,f;
	if(vide(a)){
		c.a=arbnouv();
		c.b=arbnouv();
		return c;
	}
	if(x==r(a)){
		c.a=ag(a);
		c.b=ad(a);
		return c;
	}
	if(x<r(a)){
		f=couper(ag(a),x);
		c.a=f.a;
		c.b=e(f.b,x,c.b);
		return c;
	}
	f=couper(ad(a),x);
	c.b=f.b;
	c.a=e(f.a,x,c.a);
	return c;
}

Arbre rech(Arbre a, int x){
	if(vide(a)) return a;
	if(x==r(a)) return a;
	if(x<r(a)) return rech(ag(a),x);
	return rech(ad(a),x);
}

int deseq(Arbre a){
	if(vide(a)) return 0;
	return h(ag(a)) - h(ad(a));
}

Arbre rd(Arbre a){
	if(vide(a)) return a;
	if(vide(ag(a))){
		exit(1);
	}
	return e(ag(ag(a)),r(ag(a)),e(ad(ag(a)),r(a),ad(a)));
}

Arbre rg(Arbre a){
	if(vide(a)) return a;
	if(vide(ad(a))){
		exit(1);
	}
	return e(e(ag(ad(a)),r(a),ag(a)),r(ad(a)),ad(ad(a)));
}

Arbre rdg(Arbre a){
	if(vide(a)) return a;
	return rd(e(rg(ag(a)),r(a),ad(a)));
}

Arbre rgd(Arbre a){
	if(vide(a)) return a;
	return rg(e(ag(a),r(a),rd(ad(a))));
}

Arbre reeq(Arbre a){
	if(deseq(a)==2 && deseq(ag(a))>=0) return rd(a);
	if(deseq(a)==-2 && deseq(ad(a))<=0) return rg(a);
	if(deseq(a)==2 && deseq(ag(a))==-1) return rgd(a);
	if(deseq(a)==-2 && deseq(ad(a))==1) return rdg(a);
	return a;
}

Arbre supr(Arbre a, int x){
	if(vide(a)) return a;
	if(x==r(a)){
		if(vide(ag(a))) return ad(a);
		if(vide(ad(a))) return ag(a);
		return reeq(e(otermax(ag(a)),r(ed(ag(a))),ad(a)));
	}
	if(x<r(a)){
		a->g=supr(a->g,x);
		return reeq(a);
	}
	return reeq(a);
}

bool trie(Arbre a){
	bool b1, b2, b3;

	if(vide(a)) return true;

	if(vide(ag(a))) b1 = true;
	else b1=r(ed(ag(a)))<r(a);

	if(vide(ad(a))) b2 = true;
	else b2=r(eg(ad(a)))<r(a);

	b3=trie(ag(a))&&trie(ad(a));
	return b1&&b2&&b3;
}

int main(void){

	Arbre a;
	a = arbnouv();

	for(int i=1; i<15  ; i++){
		a=inserF(a, i);
	}
	afficherArbre(a, 0);
    return 0;
}
