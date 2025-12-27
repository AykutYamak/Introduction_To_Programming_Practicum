#include <iostream>
#include <random>
#include <stdlib.h>
int power(int number, int power) {
	int result = 1;
	for (int i = 0; i < power; i++)
	{
		result *= number;
	}
	return result;
}
bool checkForWin(int** matrix, int size, int number) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matrix[i][j] == number)
			{
				return true;
			}
		}
	}
	return false;
}
int getLength(const char* input) {
	int count = 0;
	for (int i = 0; input[i] != '\0'; i++)
	{
		count++;
	}
	return count;
}

bool stringCompare(const char* input, const char* toCompare) {
	int lengthInput = getLength(input);
	int lengthToCompare = getLength(toCompare);
	int i = 0;
	if (lengthInput != lengthToCompare)
	{
		return false;
	}
	while (input[i] != '\0' || toCompare[i] != '\0')
	{
		if (input[i] != toCompare[i])
		{
			return false;
		}
		i++;
	}
	return true;
}
bool isValidCommand(char* command) {
	if (!stringCompare(command,"Start Game") && !stringCompare(command,"Settings") && !stringCompare(command,"Quit"))
	{
		return false;
	}
	return true;
}

void printMatrix(int** matrix, int size) {
	std::cout << "Current board:" << std::endl;
	std::cout << " ";
	for (int k = 0; k < size; k++) std::cout << "-----";
	std::cout << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << "|"; 
		for (int j = 0; j < size; j++)
		{
			if (matrix[i][j] < 10)        std::cout << "  " << matrix[i][j] << " |";
			else if (matrix[i][j] < 100)  std::cout << " " << matrix[i][j] << " |";
			else if (matrix[i][j] < 1000) std::cout << " " << matrix[i][j] << "|";
			else                          std::cout << matrix[i][j] << "|";
		}
		std::cout << std::endl;
		std::cout << " ";
		for (int k = 0; k < size; k++) std::cout << "-----";
		std::cout << std::endl;
	}
}
void spawnNewNumberInMatrix(int** matrix, int size) {
	int emptyPlace = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matrix[i][j] == 0)
			{
				emptyPlace++;
			}
		}
	}
	if (emptyPlace == 0)
	{
		return;
	}
	int randomPlaceIndex = std::rand() % emptyPlace;

	int value = (std::rand() % 100 < 90) ? 2 : 4;
	int currEmptyIndex = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matrix[i][j] == 0)
			{
				if (currEmptyIndex == randomPlaceIndex)
				{
					matrix[i][j] = value;
					return;
				}
				currEmptyIndex++;
			}
		}
	}
}
bool moveLeft(int** matrix, int size) {
	bool moved = false;
	for (int i = 0; i < size; i++)
	{
		int* row = new int[size];

		int position = 0;
		for (int j = 0; j < size; j++)
		{
			if (matrix[i][j] != 0)
			{
				row[position] = matrix[i][j];
				position++;
			}
		}
		while (position<size)
		{
			row[position] = 0;
			position++;
		}
		for (int j = 0; j < size-1; j++)
		{
			if (row[j]!=0 && row[j] == row[j+1])
			{
				row[j] *= 2;
				row[j + 1] = 0;
				j++;
			}
		}
		position = 0;
		for (int j = 0; j < size; j++)
		{
			if (row[j] != 0)
			{
				if (matrix[i][position]!=row[j])
				{
					moved = true;
				}
				matrix[i][position] = row[j];
				position++;
			}
		}
		while (position<size)
		{
			if (matrix[i][position] != 0)
			{
				moved = true;
			}
			matrix[i][position] = 0;
			position++;
		}
		delete[] row;
	}
	return moved;
}
bool moveRight(int** matrix, int size) {
	bool moved = false;
	for (int i = 0; i < size; i++)
	{
		int* row = new int[size];
		int position = 0;
		for (int j = size - 1; j >= 0; j--)
		{
			if (matrix[i][j] != 0)
			{
				row[position] = matrix[i][j];
				position++;
			}
		}
		while (position < size)
		{
			row[position] = 0;
			position++;
		}
		for (int j = 0; j < size - 1; j++)
		{
			if (row[j] != 0 && row[j] == row[j + 1])
			{
				row[j] *= 2;
				row[j + 1] = 0;
				j++;
			}
		}
		int* finalRow = new int[size];
		int p = 0;
		for (int j = 0; j < size; j++)
		{
			if (row[j] != 0)
			{
				finalRow[p] = row[j];
				p++;
			}
		}
		while (p < size)
		{
			finalRow[p] = 0;
			p++;
		}

		for (int j = 0; j < size; j++)
		{
			int targetIndex = size - 1- j;
			if (matrix[i][targetIndex] != finalRow[j])
			{
				moved = true;
			}
			matrix[i][targetIndex] = finalRow[j];
		}
		delete[] row;
		delete[] finalRow;
	}
	return moved;
}
bool moveDown(int** matrix, int size) {
	bool moved = false;
	for (int j = 0; j < size; j++)
	{
		int* col = new int[size];
		int position = 0;
		for (int i = size - 1; i >= 0; i--)
		{
			if (matrix[i][j] != 0)
			{
				col[position] = matrix[i][j];
				position++;
			}
		}
		while (position < size)
		{
			col[position] = 0;
			position++;
		}
		for (int j = 0; j < size - 1; j++)
		{
			if (col[j] != 0 && col[j] == col[j + 1])
			{
				col[j] *= 2;
				col[j + 1] = 0;
				j++;
			}
		}
		int* finalCol = new int[size];
		int p = 0;
		for (int i = 0; i < size; i++)
		{
			if (col[i]!= 0)
			{
				finalCol[p] = col[i];
				p++;
			}
		}
		while (p<size)
		{
			finalCol[p] = 0;
			p++;
		}
		for (int i = 0; i < size; i++)
		{
			int row = size - 1 - i;
			if (matrix[row][j]!=finalCol[i])
			{
				moved = true;
			}
			matrix[row][j] = finalCol[i];
		}
		delete[] col;
		delete[] finalCol;
	}
	return moved;

}
bool moveUp(int** matrix, int size) {
	bool moved = false;
	for (int j = 0; j < size; j++)
	{
		int* col = new int[size];
		int position = 0;
		for (int i = 0; i < size; i++)
		{
			if (matrix[i][j] != 0)
			{
				col[position] = matrix[i][j];
				position++;
			}
		}
		while (position < size)
		{
			col[position] = 0;
			position++;
		}
		for (int i = 0; i < size - 1; i++)
		{
			if (col[i] != 0 && col[i] == col[i + 1])
			{
				col[i] *= 2;
				col[i + 1] = 0;
				j++;
			}
		}
		int* finalCol = new int[size];
		int p = 0;
		for (int i = 0; i < size; i++)
		{
			if (col[i]!=0)
			{
				finalCol[p] = col[i];
				p++;
			}
		}
		while (p<size)
		{
			finalCol[p] = 0;
			p++;
		}
		for (int i = 0; i < size; i++)
		{
			if (matrix[i][j]!=finalCol[i])
			{
				moved = true;
			}
			matrix[i][j] = finalCol[i];
		}
		delete[]col;
		delete[]finalCol;
	}
	return moved;
}
bool checkForLoss(int** matrix, int size) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matrix[i][j] == 0)
			{
				return false;
			}
			if (j+1<size)
			{
				if (matrix[i][j] == matrix[i][j+1])
				{
					return false;
				}
			}
			if (i+1<size)
			{
				if (matrix[i][j] == matrix[i+1][j])
				{
					return false;
				}
			}
		}
	}
	return true;
}
int main() {
	char* direction = new char[6];
	char* command = new char[11];
	int n = 4, k = 11;
	do
	{
		std::cout << "Menu:" << std::endl;
		std::cout << "Start Game" << std::endl;
		std::cout << "Settings" << std::endl;
		std::cout << "Quit" << std::endl;
		std::cout << "Enter a command: ";
		std::cin.getline(command, 11);
		while (!isValidCommand(command)) {
			std::cout << "Invalid command! Try again: ";
			std::cin.getline(command, 11);
		}
		system("cls");
		if (stringCompare(command, "Settings"))
		{
			std::cout << "Enter number for the table's size between 3 and 20: ";

			std::cin >> n;
			std::cin.ignore();
			if (n < 3 || n>20)
			{
				do
				{
					std::cout << "Invalid input!" << std::endl;
					std::cout << "Enter again: ";
					std::cin >> n;
					std::cin.ignore();
				} while (n < 3 || n>20);
			}
			std::cout << "Enter target for the end of the game: ";
			std::cin >> k;
			std::cin.ignore();
			if (k < 4 || k>31)
			{
				do
				{
					std::cout << "Invalid input!" << std::endl;
					std::cout << "Enter again: ";
					std::cin >> k;
					std::cin.ignore();
				} while (k < 3 || k>20);
			}
		}
		else if (stringCompare(command, "Start Game"))
		{
			int** matrix = new int* [n];
			for (int i = 0; i < n; i++)
			{
				matrix[i] = new int[n];
				for (int j = 0; j < n; j++)
				{
					matrix[i][j] = 0;
				}
			}
			spawnNewNumberInMatrix(matrix, n);
			spawnNewNumberInMatrix(matrix, n);
			system("cls");
			bool isPlaying = true;
			while(isPlaying)
			{
				printMatrix(matrix, n);
				std::cout << "Enter direction: ";
				std::cin.getline(direction,6);
				if (stringCompare(direction,"Quit"))
				{
					std::cout << "Type 'Quit' if you want to stop the game: ";
					std::cin.getline(command,11);
					isPlaying = false;
					break;
				}
				if (stringCompare(direction,"left"))
				{
					bool done = moveLeft(matrix, n);
					if (done)
					{
						spawnNewNumberInMatrix(matrix, n);
						if (checkForWin(matrix, n, power(2, k)))
						{
							std::cout << "YOU WON!" << std::endl;
							std::cout << "Press Enter to return to menu...";
							std::cin.ignore();
							break;
						}
						else if (checkForLoss(matrix, n))
						{
							std::cout << "GAME OVER! No more moves available." << std::endl;
							std::cout << "Press Enter to return to menu...";
							std::cin.ignore();
							break;
						}
					}
				}
				else if (stringCompare(direction,"right"))
				{
					bool done = moveRight(matrix, n);
					if (done)
					{
						spawnNewNumberInMatrix(matrix, n);
						if (checkForWin(matrix, n, power(2, k)))
						{
							std::cout << "YOU WON!" << std::endl;
							std::cout << "Press Enter to return to menu...";
							std::cin.ignore();
							break;
						}
						else if (checkForLoss(matrix,n))
						{
							std::cout << "GAME OVER! No more moves available." << std::endl;
							std::cout << "Press Enter to return to menu...";
							std::cin.ignore();
							break;
						}
					}
				}
				else if (stringCompare(direction,"up"))
				{
					bool done = moveUp(matrix, n);
					if (done)
					{
						spawnNewNumberInMatrix(matrix, n);
						if (checkForWin(matrix, n, power(2, k)))
						{
							std::cout << "YOU WON!" << std::endl;
							std::cout << "Press Enter to return to menu...";
							std::cin.ignore();
							break;
						}
						else if (checkForLoss(matrix, n))
						{
							std::cout << "GAME OVER! No more moves available." << std::endl;
							std::cout << "Press Enter to return to menu...";
							std::cin.ignore();
							break;
						}
					}
				}
				else if (stringCompare(direction,"down"))
				{
					bool done = moveDown(matrix, n);
					if (done)
					{
						spawnNewNumberInMatrix(matrix, n);
						if (checkForWin(matrix, n, power(2, k)))
						{
							std::cout << "YOU WON!" << std::endl;
							std::cout << "Press Enter to return to menu...";
							std::cin.ignore();
							break;
						}
						else if (checkForLoss(matrix, n))
						{
							std::cout << "GAME OVER! No more moves available." << std::endl;
							std::cout << "Press Enter to return to menu...";
							std::cin.ignore();
							break;
						}
					}
				}
				system("cls");
			} 
			if (matrix != nullptr)
			{
				for (int i = 0; i < n; i++)
				{
					delete[] matrix[i];
				}
				delete[] matrix;
			}
		}
	} while (!stringCompare(command,"Quit"));
	
	delete[] direction;
	delete[] command;
}