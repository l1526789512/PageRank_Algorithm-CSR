#ifndef CSRMAT_H
#define CSRMAT_H
#include <vector>
#include <iostream>
#include <string>

struct CSRMatrix{

	std::vector<double> values;
	std::vector<int> rowRangeIndex;
	std::vector<int> colIndex;
	std::vector<std::string> urlNames;
};


class CSRMat{
	
	struct website;
	
	
    public:
        
        CSRMat();
        ~CSRMat();
        void printSizeOfGraph();
        int *colIndexZeroCols();
        int numOfZeroCols();
        void printMatrix();
        void buildGraph(const char* fileName, const char* fileNameURL, int sizeOfGraph);
        void clearContents();
        std::vector<website> multiplyByVector(double importanceRankings[], std::vector<website> rankVector);

    protected:
    private:
        
        int sizeOfMatrix;
        int numEls;
        double oneOverNumEls;
        bool isNewRow;
        CSRMatrix connectivityGraph;
        void addValue(double newValue, int row, int col, bool isNewRow);

};

#endif // CSR.h



