#include <iostream>
#include "digitos.h"

using namespace std;

unsigned int cociente(unsigned int a, unsigned int b) {
    if (a<b) { return a;}
    else {
           return 1+ cociente (a-b, b);
    }

}


unsigned int resto(unsigned int a, unsigned int b) {
    if (a<b) {return a;}
    else { return resto(a-b,b);}

}


void escribir_espaciado(unsigned int num) {

    if (num>0) {cout<<resto(num,10)<<" ";
                //num=(cociente(num,10));}
}}
