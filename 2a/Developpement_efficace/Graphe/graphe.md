# Graphe (inventé durant la 2e World WAR)
```c
typedef struct maillong{
    struct maillong * suiv;
    int s;
    List succ;
}Maillong * Graphe;

typedef struct maillonl{
    int v;
    struct maillonl* suiv;
}Maillongl* list;


Graphe grapheNouv(){
    return null;
}


Graphe adjt(Graphe g,int x)
{
    Maillong* m;
    m=(Maillong*)malloc(sizeof(Maillong));
    if(m==NULL)
    {
        printf("Pb malloc");
        exit(1);
    }
    m->s = x;
    m->suiv=g;
    m->succ=listNouv();
    return m;
}


Graphe adjs(Graphe g,int s)
{
    if(vide(g))return adjt(g,s);
    if(s<g->s)
    {
        return adjt(g,s);
    }
    if(s==g->s)return g;
    g->suiv = adjs(g->suiv,s);
    return g;
}

Bool vide(Graphe g)
{
    return g==NULL;
}

Bool exist(Graphe g,int x)
{
    if(vide(g))return False;
    if(x<g->v)return False;
    if(x==g->v)return True;
    return exist(g->suiv,x);
}

Graphe adja(Graphe g,int x,int y)
{
    Maillong* aux=g;
    if(vide(g))return g;
    if(!exist(x) || !exist(y))return g;
    while(g->v!=x)
    {
        g=g->suiv;
    }
    g->succ=inserer(g->succ,y);
    return aux;
}

Graphe supra(Graphe g, int x,int y)
{
    Maillong* aux=g;   
    if(!exist(x,y))return g;
    while(g->v!=x)
    {
        g=g->succ;
    }
    g->succ=supra(g->succ,y);
    return aux;
}

int di(Graphe g,x)
{
    int cpt = 0;
    while(!vide(g))
    {
        if(appartient(g->succ,x))cpt++;
        g=g->suiv;
    }
    return cpt;
}


int de(Graphe g,x)
{
    if(vide(g))return g;
    if(!exist(g,x))
    {
        return 0;
    }
    while(g->v!=x)
    {
        g=g->suiv;
    }
    return longueur(g->succ);
}

Graphe suprs(Graphe g,int x)
{
    Maillong* aux=g
    if(vide(g))return g;
    if(di(g,x)!=0 || de(g,x)!=0)return g;
    return supr1(g->suiv,x)
}

Graphe suprs1(Graphe g,int x)
{
    if(vide(g))return g;
    if((x<g->s))return g;
    if(x==g->s)return suprst(g);
    g->suiv=supr1(g->suiv,x);
    return g;
}
Graphe suprst(Grapge g)
{
    Maillong* m;
    m=g;
    g=g->suiv;
    free(m);
    return g;
}

digraph family
{
    1[label="summet1"]
    2[label="summet2"]
    3[label="summet3"]
    4[label="summet4"]
    1->2
    2->3
    1->3
    2->4
    3->4
}


void afficher(Graphe g)
{
    FILE *f;
    Graphe aux =g;
    List l;
    f=fopen("graphe.txt","w");
    if(f==NULL)
    {
        printf("pb ouverture de fichier");
        exit(1);
    }
    fprintf(f,"diagraph family\n{\n");
    while(!vide(g))
    {
        fprintf("   %d[label=\"%d\"]",g->s,g->s);
        g=g->suiv;
    }
    while(!vide(aux))
    {
        l1=aux->suiv;
        while(l1!=NULL)
        {
            fprintf("%d->%d",aux->v,l1->v);
            l1=l1->suiv;
        }
        aux=aux->suiv;
    }
    fprintf("}\n");
    fclose(f);
    system("dotly Graphe.txt");
}

List fct(Graphe g,List e, List l)
{
    int z;
    List l1;
    if(vide(e))return l;
    z=tete(e);
    if(appartient(l,z))return l;
    else l1=fct(g,essuc(g,z),inserer(l,z)); //ESSUC: ensemble des successeurs d'un sommets
    return fct(g,sup(e,3),l1);
}
```
