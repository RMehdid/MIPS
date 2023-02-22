# Partie 1:
### a- Explication de la méthode d’utilisation des fonctions et la pile avec MIPS:
En Assembleur MIPS, il y a plusieurs instructions qui sont utilisées pour créer et utiliser des fonctions. Voici un aperçu de ces instructions :

1.  `jal` (jump and link) : cette instruction permet de sauter vers une autre adresse de mémoire, en même temps qu'elle enregistre l'adresse de retour dans le registre $ra (return address). Elle est généralement utilisée pour appeler une fonction.
    
2.  `jr` (jump register) : cette instruction permet de sauter vers l'adresse contenue dans le registre $ra. Elle est généralement utilisée pour retourner d'une fonction.
    
3.  `move` : cette instruction permet de copier la valeur d'un registre dans un autre. Elle peut être utilisée pour sauvegarder la valeur de certains registres avant d'appeler une fonction, afin de les rétablir à la fin de l'appel de fonction.
    
4.  `addi` (add immediate) : cette instruction permet d'ajouter une valeur immédiate à un registre. Elle peut être utilisée pour déplacer le pointeur de pile ($sp) avant et après l'appel de fonction, afin de réserver de la place pour les paramètres et pour les variables locales de la fonction.
    
### b - Exemple d'utilisation d'une fonction:
Voici un exemple de code Assembleur MIPS qui utilise ces instructions pour créer et utiliser une fonction nommée `fonction` :
```
fonction:
    # Sauvegarder les registres $s0 et $s1
    move $t0, $s0
    move $t1, $s1

    # Réserver de la place sur la pile pour les variables locales
    addi $sp, $sp, -4

    # Code de la fonction

    # Rétablir les registres $s0 et $s1
    move $s0, $t0
    move $s1, $t1

    # Déplacer le pointeur de pile à sa position initiale
    addi $sp, $sp, 4

    # Retourner de la fonction
    jr $ra

# Appel de la fonction
jal fonction
```

### c - Explication de la méthode d'utilisation de la pile:
La pile (stack en anglais) est une structure de données qui permet de stocker des informations de manière temporaire. Elle est souvent utilisée dans les programmes assembleur MIPS pour stocker les variables locales des fonctions et les informations de retour lors de l'appel de fonctions.

Voici comment la pile est généralement utilisée dans un programme assembleur MIPS:

1.  Le pointeur de pile ($sp) est initialisé à la fin de la mémoire allouée au programme.
    
2.  Lorsqu'une fonction est appelée, le pointeur de pile est déplacé vers le haut (en réduisant sa valeur) pour réserver de la place pour les variables locales de la fonction. Cela est généralement fait en utilisant l'instruction `addi $sp, $sp, -4` pour réserver 4 octets de mémoire (puisque chaque registre a une taille de 4 octets en MIPS).
    
3.  Les variables locales de la fonction sont stockées dans la mémoire allouée sur la pile en utilisant des instructions comme `sw` (store word) qui permet de stocker la valeur d'un registre dans la mémoire à une adresse donnée.
    
4.  Lorsque la fonction est terminée, le pointeur de pile est déplacé vers le bas (en augmentant sa valeur) pour libérer l'espace réservé pour les variables locales. Cela est généralement fait en utilisant l'instruction `addi $sp, $sp, 4` pour libérer 4 octets de mémoire.

### Méthodes d'utilisation de la pile:
Quelques exemples quand la pile est généralement utilisée dans un programme assembleur MIPS:

-   Lorsqu'une fonction est appelée, l'adresse de retour est généralement stockée sur la pile, afin de pouvoir retourner à l'instruction qui a appelé la fonction lorsque celle-ci est terminée. Cela est généralement fait en utilisant l'instruction `jal` (jump and link), qui saute vers l'adresse de la fonction et enregistre l'adresse de retour sur la pile.
    
-   Les variables locales des fonctions sont généralement stockées sur la pile, afin de ne pas utiliser de registres qui pourraient être nécessaires à d'autres instructions. Cela permet également de ne pas perturber l'état des registres lors de l'appel de fonctions.
    
-   La pile peut également être utilisée pour stocker des informations temporaires lors de l'exécution d'un programme, comme par exemple les résultats intermédiaires d'une calcul lors de l'évaluation d'une expression.
    

Il est important de noter que la pile n'est pas la seule structure de données utilisée dans les programmes assembleur MIPS. Il existe d'autres structures de données comme les tableaux et les listes chainées qui peuvent être utilisées pour stocker des données de manière plus structurée.
### d - Exemple d'utilisation de la pile:

