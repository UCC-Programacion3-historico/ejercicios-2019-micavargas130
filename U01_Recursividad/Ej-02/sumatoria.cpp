#include "sumatoria.h"


int sumatoria(int *arr,  int size)
{
    if (size-1==0) { return arr[0];}
    else
        return arr[size-1] + sumatoria(arr, size-1);
}