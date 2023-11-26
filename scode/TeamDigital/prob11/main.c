#include<stdio.h>
using System;
 
class GFG 
{ 
 static int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} static int solve(int []health, int n) 
{  int currentgcd = gcd(health[0], health[1]); 
 for (int i = 2; i < n; ++i) 
    { 
        currentgcd = gcd(currentgcd, health[i]); 
    } 
    return currentgcd; 
    public static void Main(String []args) 
{ 
    int []health = { 4, 6, 8, 12 }; 
    int n = health.Length; 
    Console.WriteLine(solve(health, n)); 
} 
} 