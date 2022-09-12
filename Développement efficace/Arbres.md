# Arbres

Un arbre est un graphe connexe, sans boucle et avec un racine.
Il est très utile pour trouver un éléments facilement (recherche dichotomique).

## Parties

- Opérations de base
- Opérations sélécteur (donne l'état de l'arbre)
- Tri (insert, suppr, check)
- Equilibre

## Fonctions
### Sommaire
[arbnouv](#arbnouv) : -> arbre
[e](#e) : arbre, int, arbre -> arbre
ag - d  : arbre -> arbre
r : arbre -> int
vide : arbre -> bool

## Code
#### arbnouv 
Créer un arbre vide.
```c
Arbre arbnouv(void){
	return NULL;
}
```

#### e
Enracine deux arbres ensemble.
```c
Arbre e (Arbre a, int x, Arbre b){
	Maillon* m;
	m = (Maillon*) malloc (sizeof(Maillon));
	if(m==null){
		printf("Pb malloc");
		exit(1);
	}
	m -> v = m;
	m -> g = a;
	m -> d = b;
	return m;
}
```

#### ag (ad) 
Récupère l'arbre gauche ou droit.
```c
Arbre ag (Arbre a){
	if(vide(a)){
		printf("Arbre vide");
		exit(1);
	}
	return a -> g;
}
```

```c

```

## Structure
```c
typedef struct maillon{
	struct maillon *g;
	int v;
	struct maillon *d;
} maillon, *Arbre
```

