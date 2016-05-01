# Renninger_CSCI2270_FinalProject

  This project will implement a CSR Sparse matrix as the basis for a C++ implentation of the 
Google PageRank Algorithm. A web crawler will be used to generate test cases, upon which my PageRank Algorithm will be tested.
The crawler should store a normed, sparse matrix (in COO format) representation of a connectivity matrix (a graph). From there, it will be converted to CSR and its principle eigenvector will be calculated to a set precision using the power method (matrix - vector multiplication) and the PageRank of each item in the test case will be determined. Also included are the Matlab scripts I wrote to generate the test cases. The project is broken up into two large parts:
  
  1) Generating, storing and working  with the CSR connectivity matrix.
      - this essentially involves reading in text files from a crawler in COO format (row, col, value) and storing them as CSR for      fast multiplication.
      - testing the print function is very important, as it is the only way to tell if the right structure is being stored.
      
  2) Using this matrix to calculate and display the respective PageRank of the matrix.
      - need to test that the matrix multiplication work as it should. It is matrix - vector multiplication. This is specific to        calculating eigenvectors only. 
      - this potion was causing undefined behavior up until last few commits, probably still has bugs.
      - the display portion of the eigenvalues needs to be verified that the correct things are being displayed.

HOW TO RUN:
Download the .zip repository and extract it. DO NOT change the file structure. Then, simply open PageRank.cpp, build it, and run it in its native directory. All of the options are included in command prompt menu, and you are only given a few options to ease debugging concerns. In the menu, 1st select a test case size from the onscreen menu (option 1), then choose another option. You will not be able to do anything else until you build up the CSR Matrix from the test case.

- IF YOU ARE USING CODEBLOCKS, build your project inside this folder. Add PageRank.cpp,
  CSRMat.cpp, and CSRMat.h to the project and build it. Make sure to delete the main.cpp that
  is automatically created by codeblocks, as it will give you a multiple definition of main error.

- IF YOU USE A TEXT EDITOR, just compile all of the .cpps in the Src2 folder using the *.cpp command line option.


DEPENDENCIES:
The Project should require no special dependencies. It uses all normally included libraries in standard C++98.

SYSTEM REQUIREMENTS: 
- The program uses no special features of any operating system. The only thing to remember to not do is to chnage the file structure    of the repoistory. Reading in the test cases is dependent on the file structure, and without the test cases, the program is useless.
- If you use codeblocks, make sure to build the project in the Renninger_CSCI2270_FinalProject, otherwise my program will not be able   to find the .txt test cases.

GROUP MEMBERS:
N/A. (I worked alone on this project)

OPEN ISSUES/BUGS
There needs to be a lot more testing done on the PageRank calculation portion of the system. Right now it appears like it is printing correctly, but more testing of the matrix multiplication algorithm would certainly help its believed accuracy. 
- User might be able to run some menu options without first building the CSR Matrix. Can cause crashes.
