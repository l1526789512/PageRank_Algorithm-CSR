#include "CSRMat.h"
#include <iostream>

CSRMat::CSRMat(const char* fileNameMat, const char* fileNameURL, int sizeOfGraph){

	/// Build the Graph ///
	index = 0;
	std::ifstream inFileMat(fileNameMat, ifstream::in);
	std::string dataMat;
	
	std::ifstream inFileURL(fileNameURL, ifstream::in);
	std::string dataURL;
	
	
	int count = 0; // keep track of how many lines are read in.
	
	
	/// Reading Graph in
	if(inFileMat.good()){ 
	
		while(getline(inFileMat, dataMat)){
		
			std::stringstream ss(dataMat);
			std::string newSS;
			
		
			if( count == 0 ){ // reading vertexes into graph from first line
			
				/// get first input
			
				std::getline(ss, newSS, ',');
				std::stringstream cityName(newSS);
				int sizeOfMatrix;
				getline(cityName, sizeOfMatrix);
				
				count++;
				
			} else { // creating the sparse matrix
				
				
					
				
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
	
	
	
	/// reading in the URL names
	
	if(inFileURL.good()){ 
		
			while(getline(inFileURL, dataURL, "\n")){
			
				std::stringstream ss(dataURL);
				std::string newSS;
				
		
				std::getline(ss, newSS);
				std::stringstream cityStream(newSS);
				std::string URL;
				getline(cityStream, URL);
				
				urlNames.push_back(URL)
				
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


