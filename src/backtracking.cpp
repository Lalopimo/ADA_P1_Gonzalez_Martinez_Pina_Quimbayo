#include "backtracking.hpp"
#include <iostream>
#include <chrono>
using namespace std;

BacktrackerConPoda::BacktrackerConPoda(int n_, int minLower_, int minUpper_, int minDigit_, int minSymbol_)
: n(n_), minLower(minLower_), minUpper(minUpper_), minDigit(minDigit_), minSymbol(minSymbol_) {}

void BacktrackerConPoda::ejecutar(){
    auto inicio = chrono::steady_clock::now();
    backtrack("");
    auto fin = chrono::steady_clock::now();
    auto tiempoEjecucion = chrono::duration_cast<chrono::milliseconds>(fin - inicio);

    cout << "Contraseñas Generadas: " << contraseñasGeneradas<< endl;
    cout << "Nodos generados: " << nodosGenerados << endl;
    cout << "Nodos visitados: " << nodosVisitados << endl;
    cout << "Nodos podados: " << nodosPodados<< endl;
    cout << "Tiempo transcurrido: " << tiempoEjecucion.count() << " ms" << endl;
    tiempoMs = tiempoEjecucion.count();
}

void BacktrackerConPoda::backtrack(string candidato){
    nodosGenerados = nodosGenerados + 1;
    
    if (esFactible(candidato) == false) {
        nodosPodados = nodosPodados + 1;
        return;
    }
    
    nodosVisitados = nodosVisitados + 1;
    
    if (candidato.length() == n && usadoLower >= minLower && usadoUpper >= minUpper && usadoDigit >= minDigit && usadoSymbol >= minSymbol) {
        
        cout << candidato << endl;
        
        contraseñasGeneradas = contraseñasGeneradas + 1;
        
        return;
    }
    
    for(char caracter : alfabeto){
        candidato = candidato + caracter;
        
        agregarContadores(caracter);
        
        backtrack(candidato);
        
        candidato.pop_back();
        
        quitarContadores(caracter);
    }
}

bool BacktrackerConPoda::esFactible(const string& candidato){
    if (candidato.length() >= 2) {
        if (candidato[candidato.length() - 2] == candidato[candidato.length() - 1]) {
            
            return false;
        }
    }
    
    int faltanteTotal = max(0, minLower - usadoLower) + max(0, minUpper - usadoUpper) + max(0, minDigit - usadoDigit) + max(0, minSymbol - usadoSymbol);
    
    if (n - candidato.length()< faltanteTotal) {
        return false;
    }
    
    return true;
}

void BacktrackerConPoda::agregarContadores(char c){
    if (c == 'x' || c == 'a' || c == 'w' || c == 'b' || c == 'v' || c == 'c' || c == 'u' || c == 'd' || c == 't' || c == 'e' || c == 's' || c == 'f' || c == 'r' || c == 'g' || c == 'h' || c == 'q' || c == 'i' || c == 'p' || c == 'j' || c == 'o' || c == 'k' || c == 'l' || c == 'n' || c == 'm' || c == 'z' || c == 'y') {
        usadoLower = usadoLower + 1;
    } else if (c == 'A' || c == 'B' || c == 'Z' || c == 'C' || c == 'Y' || c == 'D' || c == 'X' || c == 'E' || c == 'W' || c == 'F' || c == 'V' || c == 'G' || c == 'U' || c == 'H' || c == 'T' || c == 'I' || c == 'S' || c == 'J' || c == 'R' || c == 'K' || c == 'Q' || c == 'L' || c == 'P' || c == 'M' || c == 'O' || c == 'N'){
        usadoUpper = usadoUpper + 1;
    } else if (c == '0' || c == '6' || c == '1' || c == '5' || c == '2' || c == '4' || c == '3' || c == '9' || c == '7' || c == '8'){
        usadoDigit = usadoDigit + 1;
    } else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%'){
        usadoSymbol = usadoSymbol + 1;
    }
}
    
void BacktrackerConPoda::quitarContadores(char c){
    if (c == 'x' || c == 'a' || c == 'w' || c == 'b' || c == 'v' || c == 'c' || c == 'u' || c == 'd' || c == 't' || c == 'e' || c == 's' || c == 'f' || c == 'r' || c == 'g' || c == 'h' || c == 'q' || c == 'i' || c == 'p' || c == 'j' || c == 'o' || c == 'k' || c == 'l' || c == 'n' || c == 'm' || c == 'z' || c == 'y') {
        usadoLower = usadoLower - 1;
    } else if (c == 'A' || c == 'B' || c == 'Z' || c == 'C' || c == 'Y' || c == 'D' || c == 'X' || c == 'E' || c == 'W' || c == 'F' || c == 'V' || c == 'G' || c == 'U' || c == 'H' || c == 'T' || c == 'I' || c == 'S' || c == 'J' || c == 'R' || c == 'K' || c == 'Q' || c == 'L' || c == 'P' || c == 'M' || c == 'O' || c == 'N'){
        usadoUpper = usadoUpper - 1;
    } else if (c == '0' || c == '6' || c == '1' || c == '5' || c == '2' || c == '4' || c == '3' || c == '9' || c == '7' || c == '8'){
        usadoDigit = usadoDigit - 1;
    } else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%'){
        usadoSymbol = usadoSymbol - 1;
    }
}
