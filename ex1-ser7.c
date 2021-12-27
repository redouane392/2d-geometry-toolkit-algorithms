#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

typedef struct{
    float x;
    float y;
    float z;
} Point;

void saisir_point(Point * M){
    printf("Entrer l'absisse du point : \n");
    scanf("%f", &M->x);
    printf("Entrer l'ordonnee du point : \n");
    scanf("%f", &M->y);
}

void afficher_point(Point M){
    printf("Point(%f,%f)\n",M.x,M.y);
}


void transpoint(Point T, Point M ){

    printf("donner les distance suivant x pour faire la translation :\n");
    scanf("%f", &T.x);
    printf("donner les distance suivant y pour faire la translation :\n");
    scanf("%f", &T.y);

    printf("Votre nouveaux point(%f,%f) avec votre translation est (%f,%f)\n", M.x , M.y , M.x + T.x ,  M.y + T.y );

}


void homothetie(Point M ){
    float k;
    printf("donner le cohéficient k de l'homothétie:\n");
    scanf("%f", &k);

    printf("Votre nouveaux point(%f,%f) avec l'homothétie est (%f,%f)\n", M.x , M.y , M.x * k ,  M.y * k  );

}


void rotation( Point M ){
    float k;
    printf("donner l'angle k de rotation:\n");
    scanf("%f", &k);
    printf("Votre nouveaux point(%f,%f) avec l'homothétie est (%f,%f)\n", M.x , M.y ,  M.x * cos(k) - M.y *  sin(k) , M.x*sin(k) + M.y*cos(k));

}

void distance(Point M2 , Point M){
    printf("donner l'abscisse x du deuxieme point  :\n");
    scanf("%f", &M2.x);
    printf("donner l'ordonnée y du deuxieme point  :\n");
    scanf("%f", &M2.y);

    printf("La distance entre les deux point (%f,%f) et (%f,%f) est %f .\n",M.x , M.y , M2.x , M2.y , sqrt( pow(( M.x - M2.x ) , 2 ) + pow(( M.y - M2.y ) , 2 )));

}

void Transformation_car_en_pol_cyl_sph(Point M){

    printf("donner la hauteur x du point  :\n");
    scanf("%f", M.z);

    float r= sqrt( pow( M.x , 2 ) + pow( M.y , 2 ) );

    printf("voila les coordonnées en système polaire (r,O) : (%f,%f) \n",r,atan(M.y/M.x) );

    printf("voila les coordonnées en système cyindriques (r,O,z) : (%f,%f,%f) \n",r,atan(M.x/M.y),M.z );

    float rr= sqrt( pow( M.x , 2 ) + pow( M.y , 2 ) + pow(M.z , 2) );

    printf("voila les coordonnées en système sphérique (r,O,f) : (%f,%f,%f)\n ",rr,atan(M.x/M.y),atan(r/M.z) );
}

void main(){
    Point* M;
    M=malloc(sizeof(Point));
    Point T;
    Point M2;
    saisir_point(M);
    afficher_point(*M);
    transpoint(T, *M );
    homothetie(*M );
    rotation( *M );
    distance(M2 , *M);
    Transformation_car_en_pol_cyl_sph(*M);
}