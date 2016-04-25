#ifndef CSR_H
#define CSR_H
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


class CSR{
	
    public:
        
        Graph(const char* fileName, int sizeOfGraph);
        ~Graph();
        void displayEdges();
        void assignDistricts();
        void shortestPath(std::string startingCity, std::string endingCity);

    protected:
    private:
        
        std::vector <vertex> vertices;
        bool BFTraversalLabel(std::string startingCity, int distID, int index);
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        vertex* searchVertex(std::string cityName);
        void resetGraph();
        long float = 
        int sizeOfMatrix;

};

#endif // CSR.h



