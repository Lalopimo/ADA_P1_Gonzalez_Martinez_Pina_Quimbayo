#include "BTSinPoda.hpp"
#include <iostream>
using namespace std;

BacktrackerSinPoda::BacktrackerSinPoda(int n_, int minLower_, int minUpper_, int minDigit_, int minSymbol_)
: n(n_), minLower(minLower_), minUpper(minUpper_), minDigit(minDigit_), minSymbol(minSymbol_) {}

void BacktrackerSinPoda::ejecutar(){
    auto inicio = chrono::steady_clock::now();
    backtrack("");
    auto fin = chrono::steady_clock::now();
    auto tiempoEjecucion = chrono::duration_cast<chrono::milliseconds>(fin - inicio);
    
    cout << "Contraseñas Generadas: " << contraseñasGeneradas<< endl;
    cout << "Nodos generados: " << nodosGenerados << endl;
    cout << "Tiempo transcurrido: " << tiempoEjecucion.count() << " ms" << endl;
    tiempoMs = tiempoEjecucion.count();
    
}

void BacktrackerSinPoda::backtrack(string candidato){
    
    nodosGenerados = nodosGenerados + 1;
    /*
     if (esFactible(candidato) == false) {
     nodosPodados = nodosPodados + 1;
     return;
     }
     */
    nodosVisitados = nodosVisitados + 1;
    if (candidato.length() == n ){
        if (usadoLower >= minLower && usadoUpper >= minUpper && usadoDigit >= minDigit && usadoSymbol >= minSymbol) {
            if (verificarRepetidos(candidato) == true){
                cout << candidato << endl;
                
                contraseñasGeneradas = contraseñasGeneradas + 1;
                
                return;
            }
        }
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

void BacktrackerSinPoda::agregarContadores(char c){
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
    
void BacktrackerSinPoda::quitarContadores(char c){
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
    
bool BacktrackerSinPoda::verificarRepetidos(string candidato){
    for (int i=1; i < n; i ++){
        if (candidato[i] == candidato[i-1]){
            return false;
        }
    }
    return true;
}
