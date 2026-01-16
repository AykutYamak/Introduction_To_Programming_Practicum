#include <iostream>

int tenthExercise(int n) {
	if (n == 1)
	{
		return 1;
	}
	return tenthExercise(n - 1) + tenthExercise(n - 2);
}
int main()
{
	int size;
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
	int indexColumn = size-1;
	for (int i = 0; i < size; i++)
	{
		std::cout << matrix[i][indexColumn] << " ";
		indexColumn -= 1;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl; 
	std::cout << std::endl;

	for (int i = 1; i < size; i++)
	{
		int indexColumn = size - 1;
		while (indexColumn>=size-i-1)
		{
			std::cout << matrix[i][indexColumn] << " ";
			indexColumn--;
		}
		
		
		std::cout << std::endl;
	}

	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}
