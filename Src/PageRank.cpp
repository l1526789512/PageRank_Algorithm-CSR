#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include "CSRMat.h"


using namespace std;


struct website{
    
    std::string name;
    int ranking;
};

//vector<website> addVectors( vector<website> oldVector , vector<website> newVector );



int main(){
	
	{
	
		vector<website> rankVector;
		CSRMat sparseGraph;
		bool hasMadeGraph = false;
		
		while(1){
			
			////Diplay Menu
			cout << "======Main Menu======" << endl;
			cout << "1. Create Sparse Graph" << endl;
			cout << "2. Print its contents" << endl;
			cout << "3. " << endl;
			cout << "4. " << endl;
			cout << "5. Exit" << endl;
			
			
			string userInput;
			getline(cin, userInput); // get user input
			
			
			// Determine what to run based on user input
			if(userInput == "1"){
				
				sparseGraph.clearContents();
				
				while(!hasMadeGraph){
					
					/// create graph from selected test case
					
					string testCase;
					
					cout << "Choose which test to run: " << endl;
					cout << "1. 10" << endl;
					cout << "2. 20" << endl;
					cout << "3. 50" << endl;
					cout << "4. 100" << endl;
					cout << "5. 200" << endl;
					cout << "6. Go Back" << endl;
				
					getline(cin, testCase);
					
					if(testCase == "1"){
						
						sparseGraph.buildGraph("../Test_Cases/Graph_10.txt", "../Test_Cases/Graph_10_urls.txt", 10);
						hasMadeGraph = true;
						break;
						
					} else if(testCase == "2"){
						
						sparseGraph.buildGraph("../Test_Cases/Graph_20.txt", "../Test_Cases/Graph_20_urls.txt", 20);
						hasMadeGraph = true;
						break;
						
					} else if(testCase == "3"){
					
						sparseGraph.buildGraph("../Test_Cases/Graph_50.txt", "../Test_Cases/Graph_50_urls.txt", 50);
						hasMadeGraph = true;
						break;
						
					} else if(testCase == "4"){
					
						sparseGraph.buildGraph("../Test_Cases/Graph_100.txt", "../Test_Cases/Graph_100_urls.txt", 100);
						hasMadeGraph = true;
						break;
						
					} else if(testCase == "5"){
					
						sparseGraph.buildGraph("../Test_Cases/Graph_200.txt", "../Test_Cases/Graph_200_urls.txt", 200);
						hasMadeGraph = true;
						break;
						
					} else if(testCase == "6"){
					
						break;
					
					} else {
					
						cout << "Please make a valid selection for a test case." << endl;
						
					}
					
				}
				
				
				
				//int year = atoi(insertYear.c_str());
				
				//movieTable.insertMovie(insertTitle, year);
				
			} else if(userInput == "2"){
			
				/// print graph
				if(hasMadeGraph){
				
					sparseGraph.printMatrix();
					
				} else {
				
					cout << "Please create graph before trying to print it." << endl;
				}
				
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


/*
vector<website> addVectors( vector<website> oldVector , vector<website> newVector ){

	
}
*/
