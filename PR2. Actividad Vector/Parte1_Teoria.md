# Explorando el uso de `#include <vector>` en C++ — Parte 1

**Alumno:** Álvaro Silva · Programació II · 2º DAM

---

## 1. ¿Qué es un vector en C++?

Un `vector` es un espacio/lista que se hace más pequeño o más grande en función de lo que necesite el programa/usuario.

En memoria: heap

---

## 2. Ventajas de `vector` frente a los arrays normales

| | Array estático `int a[10]` | Array dinámico `new int[n]` | `vector<int>` |
|---|---|---|---|
| ¿El tamaño puede cambiar en ejecución? | | | |
| ¿Quién libera la memoria? | | | |
| ¿Sabe su propio tamaño? | | | |
| ¿Se puede copiar con `=`? | | | |
| ¿Hay acceso con comprobación de límites? | | | |
| Riesgo de leak / doble `delete` | | | |

Conclusión: Un vector es mejor pues no es estático y si necesitamos más espacio el vector se puede ampliar, un array no.

---

## 3. ¿Cómo se declaran los vectores?

| Quiero… | Declaración |
|---|---|
| Un vector de enteros vacío | `vector<int> enteros` |
| Un vector de 5 enteros | `vector<int> enteros[5]` → valen 5 espacios |
| Un vector de 5 enteros, todos a 7 | `vector<int> enteros[5] = {7, 7, 7, 7, 7}` |
| Un vector con los valores 3, 1, 4 | `vector<int> enteros[3] = {3, 1, 4}` |
| Un vector de strings vacío | `vector<string> letras` |
| Una copia de otro vector `v` | `vector<string> letras[v]` |

Diferencia entre `vector<int> a(5);` y `vector<int> a{5};`:

El primero indica que es de 5 posiciones y el segundo completa la primera posición indicando que es 5

---

## 4. Funciones principales

### `push_back`
- Qué hace: Mete un elemento al final de la lista empujando para atrás los del principio
- Ejemplo: `lista.push_back(10);`
- Cuándo lo usaría: para una lista de la compra

### `pop_back`
- Qué hace: Borra el ultimo elemento de la lista en
- Ejemplo: `vector<int> lista = {10, 20, 30};`
           `lista.pop_back();`
- Cuándo lo usaría: cuanto quiero hacer más corta la lista

### `size`
- Qué hace: Nos dice cuantos elementos hay guardados en la lista en el momento en el que se ejecuta
- Ejemplo: `cout << lista.size();`
- Cuándo lo usaría: Cuando quiero saber el tamaño de la lista, normalmente se usa junto a cout

### `clear`
- Qué hace: Lo mismo que un /clear en una terminal, elimina todos los elementos de la lista de golpe.
- Ejemplo: `lista.clear();                    `
- Cuándo lo usaría: Cuando quiero vaciar una lista

### `empty`
- Qué hace: Te dice si la lista está vacía o no, devuelve true o false
- Ejemplo: `if (lista.empty()) {  cout << "La lista esta vacia" << endl; }`
- Cuándo lo usaría: Si quiero saber si la lista esta vacía o no independientemente de sus tamaño.

### `resize`
- Qué hace: Sirve para redimensionar el tamaño del vector a la fuerza haciendolo más grande o más pequeño según el numero que se le pida
- Ejemplo: `lista.resize(4);` (los nuevos huevos están vacios (0)
- Cuándo lo usaría: Si quiero reducir o aumentar drásticamente el tamaño del vector.
