#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "extraFunction2.cpp"
#include "probabilityCalculationFunctions.cpp"



int main(int numberOfCommandLineArguments, char *arrayOfCommandLineArguments[]) {

    std::string stg;
    
    for (int i = 1; i < numberOfCommandLineArguments; i++){
        if (std::string(arrayOfCommandLineArguments[i]) == "given") {
            stg += "/";
            continue;
        }
        stg += arrayOfCommandLineArguments[i];
        stg += ",";

    }
    
    //  Example - stg = Bt,Ef/Jf or Mt,Ef
    //  Example - numAndDeno = [Bt$Mf& , Ef]

    //  produceNumeratorAndDenominator - comes from extraFunction2.cpp
    std::vector<std::string> numAndDeno = produceNumeratorAndDenominator(stg);
    double answer = calculateFinalProbability (numAndDeno);
    std::cout << answer ;

    return 0;
}