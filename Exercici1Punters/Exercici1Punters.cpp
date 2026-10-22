#include <iostream>
using namespace std;

void mostrar(int* p, int n) {
    for (int i = 0; i < n; i++) {        
        cout << *(p + i) << " ";          
    }                                     
    cout << endl;
}

void multiplicaX(int* p, int n, int x) {
    for (int i = 0; i < n; i++) {
        *(p + i) *= x;                 
    }                                   
}

void divideX(int* p, int n, int x) {
    for (int i = 0; i < n; i++) {
        *(p + i) /= x;                  
    }
}

void maximX(int* p, int n) {
    int maxim = *(p + 0);            
   
    for (int i = 1; i < n; i++) {         
        if (*(p + i) > maxim) {          
            maxim = *(p + i);              
        }
    }
    cout << "Maxim: " << maxim << endl;
}

//=================================

int main() {
    int n;                             
    cout << "Mida de l'array: ";
    cin >> n;                            

    if (n <= 0) {                         
        cout << "Mida no valida" << endl; 
        return 1;
    }

    int* v = new int[n];                
   
   

    cout << "Introdueix " << n << " valors:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> *(v + i);                 
    }                                 

    cout << "Abans:          "; mostrar(v, n);
    multiplicaX(v, n, 3);                
    cout << "Despres de *3:  "; mostrar(v, n);
    divideX(v, n, 3);
    cout << "Despres de /3:  "; mostrar(v, n);
    maximX(v, n);

    delete[] v;                        

    v = nullptr;                         
    return 0;
}