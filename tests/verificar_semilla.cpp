// verificar_semilla.cpp
// Utilidad de verificación de semilla y parámetros de política para el BT
// Reproduce el cálculo documentado en el informe a partir de los apellidos del equipo.

#include <iostream>
#include <string>
using namespace std;

int main() {
    // La "ñ" se normalizó a "n", decisión documentada ante ambigüedad, ASCII estándar no incluye la ñ).
    string apellidos = "gonzalezmartinezpinaquimbayo";

    long sumaAscii = 0;
    for (char c : apellidos) {
        sumaAscii += static_cast<int>(c);
    }

    long semilla = sumaAscii % 100000;

    int minLower = 2 + (semilla % 3);
    int minUpper = 1 + (semilla % 2);
    int minDigit = 1 + (semilla % 3);
    int minSymbol = 1;
    int n = 8;

    int sumaMinimos = minLower + minUpper + minDigit + minSymbol;

    cout << "Apellidos concatenados: " << apellidos << endl;
    cout << "Suma de codigos ASCII: " << sumaAscii << endl;
    cout << "Semilla (suma mod 100000): " << semilla << endl;
    cout << endl;
    cout << "Parametros de la politica (Seccion 9.2):" << endl;
    cout << "  minLower  = " << minLower << endl;
    cout << "  minUpper  = " << minUpper << endl;
    cout << "  minDigit  = " << minDigit << endl;
    cout << "  minSymbol = " << minSymbol << endl;
    cout << "  n         = " << n << endl;
    cout << endl;
    cout << "Suma de minimos = " << sumaMinimos
         << (sumaMinimos <= n ? " (<= n, cumple)" : " (> n, requiere ajuste)") << endl;

    return 0;
}
