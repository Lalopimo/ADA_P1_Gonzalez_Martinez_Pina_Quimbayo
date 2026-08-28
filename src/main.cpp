#include <iostream>
#include "brute_force.hpp"

int main() {

    std::string targetHash = "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad";
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    int minLength = 3;
    int maxLength = 3;

    BruteForce::Algorithm bruteForce;

    std::string result = bruteForce.find(
        targetHash,
        alphabet,
        minLength,
        maxLength
    );

   if (!result.empty()) {
    std::cout << "Password found: " << result << std::endl;
    } else {
        std::cout << "Password not found." << std::endl;
    }

std::cout << "Candidates evaluated: " << bruteForce.getCandidates() << std::endl;
std::cout << "Execution time: " << bruteForce.getTime() << " seconds" << std::endl;

    return 0;
}