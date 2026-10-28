#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

// ---------------------------------------------------------------------
//  Funciones auxiliares
// ---------------------------------------------------------------------
void imprimir(const vector<int>& v) {

    for (int x : v) {
        cout << x << " ";
    } 
    cout << endl;
}

void imprimir(const vector<string>& v) {
    for (const string& x : v) {
        cout << x << " ";
    }
    cout << endl;
}

// ---------------------------------------------------------------------
//  Ejercicio 1: Declaracion e inicializacion
// ---------------------------------------------------------------------
void ejercicio1() {
    cout << "\n--- Ejercicio 1: Declaracion e inicializacion ---\n";

    vector<int> numeros2;                  // vector vacío
    for (int i = 1; i <= 10; i++) {
        numeros2.push_back(i);              // añade i al final
    }
    imprimir(numeros2);

}


// ---------------------------------------------------------------------
//  Ejercicio 2: Insercion y eliminacion
// ---------------------------------------------------------------------
void ejercicio2() {
    cout << "\n--- Ejercicio 2: Insercion y eliminacion ---\n";
    
    vector<string> ciudades;          // vacío

    ciudades.push_back("Terrassa");    // añade al final
    ciudades.push_back("Munich");    
    ciudades.push_back("Sevilla");    
    ciudades.push_back("Valencia");    
    ciudades.push_back("Vaduz");   
    

    ciudades.pop_back();              // quita la última

    imprimir(ciudades);
}


// ---------------------------------------------------------------------
//  Ejercicio 3: Recorrido y modificacion
// ---------------------------------------------------------------------
void ejercicio3() {
    cout << "\n--- Ejercicio 3: Recorrido y modificacion ---\n";

    vector<int> v = { 1, 2, 3, 4, 5 };

    for (int& x : v) {
        x *= 2;
    }

    imprimir(v);
}


// ---------------------------------------------------------------------
//  Ejercicio 4: Funciones avanzadas (sort)
// ---------------------------------------------------------------------
void ejercicio4() {
    cout << "\n--- Ejercicio 4: Uso de funciones avanzadas ---\n";

    vector<int> numeros;                     // vacío

    for (int i = 0; i < 5; i++) {
        int n;
        cout << "Numero " << i + 1 << ": ";
        cin >> n;
        numeros.push_back(n);               // lo guardas en el vector
    }
    
    imprimir(numeros);                      // antes de ordenarlos
    sort(numeros.begin(), numeros.end());
    imprimir(numeros);                      
}


// ---------------------------------------------------------------------
//  Ejercicio 5: Busqueda y contador de palabras
// ---------------------------------------------------------------------
void ejercicio5() {
    cout << "\n--- Ejercicio 5: Busqueda y contador de palabras ---\n";

    vector<string> palabras;
    string linea;

    cout << "Escribe palabras separadas por espacios: ";
    cin.ignore();                        // descarta el '\n' que dejó el menú
    getline(cin, linea);                 // lee la línea ENTERA, con espacios

    istringstream flujo(linea);          // convierte la línea en un "cin" de mentira
    string palabra;
    while (flujo >> palabra) {           // saca palabra a palabra hasta que no quedan
        palabras.push_back(palabra);
    }

    imprimir(palabras);

    string buscada;
    cout << "Que palabra quieres buscar? ";
    cin >> buscada;

    int contador = 0;
    for (const string& p : palabras) {
        if (p == buscada) {
            contador++;
        }
    }

    cout << buscada << " aparece " << contador << " veces" << endl;
}


// ---------------------------------------------------------------------
//  main
// ---------------------------------------------------------------------
int main() {
    int opcion;
    do {
        cout << "\n===== ACTIVIDAD VECTOR =====\n"
             << "1. Declaracion e inicializacion\n"
             << "2. Insercion y eliminacion\n"
             << "3. Recorrido y modificacion\n"
             << "4. Funciones avanzadas (sort)\n"
             << "5. Busqueda y contador de palabras\n"
             << "0. Salir\n"
             << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: ejercicio1(); break;
            case 2: ejercicio2(); break;
            case 3: ejercicio3(); break;
            case 4: ejercicio4(); break;
            case 5: ejercicio5(); break;
            case 0: cout << "Adeu!\n"; break;
            default: cout << "Opcion no valida\n";
        }
    } while (opcion != 0);

    return 0;
}
