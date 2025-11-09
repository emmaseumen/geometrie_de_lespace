# geometrie_de_lespace
## description du projet✨📰
Les mathematiques, la logique spaciale nous pemet de comprendre les concepte de la geometrie 2D a travers les structures comme points et vecteurs. Mon projet nous montre comment modeliser des concepte mathematique.
## presentation du fichier et leurs localisations📰
 mon programme utilise des fonctions tel que point et vector pour cela nous avons cree des fichiers tel que:
## localisation de point.h
SRC/geometrie/point.h
 
 #ifndef POINT_H
#define POINT_H

#include <string>
#include "vector.h"

struct Point2f {
    float x;
    float y;
};

Point2f MakeP2f(float x, float y);
Point2f Translate(const Point2f& p, float dx, float dy);//fonction qui permet de calculer les coordonnees d un point
Point2f Translate(const Point2f& p, const Vector2f& v);//fonction qui permet de calculer la translation d un point par un vecteur
Point2f Scale(const Point2f& p, float sx, float sy);//fonction qui permet de calculer l homothetie d un point
Point2f Scale(const Point2f& p, const Vector2f& s);//fonction qui permet de calculer l homothetie d un point par un vecteur
Point2f Rotate(const Point2f& p, float angleDegree);//fonction pour calculer la rotation d un point

std::string ToString(const Point2f& p);//permet d afficher le resultat d un point

#endif
## qui a ete implemente dans point.cpp
## localisation de point.cpp
SRC/geometrie/point.cpp

#ifndef POINT_H
#define POINT_H

Point2f MakeP2f(float x, float y){
    return x,y;//retourne les coordonnees x et y d un point
}
Point2f Translate(const Point2f& p, float dx, float dy){
    return Point2f(p.x + dx, p.y + dy);// permet de retournerles coordonnees d un point de type point2f
}
Point2f Translate(const Point2f& p, const Vector2f& v){
    return point2f(p.x + v.x, p.y + v.y);//permet de retourner les coordonnees du vecteur
}
Point2f Scale(const Point2f& p, float sx, float sy){
    return Point2f(p.x * sx, p.y * sy);//permet de multiplier les coordonnees du point par un facteur d echelle
}
Point2f Scale(const Point2f& p, const Vector2f& s){
    return point2f(p.x * s.x, p.y * sy);// permet de multiplier les coordonnees d un vecteur par un facteur d echelle
}
Point2f Rotate(const Point2f& p, float angleDegree){
    float rad = angleDegree * M_pi/180.0;//permet de convertir l angle de rotation en radian
    return point2f(p.x * cos(rad)-p.y * sin(rad), p.x * sin(rad)-p.y * cos(rad));//permet de calculer les coordonnees de la rotation connaissant son origine
}
std::string ToString(const Point2f& p){//permet d afficher le resultat
    return(tostring(p.x) + tostring(p.y));//permet de les afficher sous forme de textes comme (x,y)
}    
## localisation de vector.h
SRC/geometrie/vector.h

#ifndef VECTOR_H
#define VECTOR_H

#include <string>
#include <cmath>

struct Vector2f {
    float x;
    float y;
};

Vector2f MakeV2f(float x, float y);
Vector2f MakeV2f(const Point2f& a, const Point2f& b);
//fonction qui permet de faire des operations sur les vecteurs
Vector2f Add(const Vector2f& a, const Vector2f& b);
Vector2f Sub(const Vector2f& a, const Vector2f& b);
Vector2f Scale(const Vector2f& v, float scalar);
float Dot(const Vector2f& a, const Vector2f& b);
float Length(const Vector2f& v);
Vector2f Normalize(const Vector2f& v);
Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t);
float Determinant(const Vector2f& a, const Vector2f& b);

std::string ToString(const Vector2f& v);//permet d afficher le resultat sur les vecteurs
#endif
## qui a ete implemente dans vector.cpp
## localisation de vector.cpp

#ifndef VECTOR_H
#define VECTOR_H

Vector2f MakeV2f(float x, float y){
    return x,y;
}
Vector2f MakeV2f(const Point2f& a, const Point2f& b){
    return vec2f(b.x-a.x, b.y-a.y);//permet de donner les composantes du vecteur
}
Vector2f Add(const Vector2f& a, const Vector2f& b){
    return (a.x + b.x, a.y + b.y);//permet d additionner les cordonnees de deux vecteurs
}
Vector2f Sub(const Vector2f& a, const Vector2f& b){
    return (a.x - b.x, a.y - b.y);//permet de soustraire les coordonnees de deux vecteurs
}
Vector2f Scale(const Vector2f& v, float scalar){
    return (v.x * scalar, v.y * scalar);//permet de multiplier un vecteur par un scalaire en changeant ca longueur
}
float Dot(const Vector2f& a, const Vector2f& b){
    return (a.x * b.x + a.y * b.y);//permet de calculer le produit scalaire
}
float Length(const Vector2f& v){
    return sqrt(v.x * v.y + v.x * v.y);//permet de calculer la norme d un vecteur
}
Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t){
    return vec2f(a.x + t * (b.x - a.x), a.y + t * (b.y - a.y));//permet de faire l interpolation lineaire entre deux vecteurs a et b
}
float Determinant(const Vector2f& a, const Vector2f& b){
    return (a.x * b.x - a.y * b.y);//permet de calculer le determinant de deux vecteurs 
}
std::string ToString(const Vector2f& v){
    return(+ tostring (v.x) + ","+ tostring(v.y));//permet d afficher le resultats en texte comme (x,y)
}
## localisation de utils.h
SRC/geometrie/utils.h

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

// Templates ToString et Print
template<typename T>
std::string ToString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

template<typename T>
std::string ToString(const std::vector<T>& v) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        oss << ToString(v[i]);
        if (i + 1 < v.size()) oss << ", ";
    }
    oss << "]";
    return oss.str();
}

template<typename K, typename V>
std::string ToString(const std::map<K, V>& m) {
    std::ostringstream oss;
    oss << "{";
    for (auto it = m.begin(); it != m.end(); ++it) {
        oss << ToString(it->first) << ": " << ToString(it->second);
        if (std::next(it) != m.end()) oss << ", ";
    }
    oss << "}";
    return oss.str();
}

template<typename T, typename... Args>
void Print(const T& first, const Args&... args) {
    std::cout << ToString(first);
    ((std::cout << ", " << ToString(args)), ...);
    std::cout << std::endl;
}

Et apres cela nous avon creer notre main.cpp ou l on va implemente tout notre programme

## fichier principale📰
## localisation de main.cpp
SRC/main.cpp

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
## compilation et execution🎰
g++ src/main.cpp src/geometry/*.cpp -I src/geometry -o geometry
## prerequis acquis😎👾
parmis les conceptes mathematiques nous avons:
~ les transformations vectoriels(translation,la rotation,l homothetie)
~ les calculs vectoriels
~ le lerp ou interpolation lineaire
## devoppement personnel👌🎗️
En realisant ce projet l etudiant obtient des competences tel que:
~ la programmation modulaire
~ implemente certaine fonctions mathematique
~ structurer un programme en plusieurs parties independantes
