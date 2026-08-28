#include "brute_force.hpp"
#include "third_party/picosha2.h"
#include <chrono>

namespace BruteForce {

    std::string Algorithm::find(
        std::string targetHash,
        std::string alphabet,
        int minLength,
        int maxLength
    )
    {
        time = 0.0;
        isFound = false;
        candidates = 0;

        auto start = std::chrono::high_resolution_clock::now();

        if (alphabet.empty() || minLength <= 0 || maxLength < minLength) {
            return "";
        }

        for (int length = minLength; length <= maxLength; length++) {

            std::string result = generateCandidates(
                targetHash,
                alphabet,
                length,
                ""
            );

            if (!result.empty()) {

                auto end = std::chrono::high_resolution_clock::now();

                time = std::chrono::duration<double>(
                    end - start
                ).count();

                isFound = true;

                return result;
            }
        }

        auto end = std::chrono::high_resolution_clock::now();

        time = std::chrono::duration<double>(
            end - start
        ).count();

        return "";
    }


    std::string Algorithm::generateCandidates(
        std::string targetHash,
        std::string alphabet,
        int length,
        std::string currentCandidate
    )
    {
        if (currentCandidate.length() == length) {

            candidates++;

            std::string candidateHash =
                picosha2::hash256_hex_string(currentCandidate);

            if (candidateHash == targetHash) {

                isFound = true;

                return currentCandidate;
            }

            return "";
        }

        for (char c : alphabet) {

            std::string newCandidate = currentCandidate + c;

            std::string result = generateCandidates(
                targetHash,
                alphabet,
                length,
                newCandidate
            );

            if (!result.empty()) {

                return result;
            }
        }

        return "";
    }

    unsigned int Algorithm::getCandidates(){
        return candidates;
    }

    double Algorithm::getTime(){
        return time;
    }

}