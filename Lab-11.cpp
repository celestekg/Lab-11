//Celeste Going
//Lab 11
/*This program uses two-dimensional arrays to analyze
matrices and determine if they are a "magic square," or
a matrix in which the sum of each row, column, main diagonal,
and reverse diagonal all equal the same value. The program
then prints the matrix, along with the sum of each row, column,
main diagonal, and reverse diagonal. The program will
continue to anaylze matrices until it reaches a size of -1.*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void readData(ifstream& infile, int** mat, int size);
void printMatrix(int** mat, int size);

int rowSumByIndex(int** mat, int size, int index);
int columnSumByIndex(int** mat, int size, int index);
int mainDiagonalSum(int** mat, int size);
int otherDiagonalSum(int** mat, int size);

bool isMagicSquare(int** mat, int size);

int main()
{
	ifstream infile;
	infile.open("data.txt");

	if (!infile)
	{
		cout << "Input file cannot be opened!" << endl;
		return 1;
	}

	int size;
	int count = 0;

	infile >> size;

	while (size != -1)
	{
		count++;

		int** mat = new int* [size];
		for (int i = 0; i < size; i++)
			mat[i] = new int[size];

		readData(infile, mat, size);

		cout << "============" << endl;
		cout << "= Square " << count << " =" << endl;
		cout << "============" << endl;

		printMatrix(mat, size);
		cout << endl;

		for (int i = 0; i < size; i++)
		{
			cout << "The sum of the row " << i << " is " << rowSumByIndex(mat, size, i) << endl;
		}
		cout << endl;

		for (int i = 0; i < size; i++)
		{
			cout << "The sum of the column " << i << " is " << columnSumByIndex(mat, size, i) << endl;
		}
		cout << endl;

		cout << "The sum of the main diagonal is " << mainDiagonalSum(mat, size) << endl;
		cout << "The sum of the reverse diagonal is " << otherDiagonalSum(mat, size) << endl;
		cout << endl;

		if (isMagicSquare(mat, size))
			cout << "This matrix is a magic box!" << endl;
		else
			cout << "This matrix is not a magic box!" << endl;
		cout << endl << endl;

		for (int i = 0; i < size; i++)
			delete[] mat[i];
		delete[] mat;

		infile >> size;
	}

	infile.close();

	return 0;
}

void readData(ifstream& infile, int** mat, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			infile >> mat[i][j];
		}
	}
}

void printMatrix(int** mat, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
}

int rowSumByIndex(int** mat, int size, int index)
{
	int total = 0;

	for (int j = 0; j < size; j++)
	{
		total += mat[index][j];
	}

	return total;
}

int columnSumByIndex(int** mat, int size, int index)
{
	int total = 0;

	for (int i = 0; i < size; i++)
	{
		total += mat[i][index];
	}

	return total;
}

int mainDiagonalSum(int** mat, int size)
{
	int total = 0;

	for (int i = 0; i < size; i++)
	{
		total += mat[i][i];
	}

	return total;
}

int otherDiagonalSum(int** mat, int size)
{
	int total = 0;

	for (int i = 0; i < size; i++)
	{
		total += mat[i][size - 1 - i];
	}

	return total;
}

bool isMagicSquare(int** mat, int size)
{
	int rowSum1 = rowSumByIndex(mat, size, 0);

	for (int i = 1; i < size; i++)
	{
		int rowSum2 = rowSumByIndex(mat, size, i);

		if (rowSum1 != rowSum2)
			return false;
	}

	int columnSum1 = columnSumByIndex(mat, size, 0);

	if (rowSum1 != columnSum1)
		return false;

	for (int i = 1; i < size; i++)
	{
		int columnSum2 = columnSumByIndex(mat, size, i);

		if (columnSum1 != columnSum2)
			return false;
	}

	int mainDiagonal = mainDiagonalSum(mat, size);

	if (rowSum1 != mainDiagonal)
		false;

	int otherDiagonal = otherDiagonalSum(mat, size);

	if (mainDiagonal != otherDiagonal)
		return false;

	return true;
}