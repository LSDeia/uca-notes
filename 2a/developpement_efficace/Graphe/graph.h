#include <stdbool.h>

typedef struct maillong{
     struct maillong *suiv;
     int s;
     struct maillonl *succ;
}Maillong, *Graph;

typedef struct maillonl{
    int v;
    struct maillonl *suiv;
}Maillonl, *List;

bool appart(List l, int x);
int longueur(List l);
Graph suprs(Graph g, int x);
Graph suprs1(Graph g, int x);
Graph suprst(Graph g);
int main(void);
List isertL(List l, int x);
List iserL(List l, int x);
Graph graphNouv();
Graph adjt(Graph g,int x); // Ajout en tête des graphes
Graph adjs(Graph g,int s); // Ajout un sommet (sert a quoi que ça retourne le graphe ?)
bool videG(Graph g);
bool videL(List l);
Graph adja(Graph g,int x,int y); // utilise inserer + Ajoute le chemin x->y
bool exs(Graph g,int x);
bool exsL(List l, int x);
Graph supra(Graph g, int x,int y); // suprime la relation x->y
int di(Graph g,int x); // utilise la fonctione appartient() + retourne nbr de relation ->x
int de(Graph g,int x); // utilise fonction longueur() + retourne nbr de relation x->
Graph suprs(Graph g,int x); // utilise spr1(),di() et de() + férif si c'est possible de spr
Graph suprs1(Graph g,int x); // utilise suprt() saute le mailllon ou il y a x
Graph suprst(Graph g); // free ! + retourne g->suiv
void afficher(Graph g); // 2 while
List suprL(List l, int x);
/* Layout imprim fichier
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
*/

List fct(Graph g,List e, List l); // parcour en profondeur