```
fonction:
    # Réserver de la place sur la pile pour les variables locales
    addi $sp, $sp, -4

    # Stocker la valeur de $t0 dans la première variable locale
    sw $t0, 0($sp)

    # Stocker la valeur de $t1 dans la deuxième variable locale
    sw $t1, 4($sp)

    # Code de la fonction

    # Charger la valeur de la première variable locale dans $t0
    lw $t0, 0($sp)

    # Charger la valeur de la deuxième variable locale dans $t1
    lw $t1, 4($sp)

    # Déplacer le pointeur de pile à sa position initiale
    addi $sp, $sp, 4

    # Retourner de la fonction
    jr $ra

```

# Partie 2:

### a - Programme C (Bubble sort):
```
#include <stdio.h>
main(){ 

	/* Déclarations */
	int A[50];/*tableau donné */ 

	int N; /*dimension*/
	int I; /* indice élément tableau */
	int J; /* indice élément tableau */ 
	int AIDE; /* pour la permutation */ 

	/* Saisie des données */  
	printf("Dimension du tableau (max.50) : "); scanf("%d", &N );
	  
	for (J=0; J<N; J++){
	    printf("Elément %d : ", J);
	    scanf("%d", &A[J]); 
	}

	/* Affichage du tableau */
	printf("Tableau donné: \n");
	for (J=0; J<N; J++)
		printf("%d ", A[J]);
		
	printf("\n");
		
	/* Tri du tableau */ 
	for (J=1; J<N; J++)
	    for (I=0; I<N-1; I++) 
			if (A[I] > A[I+1]){
		        AIDE = A[I];
				A[I] = A[I+1];
				A[I+1] = AIDE;
	        }
	         
	/* Edition du résultat */
	printf("Tableau trié :\n");
	for (J=0; J<N; J++) 
		printf("%d ", A[J]);
	
	printf("\n");
	
	return 0; 
}
```
### Execution de programme:
```
Dimension du tableau (max.50) : 4 // longeur de tableau entrée;
Elément 0 : 1 // element 1 entré;
Elément 1 : 2 // element 2 entré;
Elément 2 : 6 // element 3 entré;
Elément 3 : 3 // element 4 entré;
Tableau donné: 
1 2 6 3 // affichage de tableau avant triage
Tableau trié :
1 2 3 6 // affichage de tableau après triage
```

### b - Etape de traduction programme C en MIPS:
1.  on Identifie les instructions C qui nécessitent une traduction en code Assembleur MIPS. Certaines instructions C peuvent être directement traduites en Assembleur MIPS, tandis que d'autres nécessiteront plusieurs instructions Assembleur MIPS pour être exécutées.
    
2.  Pour chaque instruction C à traduire, on choisit les opérandes Assembleur MIPS qui seront utilisés. Les opérandes Assembleur MIPS peuvent être des registres, des valeurs immédiates, ou des adresses de mémoire.
    
3.  Pour chaque instruction C à traduire, on détermine l'instruction Assembleur MIPS ou les instructions Assembleur MIPS qui permettront de réaliser l'opération souhaitée.
    
4.  Pour chaque instruction C à traduire, on écrit l'instruction Assembleur MIPS ou les instructions Assembleur MIPS correspondantes en suivant la syntaxe de l'Assembleur MIPS.
    
5.  On répète ces étapes jusqu'à ce que toutes les instructions C du programme aient été traduites en Assembleur MIPS.

### Traduction de programme C en MIPS:

### c - Execution sur MARS:

# Partie 3:

### a - Explication de tour de hanoi:
Le problème de tour de Hanoi consiste à déplacer un ensemble de disques de différentes tailles, empilés les uns sur les autres sur un piquet, vers un autre piquet, en suivant certaines règles. Les règles sont les suivantes:

1.  On ne peut déplacer qu'un seul disque à la fois.
2.  On ne peut déposer un disque plus grand sur un disque plus petit.

Le but est de déplacer tous les disques du piquet de départ vers le piquet de destination en suivant ces règles. Le problème de tour de Hanoi a été inventé en 1883 par le mathématicien français Édouard Lucas. Il a été nommé d'après la ville de Hanoï en Vietnam, où une légende raconte qu'il y a un temple avec trois piquets et un nombre infini de disques de tailles différentes. Selon la légende, quand tous les disques auront été déplacés d'un piquet à un autre, le monde prendra fin.

Le problème de tour de Hanoi est souvent utilisé en informatique pour illustrer les algorithmes de recherche et de résolution de problèmes. Il peut être résolu de manière récursive, c'est-à-dire en utilisant une technique qui consiste à décomposer un problème en sous-problèmes plus petits jusqu'à ce qu'ils soient suffisamment simples pour être résolus directement.

