#ifndef CSRMAT_H
#define CSRMAT_H
#include <vector>
#include <iostream>

struct vertex;

struct adjVertex{
    
    vertex *v;
    int weight;
};

struct vertex{
    
    //int ID;
    std::string name;
    int district;
    bool visited;
    int distance;
    std::vector <adjVertex> adj;
    vertex *parent;
    bool solved;
};


class CSRMat{
	
    public:
        
        CSRMat(const char* fileName, int sizeOfGraph, int numOfElems);
        ~CSRMat();
        void addValue(float newValue, int row, int col);
        int sizeOfGraph();
        int *colIndexZeroCols();
        int numOfZeroCols();
        float *multiplyByVector(float importanceRankings[]);
        
        
        void displayEdges();
        void assignDistricts();
        void shortestPath(std::string startingCity, std::string endingCity);

    protected:
    private:
        
        int sizeOfMatrix;
        std::vector <float> values;
        std::vector <int> rowRangeIndex;
        std::vector <int> colIndex;

};

#endif // CSR.h



