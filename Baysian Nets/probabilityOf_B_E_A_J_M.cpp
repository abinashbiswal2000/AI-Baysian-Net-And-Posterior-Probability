

double probabilityOfBurglary(bool trueOrFalse) {
    if (trueOrFalse == 1) {
        return 0.001;
    } else {
        return 1 - 0.001;
    }
}

double probabilityOfEarthQuake (bool trueOrFalse) {
    if (trueOrFalse == 1) {
        return 0.002;
    } else {
        return 1 - 0.002;
    }
}

double probabilityOfAlarm (bool trueOrFalse , bool burglary , bool earthquake) {
    if (trueOrFalse == 1) {
        if (burglary == 1 && earthquake == 1) {
            return 0.95;
        } else if (burglary == 1 && earthquake == 0) {
            return 0.94;
        } else if (burglary == 0 && earthquake == 1) {  
            return 0.29;
        } else {
            return 0.001;
        }
    } else {
        if (burglary == 1 && earthquake == 1) {
            return 1 - 0.95;
        } else if (burglary == 1 && earthquake == 0) {
            return 1 - 0.94;
        } else if (burglary == 0 && earthquake == 1) {
            return 1 - 0.29;
        } else {
            return 1 - 0.001;
        }
    }
}

double probabilityOfJohnCalling (bool trueOrFalse , bool alarm) {
    if (trueOrFalse == 1) {
        if (alarm == 1) {
            return 0.9;
        } else {
            return 0.05;
        }     
    } else {
        if (alarm == 1) {
            return 1 - 0.9;
        } else {
            return 1 - 0.05;
        }
    }
}


double probabilityOfMaryCalling (bool trueOrFalse , bool alarm) {
    if (trueOrFalse == 1) {
        if (alarm == 1) {
            return 0.7;
        } else {
            return 0.01;
        }     
    } else {
        if (alarm == 1) {
            return 1 - 0.7;
        } else {
            return 1 - 0.01;
        }
    }
}
