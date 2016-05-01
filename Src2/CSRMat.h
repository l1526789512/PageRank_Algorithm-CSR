#ifndef CSRMAT_H
#define CSRMAT_H
#include <vector>
#include <iostream>
#include <string>




class CSRMat{
	
	
	
    public:
        
        CSRMat();
        ~CSRMat();
        std::vector<double> rankVector;
        void printGraphData();
        int numOfZeroCols();
        void printMatrix();
        void printRankings(int numberToPrint);
        bool buildGraph(const char* fileName, const char* fileNameURL, int sizeOfGraph);
        void clearContents();
        int returnSizeOfMat();
        int returnNumEls();
        //void saveRankVector(std::vector<double> newRankVec);
        std::vector<double> multiplyByVector( std::vector<double> rankVector, double scaling );

        struct CSRMatrix{

        std::vector<double> values;
        std::vector<int> rowRangeIndex;
        std::vector<int> colIndex;
        std::vector<std::string> urlNames;
        
        };

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



