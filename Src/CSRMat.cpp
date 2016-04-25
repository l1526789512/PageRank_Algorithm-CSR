#include "CSRMat.h"
#include <iostream>

CSRMat::CSRMat(const char* fileName, int sizeOfGraph){

	/// Build the Graph ///
	index = 0;
	std::ifstream inFile(filename, ifstream::in);
	std::string data;
	//inFile.open(fileName);
	
	int count = 0; // start as -1, so by the time read 2nd line, can use 0 index of cities[]
	
	std::string names[15]; // array to hold the names of all of the 
	int weights[15]; // array to hold the weights of edges for every line
		
		
	if(inFile.good()){
	
		while(getline(inFile, data)){
		
			std::stringstream ss(data);
			std::string newSS;
			
			if( count == 0 ){ // reading vertexes into graph from first line
			
				/// ignore first input
				std::getline(ss, newSS, ',');
				std::stringstream cityName(newSS);
				std::string name;
				getline(cityName, name);
				
				for(int i = 0; i < 10; i++){ // add all verticies
					
					std::getline(ss, newSS, ',');
					std::stringstream cityStream(newSS);
					getline(cityStream, names[i]);
					Graph::addVertex(names[i]);
				}
				
				count++;
				
			} else { // creating the edges based on weights
				
				/// ignore first input
				std::getline(ss, newSS, ','); // throw away first entry
				std::stringstream weightStream(newSS);
				int weight;
				weightStream >> weight;
				
				for(int i = 0; i < 10; i++){ // now add edges whenever number is > 0
				
					std::getline(ss, newSS, ',');
					std::stringstream weightStream(newSS);
					weightStream >> weights[i];
					
					if(weights[i] > 0){ // only add the edge to graph is weight is greater than 0
						//cout << "1: " << names[count - 1] << " 2: " << names[i] << " 3: " << weights[i] << std::endl;
						Graph::addEdge(names[count - 1], names[i], weights[i]); // add the weight at the row (count) and column (i) of the non-zero weight
					}
				}
				
				count++;
			}
		}	
		
	} else {
	
		std::cout << "This File be bAD :(" << std::endl;
	}
}





CSRMat::~CSRMat(){

	
}



CSRMat::void addValue(float newValue, int row, int col){

	
}



CSRMat::int sizeOfGraph(){

	
}


CSRMat::int *colIndexZeroCols(){

	
}


CSRMat::int numOfZeroCols(){

	
}


CSRMat::std::vector<website> multiplyByVector(float importanceRankings[], std::vector<website> rankVector){

	
}


