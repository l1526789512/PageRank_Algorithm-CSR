#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "CSRMat.h"


using namespace std;

#define POWER_METHOD_TOLERANCE 0.1
#define ALPHA 0.85

/// Functions Used to Calc Principle Eigen Vector
vector<double> addVectors( vector<double> oldVector , vector<double> newVector, double scaling); // use scaling = 1 for addition, -1 for subtraction 
vector<double> oneMultiply( vector<double> inVector, double scaling );
vector<double> normalize( vector<double> inVector );
double avgDifference(vector<double> rankVectorOld, vector<double> rankVectorNew);
vector<double> PowerMethod( CSRMat sparseGraph, vector<double> inVector, int &powerIterations);


int main(){
	
	{
	
		vector<double> rankVector;
		CSRMat sparseGraph;
		bool hasMadeGraph = false;
		int powerIterations = 0;
		
		while(1){
			
			////Diplay Menu
			cout << "======Main Menu======" << endl;
			cout << "1. Create Sparse Graph" << endl;
			cout << "2. Print its contents" << endl;
			cout << "3. Print Size and Analytics of Test Case" << endl;
			cout << "4. Calculate Principle Eigenvector / PageRank Vector" << endl;
			cout << "5. Exit" << endl;
			
			
			string userInput;
			getline(cin, userInput); // get user input
			
			
			// Determine what to run based on user input
			if(userInput == "1"){
				
				hasMadeGraph = false;
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
						//break;
						
					} else if(testCase == "2"){
						
						sparseGraph.buildGraph("../Test_Cases/Graph_20.txt", "../Test_Cases/Graph_20_urls.txt", 20);
						hasMadeGraph = true;
						//break;
						
					} else if(testCase == "3"){
					
						sparseGraph.buildGraph("../Test_Cases/Graph_50.txt", "../Test_Cases/Graph_50_urls.txt", 50);
						hasMadeGraph = true;
						//break;
						
					} else if(testCase == "4"){
					
						sparseGraph.buildGraph("../Test_Cases/Graph_100.txt", "../Test_Cases/Graph_100_urls.txt", 100);
						hasMadeGraph = true;
						//break;
						
					} else if(testCase == "5"){
					
						sparseGraph.buildGraph("../Test_Cases/Graph_200.txt", "../Test_Cases/Graph_200_urls.txt", 200);
						hasMadeGraph = true;
						//break;
						
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
			
				/// Print Size of Test Case
				if(hasMadeGraph){
				
					sparseGraph.printGraphData();
					
				} else {
				
					cout << "Please create graph before trying to print it." << endl;
				}
				
			} else if(userInput == "4"){
			
				/// Calculate Principle Eigenvector / PageRank Vector
				
				std::vector<double> rankVector; // this will be the vector to display, needs initial guess
				int numOfWebsites = sparseGraph.returnSizeOfMat(); // this is the size of the Rankings vector
				
				/// Creating intial guess for rankVector
				for(int i = 0; i < numOfWebsites; i++){
				
					if(i == 0) // start with inital guess of first elem 1, all other elems are 0
						rankVector.push_back(0.5);
					else if (i == 1)
						rankVector.push_back(0.5);
					else
						rankVector.push_back(0);
						
				}
				
				
				/// Doing Power Method on this initial guess, returns the converged principle eigenvector / rankings
				sparseGraph.rankVector = PowerMethod( sparseGraph, rankVector, powerIterations);
				cout << "Power Method Iterations: " << powerIterations << endl;
				//sparseGraph.rankVector = sparseGraph.multiplyByVector(rankVector, 1);
				sparseGraph.printRankings(10);
				
			} else if(userInput == "5"){
			
				/// quit program
				cout << "Goodbye. :(" << endl;
				break;
		
			} else if(userInput == "5"){
			
				/// quit program
				cout << "Goodbye. :(" << endl;
				break;
		}
	}
	
	return 0;
	
	}
}



vector<double> addVectors( vector<double> Vector1 , vector<double> Vector2 , double scaling){

	std::vector<double> outVec; // this is the return vector
	int sizeOfVector = Vector1.size();
	double sum;
	
	for(int i = 0; i < sizeOfVector; i++){
	
		sum = (Vector1[i] + Vector2[i]) * scaling; //add up elems. of two vectors
		outVec.push_back(sum); // append them to the same index of outVec
	}
	
	return outVec;
}



vector<double> oneMultiply( vector<double> inVector, double scaling ){

	int size = inVector.size();
	double sum = 1;
	

	for(int i = 0; i < size; i++){
	
		inVector[i] = sum * scaling; // make every entry of vector the sum of all elems. in it originally
	}
	
	return inVector;
}



vector<double> normalize( vector<double> inVector ){

	
	int size = inVector.size();
	double sum = 0;
	
	
	for(int i = 0; i < size; i++){
	
		sum = sum + inVector[i]; // sum up every elem squared in vector
	}
	
	cout << "sum: " << sum << endl;
	double magnitude = sum; // take the sqaure root of the sum of the squares of each elem.
	
	
	for(int i = 0; i < size; i++){
	
		inVector[i] = inVector[i] / magnitude; // normalize each elem of the vector
	}
	
	
	return inVector;
} 



double avgDifference(vector<double> rankVectorOld, vector<double> rankVectorNew){

	int size = rankVectorOld.size();
	//double sum = 0;
	double avgDiff = 0;
	double tempDiff = 0;
	//vector<double> diffVec = addVectors(rankVectorNew, rankVectorOld, -1); // subtract new from old
	
	for(int i = 0; i < size; i++){
	
		tempDiff = abs(rankVectorNew[i] - rankVectorOld[i]);
		
		if(tempDiff > avgDiff)
			avgDiff = tempDiff;
			
		//sum = abs(sum + diffVec[i]); // sum up all rows in vector
	}
	
	//avgDiff = sum / double(size);
	
	return avgDiff;
}



vector<double> PowerMethod( CSRMat sparseGraph, vector<double> rankVector, int &powerIterations){

	cout << "Entered power method" << endl;

	double diff = 1;
	vector<double> newRankVector = rankVector;
	
	double arraySize = double(sparseGraph.returnSizeOfMat());
	
	/// Constants for two vectors
	double s_const = ALPHA;
	double ones_const = ( 1 - ALPHA ) / arraySize;
	
	cout << "About to enter while loop" << endl;
	
	while(diff > POWER_METHOD_TOLERANCE){
		
		/// Creating Vectors to converge
		cout << "About to create vectors" << endl;

		

		//sparseGraph.printGraphData();
		//cout << "about to vector multiply" << endl;
		std::vector<double> S = sparseGraph.multiplyByVector(rankVector, s_const);
		//S = normalize(S);
		//cout << "About to one multiply" << endl;

		std::vector<double> Ones = oneMultiply(rankVector, ones_const);
		//Ones = normalize(Ones);
		//cout << "About to build and normalize vector" << endl;

		newRankVector = addVectors(S, Ones, 1); // add the two contributions		
		//newRankVector = normalize(newRankVector); // normalize the new vector
		newRankVector = normalize(newRankVector);
		diff = avgDifference(rankVector, newRankVector); // find the average differance between elements of the two vectors
		
		int size = newRankVector.size();
		double sum = 0;
		
		
		
		for(int i = 0; i < size; i++){
		
			sum = sum + newRankVector[i]; // sum up every elem squared in vector
		}
		
		cout << "sum: " << sum << endl;
		rankVector = newRankVector;
		
		powerIterations++;
		cout << "diff: " << diff << endl;

		
	}
	
	
	return rankVector;
}
