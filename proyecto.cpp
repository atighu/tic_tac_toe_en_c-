#include <iostream>
#include <cstdlib>
#include <ctime>

// Prototipos de las funciones
void cargar_matriz(int n, int m, char mat[][3]);
void imprimir_matriz(int n, int m, char mat[][3]);
void juegapersona(char mat[][3], char jugador);
void juega_pc(char mat[][3], char pc);
bool hay_ganador(char mat[][3]);
bool empate(char mat[][3]);

int main() {
    char mat[3][3];
    cargar_matriz(3, 3, mat);
    imprimir_matriz(3, 3, mat);
    int termino = 0;
    int empieza = 0;
    char jugador, pc;
    
    std::cout << "Elige 1 para empezar, sino empieza la pc: ";
    std::cin >> empieza;
    
    if (empieza == 1) {
        std::cout << "Empieza el jugador" << std::endl;
    } else {
        std::cout << "Empieza la pc" << std::endl;
    }
    
    std::cout << "Elige x sino elige o: ";
    std::cin >> jugador;
    
    if (jugador == 'x') {
        std::cout << "Elegiste jugar con la x" << std::endl;
        pc = 'o';
    } else {
        std::cout << "Elegiste jugar con el o" << std::endl;
        pc = 'x';
    }
    
    while (termino == 0) {
        if (empieza == 1) {
            juegapersona(mat, jugador);
            if (hay_ganador(mat)) {
                std::cout << "¡Ganaste!" << std::endl;
                imprimir_matriz(3, 3, mat);
                termino = 1;
                break;
            }
            if (empate(mat)) {
                std::cout << "Empate" << std::endl;
                // imprimir_matriz(3, 3, mat);
                termino = 1;
                break;
            }
            juega_pc(mat, pc);
            imprimir_matriz(3, 3, mat);
            if (hay_ganador(mat)) {
                std::cout << "¡La PC ganó!" << std::endl;
                imprimir_matriz(3, 3, mat);
                termino = 1;
                break;
            }
            if (empate(mat)) {
                std::cout << "Empate" << std::endl;
                // imprimir_matriz(3, 3, mat);
                termino = 1;
                break;
            }
        } else {
            juega_pc(mat, pc);
            imprimir_matriz(3, 3, mat);
            if (hay_ganador(mat)) {
                std::cout << "¡La PC ganó!" << std::endl;
                // imprimir_matriz(3, 3, mat);
                termino = 1;
                break;
            }
            if (empate(mat)) {
                std::cout << "Empate" << std::endl;
                // imprimir_matriz(3, 3, mat);
                termino = 1;
                break;
            }
            juegapersona(mat, jugador);
            if (hay_ganador(mat)) {
                std::cout << "¡Ganaste!" << std::endl;
                imprimir_matriz(3, 3, mat);
                termino = 1;
                break;
            }
            if (empate(mat)) {
                std::cout << "Empate" << std::endl;
                // imprimir_matriz(3, 3, mat);
                termino = 1;
                break;
            }
        }
    }
    return 0;
}

// Función para cargar la matriz con espacios en blanco
void cargar_matriz(int n, int m, char mat[][3]) {
    for (int fil = 0; fil < n; fil++) {
        for (int col = 0; col < m; col++) {
            mat[fil][col] = '-';
        }
    }
}

// Función para imprimir la matriz
void imprimir_matriz(int n, int m, char mat[][3]) {
    for (int fil = 0; fil < n; fil++) {
        for (int col = 0; col < m; col++) {
            std::cout << mat[fil][col] << " ";
        }
        std::cout << std::endl;
    }
}

// Función para que la persona juegue
void juegapersona(char mat[][3], char jugador) {
    int f, c;
    std::cout << "Ingrese fila: ";
    std::cin >> f;
    std::cout << "Ingrese columna: ";
    std::cin >> c;
    while (mat[f][c] == 'o' || mat[f][c] == 'x') {
        std::cout << "Esa celda ya está ocupada. Ingrese fila: \n";
        std::cin >> f;
        std::cout << "Ingrese columna: ";
        std::cin >> c;
    }
    mat[f][c] = jugador;
}

// Función para que la PC juegue
void juega_pc(char mat[][3], char pc) {
    int min = 0, max = 2, f, c;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    f = std::rand() % (max - min + 1) + min;
    c = std::rand() % (max - min + 1) + min;
    while (mat[f][c] == 'x' || mat[f][c] == 'o') {
        f = std::rand() % (max - min + 1) + min;
        c = std::rand() % (max - min + 1) + min;
    }
    mat[f][c] = pc;
}
// Función para verificar si hay un ganador
bool hay_ganador(char mat[][3]) {
    if ((mat[0][0] == 'x' && mat[1][1] == 'x' && mat[2][2] == 'x') || 
        (mat[0][2] == 'x' && mat[1][1] == 'x' && mat[2][0] == 'x') || 
        (mat[0][0] == 'x' && mat[0][1] == 'x' && mat[0][2] == 'x') || 
        (mat[1][0] == 'x' && mat[1][1] == 'x' && mat[1][2] == 'x') || 
        (mat[2][0] == 'x' && mat[2][1] == 'x' && mat[2][2] == 'x') || 
        (mat[0][0] == 'x' && mat[1][0] == 'x' && mat[2][0] == 'x') || 
        (mat[0][1] == 'x' && mat[1][1] == 'x' && mat[2][1] == 'x') || 
        (mat[0][2] == 'x' && mat[1][2] == 'x' && mat[2][2] == 'x'))   
    {
        return true;
    } else if ((mat[0][0] == 'o' && mat[1][1] == 'o' && mat[2][2] == 'o') || 
               (mat[0][2] == 'o' && mat[1][1] == 'o' && mat[2][0] == 'o') || 
               (mat[0][0] == 'o' && mat[0][1] == 'o' && mat[0][2] == 'o') || 
               (mat[1][0] == 'o' && mat[1][1] == 'o' && mat[1][2] == 'o') || 
               (mat[2][0] == 'o' && mat[2][1] == 'o' && mat[2][2] == 'o') || 
               (mat[0][0] == 'o' && mat[1][0] == 'o' && mat[2][0] == 'o') || 
               (mat[0][1] == 'o' && mat[1][1] == 'o' && mat[2][1] == 'o') || 
               (mat[0][2] == 'o' && mat[1][2] == 'o' && mat[2][2] == 'o'))   
    {
        return true;
    }
    return false;
}

// Función para verificar si hay un empate
bool empate(char mat[][3]) {
    for (int f = 0; f < 3; f++) {
        for (int c = 0; c < 3; c++) {
            if (mat[f][c] == '-') {
                return false; 
            }
        }
    }
    return true; 
}




