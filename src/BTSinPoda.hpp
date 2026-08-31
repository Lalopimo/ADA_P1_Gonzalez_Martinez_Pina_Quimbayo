#ifndef BTSINPODA_HPP
#define BTSINPODA_HPP

#include <string>
using namespace std;

class BacktrackerSinPoda {
public:
    BacktrackerSinPoda(int n, int minLower, int minUpper, int minDigit, int minSymbol);
    void ejecutar();
    int getContrasenasGeneradas() const { return contraseñasGeneradas; }
    int getNodosGenerados() const { return nodosGenerados; }
    double getTiempoMs() const { return tiempoMs; }
    
private:
    int usadoLower = 0, usadoUpper = 0, usadoDigit = 0, usadoSymbol = 0;
    int contraseñasGeneradas = 0, nodosGenerados = 0, nodosVisitados = 0, nodosPodados = 0;
    double tiempoMs = 0;
    const string alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%";
    int n, minLower, minUpper, minDigit, minSymbol;
    void backtrack(string candidato);
    void agregarContadores(char c);
    void quitarContadores(char c);
    bool verificarRepetidos(string candidato);
};

#endif // !BTSINPODA_HPP

