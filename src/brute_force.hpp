#ifndef BRUTE_FORCE_HPP
#define BRUTE_FORCE_HPP

#include <string>

namespace BruteForce {

    class Algorithm {

    private:

        bool isFound;

        unsigned int candidates;

        double time;
 
        std::string generateCandidates(
            std::string targetHash,
            std::string alphabet,
            int length,
            std::string currentCandidate
        );

    public:

        std::string find(
            std::string targetHash,
            std::string alphabet,
            int minLength,
            int maxLength
        );

        unsigned int getCandidates();
        double getTime();

    };

}

#endif