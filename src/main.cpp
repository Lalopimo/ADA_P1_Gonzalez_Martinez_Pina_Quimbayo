#include <iostream>
#include <cstdlib>
#include "brute_force.hpp"
#include "backtracking.hpp"
#include "BTSinPoda.hpp"

using namespace std;

int main(int argc, char* argv[]) {

    cout << "=== ADA P1 - Fuerza Bruta y Backtracking ===" << endl;
    cout << "Que modulo deseas ejecutar?" << endl;
    cout << "  1. Fuerza Bruta (FB)" << endl;
    cout << "  2. Backtracking (BT)" << endl;
    cout << "Opcion: ";

    int modulo;
    cin >> modulo;

    if (modulo == 1) {
        // === Modulo FB ===
        string targetHash;
        cout << "gimme your hash" << "\n";
        cin >> targetHash;
        int option;
        cout << "What do you want, brute force or dictionary attack? " << "\n";
        cin >> option;

        if (option == 1) {
            cout << "Give me your alphabet" << "\n";
            string alphabet;
            cin >> alphabet;

            cout << "give the length among the 4 to 6" << "\n";
            cout << "the min length: " << "\n";
            int minLength;
            cin >> minLength;
            cout << "the max length: " << "\n";
            int maxLength;
            cin >> maxLength;

            BruteForce::Algorithm bruteForce;
            string result = bruteForce.find(targetHash, alphabet, minLength, maxLength);

            if (!result.empty()) {
                cout << "Password found: " << result << endl;
            } else {
                cout << "Password not found." << endl;
            }
            cout << "Candidates evaluated: " << bruteForce.getCandidates() << endl;
            cout << "Execution time: " << bruteForce.getTime() << " miliseconds" << endl;

        } else if (option == 0) {
            string pathDictionary = "resources/diccionario.txt";
            BruteForce::Algorithm bruteForce;
            string result = bruteForce.dictionaryAttack(targetHash, pathDictionary);

            if (!result.empty()) {
                cout << "Password found: " << result << endl;
            } else {
                cout << "Password not found." << endl;
            }
            cout << "Execution time: " << bruteForce.getTime() << " miliseconds" << endl;
        }

    } else if (modulo == 2) {
        // === Modulo BT ===
        if (argc != 6) {
            cout << "\nPara BT, ejecuta asi: " << argv[0]
                 << " <n> <minLower> <minUpper> <minDigit> <minSymbol>" << endl;
            return 1;
        }

        int n = atoi(argv[1]);
        int minLower = atoi(argv[2]);
        int minUpper = atoi(argv[3]);
        int minDigit = atoi(argv[4]);
        int minSymbol = atoi(argv[5]);

        cout << "\n=== Backtracking CON poda ===" << endl;
        BacktrackerConPoda bt(n, minLower, minUpper, minDigit, minSymbol);
        bt.ejecutar();

        cout << "\n=== Backtracking SIN poda ===" << endl;
        BacktrackerSinPoda btSinPoda(n, minLower, minUpper, minDigit, minSymbol);
        btSinPoda.ejecutar();

    } else {
        cout << "Opcion invalida." << endl;
        return 1;
    }

    return 0;
}
