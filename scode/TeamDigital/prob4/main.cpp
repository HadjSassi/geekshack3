#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
double a,b;
float s;
Vector Add(Vector a, Vector b)
{
    return Vector(a.x + b.x, a.y + b.y/*, a.z + b.z*/);
}

Vector Mult(Vector a, float s)
{
    return Vector(a.x * s, a.y * s/*, a.z * s*/);
}

float Dot(Vector a, Vector b)
{
    return a.x * b.x + a.y * b.y /*+ a.z * b.z*/;
}

float Norm(Vector a)
{
    return sqrt(a.x * a.x + a.y * a.y /*+ a.z * a.z*/);
}

Vector Normalize(Vector a)
{
    return Mult(a, 1/Norm(a));
}

Vector Project(Vector v, Vector a)
{
    return Mult(Normalize(a), Dot(v, a)/Norm(a));
}

Vector Bounce(Vector v, Vector n)
{
    return Add(v, Mult(Project(v, n), -2));
} 
 
