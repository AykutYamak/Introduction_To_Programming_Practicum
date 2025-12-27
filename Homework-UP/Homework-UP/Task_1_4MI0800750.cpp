#include <iostream>
//hasUniqueDigits()
//checkForBulls()
void intToIntArray(int* arr, int number, int m) {
	for (int i = m-1; i >= 0; i--)
	{
		arr[i] = number % 10;
		number /= 10;
	}
}
int getCountDigits(int number) {
	if (number == 0)
	{
		return 1;
	}
	int count = 0;
	while (number!=0)
	{
		number /= 10;
		count++;
	}
	return count;
}
bool hasUniqueDigits(int number, int m) {
	bool used[10] ={false}; 
	for (int i = 0; i < m; i++) {
		int digit = number % 10;
		if (used[digit]) {
			return false;
		}
		used[digit] = true;
		number /= 10;
	}
	return true;
}
void initSearchSpace(bool* validArray, int max, int m) {
	for (int i = 0; i < max; i++)
	{
		validArray[i] = hasUniqueDigits(i, m);
	}
}
int power(int number, int pow) {
	if (pow == 0)
	{
		return 1;
	}
	int result = 1;
	for (int i = 0; i < pow; i++)
	{
		result *= number;
	}
	return result;
}
bool checkGuess(int* candidate, int* guess, int bulls, int cows, int m) {
	int currBulls = 0;
	int currCows = 0;
	for (int i = 0; i < m; i++)
	{
		if (candidate[i] == guess[i])
		{
			currBulls++;
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i!=j && candidate[i] == guess[j])
			{
				currCows++;
			}
		}
	}
	return (currBulls == bulls && currCows == cows);
}
void resultAndPrint(int** matrix, int n, int m) {
	int max = power(10, m);
	bool* valid = new bool[max];
	initSearchSpace(valid, max, m);
	int* candidateDigits = new int[m];
	for (int i = 0; i < max; i++)
	{
		if (!valid[i])
		{
			continue;
		}
		intToIntArray(candidateDigits, i, m);
		bool canBe = true;
		for (int j = 0; j < n; j++)
		{
			int bulls = matrix[j][m];
			int cows = matrix[j][m + 1];
			
			if (!checkGuess(candidateDigits,matrix[j],bulls,cows,m))
			{
				canBe = false;
				break;
			}
		}
		if (canBe)
		{
			for (int h = 0; h < m; h ++)
			{
				std::cout << candidateDigits[h];
			}
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	delete[] valid;
	delete[] candidateDigits;
}
int main() {
	int m, n;
	std::cout << "Enter value for m: ";
	std::cin >> m;
	std::cin.ignore();
	if (m < 1 || m > 6)
	{
		do
		{
			std::cout << "Invalid input for m!" << std::endl;
			std::cout << "Enter value for m: ";
			std::cin >> m;
			std::cin.ignore();
		} while (m < 1 || m>6);
	}
	std::cout << "Enter value for n: ";
	std::cin >> n;
	std::cin.ignore();
	if (n < 1)
	{
		do
		{
			std::cout << "Invalid input for n!" << std::endl;
			std::cout << "Enter value for n: ";
			std::cin >> n;
			std::cin.ignore();
		} while (n<1);
	}
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m + 2];
	}
	for (int i = 0; i < n; i++)
	{
		int number, bulls, cows;
		std::cin >> number >> bulls >> cows;
		int digits = getCountDigits(number);
		if (digits > m || bulls < 0 || cows < 0 || (bulls+cows) > m)
		{
			std::cout << "Invalid input!" << std::endl;
			i--;
			continue;
		}
		intToIntArray(matrix[i], number, m);
		matrix[i][m] = bulls;
		matrix[i][m + 1] = cows;
	}
	resultAndPrint(matrix, n, m);
	
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}