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