#include "geometry/point.h"
#include "geometry/vector.h"
#include "geometry/utils.h"

int main() {
    Point2f p1 = MakeP2f(2.0f, 3.0f);//permet la creation des points grace a la fonction Makep2f
    point2f p2 = MakeP2f(4.0f,6.0f);

    Print("Point 1:", ToString(p1));//affiche un point grace a tostring et print

    Vector2f v1 = MakeV2f(1.0f, -1.0f);//permet la creation de vecteurs grace a la fonction makev2f
    Vector2f v2 = MakeV2f(1.4f, 2.3f);

    Print("vecteur 1:", ToString(v1));//affichage d un vecteur grace a la fonction print et tostring
    
    //pour le produit d un vecteur par un scalaire grace a scale
    v2 = scale(v1, 0.5f);
    Print("le vecteur initiale v1:",ToString(v1));
    Print("le vecteur consequent est:",ToString(V2));
    
    //pour la translation d un point par des deltats dx et dy
    point2f p5 = scale(p1, 2.0, 3.0f);
    Print(("point P1 scale par sx=2.0 ET sy=3.0:"),ToString(p5));

    Point2f p3 = Translate(p1, v_scale);//pour la translation d un point par un vecteur 
    Print("point p1 translate par le vecteur v1:", ToString(p3));
    
    point2f p4 = rotation(p1, 90.0f);//pour la rotation d un point
    Print("point consequent apres une rotation de 90 degre:",ToString(P4));
    
    //pour le produit scalaire d un point par un vecteur 
    point2f p7 = scale(p1, v1);
    Print("point p1 scale par le vecteur v1:",ToString(p7));
    
    //pour le produit scalaire d un point par deux reels
    point2f p6 = scale(p1, 2.0f, 3.0f);
    Print("point p1 scale par sx=2.0 et sy=3.0:",ToString(p6));
    
    //pour le scalaire de deux vecteurs par la fonction dot
    float dot = Dot(v1, v2);
    Print("le vecteur v1:",ToString(v1));
    Print("le vecteur v2:",ToString(v2));

    //pour la longueur d un vecteur grace a lenght
    float len = lenght(v1);
    Print("le vecteur v1:",ToString(v1));
    Print("sa longueur est de:",len);

    //pour normaliser un vecteur
    Vector2f norm = Normalize(v1);
    Print("le vecteur v1:",ToString(v1));
    Print("le vecteur normalise de v1 est:",ToString(norm));

    //pour le determinant de deux vecteurs 
    float det = Determinant(v1, v2);
    Print("le vecteur v1:",ToString(v1));
    Print("le vecteur v2:",ToString(v2));
    Print("le determinant de v1 et v2 est:",ToString(det));

    //pour la creation d un vecteur a partir de deux point 
    Vector2f v4 = Makev2f(p1, p2);
    print("le point p1:",ToString(p1));
    Print("le point p2:",ToString(p2));
    Print("le vecteur consequent de p1 et p2 est:",ToString(v4));

    //pour l interpolation lineaire entre deux vecteurs
    Vector2f v3 = Lerp(v1, v2, 0.5f);
    Print("le vecteur v1:",ToString(v1));
    Print("le vecteur v2:",ToString(v2));
    Print("le vecteur resultant de l interpolation lineaire entre v1 et v2 est:",ToString(v3));

    //pour la soustraction de deux vecteurs 
    Vector2f v5 = Sub(v1,v2);
    Print("le vecteur v1:",ToString(v1));
    Print("le vecteur v2:",ToString(v2));
    Print("la difference de v1 et v2 est:",ToString(v5));

    //pour l addition de deux vecteurs
    Vector2f v6 = add(v1, v2);
    Print("le vecteur v1:",ToString(v1));
    print("le vecteur v2:",ToString(v2));
    Print("la somme de v1 et v2 est:",ToString(v6));

    
    return 0;
}