Voici comment on peut résoudre le problème de tour de Hanoi avec trois piquets et deux disques:

1.  On déplace le disque le plus petit du piquet de départ vers le piquet de travail.
2.  On déplace le disque le plus grand du piquet de départ vers le piquet de destination.
3.  Déplacez le disque le plus petit du piquet de travail vers le piquet de destination.

### Programme C (Tower of Hanoi):
```
#include<stdio.h>
#include<math.h>

void  hanoi(int ndisque, char source, char intermediaire, char  destination){
	if(ndisque  ==  1)
		printf("Deplacer le disque de la tour ((%c)) a la tour ((%c)) \n",  source,  destination);
		
	else  {
		hanoi(ndisque - 1, source destination intermediaire);
		hanoi(1, source, intermediaire, destination);
		hanoi(ndisque - 1, intermediaire source  destination);
	}
}

int  main()  {

	int  Nombre_Disque,  Deplacement;
	
	printf("Entrer le nombre de disque a déplacer: ");
	
	scanf("%d",&Nombre_Disque);
	printf("\n");
	
	Deplacement=pow(2,Nombre_Disque)-1;
	printf("Il faut %d deplacement pour deplacer les %d disques de la tour A vers la tour c en utilisant la tour B. \n", Deplacement, Nombre_Disque);
	
	hanoi(Nombre_Disque,'A','B','C');
	printf("\n");
	
	return  0;
}
```

### c - Explication de ce programme C:
Ce programme résout le problème de tour de Hanoi en utilisant la technique de la récursion. La fonction `hanoi` est une fonction récursive qui prend en argument le nombre de disques à déplacer, ainsi que les noms des trois piquets (`source`, `intermediaire` et `destination`).

La fonction vérifie d'abord si le nombre de disques à déplacer est égal à 1. Si c'est le cas, elle imprime un message indiquant que le disque doit être déplacé du piquet `source` vers le piquet `destination`. Si le nombre de disques à déplacer est supérieur à 1, la fonction appelle elle-même trois fois en utilisant des arguments différents.

La première fois, elle appelle la fonction avec le nombre de disques diminué de 1, le piquet `source` comme piquet de départ, le piquet `destination` comme piquet de travail et le piquet `intermediaire` comme piquet de destination. Cela permet de déplacer les disques les plus petits du piquet `source` vers le piquet `intermediaire`, en utilisant le piquet `destination` comme piquet de travail temporaire.

La deuxième fois, la fonction appelle elle-même avec le nombre de disques égal à 1, le piquet `source` comme piquet de départ, le piquet `intermediaire` comme piquet de travail et le piquet `destination` comme piquet de destination. Cela permet de déplacer le plus grand disque du piquet `source` vers le piquet `destination`.

La troisième fois, la fonction appelle elle-même avec le nombre de disques diminué de 1, le piquet `intermediaire` comme piquet de départ, le piquet `source` comme piquet de travail et le piquet `destination` comme piquet de destination. Cela permet de déplacer les disques du piquet `intermediaire` vers le piquet `destination`, en utilisant le piquet `source` comme piquet de travail temporaire.

La fonction `main` demande à l'utilisateur le nombre de disques à déplacer, calcule le nombre de déplacements nécessaires en utilisant la formule `pow(2, Nombre_Disque) - 1` et appelle la fonction `hanoi` avec les arguments appropriés. Ensuite, elle imprime un message indiquant le nombre de déplacements nécessaires et appelle la fonction `hanoi` pour résoudre le problème.

### e - Déroulement manuel de programme:

