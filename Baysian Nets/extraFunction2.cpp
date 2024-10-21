#include <vector>
#include <sstream>

std::vector<std::string> produceNumeratorAndDenominator (std::string stg) {

    std::vector<std::string> parts;
    std::vector<std::string> probabilityToFind;
    std::vector<std::string> conditions;

    std::stringstream ss(stg);
    std::string token;

    while(std::getline(ss, token, '/')) {
        parts.push_back(token);
    }
    
    std::stringstream ss2(parts[0]);
    while(std::getline(ss2, token, ',')) {
        probabilityToFind.push_back(token);
    }

    if (parts.size() != 1) {
        std::stringstream ss3(parts[1]);
        while(std::getline(ss3, token, ',')) {
            conditions.push_back(token);
        }
    }

    std::string numeratorString;
    std::string denominatorString;

    for (auto i : probabilityToFind) {
        numeratorString += i;
        numeratorString += "&";
    }

    if (parts.size() != 1) {
        for (auto i : conditions) {
            numeratorString += i;
            numeratorString += "&";
            denominatorString += i;
            denominatorString += "&";
        }
    } else {
        denominatorString += "None";
    }

    std::vector<std::string> vec = {numeratorString , denominatorString};

    return vec;
}