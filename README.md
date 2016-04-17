# Renninger_CSCI2270_FinalProject

This project will implement a CSR Sparse matrix as the basis for a C++ implentation of the 
Google PageRank Algorithm. A web crawler will be used to generate test cases, upon which my PageRank Algorithm will be tested.
The crawler should store a normed, sparse matrix (in CSR format) representation of a connectivity matrix (a graph). From there, its 
eigenvalues will be calculated to a set precision using the power method (matrix - vector multiplication) and the PageRank of each 
item in the test case will be determined.
