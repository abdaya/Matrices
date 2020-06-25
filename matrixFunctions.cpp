#include "functionSignatures.h"


void Menu() {
	cout << "\t\t1)Summation of 2 Matrices" << endl;
	cout << "\t\t2)Subtraction of 2 Matrices" << endl;
	cout << "\t\t3)Multiplication of 2 Matrices" << endl;
	cout << "\t\t4)Power of a Matrix" << endl;
}

int** allocateMemory(usp l,usp c) {
	int** M = new int* [*l];
		for (int i = 0; i < *l; i++) {
			M[i] = new int[*c];
	    }
	return M;
}

void displayMatrix(int** Matrix, usp l, usp c) {
	for (int i = 0; i < *l; i++) {
		for (int j = 0; j < *c; j++) {
			cout<<Matrix[i][j]<<" ";
		}
		cout << endl;
	}
}
int** fillMatrix(int** M, usp l, usp c) {
	for (int i = 0; i < *l; i++) {
		for (int j = 0; j < *c; j++)
			cin >> M[i][j];
	}
	return M;
}
// ******************* Summation *******************

int** sum2Matrices(usp l,usp c) {
	int** M1, **M2, **M3;
	M1 = allocateMemory(l, c);
	M2 = allocateMemory(l, c);
	M3 = allocateMemory(l, c);
	fillMatrix(M1, l, c);
	fillMatrix(M2, l, c);
	for (int i = 0; i < *l; i++) {
		for (int j = 0; j < *c; j++) {
			M3[i][j] = M1[i][j] + M2[i][j];
		}
	}
	for (int i = 0; i < *l; i++) {
		delete[] M1[i];
		delete[] M2[i];
	}
	delete[] M1;
	delete[] M2;
	M1 = nullptr;
	M2 = nullptr;
	return M3;
}

// ******************* Subtraction *******************

int** sub2Matrices(usp l, usp c) {
	int** M1, ** M2, ** M3;
	M1 = allocateMemory(l, c);
	M2 = allocateMemory(l, c);
	M3 = allocateMemory(l, c);
	fillMatrix(M1, l, c);
	fillMatrix(M2, l, c);
	for (int i = 0; i < *l; i++) {
		for (int j = 0; j < *c; j++) {
			M3[i][j] = M1[i][j] - M2[i][j];
		}
	}
	for (int i = 0; i < *l; i++) {
		delete[] M1[i];
		delete[] M2[i];
	}
	delete[] M1;
	delete[] M2;
	M1 = nullptr;
	M2 = nullptr;
	return M3;
}

// ******************* Multiplication *******************

int** multiplyMatrices(usp l1,usp c1,usp c2) {  // c1 == l2
	int** M1, ** M2, ** M3;
	M1 = allocateMemory(l1, c1);
	M2 = allocateMemory(c1, c2);
	M3 = allocateMemory(l1, c2);
	fillMatrix(M1, l1, c1);
	fillMatrix(M2, c1, c2);

	for (int i = 0; i < *l1; i++) {
		for (int j = 0; j < *c2; j++) {
			int temp = 0;
			for (int m = 0; m < *c1; m++) {
				temp += M1[i][m] * M2[m][j];
			}
			M3[i][j] = temp;
		}
	}
	for (int i = 0; i < *l1; i++) {
		delete[] M1[i];
	}
	for (int i = 0; i < *c1; i++) {
		delete[] M2[i];
	}
	delete[] M1;
	delete[] M2;
	M1 = nullptr;
	M2 = nullptr;
	return M3;
}
//*************************** power of a matrix ****************

int** helpMatrix(int** matrixOriginal, int** matrix,usp l) {
	int** M3 = allocateMemory(l,l);
	for (int i = 0; i < *l; i++) {
		for (int j = 0; j < *l; j++) {
			int temp = 0;
			for (int m = 0; m < *l; m++) {
				temp += matrix[i][m] * matrixOriginal[m][j];
			}
			M3[i][j] = temp;
		}
	}
	matrix = M3;
	M3 = nullptr;
	return matrix;
}

int** powMatrices(usp l, usp p) {
	int** M1, ** M1_Original;
	int loop = 1;
	M1 = allocateMemory(l, l);
	M1_Original = allocateMemory(l, l);
	fillMatrix(M1, l, l);
	M1_Original = M1;
	while (loop < *p) {
		M1 = helpMatrix(M1_Original, M1, l);
		loop++;
	}
	for (int i = 0; i < *l; i++) {
		delete[] M1_Original[i];
	}
	delete[] M1_Original;
	M1_Original = nullptr;
	return M1;
}