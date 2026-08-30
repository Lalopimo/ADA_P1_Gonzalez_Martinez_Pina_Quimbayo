#include <iostream>
#include <cstdlib>
#include "brute_force.hpp"
#include "backtracking.hpp"
#include "BTSinPoda.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    
    cout << "=== Fuerza Bruta ===" << endl;
    string targetHash = "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad";
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    
    int minLength = 3;
    int maxLength = 3;
    
    BruteForce::Algorithm bruteForce;
    
    string result = bruteForce.find(
                                    targetHash,
                                    alphabet,
                                    minLength,
                                    maxLength
                                    );
    
    if (!result.empty()) {
        cout << "Password found: " << result << endl;
    } else {
        std::cout << "Password not found." << std::endl;
    }
    
    cout << "Candidates evaluated: " << bruteForce.getCandidates() << endl;
    cout << "Execution time: " << bruteForce.getTime() << " seconds" << endl;
    
    
    if (argc != 6) {
        cout << "\nUso: " << argv[0] << " <n> <minLower> <minUpper> <minDigit> <minSymbol>" << endl;
        return 1;
    }
    
    int n = atoi(argv[1]);
    int minLower = atoi(argv[2]);
    int minUpper = atoi(argv[3]);
    int minDigit = atoi(argv[4]);
    int minSymbol = atoi(argv[5]);
    
    cout << "=== Backtracking CON poda ===" << endl;
    BacktrackerConPoda bt(n, minLower, minUpper, minDigit, minSymbol);
    bt.ejecutar();
    
    cout << "\n=== Backtracking SIN poda ===" << endl;
    BacktrackerSinPoda btSinPoda(n, minLower, minUpper, minDigit, minSymbol);
    btSinPoda.ejecutar();
    
    return 0;
}
