/*
   Daniel Naryshev
   2327209
   dnaryshev@chapman.edu

 */
#include "Sort.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char** argv){
  	if (argc == 2){

    		string inputFile = argv[1];
    		cout << "Sorting " << inputFile << endl;
    		cout << "------------------------" << endl;
    		cout << endl;
        //init sorting class
    		Sort algo(inputFile);
        // call start function and pass file 
    		algo.Start(inputFile);
  	}
  	else{
  		  cout << "ERROR: Input valid file." << endl;
  	}
  	return 0;
}
