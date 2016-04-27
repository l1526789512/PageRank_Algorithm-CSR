#include "CSRMat.h"
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>
#include <fstream>
#include <climits>

using namespace std;

CSRMat::CSRMat(){
	
	/// Initialize the graph
	connectivityGraph.rowRangeIndex.push_back(0); // first elem. in row vector of CSR should be 0, as first row starts at 0 index of values vector
	
}




CSRMat::~CSRMat(){

	
}




void CSRMat::addValue(double newValue, int row, int col, bool isNewRow){
	
	/// update rowRangeIndex if new row starts
	if(isNewRow){
	
		int newRowIndex = connectivityGraph.values.size(); // the row index of the first elem in next row is simply # elems in current vector
		connectivityGraph.rowRangeIndex.push_back(newRowIndex); // append the above to the row vector
		
	}
	
	connectivityGraph.values.push_back(newValue); // update values
	connectivityGraph.colIndex.push_back(col); // update cols
	
	
}




void CSRMat::printGraphData(){

	cout << "The size of the test case is a: " << sizeOfMatrix << " x " << sizeOfMatrix << " connectivity matrix with a URL root of: http://www.harvard.edu" << endl;
	cout << "The number of non-zero elements in the test CSR Matrix is: " << numEls << endl;
	cout << "The number of dangling nodes is: " << numOfZeroCols() << endl;
	cout << "The dangling node jumping probability is: " << oneOverNumEls << endl;
	
}




int CSRMat::numOfZeroCols(){

	
	int zeroColsCount = 0;
	bool hasVisitedNonZeroRow = false;
	
	for(int index = 0; index < connectivityGraph.rowRangeIndex.size(); index++){ // go through row list
		
		for(int j = connectivityGraph.rowRangeIndex[index - 1]; j < connectivityGraph.rowRangeIndex[index]; j++){ // print values in range specified by range vector
			
			if(connectivityGraph.values[j] == oneOverNumEls){
				
				hasVisitedNonZeroRow = true;
				zeroColsCount++;
	
			}
			
		}
		
		if(hasVisitedNonZeroRow)
			break; // only count cols in 1st row, if you keep counting them on each row you'll get duplicates
	}
	
	return zeroColsCount;
}



/*
std::vector<website> CSRMat::multiplyByVector(double importanceRankings[], std::vector<website> rankVector){

	
}
*/



void CSRMat::printMatrix(){
	
	//int index = 1; // for printing row indexes
	int numElemsInRow;
	
	for(int index = 0; index < connectivityGraph.rowRangeIndex.size(); index++){ // go through row list
		
		for(int j = connectivityGraph.rowRangeIndex[index - 1]; j < connectivityGraph.rowRangeIndex[index]; j++){ // print values in range specified by range vector
			
			numElemsInRow = connectivityGraph.rowRangeIndex[index] - connectivityGraph.rowRangeIndex[index - 1];
			
			cout << "Row: " << index << " Column: " << connectivityGraph.colIndex[j] << " Value: " << connectivityGraph.values[j] 
			<< " -- Number of Non-Zero Elements in Row: " << numElemsInRow << endl;
		}
	}
		
	
	
}




void CSRMat::clearContents(){

	connectivityGraph.values.clear();
	connectivityGraph.rowRangeIndex.clear();
	connectivityGraph.colIndex.clear();
	connectivityGraph.urlNames.clear();
	
	CSRMat(); // call constructor here;
}




void CSRMat::buildGraph(const char* fileNameMat, const char* fileNameURL, int sizeOfGraph){

	/// Build the Graph ///
	
	std::ifstream inFileMat(fileNameMat, ifstream::in);
	std::string dataMat;
	
	std::ifstream inFileURL(fileNameURL, ifstream::in);
	std::string dataURL;
	
	
	int count = 0; // keep track of how many lines are read in.
	int currentRow = 0; // initialize 
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
				double value;
				valueStream >> value;
				
				
				
				/// Checking if current line contains a new row for CSR storage
				
				
				if(count == 1 && row == currentRow){
					
					//isFirstTime = true;
					currentRow = row;
					
				} else if( count == 1 && row != currentRow ){
					
					if( (currentRow + 1) == row ){ // no row of zeros
					
						currentRow = row; // set currentRow to the current row
						isNewRow =  true;
						
					} else { // row of all zeros preceeds current row
					
						currentRow = row; // set currentRow to the current row
						int newRowIndex = connectivityGraph.values.size(); // the row index of the first elem in next row is simply # elems in current vector
						connectivityGraph.rowRangeIndex.push_back(newRowIndex); // append the above to the row vector
						
					}
					
					
					
				} else {
					
					//isFirstTime = false;
					
					if(row != currentRow){ // if now reading in values from new row
						
						currentRow = row; // set currentRow to the current row
						isNewRow =  true;
						
					}
				} 
				
				addValue(value, row, column, isNewRow); // add the values to the CSR Mat
				
				isNewRow = false; // reset every time newline is read in
				count++;
			}
			
			
			
		}
		
		/// VERY IMPORTANT - tells where the last row ends
		int newRowIndex = connectivityGraph.values.size(); // the row index of the first elem in next row is simply # elems in current vector
		connectivityGraph.rowRangeIndex.push_back(newRowIndex); // append the above to the row vector	
		
	} else {
	
		std::cout << "This File be bAD :(" << std::endl;
	}
	
	
	numEls = count - 1; // num els in CSR is how many lines were read in (how many non-zero elems there are in the CSR mat)
	oneOverNumEls = 1 / double(sizeOfMatrix);
	
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
