bool Busqueda_Binaria(int *array,int n, int inicio, int fin) {
    

    if (inicio<fin) {

        if (array[inicio] == n) { return true; }

        else { Busqueda_Binaria(array, n, inicio + 1, fin); }
    }
    
    return false;
 
}
