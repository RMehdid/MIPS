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