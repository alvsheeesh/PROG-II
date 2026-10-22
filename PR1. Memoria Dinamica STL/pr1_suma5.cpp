#include <iostream>
using namespace std;

void mostrar(int* p, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(p + i) << " ";
    }
    cout << endl;
}

void sumaX(int* p, int n, int x) {
    for (int i = 0; i < n; i++) {
        *(p + i) += x;
    }
}

void restaX(int* p, int n, int x) {
    for (int i = 0; i < n; i++) {
        *(p + i) -= x;
    }
}

void minimX(int* p, int n) {
    int minim = *(p + 0);
    for (int i = 1; i < n; i++) {
        if (*(p + i) < minim) {
            minim = *(p + i);
        }
    }
    cout << "Minim: " << minim << endl;
}

//=======================

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
    sumaX(v, n, 5);
    cout << "Despres de +5:  "; mostrar(v, n);
    restaX(v, n, 5);
    cout << "Despres de -5:  "; mostrar(v, n);
    minimX(v, n);

    delete[] v;
    v = nullptr;
    return 0;
}
