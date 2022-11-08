# Méthode d'optimisation - 1

## Unicode

Flèche droite: →

## Historique

1937 → optimisation des radars britannique  
1939 -1944 →  Base de la prog linéaire  
1947 →  algo du simplex par les américains  

Acteurs:
 - Académique
 - Idustriel

## Problème

- Optimisation dans la production (min coûts, max gain)
- Ordonnancement (planifier des tâches)
- Réseaux (Transport, Elec)

## Programmation linéaire → PL

_Ce n'est que des maths_

#### Exemple

Tableau des fruits avec protéine et prix.
Il faut avoir toute les protéines/vitamines récommandé au prix minimum.

→ Résolu par l'algo du simplex, accessible partout maintenant (Excel,...)

### Comment résoudre

_Tout est lié à la géométrie_

#### Exemple

Soit x la qt mensuelle de bois (T) utilisé par une menuiserie, 1T coûte 500€.

minimiser: 500x  
tel que:
- x >= 10 c1
- 2x >= 50 c2 
- x >= 0 c3

#### Solution
---0-c3->--------10-c1->--[Espace de solution]--<-c2-25-------------- 

Probléme à 1 variable → Plan sur 1 dimension  
Problème à n variable → Plan sur n dimension  
Possibilité de ne pas avoir de solution sur n-dimension, contrainte contraire 


