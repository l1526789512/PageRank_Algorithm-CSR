#include "CSRMat.h"
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>
#include <fstream>
#include <climits>

using namespace std;

CSRMat::CSRMat(const char* fileNameMat, const char* fileNameURL, int sizeOfGraph){
	
	/// Initialize the graph
	connectivityGraph.rowRangeIndex.push_back(0); // first elem. in row vector of CSR should be 0, as first row starts at 0 index of values vector
	
	
	/// Build the Graph ///
	
	std::ifstream inFileMat(fileNameMat, ifstream::in);
	std::string dataMat;
	
	std::ifstream inFileURL(fileNameURL, ifstream::in);
	std::string dataURL;
	
	
	int count = 0; // keep track of how many lines are read in.
	//bool isFirstTime = false;
	
	/// Reading Graph in
	if(inFileMat.good()){ 
	
		while(getline(inFileMat, dataMat)){
		
			std::stringstream ss(dataMat);
			std::string newSS;
			
		
			if( count == 0 ){ // reading vertexes into graph from first line
			
				/// get first input
			
				std::getline(ss, newSS, ',');
				std::stringstream sizeStream(newSS);
				int sizeOfMatrix;
				sizeStream >> sizeOfMatrix; // set the row / cols of the square matrix (e.g. 10x10 mat would have sizeOfMatrix = 10)
				
				count++;
				
			} else { // creating the sparse matrix
				
				/// pick row out of the stream
				std::getline(ss, newSS, ','); 
				std::stringstream rowStream(newSS);
				int row;
				rowStream >> row;
				
				/// pick col out of stream
				std::getline(ss, newSS, ','); 
				std::stringstream colStream(newSS);
				int column;
				colStream >> column;
				
				/// pick value out of stream
				std::getline(ss, newSS, ','); 
				std::stringstream valueStream(newSS);
				float value;
				valueStream >> value;
				
				
				
				/// Checking if current line contains a new row for CSR storage
				
				int indexOfFirstElem = 2; // initialize 
				
				
				if(count == 1){
					
					//isFirstTime = true;
					indexOfFirstElem = row;
					
				} else {
					
					//isFirstTime = false;
					
					if(row != indexOfFirstElem){
					
						isNewRow =  true;
					}
				} 
				
				addValue(value, row, column, isNewRow); // add the values to the CSR Mat
				
				isNewRow = false; // reset every time newline is read in
				count++;
			}
			
		}	
		
	} else {
	
		std::cout << "This File be bAD :(" << std::endl;
	}
	
	
	numEls = count - 1; // num els in CSR is how many lines were read in (how many non-zero elems there are in the CSR mat)
	
	
	/// reading in the URL names
	
	if(inFileURL.good()){ 
		
			while(getline(inFileURL, dataURL)){
			
				std::stringstream ss(dataURL);
				std::string newSS;
				
		
				std::getline(ss, newSS);
				std::stringstream URLStream(newSS);
				std::string URL;
				getline(URLStream, URL);
				
				connectivityGraph.urlNames.push_back(URL); // add URL to the CSR matrix
				
			}	
			
		} else {
		
			std::cout << "This File be bAD :(" << std::endl;
		}	
	
	
}





CSRMat::~CSRMat(){

	
}



void CSRMat::addValue(float newValue, int row, int col, bool isNewRow){
	
	/// update rowRangeIndex if new row starts
	if(isNewRow){
	
		int newRowIndex = connectivityGraph.values.size(); // the row index of the first elem in next row is simply # elems in current vector
		connectivityGraph.rowRangeIndex.push_back(newRowIndex); // append the above to the row vector
		
	}
	
	connectivityGraph.values.push_back(newValue); // update values
	connectivityGraph.colIndex.push_back(col); // update cols
	
	
}



int CSRMat::sizeOfGraph(){

	return 1;
}


int* CSRMat::colIndexZeroCols(){
	
	int *p = &numEls;
	return p;
}


int CSRMat::numOfZeroCols(){

	return 1;
}


/*
std::vector<website> CSRMat::multiplyByVector(float importanceRankings[], std::vector<website> rankVector){

	
}
*/

void CSRMat::printMatrix(){

	
	
}
