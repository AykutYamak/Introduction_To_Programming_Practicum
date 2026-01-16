#include <iostream>
bool isStepenNa2Rec(int n) {
	if (n==1)
	{
		return true;
	}
	if (n%2==0)
	{
		return isStepenNa2Rec(n / 2);
	}
	return false;
}
int funckiqRec(int n) {
	if (n<=1) 
		return 1; 
	
	return funckiqRec(n - 1) + funckiqRec(n - 2);
}
bool isPalindromRec(const char arr[], int start, int end) {
	if (start>=end)
	{
		return true;
	}
	if (arr[start] != arr[end])
	{
		return false;
	}
	return isPalindromRec(arr, start+1, end-1);
}
void printCollatzSequenceRec(long long n, int step = 0) {
	if (step >= 500) {
		return;
	}
	std::cout << n << " ";
	if (n == 1)
	{
		return;
	}
	if (n%2==0)
	{
		printCollatzSequenceRec(n/2,step+1);
	}
	if (n%2==1)
	{
		printCollatzSequenceRec(3*n+1,step+1);
	}

}
int differenceRec(int arr[],int i, int size)
{
	if (i==size-1)
	{
		return arr[i];
	}

	return differenceRec(arr, i + 1, size) - arr[i];
}
void splitRec(char* const str, char** dest, char delim, int row, int col) {
	if (*str == '\0')
	{
		dest[row][col] = '\0';
		dest[row + 1][0] = '\0';
		return;
	}
	if (*str == delim)
	{
		dest[row][col] = '\0';
		splitRec(str + 1, dest, delim, row + 1, 0);
	}
	else
	{
		dest[row][col] = *str;
		splitRec(str + 1, dest, delim, row, col + 1);
	}
}
//TODO: 5ta zadacha ot faila 12ta sedmica
//void censoreUncensoreString(char* str, int size, int indexWord, int countSpaces) {
//	if (countSpaces == indexWord)
//	{
//
//	}
//}
int recSumOfNumbersTONRec(unsigned int n) {
	if (n == 0)
	{
		return n;
	}
	return n + recSumOfNumbersTONRec(n - 1);
}
int tripleFactorielRec(unsigned n, int i) {
	if (n - 3 * i < 0 || n - 3 * i > 3)
	{
		return n;
	}
	return n * tripleFactorielRec(n - 3 * i, i + 3);
}
int sumOfDigitsRec(int n) {
	if (n == 0)
	{
		return n;
	}
	return n % 10 + sumOfDigitsRec(n / 10);
}

double divisionOnOddIndexRec(int* arr, int i, int size) {
	if (i + 2 >= size - 1)
	{
		return arr[i];
	}
	if (i%2!=0)
	{
		return divisionOnOddIndexRec(arr, i + 2, size) / arr[i];
	}
	return divisionOnOddIndexRec(arr, i + 1, size);
}
void saveMainDiagonalToArray(int matrix [][10], int rows, int cols, int matrix_row, int matrix_col, int* newArray) {
	if (matrix_row >= rows && matrix_col >= cols)
	{
		return;
	}
	newArray[matrix_row] = matrix[matrix_row][matrix_col];
	
	saveMainDiagonalToArray(matrix, rows, cols, matrix_row + 1, matrix_col + 1, newArray);
}
int helperMinElemInArrayJunk(int* arr, int size) {
	if (size == 1)
	{
		return arr[0];
	}
	int min_element = helperMinElemInArrayJunk(arr, size - 1);
	return arr[size - 1] < min_element ? arr[size - 1] : min_element;
}
int sumOfMinElementsInMatrix(int** matrix, int rows, int cols, int matrix_row) {
	if (matrix_row == rows)
	{
		return 0;
	}
	return helperMinElemInArrayJunk(matrix[matrix_row],cols) + sumOfMinElementsInMatrix(matrix,rows,cols,matrix_row+1);
} 
int main()
{
	/*int size;
	std::cin >> size;
	int** matrix = new int* [size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
	std::cout << sumOfMinElementsInMatrix(matrix, size, size, 0);*/

}
