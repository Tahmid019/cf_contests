#include<stdio.h>


int main(){

    long long a = 5;
    long long* p = &a;
    long long** q = &p;
    long long*** r = &q;
    
    scanf("%d",**r);
    printf("a = %lld", ***r);
    
    /*
    
    %d - double
    %c - character
    %s - character array
    %ld - long double
    %l - long long
    %f - float
    %lf - long float
    
    %p - pointer - address
    %x - dec - 10
    %o - octacode - 8
    %h - hex - 16

    
    */


    return 0;
}