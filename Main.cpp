#include "functionSignatures.h"


int main() {
	int** M3;
	unsigned short choice,l,c;
	Menu();
	cout << "Enter your choice : "; cin >> choice;
	switch (choice) {
	case 1: {
		cout << "Enter the Number of lines   : "; cin >> l;
		cout << "Enter the Number of columns : "; cin >> c;
		M3 = sum2Matrices(&l, &c);
		displayMatrix(M3, &l, &c);
	} break;
	case 2: {
		cout << "Enter the Number of lines   : "; cin >> l;
		cout << "Enter the Number of columns : "; cin >> c;
		M3 = sub2Matrices(&l, &c);
		displayMatrix(M3, &l, &c);
	}break;
	case 3: {
		unsigned short l1, c1, l2, c2;
		do {
			cout << "Matrix 1 :" << endl;
			cout << "Enter the Number of lines   : "; cin >> l1;
			cout << "Enter the Number of columns : "; cin >> c1;
			cout << "Matrix 2 :" << endl;
			cout << "Enter the Number of lines   : "; cin >> l2;
			cout << "Enter the Number of columns : "; cin >> c2;
			if (c1 != l2) cout << "ERROR C1 != L2" << endl;
		} while (c1 != l2);

		M3 = multiplyMatrices(&l1, &c1,&c2);
		displayMatrix(M3, &l1, &c2);
	}break;
	case 4: {
		unsigned short p;
		cout << "Enter the Number of lines (it's squared) : "; cin >> l;
		cout << "Enter the power of the matrix            : "; cin >> p;
		M3 = powMatrices(&l,&p);
		displayMatrix(M3, &l,&l);	
	}break;
	default: cout << "The number you've entered is not correct." << endl;
	}
	cin.get();
}