#include <vector>
#include <array>
#include <sstream>
#include <math.h>



//  -------------------------------------------------------------





//  ---------------------------------------------------------

std::vector<std::string> splitString (std::string stg, char splitingCharacter) {

    std::vector<std::string> parts;

    std::stringstream ss(stg);
    std::string token;

    while(std::getline(ss, token, splitingCharacter)) {
        parts.push_back(token);
    }

    return parts;
}

//  ---------------------------------------------------------

bool elementInVector (char element , std::vector<std::string> vec) {
    for (auto i : vec) {
        if (i[0] == element) {
            return 1;
        }
    }
    return 0;
}

//  ---------------------------------------------------------

std::string pattern (int emptySpots) {
    // int iterations = pow(2,emptySpots);
    if (emptySpots == 0) {
        return "";
    } else if (emptySpots == 1) {
        return "t/f";
    } else if (emptySpots == 2) {
        return "t,t/t,f/f,t/f,f";
    } else if (emptySpots == 3) {
        return "t,t,t/t,t,f/t,f,t/f,t,t/t,f,f/f,t,f/f,f,t/f,f,f";
    } else if (emptySpots == 4) {
        return "t,t,t,t/t,t,t,f/t,t,f,t/t,f,t,t/f,t,t,t/t,t,f,f/t,f,f,t/f,f,t,t/f,t,f,t/t,f,t,f/f,t,t,f/t,f,f,f/f,t,f,f/f,f,t,f/f,f,f,t/f,f,f,f";
    } else {
        return "t,t,t,t,t/t,t,t,f,t/t,t,f,t,t/t,f,t,t,t/f,t,t,t,t/t,t,f,f,t/t,f,f,t,t/f,f,t,t,t/f,t,f,t,t/t,f,t,f,t/f,t,t,f,t/t,f,f,f,t/f,t,f,f,t/f,f,t,f,t/f,f,f,t,t/f,f,f,f,t/t,t,t,t,f/t,t,t,f,f/t,t,f,t,f/t,f,t,t,f/f,t,t,t,f/t,t,f,f,f/t,f,f,t,f/f,f,t,t,f/f,t,f,t,f/t,f,t,f,f/f,t,t,f,f/t,f,f,f,f/f,t,f,f,f/f,f,t,f,f/f,f,f,t,f/f,f,f,f,f";
    }
}

//  ---------------------------------------------------------

