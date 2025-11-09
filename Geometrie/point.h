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
