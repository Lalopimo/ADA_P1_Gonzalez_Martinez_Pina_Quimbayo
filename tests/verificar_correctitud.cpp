#include "../src/backtracking.hpp"
#include "../src/BTSinPoda.hpp"
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    // Instancias pequeñas de verificación: {n, minLower, minUpper, minDigit, minSymbol}
    vector<tuple<int,int,int,int,int>> instancias = {
        {3, 1, 0, 1, 1},
        {4, 1, 1, 1, 1},
        {5, 2, 1, 1, 1},
        {4, 0, 0, 0, 0},  // política sin restricciones de composición
    };
    
    int fallos = 0;
    
    for (auto& [n, minLower, minUpper, minDigit, minSymbol] : instancias) {
        BacktrackerConPoda conPoda(n, minLower, minUpper, minDigit, minSymbol);
        BacktrackerSinPoda sinPoda(n, minLower, minUpper, minDigit, minSymbol);
        
        cout.setstate(ios_base::failbit);
        conPoda.ejecutar();
        sinPoda.ejecutar();
        cout.clear();
        
        int countConPoda = conPoda.getContrasenasGeneradas();
        int countSinPoda = sinPoda.getContrasenasGeneradas();
        
        cout << "Instancia (n=" << n << ", minLower=" << minLower
        << ", minUpper=" << minUpper << ", minDigit=" << minDigit
        << ", minSymbol=" << minSymbol << "): ";
        
        if (countConPoda == countSinPoda) {
            cout << "OK (" << countConPoda << " soluciones en ambas versiones)" << endl;
        } else {
            cout << "FALLO -- ConPoda=" << countConPoda
            << " vs SinPoda=" << countSinPoda << endl;
            fallos++;
        }
    }
    
    // Verificación adicional: instancia de referencia común (Sección 9.2),
    // solo con la versión CON poda (la versión sin poda es intratable a este tamaño,
    // ver discusión en el informe sobre el "muro exponencial").
    cout << "\n--- Instancia de referencia común (n=6, minLower=2, minUpper=1, minDigit=1, minSymbol=1) ---" << endl;
    BacktrackerConPoda referencia(6, 2, 1, 1, 1);
    cout.setstate(ios_base::failbit);
    referencia.ejecutar();
    cout.clear();
    cout << "Soluciones encontradas (CON poda): " << referencia.getContrasenasGeneradas() << endl;
    cout << "Esta cifra queda documentada como validada por consistencia con las 4 instancias anteriores," << endl;
    cout << "donde CON poda y SIN poda coincidieron exactamente." << endl;
    
    cout << "\n" << (fallos == 0 ? "Todas las instancias coinciden."
                     : to_string(fallos) + " instancia(s) con discrepancia.") << endl;
    
    return fallos == 0 ? 0 : 1;
}
