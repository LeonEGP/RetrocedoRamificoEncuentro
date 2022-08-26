// ---------- DATOS DE ENTREGA ---------- //
//Programa que: Implementa la técnica de programación "backtracking" y "Branch & Found".
//Programadores: León Emiliano García Pérez [A00573074], Carla Morales López [A01639225].
//Fecha de entrega: Viernes 26 de Agosto de 2022.

//Inclusión de librerías.
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//Ajuste a estandar.
using namespace std;

//Función que imprime en consola un salto de línea, no recibe parámetros y no tiene valor de retorno.
void espacio() {
    cout << endl;
}

//Función que imprime en consola un vector, recibe como parámetro un vector de enteros y no tiene valor de retorno.
void mostrar(vector <int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
    }
    cout << endl;
}

//Función que imprime en consola un vector de vectores, recibe como parámetro un vector de vectores de enteros y no tiene valor de retorno.
void imprimir(vector <vector <int>> vec) {
    for (int i = 0; i < vec.size(); i++) {
        mostrar(vec[i]);
    }
}

//Función que imprime en consola un vector de vectores (solución via Backtracking), recibe como parámetro un vector de vectores de enteros y no tiene valor de retorno.
void imprimirSolucion(vector <vector <int>> solucion) {
    for (int i = 0; i < solucion.size(); i++) {
        mostrar(solucion[i]);
    }
}

//Función que verifica si un movimiento es válido (solución via Backtracking), recibe como parámetro dos enteros (movimiento en X y movimiento en Y), vector de vectores de enteros (solución) y vector de vectores de enteros (laberinto), retorna un valor booleano.
bool movimientoValido(int movimientoX, int movimientoY, vector< vector<int> >& solucion, vector< vector<int> >& laberinto) {
    return (movimientoX >= 0 && movimientoX < solucion.size() && movimientoY >= 0 && movimientoY < solucion.size() && solucion[movimientoX][movimientoY] == 0 && laberinto[movimientoX][movimientoY] == 1);
}

//Función que permite encontrar camino (solución via Backtracking), recibe como parámetro dos enteros (actual X y actual Y), vector de vectores de enteros (solución), dos vectores de enteros (coordena X y coordenada Y), entero n y vector de vectores de enteros (laberinto), retorna un valor booleano.
bool encontrarCamino(int actualX, int actualY, vector< vector<int> >& solucion, vector<int> coordenadaX, vector<int> coordenadaY, int n, vector< vector<int> >& laberinto) {
    
    //Declaración/Inicialización de variables.
    int movimientoX;
    int movimientoY;

    //Verficiación de alcanzabilidad del destino.
    if (actualX == n - 1 && actualY == n - 1) {
        solucion[n - 1][n - 1] = 1;
        return true;
    }

    //Los dos posibles movimientos.
    for (int i = 0; i < 2; ++i) {
        movimientoX = actualX + coordenadaX[i];
        movimientoY = actualY + coordenadaY[i];

        if (movimientoValido(movimientoX, movimientoY, solucion, laberinto)) {
            solucion[actualX][actualY] = 1;
            if (encontrarCamino(movimientoX, movimientoY, solucion, coordenadaX, coordenadaY, n, laberinto)) {
                return true;
            }
            else {
                solucion[actualX][actualY] = 0;
            }
        }
    }
    return false;
}

//Función que da solución mostrando el camino de solución a un laberinto dado (solución via Backtracking), recibe como parámetro un vector de vectores de entero (laberinto), no tiene valor de retorno. 
void backtracking(vector <vector <int>> laberinto) { //Complejidad Computacional O(2^(N*M)), siendo M y N las dimensiones del laberinto a resolver.

    //Declaración/Inicialización de variables.
    vector < vector<int> > solucion(laberinto[0].size(), vector<int>(laberinto[0].size(), 0));
    vector<int> coordenadaX = { 0,1 };
    vector<int> coordenadaY = { 1,0 };
    int actualX;
    int actualY;
    int n;

    solucion[0][0] = 1;
    actualX = 0;
    actualY= 0;
    n = laberinto[0].size();

    //Encontrar el siguiente destino.
    if (encontrarCamino(actualX, actualY, solucion, coordenadaX, coordenadaY, n, laberinto)) {
        imprimirSolucion(solucion);
    }
    else {
        cout << "SIN SALIDA!" << endl;
    }
}

