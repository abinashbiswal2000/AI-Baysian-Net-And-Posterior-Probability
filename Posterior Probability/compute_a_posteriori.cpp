#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

class Bag {
    private:
        double probability;
        double cherryProbability;
        double limeProbability;

    
    public:
        Bag (double p, double cP, double lP) {
            this->probability = p;
            this->cherryProbability = cP;
            this->limeProbability = lP;
        }

        void printData () {
            std::cout << "Cherry Probability = " << this->cherryProbability << std::endl;
            std::cout << "Lime Probability   = " << this->limeProbability << std::endl;
            std::cout << "Probability        = " << this->probability << std::endl << std::endl;;
        }

        void setProbability (double newProbability) {
            this->probability = newProbability;
        }

        double getCherryProbability () {
            return this->cherryProbability;
        }

        double getLimeProbability () {
            return this->limeProbability;
        }

        double getProbability () {
            return this->probability;
        }

};



double totalProbabilityOfFruit (char fruit, Bag b1, Bag b2, Bag b3, Bag b4, Bag b5) {
    Bag arr[5] = {b1, b2, b3, b4, b5};
    double total = 0;
    for (auto i : arr) {
        if (fruit == 'C') {
            total += i.getCherryProbability() * i.getProbability();
        } else {
            total += i.getLimeProbability() * i.getProbability();
        }
    }
    return total;
}

void updateProbability (char fruit, double totalProbability, Bag & b1, Bag & b2, Bag & b3, Bag & b4, Bag & b5) {

    double num;

    if (fruit == 'L') {

        num = b1.getLimeProbability() * b1.getProbability() / totalProbability;
        b1.setProbability(num);

        num = b2.getLimeProbability() * b2.getProbability() / totalProbability;
        b2.setProbability(num);

        num = b3.getLimeProbability() * b3.getProbability() / totalProbability;
        b3.setProbability(num);

        num = b4.getLimeProbability() * b4.getProbability() / totalProbability;
        b4.setProbability(num);
        
        num = b5.getLimeProbability() * b5.getProbability() / totalProbability;
        b5.setProbability(num);

    } else {

        num = b1.getCherryProbability() * b1.getProbability() / totalProbability;
        b1.setProbability(num);

        num = b2.getCherryProbability() * b2.getProbability() / totalProbability;
        b2.setProbability(num);

        num = b3.getCherryProbability() * b3.getProbability() / totalProbability;
        b3.setProbability(num);

        num = b4.getCherryProbability() * b4.getProbability() / totalProbability;
        b4.setProbability(num);
        
        num = b5.getCherryProbability() * b5.getProbability() / totalProbability;
        b5.setProbability(num);

    }    
    
}


double cherryProbabilityAfterQ (Bag b1, Bag b2, Bag b3, Bag b4, Bag b5) {
    double num = 0;
    num += b1.getCherryProbability() * b1.getProbability();
    num += b2.getCherryProbability() * b2.getProbability();
    num += b3.getCherryProbability() * b3.getProbability();
    num += b4.getCherryProbability() * b4.getProbability();
    num += b5.getCherryProbability() * b5.getProbability();
    return num;
}

double limeProbabilityAfterQ (Bag b1, Bag b2, Bag b3, Bag b4, Bag b5) {
    double num = 0;
    num += b1.getLimeProbability() * b1.getProbability();
    num += b2.getLimeProbability() * b2.getProbability();
    num += b3.getLimeProbability() * b3.getProbability();
    num += b4.getLimeProbability() * b4.getProbability();
    num += b5.getLimeProbability() * b5.getProbability();
    return num;
}



int main (int numberOfCommandLineArguments, char *arrayOfCommandLineArguments[]) {
    
    std::ofstream outputFile("result.txt");
    outputFile << std::fixed << std::setprecision(std::numeric_limits<double>::max_digits10);


    Bag b1(0.1, 1, 0);
    Bag b2(0.2, 0.75, 0.25);
    Bag b3(0.4, 0.5, 0.5);
    Bag b4(0.2, 0.25, 0.75);
    Bag b5(0.1, 0, 1);
    
    if (numberOfCommandLineArguments == 2) {
        std::string input = arrayOfCommandLineArguments[1];
        outputFile << "Observation sequence Q: " << input << std::endl;

        int length = 0; 
        for (auto i : input) {
            length++;
        }
        outputFile << "Length of Q: " << length << std::endl << std::endl;

        int index = 1;
        for (auto i : input) {

            double totalProb = totalProbabilityOfFruit(i, b1, b2, b3, b4, b5);
            updateProbability(i , totalProb , b1 , b2 , b3 , b4 , b5);

            outputFile << "After Observation " << index << " = " << i << std::endl << std::endl;
            index++;
            outputFile << "P(h1 | Q) = " << b1.getProbability() << std::endl;
            outputFile << "P(h2 | Q) = " << b2.getProbability() << std::endl;
            outputFile << "P(h3 | Q) = " << b3.getProbability() << std::endl;
            outputFile << "P(h4 | Q) = " << b4.getProbability() << std::endl;
            outputFile << "P(h5 | Q) = " << b5.getProbability() << std::endl << std::endl;

            outputFile << "Probability that the next candy we pick will be C, given Q: " << cherryProbabilityAfterQ(b1 , b2 , b3 , b4 , b5) << std::endl;
            outputFile << "Probability that the next candy we pick will be L, given Q: " << limeProbabilityAfterQ(b1 , b2 , b3 , b4 , b5) << std::endl <<std::endl;
        }

        outputFile.close();
    } else {
        outputFile << "Observation sequence Q: " << std::endl;
        outputFile << "Length of Q: 0" << std::endl << std::endl;        

        outputFile.close();
    }

    return 0;
}