1.  L'utilisateur entre le nombre de disques à déplacer, qui est 3.
2.  Le programme calcule le nombre de déplacements nécessaires en utilisant la formule `pow(2, Nombre_Disque) - 1`, ce qui donne 7 déplacements.
3.  Le programme imprime un message indiquant qu'il faut 7 déplacements pour déplacer les 3 disques de la tour A vers la tour C en utilisant la tour B.
4.  La fonction `hanoi` est appelée avec les arguments suivants: `ndisque` égal à 3, `source` égal à 'A', `intermediaire` égal à 'B' et `destination` égal à 'C'.
5.  La fonction vérifie si `ndisque` est égal à 1. Comme ce n'est pas le cas, elle appelle elle-même trois fois avec des arguments différents.
6.  La première fois, elle appelle la fonction avec `ndisque` égal à 2, `source` égal à 'A', `intermediaire` égal à 'C' et `destination` égal à 'B'.
7.  La fonction vérifie à nouveau si `ndisque` est égal à 1. Comme ce n'est pas le cas, elle appelle elle-même trois fois avec des arguments différents.
8.  La première fois, elle appelle la fonction avec `ndisque` égal à 1, `source` égal à 'A', `intermediaire` égal à 'B' et `destination` égal à 'C'.
9.  La fonction vérifie à nouveau si `ndisque` est égal à 1. Comme c'est le cas, elle imprime un message indiquant que le disque doit être déplacé de la tour 'A' vers la tour 'C'.
10.  La deuxième fois, la fonction appelle elle-même avec `ndisque` égal à 1, `source` égal à 'A', `intermediaire` égal à 'B' et `destination` égal à 'C'.
11.  La fonction vérifie à nouveau si `ndisque` est égal à 1. Comme c'est le cas, elle imprime un message indiquant que le disque doit être déplacé de la tour 'A' vers la tour 'C'.
12.  La troisième fois, la fonction appelle elle-même avec `ndisque` égal à 1, `source` égal à 'B', `intermediaire` égal à 'A' et `destination` égal à 'C'.
13.  La deuxième fois, la fonction appelle elle-même avec `ndisque` égal à 2, `source` égal à 'B', `intermediaire` égal à 'A' et `destination` égal à 'C'.
14.  La fonction vérifie à nouveau si `ndisque` est égal à 1. Comme ce n'est pas le cas, elle appelle elle-même trois fois avec des arguments différents.
15.  La première fois, elle appelle la fonction avec `ndisque` égal à 1, `source` égal à 'B', `intermediaire` égal à 'C' et `destination` égal à 'A'.
16.  La fonction vérifie à nouveau si `ndisque` est égal à 1. Comme c'est le cas, elle imprime un message indiquant que le disque doit être déplacé de la tour 'B' vers la tour 'A'.
17.  La deuxième fois, la fonction appelle elle-même avec `ndisque` égal à 1, `source` égal à 'C', `intermediaire` égal à 'B' et `destination` égal à 'A'.
18.  La fonction vérifie à nouveau si `ndisque` est égal à 1. Comme c'est le cas, elle imprime un message indiquant que le disque doit être déplacé de la tour 'C' vers la tour 'A'.
19.  La troisième fois, la fonction appelle elle-même avec `ndisque` égal à 1, `source` égal à 'C', `intermediaire` égal à 'A' et `destination` égal à 'B'.
20.  La fonction vérifie à nouveau si `ndisque` est égal à 1. Comme c'est le cas, elle imprime un message indiquant que le disque doit être déplacé de la tour 'C' vers la tour 'B'.
21.  La troisième fois, la fonction appelle elle-même avec `ndisque` égal à 2, `source` égal à 'A', `intermediaire` égal à 'B' et `destination` égal à 'C'.
22.  La fonction vérifie à nouveau si `ndisque` est égal à 1. Comme ce n'est pas le cas, elle appelle elle-même trois fois avec des arguments différents.
23.  La première fois, elle appelle la fonction avec `ndisque` égal à 1, `source` égal à 'A', `intermediaire` égal à 'C' et `destination` égal à 'B'.
24.  La deuxième fois, la fonction appelle elle-même avec `ndisque` égal à 1, `source` égal à 'C', `intermediaire` égal à 'B' et `destination` égal à 'A'.
25.  La fonction vérifie à nouveau si `ndisque` est égal à 1. Comme c'est le cas, elle imprime un message indiquant que le disque doit être déplacé de la tour 'C' vers la tour 'A'.
26.  La troisième fois, la fonction appelle elle-même avec `ndisque` égal à 1, `source` égal à 'B', `intermediaire` égal à 'A' et `destination` égal à 'C'.
27.  La fonction vérifie à nouveau si `ndisque` est égal à 1. Comme c'est le cas, elle imprime un message indiquant que le disque doit être déplacé de la tour 'B' vers la tour 'C'.
28.  La fonction `hanoi` est terminée et le programme s'achève.

Au final, le programme aura imprimé un total de 7 messages indiquant les déplacements de chaque disque de la tour de départ vers la tour de destination en utilisant la tour intermédiaire.

### Execution de programme:
```
Entrer le nombre de disque a déplacer: 3

Il faut 7 deplacement pour deplacer les 3 disques de la tour A vers la tour c en utilisant la tour B. 
Deplacer le disque de la tour ((A)) a la tour ((C)) 
Deplacer le disque de la tour ((A)) a la tour ((B)) 
Deplacer le disque de la tour ((C)) a la tour ((B)) 
Deplacer le disque de la tour ((A)) a la tour ((C)) 
Deplacer le disque de la tour ((B)) a la tour ((A)) 
Deplacer le disque de la tour ((B)) a la tour ((C)) 
Deplacer le disque de la tour ((A)) a la tour ((C))
```
