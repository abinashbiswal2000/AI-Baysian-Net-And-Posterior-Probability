1.  Name    - 
    UTA ID  - 

2.  Programming Language Used = C++

3.  Compiler Information - g++ (MinGW.org GCC-6.3.0-1) 6.3.0

4.  How code is Structured?
    compute_a_posteriori.cpp has 1 class and 4 functions defined before the main function
    -   Bag(Class)
    -   totalProbabilityOfFruit (Function)
    -   updateProbability (Function)
    -   cherryProbabilityAfterQ (Function)
    -   limeProbabilityAfterQ (Function)

    Bag Class
    -   The first attribute is the probability of class
    -   The second attribute is the probability of cherry
    -   The third attribute is the probability of lime
    -   There are other methods to get these probabilities.
        There is a method to change the bag probability as well.

    Main Function (Line 124)
    -   5 Bag objects are instanciated.
    -   Then depending on the command line input, i.e if there is a pattern mentioned or not,
        there is an if else block to handle both the scenarios.
    -   Then there is a loop(line 147) , which keeps updating the probabilities from observation to observation.
    -   In case, no pattern is given in the command line, then observations sequence is printed as an empty string.
        and the length of the sequence is printed as 0.
    -   After the code finishes execution, a file called 'result.txt' will be created, where all the output will be printed.


        
    
5.  How to run the code?
    -   Install a c++ complier like minGW for windows.
        Youtube Video Link for Installation: https://www.youtube.com/watch?v=FEeFG9OR-QU
        Watch from 0:00 - 4:50
    -   Open command prompt (windows) in the folder(directory) where the program file is located.
    -   Type: g++ compute_a_posteriori.cpp -o compute_a_posteriori
        The step above will generate the executable file with the name 'compute_a_posteriori'
    -   Now you may type the following command and see the results
        Command: 
        .\compute_a_posteriori.exe pattern
        example - .\compute_a_posteriori.exe CLLCCLCCC

6.  Important Points
    **  Please make sure that the pattern is typed in uppercase.
        i.e - CLCCCCC (not - clccccc)

    **  Ensure that all the files are in the same folder 
        -   compute_a_posteriori.cpp
        -   compute_a_posteriori.exe
    
    **  The inputs have to be entered in a particular order.
        Executable_compute_a_posteriori 
        
    **  Before running the code please ensure that the executable file preceeded by '.\'
        Example - .\compute_a_posteriori.exe