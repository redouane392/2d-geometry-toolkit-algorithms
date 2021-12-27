#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#include <stdbool.h>

typedef struct{
    float x0;
    float y0;

} Vecteur;



void saisir_point(Vecteur *AB , Vecteur *CD){
    printf("on va entrer maintenant les coordonnée de AB :\n");
    printf("Entrer l'ordonnée x  du vecteur AB : \n");
    scanf("%f", &AB->x0);
    printf("Entrer l'abscisse y  du vecteur AB : \n");
    scanf("%f", &AB->y0);
   
    printf("on va entrer maintenant les coordonnée de CD :\n");
    printf("Entrer l'ordonnée x  du vecteur CD : \n");
    scanf("%f", &CD->x0);
    printf("Entrer l'abscisse y  du vecteur CD : \n");
    scanf("%f", &CD->y0);
   
}


void somme(Vecteur AB , Vecteur CD){
    printf("La somme des deux vecteur est le vecteur de coordonnées (%f,%f)  " , 
    AB.x0 + CD.x0 , AB.y0 + CD.y0  );
}

void produitsca( Vecteur AB , Vecteur CD){

    printf("le produit scalaire des deux vecteur est %f ", AB.x0 * CD.x0 + AB.y0 * CD.y0 );

}

void produitvecsca(Vecteur AB){
    float K;
    printf("donner le scalaire K :");
    scanf ("%f", &K);
    
    printf("le produit de vecteur AB par le scalaire K est %f ", AB.x0 * K , AB.y0 * K);
}

void norme (Vecteur AB ){
    printf("L anorme du vecteur AB est %f", sqrt(pow( AB.x0 , 2 ) + pow( AB.y0 , 2)));
}


bool parrallele(Vecteur AB , Vecteur CD){
return AB.x0 * CD.y0 - CD.x0 * AB.y0 == 0 ; 
}

void orthogonaux(Vecteur AB , Vecteur CD){
    if(AB.x0 * CD.x0 + AB.y0 * CD.y0 == 0 ){
        printf("les deux vecteurs AB et CD sont orthogonaux");
    }else printf("les deux vecteurs AB et CD ne sont pas orthogonaux");
}
 


void main(){
    Vecteur *CD;
    CD=malloc(sizeof(Vecteur));
    Vecteur *AB;
    AB=malloc(sizeof(Vecteur));
    saisir_point(AB , CD);
    somme(*AB ,*CD);
    produitsca( *AB ,*CD);
    produitvecsca(*AB);
    norme (*AB );
    parrallele(*AB , *CD);
    orthogonaux(*AB , *CD);


}