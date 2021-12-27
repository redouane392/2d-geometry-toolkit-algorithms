#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
    float x0;
    float y0;
    float x1;
    float y1;

} Droite;


void cooDroite(Droite *AB , Droite *CD ){
    printf("on va entrer maintenant les coordonnée de AB :\n");
    printf("Entrer l'abscisse x du point A : \n");
    scanf("%lf", &AB->x0);
    printf("Entrer l'ordonnée y du point A : \n");
    scanf("%lf", &AB->y0);
    printf("Entrer l'abscisse x du point B : \n");
    scanf("%lf", &AB->x1);
    printf("Entrer l'ordonnée y du point B : \n");
    scanf("%lf", &AB->y1);

    printf("on va entrer maintenant les coordonnée de CD :\n");
    printf("Entrer l'abscisse x du point C : \n");
    scanf("%lf", &CD->x0);
    printf("Entrer l'ordonnée y du point C : \n");
    scanf("%lf", &CD->y0);
    printf("Entrer l'abscisse x du point D : \n");
    scanf("%lf", &CD->x1);
    printf("Entrer l'ordonnée y du point D : \n");
    scanf("%lf", &CD->y1);

}
void vecteurdir(Droite AB ){
    printf("voila les coordonnée du vecteur dircteur de la droite AB (%.2f,%.2f)", AB.x1-AB.x0, AB.y1-AB.y0);

}

void vecteurnor(Droite AB ){
    printf("voila les coordonnée du vecteur normal de la droite AB (%.2f,%.2f)",AB.y0-AB.y1 , AB.x1-AB.x0);
}

void parralleledroite(Droite AB , Droite CD){
    if(AB.x1-AB.x0 * CD.y1-CD.y0 - CD.x1-CD.x0 * AB.y1-AB.y0 ){
        printf("les deux droite AB et CD sont parrallele");
    }else printf("les deux droite AB et CD ne sont pas parrallele");
}


void orthogonauxdroite(Droite AB , Droite CD){
    if(AB.x1-AB.x0 * CD.x1-CD.x0 + AB.y0-AB.y1 * CD.y0-CD.y1 == 0 ){
        printf("les deux doite AB et CD sont orthogonaux");
    }else printf("les deux doite AB et CD ne sont pas orthogonaux");
}

void verifier_P_d_droite(Droite AB){
    char a;
    float x , y;
    printf("Si vous tapez (ok pour moi) le programme s'arrete et passe au programme suivant");
    do{scanf("/s",a);
    printf("donner votre point en forme de x y : " );
    scanf("%.2f %.f", &x , &y);
    if((AB.x1-AB.x0) * (y-AB.y0) - (x-AB.x0) * (AB.y1-AB.y0) ){
        printf("le point de coordonnée (%.2f,%.2f) appartient a la droite AB ", x,y);
    }else printf("le point de coordonnée (%.2f,%.2f) n'appartient pas a la droite AB ", x,y);


    }while(strcmp(a, "ok pour moi"));
}

void coupe_abs_ord(Droite AB){
    if(( (AB.x0 <0) ^  (AB.x1 < 0) ) || ((AB.y0 <0) ^ ( AB.y1 < 0 ) ) ){
        printf("la droite AB coupe l'axe des abscisse ou des ordonnée");

    }else printf("la droite AB ne coupe ni l'axe des abscisse ou bien l'axe des ordonnée");
}

void main(){
    Droite *AB;
    AB=malloc(sizeof(Droite));
    Droite *CD;
    CD=malloc(sizeof(Droite));
    cooDroite(AB , CD );
    vecteurdir(*AB );
    vecteurnor(*AB );
    parralleledroite(*AB ,*CD);
    orthogonauxdroite(*AB , *CD);
    verifier_P_d_droite(*AB);
    coupe_abs_ord(*AB);


}

