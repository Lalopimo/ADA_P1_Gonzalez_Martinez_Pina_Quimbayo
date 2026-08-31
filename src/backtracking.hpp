#ifndef BACKTRACKING_HPP
#define BACKTRACKING_HPP

#include <string>
using namespace std;

class BacktrackerConPoda {
public:
    BacktrackerConPoda(int n, int minLower, int minUpper, int minDigit, int minSymbol);
    void ejecutar();
    long long getContrasenasGeneradas() const { return contraseñasGeneradas; }
    long long getNodosGenerados() const { return nodosGenerados; }
    long long getNodosVisitados() const { return nodosVisitados; }
    long long getNodosPodados() const { return nodosPodados; }
    double getTiempoMs() const { return tiempoMs; }
    
private:
    int usadoLower = 0, usadoUpper = 0, usadoDigit = 0, usadoSymbol = 0;
    long long contraseñasGeneradas = 0, nodosGenerados = 0, nodosVisitados = 0, nodosPodados = 0;
    double tiempoMs = 0;
    const string alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%";
    int n, minLower, minUpper, minDigit, minSymbol;
    
    void backtrack(string candidato);
    bool esFactible(const string& candidato);
    void agregarContadores(char c);
    void quitarContadores(char c);
};

#endif // !BACKTRACKING_HPP
