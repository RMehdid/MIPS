#include<stdio.h>
#include<math.h>
void  hanoi( int ndisque,char source,char intermediaire,char destination)
{
      if ( ndisque == 1)
         printf("Deplacer le disque de la tour ((%c)) a la tour ((%c)) \n", source, destination);
    else {
        hanoi(ndisque - 1 , source , destination , intermediaire);
        hanoi(1 , source , intermediaire , destination );
        hanoi(ndisque - 1 ,intermediaire , source , destination);
    } 
}
int main() {
      int Nombre_Disque, Deplacement;
      printf("Entrer le nombre de disque a déplacer: ");
      scanf("%d",&Nombre_Disque);
      printf("\n");
      Deplacement=pow(2,Nombre_Disque)-1;
      printf("Il faut %d deplacement pour deplacer les %d disques de la tour A vers la tour c en utilisant la tour B. \n",Deplacement,Nombre_Disque);
      hanoi(Nombre_Disque,'A','B','C');
      printf("\n");
    return 0; 
}