#include "../src/backtracking.hpp"
#include "../src/BTSinPoda.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/stat.h>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 7) {
        cout << "Uso: " << argv[0] << " <etiqueta_variante> <n> <minLower> <minUpper> <minDigit> <minSymbol>" << endl;
        return 1;
    }

    string etiqueta = argv[1];
    int n = atoi(argv[2]);
    int minLower = atoi(argv[3]);
    int minUpper = atoi(argv[4]);
    int minDigit = atoi(argv[5]);
    int minSymbol = atoi(argv[6]);

    string csvPath = "results/resultados_bt.csv";
    bool existe = ifstream(csvPath).good();

    ofstream csv(csvPath, ios::app);
    if (!existe) {
        csv << "variante,version,n,minLower,minUpper,minDigit,minSymbol,"
            << "nodosGenerados,nodosVisitados,nodosPodados,contraseñasGeneradas,tiempoMs" << endl;
    }

    cout << "=== " << etiqueta << " -- CON PODA ===" << endl;
    BacktrackerConPoda conPoda(n, minLower, minUpper, minDigit, minSymbol);
    cout.setstate(ios_base::failbit);
    conPoda.ejecutar();
    cout.clear();
    csv << etiqueta << ",conPoda," << n << "," << minLower << "," << minUpper << ","
        << minDigit << "," << minSymbol << "," << conPoda.getNodosGenerados() << ","
        << conPoda.getNodosVisitados() << "," << conPoda.getNodosPodados() << ","
        << conPoda.getContrasenasGeneradas() << "," << conPoda.getTiempoMs() << endl;
    cout << "Listo. Nodos generados: " << conPoda.getNodosGenerados()
         << ", tiempo: " << conPoda.getTiempoMs() << " ms" << endl;

    cout << "\n=== " << etiqueta << " -- SIN PODA ===" << endl;
    BacktrackerSinPoda sinPoda(n, minLower, minUpper, minDigit, minSymbol);
    cout.setstate(ios_base::failbit);
    sinPoda.ejecutar();
    cout.clear();
    csv << etiqueta << ",sinPoda," << n << "," << minLower << "," << minUpper << ","
        << minDigit << "," << minSymbol << "," << sinPoda.getNodosGenerados() << ",,,"
        << sinPoda.getContrasenasGeneradas() << "," << sinPoda.getTiempoMs() << endl;
    cout << "Listo. Nodos generados: " << sinPoda.getNodosGenerados()
         << ", tiempo: " << sinPoda.getTiempoMs() << " ms" << endl;

    csv.close();
    return 0;
}
