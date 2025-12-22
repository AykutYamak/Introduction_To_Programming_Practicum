#include <iostream>
int getCountCharactersInWord(char* word) {
	int count = 0;
	for (int i = 0; word[i]!='\0'; i++)
	{
		count++;
	}
	return count;
}
int stringCompare(const char* input, const char* comparingString) {
	int i = 0;
	while (input[i]!='\0' && comparingString[i]!= '\0')
	{
		if (input[i]!= comparingString[i])
		{
			return input[i] - comparingString[i];
		}
		i++;
	}
	return input[i] - comparingString[i];
}
bool checkForEndOfInput(const char* input) {
	int result = stringCompare(input, "$end$");
	if (result == 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}
void enterText(char** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		std::cin.getline(matrix[i], cols);
		if (checkForEndOfInput(matrix[i]))
		{
			break;
		}
	}
}
int count(char** matrix, int rows, int cols) {
	int count = 0;
	for (int i = 0; i < rows; i++)
	{
		if (matrix[i][0] == '\0')
		{
			break;
		}
		for (int j = 0; j < cols; j++)
		{
			if ((matrix[i][j] == ' ' && matrix[i][j+1]!='\0') || matrix[i][j] == '\0')
			{
				count++;
			}
		}
	}
	return count;
}
int countLines(char** matrix, int rows, int cols) {
	int count = 0;
	for (int i = 0; i < rows; i++)
	{
		if (matrix[i][0] == '\0')
		{
			break;
		}
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j]!='\0')
			{
				count++;
				break;
			}
		}
	}
	return count;
}
int countLineWords(char* row) {
	int count = 0;
	if (row[0] == '\0')
	{
		return count;
	}
	for (int j = 0; row[j]!='\0'; j++)
	{
		if (row[j] == ' ')
		{
			count++;
		}
	}
	return count+1;
}
//FIX THIS !!!!!!!!
//int countWord(char** matrix, char* word, int rows, int cols)
//{
//	
//	int count = 0;
//	for (int i = 0; i < rows; i++)
//	{
//		char* helper = new char[getCountCharactersInWord(word) + 1];
//		for (int j = 0; j < cols; j++)
//		{
//			if ((matrix[i][j] == ' ' && matrix[i][j + 1] != '\0') || matrix[i][j] == '\0')
//			{
//				if (stringCompare(helper, word) == 0)
//				{
//					count++;
//					delete[] helper;
//				}
//			}
//			else
//			{
//				helper[j] = matrix[i][j];
//			}
//		}
//		delete[] helper;
//	}
//	return count;
//	
//}
int main()
{
    int n, m;	
	std::cout << "Enter value for N (rows):" << std::endl;
	do
	{
		std::cin >> n;
		if (n<1 || n > 100)
		{
			std::cout << "The number N should be in the range [1,100]!" << std::endl;
		}
		else
		{
			break;
		}
		std::cout << "Enter again for N:" << std::endl;
	} while (n<1 || n > 100);
	std::cout << "Enter value for M (characters per row):" << std::endl;

	do
	{
		std::cin >> m;
		if (m < 50 || m > 1024)
		{
			std::cout << "The number M should be in the range[50,1024]!" << std::endl;;
		}
		else
		{
			break;
		}
		std::cout << "Enter again for M:" << std::endl;
	} while (m < 50 || m > 1024);

	char** matrix = new char*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new char[m];
	}
	std::cin.ignore();

	std::cout << "Enter the text:" << std::endl;
	enterText(matrix,n,m);
	
	std::cout << "Enter a command:" << std::endl;
	char* input = new char[m];
	do
	{
		std::cin.getline(input, m);
		if (stringCompare(input,"count") == 0)
		{
			std::cout << count(matrix, n, m) << std::endl;
		}
		else if (stringCompare(input,"countLines") == 0)
		{
			std::cout << countLines(matrix, n, m) << std::endl;
		}
		else if (stringCompare(input,"countLineWords") == 0)
		{
			int number;
			std::cout << "Enter the line's number: " << std::endl;
			std::cin >> number;
			std::cin.ignore();
			std::cout << "Result: " << countLineWords(matrix[number - 1]) << std::endl;
		}
		/*else if (stringCompare(input,"countWord") == 0)
		{
			char* word = new char[m];
			std::cout << "Enter the word: " << std::endl;
			std::cin.getline(word, m);
			std::cout << "Result: " << countWord(matrix,word,n,m) << std::endl;
			std::cin.ignore();
		}*/
		else
		{
			if (stringCompare(input, "exit") == 0)
			{
				std::cout << "Bye!";
			}
			else
			{
				std::cout << "Invalid command!" << std::endl;
			}
		}
		std::cout << "Enter a new command:" << std::endl;
	} while (stringCompare(input,"exit")!=0);



	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] input;
}