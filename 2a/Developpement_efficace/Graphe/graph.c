#include <stdio.h>
#include "graph.h"
#include <stddef.h>
#include <stdlib.h>

Graph graphNouv()
{
    return NULL;
}

List listNouv()
{
    return NULL;
}

Graph adjt(Graph g, int x)
{
    Maillong *m;
    m=(Maillong*)malloc(sizeof(Maillong));
    if(m==NULL) exit(1);
    
    m->suiv=g; 
    m->s=x;
    m->succ=listNouv();
    return m;
}

Graph adjs(Graph g, int x)
{
    if(videG(g)) return adjt(g,x);
    if(x<g->s) return adjt(g,x);
    if(x==g->s) return g;
    g->suiv = adjs(g->suiv,x);
    return g;
}

bool videL(List l)
{
    return l==NULL;
}

bool videG(Graph g)
{
    return g==NULL;
}

Graph adja(Graph g, int x, int y)
{
    Maillong * aux = g;
    if(videG(g)) return g;
    if(!exs(g,x) || !exs(g,y)) return g;
    while(g->s!=x)
    {
        g=g->suiv;
    }
    g->succ = iserL(g->succ,y);
    return aux;
}

bool exs(Graph g, int x)
{
    if(videG(g)) return false;
    if(x<g->s) return false;
    if(x==g->s) return true;
    return exs(g->suiv, x);
}

bool exsL(List l, int x)
{
    if(videL(l)) return false;
    if(x<l->v) return false;
    if(x==l->v) return true;
    return exsL(l->suiv, x);
}

List isertL(List l, int x)
{
    Maillonl *m;
    m=(Maillonl*)malloc(sizeof(Maillonl));
    if(m==NULL) exit(1);
    m->v=x;
    m->suiv=l;
    return m;
}

List iserL(List l, int x)
{
    Maillonl *p = l;
    Maillonl *m;
    m = (Maillonl*)malloc(sizeof(Maillonl));
    if (m==NULL) exit(1);

    if(videL(l))
    {
        m->v=x;
        return m;
    }
    if (appart(l,x))
    {
        free(m);
        return l;
    }

    while(l->suiv != NULL)
    {
        if(l->suiv == NULL)
        {
            m->v = x;
            l->suiv = m;
            return p;
        }
        if(l->suiv != NULL && x > l->suiv->v)
        {
            l = l->suiv;
            break;
        }
    }
        m->v = x;
        m->suiv = l->suiv;
        l->suiv = m;
        return p;
}

Graph supra(Graph g, int x, int y)
{
    Maillong *aux=g;
    if(videG(g)) return g;
    if(!exs(g,x) || !exs(g,y)) exit(1);
    while(g->s!=x)
    {
        g=g->suiv;
    }
    g->succ=suprL(g->succ,y);
    return aux;
}

List suprL(List l, int x)
{
    Maillonl *aux=l;
    if(videL(l)) return l;
    if(!exsL(l,x)) return l;
    while(l->suiv->v!=x)
    {
        l=l->suiv;
    }
    l->suiv=l->suiv->suiv;
    return aux;
}

bool appart(List l, int x)
{
    if (videL(l)) return false;
    if (l->v == x) return true;
    return appart(l->suiv,x);
}

int di(Graph g, int x)
{
    int count = 0;
    if (videG(g)) return 0;
    if (appart(g->succ,x)) count++;
    return di(g->suiv, x) + count;
}

int de(Graph g, int x)
{
   if (videG(g)) return 0;
   return longueur(g->succ);
}

int longueur(List l)
{ 
    int count = 0;
    while(!videL(l))
    {
        count++;
        l = l->suiv;
    }
    return count;
}

Graph suprs(Graph g, int x)
{
    if (videG(g)) return g;
    if (di(g,x)!=0 || de(g,x)!=0) return g;
    return suprs1(g->suiv,x);
}

Graph suprs1(Graph g, int x)
{
    if (videG(g)) return g;
    if (x<g->s) return g;
    g->suiv = suprs1(g->suiv,x);
    return g;
}

Graph suprst(Graph g)
{
    Maillong* m;
    m=g;
    g=g->suiv;
    free(m);
    return g;
}

//List fct(Graph g,List e, List l)
//{
     //int z;
     //List l1;
     //if(videL(e))return l;
     //z=tete(e);
     //if(appart(l,z))return l1,l;
     //else l1=fct(g,essuc(g,z),inserer(l,z)); //ESSUC: ensemble des successeurs d'un sommets
     //return fct(g,sup(e,3),l1);
//}

int main(void)
{
    Graph g = graphNouv();
    g = adjs(g,1);
    g = adjs(g,2);
    g = adjs(g,3);
    Graph test = g;
    while(!videG(test))
    {
        printf("Sommet: %d\n",test->s);
        test = test->suiv;
    }
    g = adja(g,1,2);
    g = adja(g,2,3);
    g = adja(g,3,1);
    
    int count = 0;
    while(count<3)
    {
        if(exs(g,count)) printf("Exits %d",count);
        else printf("Not Exists %d",count);
        count++;
    }
    return 0;
}
