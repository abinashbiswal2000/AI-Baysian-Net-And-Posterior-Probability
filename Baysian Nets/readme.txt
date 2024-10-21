1.  Name    - Abinash Biswal
    UTA ID  - 1002175520

2.  Programming Language Used = C++

3.  Compiler Information - g++ (MinGW.org GCC-6.3.0-1) 6.3.0

4.  How code is Structured?
    There are 6 c++ files.
    -   main.cpp
    -   bnetClass.cpp
    -   probabilityCalculationFunctions.cpp
    -   probabilityOf_B_E_A_J_M.cpp
    -   extraFunctions.cpp
    -   extraFunction2.cpp

    probabilityOf_B_E_A_J_M.cpp
    -   This file has all the probability values of different events

    bnetClass.cpp
    -   This file has a class with a member function called computeProbability
        which takes 5 booleans and returns the answer
    
    extraFunctions.cpp has the following functions
    -   pattern()
    -   elementInVector()
    -   splitString()
    These functions are used to simplify the process of calculating probability

    probabilityCalculationFunctions.cpp has the following functions
    -   calculateProbabilityOfEvent()
        Here the Baysian_Network_Class object is instanciated and computeProbability method is called.
    -   calculateProbability()
        This function calculates probabilities of all the events.
    -   calculateFinalProbability()
        This function return the final value after dividing the numerator and the denominator.

    extraFunction2.cpp
    This file has a function which applies conditional probability formula and provides a numerator and a denominator.

    main.cpp
    This is file where first the numerator and the denominator are generated.
    Then final probabilities are calculated.
    
    

    Idea
    -   Receive command line arguments.
    -   Apply Conditional probability formula
    -   Extract numerator and denominator
    -   Calculate Individual probability by generating all possible events.
        Adding their probabilities and finally returning their answer.

    
    File Import Heirarchy
    -   probabilityOf_B_E_A_J_M.cpp -> bnetClass.cpp -> probabilityCalculationFunctions.cpp <- extraFunctions.cpp
    -   probabilityCalculationFunctions.cpp -> main.cpp <- extraFunction2.cpp

        
    
5.  How to run the code?
    -   Install a c++ complier like minGW for windows.
        Youtube Video Link for Installation: https://www.youtube.com/watch?v=FEeFG9OR-QU
        Watch from 0:00 - 4:50
    -   Open command prompt (windows) in the folder(directory) where the program file is located.
    -   Type: g++ main.cpp -o bnet
        The step above will generate the executable file with the name 'bnet'
    -   Now you may type the following command and see the results
        Command: 
        .\bnet.exe a1 a2 given a3
        example - .\bnet.exe Bt given Mf

6.  Important Points
    **  Please make sure that the command line arguments follow this pattern
        First letter is in upper case. - B, E, A, J, M
        Second letter is in lower case. - t, f
        'given' is in lowercase
        Example - Bf given Et etc

    **  Ensure that all the files are in the same folder 
        -   main.cpp
        -   bnet.exe        
        
    **  Before running the code please ensure that the executable file preceeded by '.\'
        Example - .\bnet.exe