//PENDIENTE DE DESCRIPCIÓN !!!!!!!!!!!!!! - PENDIENTE DE NUEVA FIRMA!!!!!!!!
void branchandfoud() { //PENDIENTE DE COMPLEJIDAD !!!!!!!!!!
    cout << "en desarrollo ..." << endl;
}

//Función main que ejecuta el programa, no recibe parámetros, retorna un entero [return 0].
int main()
{
    // ---------- DECLARACIÓN DE VARIABLES ---------- //
    int m; //Cantidad de lineas
    int n; //Cantidad de valores por linea
    int num; //Variable de apoyo de llenado de vector temporal.
    string linea; //Linea que se ingresa desde consola. 
    string temp; //String de apoyo que toma en cuenta un elemento de la linea
    vector <vector <int>> laberinto; //Laberinto formado.
    vector <int> temporal; //Vector de apoyo para formación de laberinto.

    // ---------- INICIA PROGRAMA ---------- //
    espacio();
    cout << "------ INICIANDO PROGRAMA -----" << endl;
    espacio();

    // ---------- DETECCIÓN DE ERRORES DE INPUT ---------- //

    cout << "INGRESA LA CANTIDAD DE LINEAS:" << endl;
    cin >> m;

    if (m < 0) {
        cout << "DETECCION DE ERROR DE INPUT, TOMANDO VALOR ABSOLUTO" << endl;
        m = abs(m);
    }
    else if (m == 0) {
        cout << "DETECCION DE ERROR DE INPUT, TOMANDO COMO VALOR 4" << endl;
        m = 4;
    }

    espacio();
    cout << "INGRESA LA CANTIDAD DE VALORES POR LINEA:" << endl;
    cin >> n;

    if (n < 0) {
        cout << "DETECCION DE ERROR DE INPUT, TOMANDO VALOR ABSOLUTO" << endl;
        n = abs(n);
    }
    else if (n == 0) {
        cout << "DETECCION DE ERROR DE INPUT, TOMANDO COMO VALOR 4" << endl;
        n = 4;
    }

    espacio();
    cout << "INGRESE LOS VALORES DE CADA LINEA:" << endl;
    espacio();

    // ---------- LLENADO DEL LABERINTO ---------- //

    for (int i = 0; i < m; i++) {

        linea = "";
        temporal.clear();
        cin >> linea;

        // ---------- DETECCIÓN DE ERRORES DE INPUT ---------- //

        if (linea.size() < n) {
            cout << "ERROR DE FORMACIÓN DE LINEA, INGRESANDO LINEA LIBRE" << endl;
            for (int j = 0; j < n; j++) {
                temporal.push_back(1);
            }
        }
        else {
            for (int j = 0; j < n; j++) {
                temp = linea[j];
                num = stoi(temp);
                temporal.push_back(num);
            }
        }

        laberinto.push_back(temporal);
    }

    /*
    espacio();
    cout << "LABERINTO FORMADO" << endl;
    espacio();
    imprimir(laberinto); //IMPRESIÓN DE LABERINTO PARA VERIFICACIÓN
    */

    espacio();
    cout << "SOLUCION POR BACKTRACKING:" << endl;
    espacio();
    backtracking(laberinto); //SOLUCIÓN POR BACKTRACKING - Complejidad Computacional O(2^(N*M)), siendo M y N las dimensiones del laberinto a resolver.
    espacio();
    cout << "SOLUCION POR BRANCH AND BOUND:" << endl;
    espacio();
    branchandfoud(); //SOLUCIÓN POR BRANCH AND FOUND - PENDIENTE DE DESARROLLO !!!!!!!!!!!
    espacio();
    cout << "------ TERMINANDO PROGRAMA -----" << endl;
    espacio();

    // ---------- TERMINA PROGRAMA ---------- //

    return 0;
}
