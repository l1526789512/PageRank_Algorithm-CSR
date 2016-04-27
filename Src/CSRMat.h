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
        std::vector<double> rankVector;
        void printGraphData();
        int numOfZeroCols();
        void printMatrix();
        void buildGraph(const char* fileName, const char* fileNameURL, int sizeOfGraph);
        void clearContents();
        int returnSizeOfMat();
        int returnNumEls();
        //void saveRankVector(std::vector<double> newRankVec);
        std::vector<double> multiplyByVector( std::vector<double> rankVector, double scaling );

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



