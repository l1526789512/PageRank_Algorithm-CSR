#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include "CSRMat.h"
#include "rankingsVector.h"

using namespace std;


struct website{
    
    std::string name;
    int ranking;
};

vector<website> addVectors( vector<website> oldVector , vector<website> newVector );



int main(){
	
	{
	
		vector<website> rankVector;
		
		while(1){
			
			////Diplay Menu
			cout << "======Main Menu======" << endl;
			cout << "1. Create Sparse Graph" << endl;
			cout << "2. " << endl;
			cout << "3. " << endl;
			cout << "4. " << endl;
			cout << "5. " << endl;
			
			
			string userInput;
			getline(cin, userInput); // get user input
			bool hasMadeGraph = false;
			
			// Determine what to run based on user input
			if(userInput == "1"){
				
				/// create
				string testCase;
				
				cout << "Choose which test to run: " << endl;
				cout << "1. 10" << endl;
				cout << "2. 20" << endl;
				cout << "3. 50" << endl;
				cout << "4. 100" << endl;
				cout << "5. 200" << endl;
			
				getline(cin, testCase);
				
				while(!hasMadeGraph){
					
					if(testCase == "1"){
						
						CSRMat sparseGraph("../Test_Cases/Graph_10.txt", 10);
						hasMadeGraph = true;
						
					} else if(testCase == "2"){
						
						CSRMat sparseGraph("../Test_Cases/Graph_20.txt", 20);
						hasMadeGraph = true;
						
					} else if(testCase == "3"){
					
						CSRMat sparseGraph("../Test_Cases/Graph_50.txt", 50);
						hasMadeGraph = true;
						
					} else if(testCase == "4"){
					
						CSRMat sparseGraph("../Test_Cases/Graph_100.txt", 100);
						hasMadeGraph = true;
					
					} else if(testCase == "5"){
					
						CSRMat sparseGraph("../Test_Cases/Graph_200.txt", 200);
						hasMadeGraph = true;
						
					} else {
					
						cout << "Please make a valid selection for a test case." << endl;
					}
				}
					
				
				
				int year = atoi(insertYear.c_str());
				
				movieTable.insertMovie(insertTitle, year);
				
			} else if(userInput == "2"){
			
				/// 
				
				
			} else if(userInput == "3"){
			
				///
				
			} else if(userInput == "4"){
			
				///
				
			} else if(userInput == "5"){
			
				/// quit program
				cout << "Goodbye!" << endl;
				break;
		}
	}
	
	return 0;
	
	}
}



vector<website> addVectors( vector<website> oldVector , vector<website> newVector ){

	
}
