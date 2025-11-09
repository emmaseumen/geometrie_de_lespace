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