#include "CSRMat.h"
#include <iostream>
#include <string>




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
				std::stringstream CSRStream(newSS);
				int row;
				CSRStream >> weight;
				
				std::getline(ss, newSS, ','); // throw away first entry
				std::stringstream CSRStream(newSS);
				int column;
				CSRStream >> weight;
				
				std::getline(ss, newSS, ','); // throw away first entry
				std::stringstream weightStream(newSS);
				float value;
				weightStream >> weight;
				
				addValue(value, row, col)
				
				count++;
			}
			
		}	
		
	} else {
	
		std::cout << "This File be bAD :(" << std::endl;
	}
	
	numEls = count - 1; // num els in CSR is how many lined were read in
	
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


