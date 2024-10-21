#include "probabilityOf_B_E_A_J_M.cpp"

class Bayssian_NetWork_Class {

    public:
        
        Bayssian_NetWork_Class () {}

        double computeProbability (bool b, bool e, bool a, bool j, bool m) {

            double val = 1;
            
            val *= probabilityOfBurglary (b);
            val *= probabilityOfEarthQuake (e);
            val *= probabilityOfAlarm (a, b, e);
            val *= probabilityOfJohnCalling (j, a);
            val *= probabilityOfMaryCalling (m, a);

            return val;

        }
};