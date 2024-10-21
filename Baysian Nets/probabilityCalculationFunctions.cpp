#include "extraFunctions.cpp"
#include "bnetClass.cpp"




double calculateProbabilityOfEvent (std::string pattern) {
    //  Example - (parameter) pattern = "Bt&Jf&Af&Mt&Ef&";
    std::vector<std::string> t_f_vector = splitString(pattern,'&');
    //  Example = t_f_vector = ["Bt" , "Jf" , "Af" , "Mt" , "Ef"];
    std::array<bool,5> boolArray;

    for (auto i : t_f_vector) {
        if (i[0] == 'B') {
            if (i[1] == 't') {
                boolArray[0] = 1;
            } else {
                boolArray[0] = 0;
            }
        } else if (i[0] == 'E') {
            if (i[1] == 't') {
                boolArray[1] = 1;
            } else {
                boolArray[1] = 0;
            }
        } else if (i[0] == 'A') {
            if (i[1] == 't') {
                boolArray[2] = 1;
            } else {
                boolArray[2] = 0;
            }
        } else if (i[0] == 'J') {
            if (i[1] == 't') {
                boolArray[3] = 1;
            } else {
                boolArray[3] = 0;
            }
        } else if (i[0] == 'M') {
            if (i[1] == 't') {
                boolArray[4] = 1;
            } else {
                boolArray[4] = 0;
            }
        }
    }

    //  Order = B,E,A,J,M
    //  Example - boolArray = [0 , 0 , 1 , 1 , 1];

    bool b = boolArray[0];
    bool e = boolArray[1];
    bool a = boolArray[2];
    bool j = boolArray[3];
    bool m = boolArray[4];
    
    Bayssian_NetWork_Class bay;
    double val = bay.computeProbability(b,e,a,j,m);

    return val;
}

//  ---------------------------------------------------------

double calculateProbability (std::string stg) {
    //  Example - stg = "Bt&Mf&Jt&";
    
    //  Pattern = B,E,A,J,M
    //  Left to right, Top to Bottom

    std::vector<std::string> elements = splitString(stg , '&');
    //  Example elements = ["Bt" , "Mf" , "Jt"];

    int emptySpots = 5 - elements.size();
    int iterations = pow(2,emptySpots);

    std::array<char , 5> allElements = {'B' , 'E' , 'A' , 'J' , 'M'};
    std::vector<char> missingCharacters;

    for (auto i : allElements) {
        if (!elementInVector(i, elements)) {
            missingCharacters.push_back(i);
        }
    }
    //  Example MissingCharacters = ['A' , 'E'];

    std::string patternRequired = pattern(emptySpots);
    //  Example - patternRequired = "t,t/t,f/f,t/f,f";
    std::string finalPattern = "";    

    std::vector<std::string> patternVector = splitString(patternRequired, '/');
    //  Example patternVector = ["t,t" , "t,f" , "f,t" , "f,f"];

    std::string sttgg = "";
    for (auto i : patternVector) {
        sttgg += stg;
        auto boolVector = splitString(i,',');
        for (int i = 0; i < missingCharacters.size(); i++) {
            sttgg += missingCharacters[i];
            sttgg += boolVector[i];
            sttgg += "&";
        }
        sttgg += "+";
    }

    //  Example - sttgg = "Bt&Af&Mt&Jf&Et&+Bt&Af&Mt&Jf&Et&"

    auto taskVector = splitString (sttgg,'+');
    //  Example - taskVector = ["Bt&Af&Mt&Jf&Et&" , "Bt&Af&Mt&Jf&Et&"];

    //  Now we will add the probabilities of all the events.
    double sum = 0;
    for (auto i : taskVector) {
        sum += calculateProbabilityOfEvent(i);
        //  Example - i = Bt&Af&Mt&Jf&Et&;
    }

    return sum;

}



double calculateFinalProbability (std::vector<std::string> numAndDeno) {

    if (numAndDeno[1] == "None") {
        std::string numerator = numAndDeno[0];
        return calculateProbability(numerator);
    } else {
        std::string numerator = numAndDeno[0];
        std::string denominator = numAndDeno[1];
        return calculateProbability(numerator) / calculateProbability(denominator);
    }

}