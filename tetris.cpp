#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;

const int ANCHO = 10;
const int ALTO = 20;

// Las 7 piezas clasicas de tetris como matrices (1 = bloque)
vector<vector<vector<int>>> PIEZAS = {
    {{1,1,1,1}},        // I
    {{1,1},{1,1}},      // O
    {{0,1,0},{1,1,1}},  // T
    {{1,0,0},{1,1,1}},  // L
    {{0,0,1},{1,1,1}},  // J
    {{0,1,1},{1,1,0}},  // S
    {{1,1,0},{0,1,1}}   // Z
};

vector<vector<int>> tablero(ALTO, vector<int>(ANCHO, 0));

struct Pieza {
    int tipo;
    int x, y;                // columna y fila
    vector<vector<int>> forma;
};

int puntaje = 0;

// Rota una matriz 90 grados en sentido horario
vector<vector<int>> rotar(const vector<vector<int>>& f) {
    int filas = f.size();
    int cols = f[0].size();
    vector<vector<int>> nueva(cols, vector<int>(filas));
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < cols; j++)
            nueva[j][filas - 1 - i] = f[i][j];
    return nueva;
}

// Comprueba si una forma cabe en la posicion (x, y)
bool cabeForma(const vector<vector<int>>& forma, int x, int y) {
    for (int i = 0; i < forma.size(); i++)
        for (int j = 0; j < forma[i].size(); j++)
            if (forma[i][j]) {
                int nx = x + j, ny = y + i;
                if (nx < 0 || nx >= ANCHO || ny >= ALTO) return false;
                if (ny >= 0 && tablero[ny][nx]) return false;
            }
    return true;
}

Pieza nuevaPieza() {
    Pieza p;
    p.tipo = rand() % PIEZAS.size();
    p.forma = PIEZAS[p.tipo];
    p.x = ANCHO / 2 - p.forma[0].size() / 2;
    p.y = 0;
    return p;
}

void dibujar(const Pieza& p) {
    system("cls");
    auto vista = tablero;
    for (int i = 0; i < p.forma.size(); i++)
        for (int j = 0; j < p.forma[i].size(); j++)
            if (p.forma[i][j] && p.y + i >= 0)
                vista[p.y + i][p.x + j] = 2;

    for (int i = 0; i < ANCHO + 2; i++) cout << "#";
    cout << "\n";
    for (int i = 0; i < ALTO; i++) {
        cout << "#";
        for (int j = 0; j < ANCHO; j++) {
            if (vista[i][j] == 0) cout << " ";
            else if (vista[i][j] == 1) cout << "#";
            else cout << "O";
        }
        cout << "#\n";
    }
    for (int i = 0; i < ANCHO + 2; i++) cout << "#";
    cout << "\nPuntuacion: " << puntaje << "\n";
    cout << "Controles: A(izq) D(der) S(bajar) W(rotar) X(soltar) Q(salir)\n";
}

// Elimina lineas completas y devuelve cuantas se quitaron
int limpiarLineas() {
    int eliminadas = 0;
    for (int i = ALTO - 1; i >= 0; i--) {
        bool llena = true;
        for (int j = 0; j < ANCHO; j++)
            if (!tablero[i][j]) { llena = false; break; }
        if (llena) {
            tablero.erase(tablero.begin() + i);
            tablero.insert(tablero.begin(), vector<int>(ANCHO, 0));
            eliminadas++;
            i++;
        }
    }
    return eliminadas;
}

int main() {
    srand(time(0));
    Pieza p = nuevaPieza();
    bool fin = false;

    while (!fin) {
        // Gravedad: bajo la pieza automaticamente
        if (cabeForma(p.forma, p.x, p.y + 1)) {
            p.y++;
        } else {
            // Fijo la pieza en el tablero
            for (int i = 0; i < p.forma.size(); i++)
                for (int j = 0; j < p.forma[i].size(); j++)
                    if (p.forma[i][j] && p.y + i >= 0)
                        tablero[p.y + i][p.x + j] = 1;

            puntaje += limpiarLineas() * 10;
            p = nuevaPieza();

            if (!cabeForma(p.forma, p.x, p.y)) {
                fin = true;
                break;
            }
        }

        dibujar(p);

        // Entrada del jugador
        if (_kbhit()) {
            char c = tolower(_getch());
            if (c == 'a' && cabeForma(p.forma, p.x - 1, p.y)) p.x--;
            else if (c == 'd' && cabeForma(p.forma, p.x + 1, p.y)) p.x++;
            else if (c == 's' && cabeForma(p.forma, p.x, p.y + 1)) p.y++;
            else if (c == 'w') {
                auto r = rotar(p.forma);
                if (cabeForma(r, p.x, p.y)) p.forma = r;
            }
            else if (c == 'x') { while (cabeForma(p.forma, p.x, p.y + 1)) p.y++; }
            else if (c == 'q') { fin = true; break; }
        }

        Sleep(200);
    }

    system("cls");
    cout << "GAME OVER\nPuntuacion final: " << puntaje << "\n";
    return 0;
}