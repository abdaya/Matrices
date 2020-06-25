#include<iostream>

typedef unsigned short* usp;

using std::cin;
using std::cout;
using std::endl;

void Menu();
int** allocateMemory(usp, usp);
int** sum2Matrices(usp, usp);
int** sub2Matrices(usp, usp);
void displayMatrix(int**, usp, usp);
int** fillMatrix(int**, usp, usp);
int** multiplyMatrices(usp,usp,usp);
int** powMatrices(usp,usp);