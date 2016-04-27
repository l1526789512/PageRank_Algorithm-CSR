#ifndef CSRMAT_H
#define CSRMAT_H
#include <vector>
#include <iostream>
#include <string>

struct CSRMatrix{

	std::vector<float> values;
	std::vector<int> rowRangeIndex;
	std::vector<int> colIndex;
	std::vector<std::string> urlNames;
};


class CSRMat{
	
	struct website;
	
	
    public:
        
        CSRMat(const char* fileName, const char* fileNameURL, int sizeOfGraph);
        ~CSRMat();
        int sizeOfGraph();
        int *colIndexZeroCols();
        int numOfZeroCols();
        void printMatrix();
        std::vector<website> multiplyByVector(float importanceRankings[], std::vector<website> rankVector);

    protected:
    private:
        
        int sizeOfMatrix;
        int numEls;
        int oneOverNumEls;
        int indexOfFirstElemInSparse;
        bool isNewRow;
        CSRMatrix connectivityGraph;
        void addValue(float newValue, int row, int col, bool isNewRow);

};

#endif // CSR.h



