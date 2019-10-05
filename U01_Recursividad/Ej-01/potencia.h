#ifndef POTENCIA_H
#define POTENCIA_H


unsigned int potencia(unsigned int base, unsigned int exp);
{
    int result;
    if (exp==0)
    {result=1;}
    else
   {  for (int i=0;i<exp;i++)
        result=base*base
        }

    xreturn base;
}



#endif //INC_01_RECURSIVIDAD_POTENCIA_H
