# Développement Efficace 
## Arbre

### Sommaire

- struct arbre
- struct couple
- arbnouv
- e
- r
- ag
- ad
- vide
- max
- h
- nn
- f
- nf
- egarb
- eg
- ed
- inserf
- inserr
- rech
- couper
- supr
- otermax
- trie
- deseq
- rg
- rd
- rgd
- rdg
- reeq

__29 fonction en tout :)__ 

### Fonctions

Structure de l'arbre
```c
typedef struct maillon
{
    struct maillon *g;
    int v;
    struct maillon *d;
}Maillon, *Arbre;
```

Structure du couple
```c
typedef struct
{
    Arbre g;
    Arbre d;
}Couple;
```

arbnouv: nouvel arbre
```c
Arbre arbnouv()
{
    return null;
}
```
e: enracinement
```c
Arbre e(Arbre a, int x, Arbre b)
{
    Maillon *m;
    m = (Maillon*)malloc(sizeof(Maillon));
    if(m == null)
    {
        printf("pb malloc");
        exit(1);
    }

    m->g = a;
    m->v = x;
    m->d = b;
    return m;
}
```
vide: check si vide
```c
bool vide(Arbre a)
{
    return a==null;
}
```

r: valeur de la racine
```c
int r(Arbre a)
{
    if(vide(a))
    {
        printf("Arbre vide");
        exit (1);
    }

    return a->v;
}
```
ag(d): Arbre gauche(droit)
```c
Arbre ag(Arbre a)
{
    if(vide(a))
    {
        printf("Arbre vide");
        exit(1);
    }

    return a->g;
}
```
max: Check maximum
```c
int max(int a, int b)
{
    if(a>=b) return a;
    return b;
}
```

h: hauteur
```c
int h(Arbre a)
{
    if(vide(a)) return -1;
    return 1 + max(h(ag(a)), h(ad(a)));
}
```

nn: Nombre de noeuds
```c
int nn(Arbre a)
{
    if(vide(a)) return 0;
    return 1 + nn(Ag(a)) + nn(Ad(a))
}
```

f: feuille
```c
bool f(Arbre a)
{
    if(vide(A)) return false;
    return vide(Ag(a)) && vide(Ad(a));
}
```

nf: nombre de feuille
```c
int nf(Arbre a)
{
    if(vide(a)) return 0;
    if(f(a)) return 1;
    return nf(Ag(a))+nf(Ad(a));
}
```

egarb: check arbre égaux
```c
bool egarb(Arbre a, Arbre b)
{
    if(vide(a) && vide(b)) return true;
    if(vide(a) || vide(b)) return false;
    return r(a)=r(b) && egarb(ag(a),ag(b)) && egarb(ad(a),ad(b));
}
```

eg(d): Arbre tout à gauche(droite)
```c
Arbre eg(Arbre a)
{
    if(vide(a)) return a;
    if(vide(ag(a))) return e(arbnouv(),r(a),arbnouv());
    return (eg(ag(a)));
}
```

inserf: insertion feuille
```c
Arbre inserf(Arbre a, int x){
    if(vide(a)) return e(arbnouv(),x,arbnouv());
    if(x==r(a)) return a;
    if(x<r(a))
    {
        a->g = inserf(a->g,x);
        return reeq(a);
    }
    a->d=inserf(a->d,x);
    return reeq(a);
}
```

insertion racine
```c
Arbre inR(Arbre a,int x)
{
    if(vide(a)) return e(arbnouv(),x,arbnouv());
    Couple c;
    c = couper(a,x);
    return reeq(e(c.a,x,c.b));
}
```

rech: recherche
```c
Arbre rech(Arbre a,int x)
{
    if(vide(a)) return a;
    if(x==r(a)) return a;
    if(x<r(a))) return rech(ad(a),x);
    return rech(ag(a,x));
}
```

couper: coupe
```c
Couple couper(Arbre a, int x)
{
    Couple c,f;
    if(vide(a))
    {
        c.g=arbnouv();
        c.d=arbnouv();
        return c;
    }
    if(x==r(a))
    {
        c.d=ad(a);
        c.g=ag(a);
        return c;
    }
    if(x<r(a))
    {
        f=couper(ag(a),x);
        c.g=f.g;
        c.d=e(f.d,r(a),c.d);
        return c;
    }   
    f=couple(ad(a),x);
    c.d=f.d;
    c.g=e(c.g,r(a),f.g);
    return c;
}
```

supr: Supprimer
```c
Arbre supr(Arbre a,int x)
{
    if(vide(a)) return a;
    if(x==r(a))
    {
        if(vide(ag(a))) return ad(a);
        if(vide(ad(a))) return ag(a);
        return e(otermax(ag(a)),r(ed(ag(a))),ad(a));
    }
    if(x<r(a))
    {
        a->g=supr(a->g,x);
        return a;
    }
    a->d=supr(a->d,x);
    return a;
}
```

otermax: 
```c
Arbre otermax(Arbre a)
{
    if(vide(ad(a))) return ag(a);
    a->d = otermax(a->d);
    return a;
}
```

trie: chech trier  
```c
bool trie(Arbre a)
{
    Bool b1,b2,b3;
    if(vide(a)) return true;

    if(vide(ag(a))) b1=true;
    else b1=r(ed(ag(a)))<r(a);

    if(vide(ad(a))) b2=true;
    else b2=r(eg(ad(a)))<r(a);

    b3=trie(ag(a)) && trie(ad(a));
    return b1&&b2&&b3;
}
```
deseq: déséquilibre
```c
int deseq(Arbre a)
{
    if(vide(a)) return 0;
    return h(ag(a)) - h(ad(a));
}
```

rd: rotation droite
```c
Arbre rd(Arbre a)
{
    if(vide(a))return a;
    if(vide(ag(a))) exit(1);
    return e(ag(ag(a)),r(ag(a)),e(ad(ag(a)),r(a),ad(a)));
}
```

rg: rotation gauche 
```c
Arbre rg(Arbre a)
{
    if(vide(a))return a;
    if(vide(ad(a))) exit(1);
    return e(e(ag(a),r(a),ag(ad(a))),r(ad(a)),ad(ad(a)));
}
```

rgd: roation gauche droite 
_rotation gauche de l'arbre gauche et une rotation droite de tout l'arbre_
```c
Arbre rgd(Arbre a)
{
    if(vide(a)) return a;
    return rd(e(rg(ag(a)),r(a),ad(a)));
}

```

rdg: rotation droite gauche
_rotation droite de l'arbre droit et une rotation gauche de tout l'arbre_ 
```c
Arbre rdg(Arbre a)
{
    if(vide(a)) return a;
    return rg(e(ag(a),r(a),rd(ad(a))));
}
```

reeq: réequilibré l'arbre 
```c
arbre reeq(Arbre a)
{
    if(deseq(a)==2 && deseq(ag(a))>=0)return rd(a);
    if(deseq(a)==-2 && deseq(ad(a))<=0)return rg(a);
    if(deseq(a)==2 && deseq(ag(a))==-1)return rgd(a);
    if(deseq(a)==-2 && deseq(ad(a))==1)return rdg(a);
    return a;
}
```