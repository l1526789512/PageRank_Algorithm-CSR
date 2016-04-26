#ifndef CSRMAT_H
#define CSRMAT_H
#include <vector>
#include <iostream>
#include <string>

class CSRMat{
	
	struct website;
	
	
    public:
        
        CSRMat(const char* fileName, int sizeOfGraph);
        ~CSRMat();
        void addValue(float newValue, int row, int col);
        int sizeOfGraph();
        int *colIndexZeroCols();
        int numOfZeroCols();
        std::vector<website> multiplyByVector(float importanceRankings[], std::vector<website> rankVector);

    protected:
    private:
        
        int sizeOfMatrix;
        int numEls;
        int oneOverNumEls;
        std::vector<float> values;
        std::vector<int> rowRangeIndex;
        std::vector<int> colIndex;
        std::vector<std::string> urlNames;

};

#endif // CSR.h



