#ifndef CSRMAT_H
#define CSRMAT_H
#include <vector>
#include <iostream>


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
        std::vector<float> values;
        std::vector<int> rowRangeIndex;
        std::vector<int> colIndex;

};

#endif // CSR.h



