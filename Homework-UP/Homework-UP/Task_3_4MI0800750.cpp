//#include <iostream>
//int getCountCharactersInWord(char* word) {
//	int count = 0;
//	for (int i = 0; word[i]!='\0'; i++)
//	{
//		count++;
//	}
//	return count;
//}
//int stringCompare(const char* input, const char* comparingString) {
//	int i = 0;
//	while (input[i]!='\0' && comparingString[i]!= '\0')
//	{
//		if (input[i]!= comparingString[i])
//		{
//			return input[i] - comparingString[i];
//		}
//		i++;
//	}
//	return input[i]-comparingString[i];
//}
//bool checkForEndOfInput(const char* input) {
//	int result = stringCompare(input, "$end$");
//	if (result == 0 )
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//void enterText(char** matrix, int rows, int cols) {
//	int i = 0;
//	while(i<rows)
//	{
//		std::cin.getline(matrix[i], cols);
//		if (checkForEndOfInput(matrix[i]))
//		{
//			matrix[i][0] = '\0';
//			i++;
//			break;
//		}
//		i++;
//	}
//	for (int j = i; j < rows; j++)
//	{
//		matrix[i][0] = '\0';
//	}
//}
//int count(char* const* matrix, int rows, int cols) {
//	int count = 0;
//	for (int i = 0; i < rows; i++)
//	{
//		if (matrix[i][0] == '\0')
//		{
//			continue;
//		}
//		bool check = false;
//		for (int j = 0; matrix[i][j]!='\0'; j++)
//		{
//			if (matrix[i][j] != ' ')
//			{
//				if (!check)
//				{
//					count++;
//					check = true;
//				}
//			}
//			else
//			{
//				check = false;
//			}
//		}
//	}
//	return count;
//}
//int countLines(char* const* matrix, int rows, int cols) {
//	int count = 0;
//	for (int i = 0; i < rows; i++)
//	{
//		if (matrix[i][0] == '\0')
//		{
//			break;
//		}
//		for (int j = 0; j < cols; j++)
//		{
//			if (matrix[i][j]!='\0')
//			{
//				count++;
//				break;
//			}
//		}
//	}
//	return count;
//}
//int countLineWords(char* row) {
//	int count = 0;
//	bool check = false;
//	if (row[0] == '\0')
//	{
//		return count;
//	}
//	for (int j = 0; row[j]!='\0'; j++)
//	{
//		if (row[j] != ' ')
//		{
//			if (!check)
//			{
//				count++;
//				check = true;
//			}
//		}
//		else
//		{
//			check = false;
//		}
//	}
//	return count;
//}
//int countWord(char* const* matrix, char* word, int rows, int cols)
//{
//	int wordLength = getCountCharactersInWord(word);
//	int count = 0;
//	for (int i = 0; i < rows; i++)
//	{
//		char* helper = new char[wordLength + 1];
//		int k = 0;
//		for (int j = 0; j < cols; j++)
//		{
//			if (matrix[i][j] == ' ' || matrix[i][j] == '\0')
//			{
//				if (k>0)
//				{
//					helper[k] = '\0';
//					if (stringCompare(helper, word) == 0)
//					{
//						count++;
//					}
//				}
//				k = 0;
//				if (matrix[i][j] == '\0')
//				{
//					break;
//				}
//			}
//			else
//			{
//				if (k < wordLength)
//				{
//					helper[k] = matrix[i][j];
//					k++;
//				}
//			}
//		}
//		delete[] helper;
//	}
//	return count;
//	
//}
//int lineByWord(char* const* matrix, char* word, int i,int rows, int cols) {
//	int wordLength = getCountCharactersInWord(word);
//	int count = 0;
//	for (int h = 0; h < rows; h++)
//	{
//		char* helper = new char[wordLength + 1];
//		int k = 0;
//		for (int j= 0; j < cols; j++)
//		{
//			if (matrix[h][j] == ' ' || matrix[h][j] == '\0')
//			{
//				if (k > 0)
//				{
//					helper[k] = '\0';
//					if (stringCompare(helper, word) == 0)
//					{
//						count++;
//					}
//					if (count == i)
//					{
//						delete[] helper;
//						std::cout << matrix[h] << std::endl;
//						return h + 1;
//					}
//				}
//				k = 0;
//				if (matrix[h][j] == '\0')
//				{
//					break;
//				}
//			}
//			else
//			{
//				if (k < wordLength)
//				{
//					helper[k] = matrix[h][j];
//					k++;
//				}
//			}
//		}
//		delete[] helper;
//	}
//	return -1;
//}
//int lineByMostOccurances(char* const* matrix, char* word, int rows, int cols) {
//	int mostOccurances = 0;
//	int line = 0;
//	int wordLength = getCountCharactersInWord(word);
//	char* helper = new char[wordLength+1];
//	for (int i = 0; i < rows; i++)
//	{
//		int count = 0;
//		int k = 0;
//		for (int j = 0; j < cols; j++)
//		{
//			if (matrix[i][j] == ' ' || matrix[i][j] == '\0')
//			{
//				if (k>0)
//				{
//					helper[k] = '\0';
//					if (stringCompare(helper, word) == 0)
//					{
//						count++;
//					}
//					k = 0;
//				}
//				if (matrix[i][j] == '\0')
//				{
//					break;
//				}
//			}
//			else
//			{
//				if (k<wordLength)
//				{
//					helper[k] = matrix[i][j];
//					k++;
//				}
//			}
//		}
//		if (count > mostOccurances)
//		{
//			mostOccurances = count;
//			line = i + 1;
//		}
//		count = 0;
//	}
//	delete[] helper;
//	if (line == 0)
//	{
//		return -1;
//	}
//	std::cout << matrix[line - 1] << std::endl;
//	return line;
//}
//void printLine(char* const* matrix, int line) {
//	for (int i = 0; matrix[line-1][i]!='\0'; i++)
//	{
//		std::cout << matrix[line - 1][i];
//	}
//	std::cout << std::endl;
//}
//void print(char* const* matrix, int rows) {
//	for (int i = 0; i < rows; i++)
//	{
//		if (matrix[i][0] == '\0')
//		{
//			continue;
//		}
//		for (int j = 0; matrix[i][j] != '\0'; j++)
//		{
//			
//			std::cout << matrix[i][j];
//		}
//		std::cout << std::endl;
//	}
//}
//void removeWord(char** matrix, int rows, int cols, char* word) {
//	char* helper = new char[cols];
//	char* row = new char[cols];
//	for (int i = 0; i < rows; i++)
//	{
//		if (matrix[i][0] == '\0')
//		{
//			continue;
//		}
//		int k = 0;
//		int write = 0;
//		for (int j = 0; matrix[i][j]!='\0'; j++)
//		{
//			if (matrix[i][j] == ' ')
//			{
//				helper[k] = '\0';
//				if (stringCompare(helper,word) != 0)
//				{
//					int h = 0;
//					while (helper[h] != '\0' && write<cols-1)
//					{
//						row[write] = helper[h];
//						write++;
//						h++;
//					}
//					if (write<cols-1)
//					{
//						row[write] = ' ';
//						write++;
//					}
//				}
//				k = 0;
//			}
//			else
//			{
//				if (k<cols-1)
//				{
//					helper[k] = matrix[i][j];
//					k++;
//				}
//				
//			}
//		}
//		helper[k] = '\0';
//		if (stringCompare(helper,word)!=0)
//		{
//			for (int h = 0; helper[h]!='\0'; h++)
//			{
//				if (write<cols-1)
//				{
//					row[write] = helper[h];
//					write++;
//				}
//			}
//			
//		}
//		if (write >= cols)
//		{
//			write = cols - 1;
//		}
//		if (write > 0 && row[write - 1] == ' ')
//		{
//			write--;
//		}
//		row[write] = '\0';
//		int j = 0;
//		while (row[j] != '\0')
//		{
//			matrix[i][j] = row[j];
//			j++;
//		}
//		matrix[i][j] = '\0';
//	}
//	delete[] row;
//	delete[] helper;
//	
//}
//
//void copyStringToMatrix(char** newMatrix, int cols, int rowIndex,int &write, char* word) {
//	int h = 0;
//	while (word[h]!='\0' && write < cols - 1)
//	{
//		newMatrix[rowIndex][write] = word[h];
//		write++;
//		h++;
//	}
//}
//void copyLineToMatrix(char** newMatrix, int cols, int rowIndex, char* newLine) {
//	int h = 0;
//	while (newLine[h]!='\0' && h < cols-1)
//	{
//		newMatrix[rowIndex][h] = newLine[h];
//		h++;
//	}
//	newMatrix[rowIndex][h] = '\0';
//}
//void replaceWord(char** matrix, int rows, int cols, char* word, char* toReplace) {
//	char* helper = new char[cols];
//	char* row = new char[cols];
//	for (int i = 0; i < rows; i++)
//	{
//		if (matrix[i][0]=='\0')
//		{
//			continue;
//		}
//		int k = 0;
//		int write = 0;
//		for (int j = 0; ; j++)
//		{
//			if (matrix[i][j] == ' ' || matrix[i][j] == '\0')
//			{
//				if (k > 0)
//				{
//					helper[k] = '\0';
//					char* target = helper;
//					if (stringCompare(helper, toReplace) == 0)
//					{
//						target = word;
//					}
//					int h = 0;
//					while (target[h] != '\0' && write < cols - 1)
//					{
//						row[write] = target[h];
//						write++;
//						h++;
//					}
//					if (matrix[i][j] == ' ' && write < cols-1)
//					{
//						row[write] = ' ';
//						write++;
//					}
//				}
//				k = 0;
//				if (matrix[i][j]=='\0')
//				{
//					break;
//				}
//			}
//			else
//			{
//				if (k < cols - 1)
//				{
//					helper[k] = matrix[i][j];
//					k++;
//				}
//			}
//		}
//		if (write > 0 && row[write - 1] == ' ')
//		{
//			write--;
//		}
//		row[write] = '\0';
//		int j = 0;
//		while (row[j] != '\0')
//		{
//			matrix[i][j] = row[j];
//			j++;
//		}
//		matrix[i][j] = '\0';
//	}
//	delete[] row;
//	delete[] helper;
//}
//void addLine(char*** matrix, int& rows, int cols, int lineNumber, char* newLine) {
//	if (getCountCharactersInWord(newLine) >= cols)
//	{
//		std::cout << "The new line is way too long!" << std::endl;
//		return;
//	}
//	char** newMatrix = new char*[rows+1];
//	for (int i = 0; i < rows+1; i++)
//	{
//		newMatrix[i] = new char[cols];
//	}
//	for (int i = 0; i < lineNumber-1; i++)
//	{
//		copyLineToMatrix(newMatrix, cols, i, (*matrix)[i]);
//	}
//	copyLineToMatrix(newMatrix, cols, lineNumber-1, newLine);
//	for (int i = lineNumber-1; i < rows; i++)
//	{
//		copyLineToMatrix(newMatrix, cols, i + 1, (*matrix)[i]);
//	}
//	for (int i = 0; i < rows; i++)
//	{
//		delete[](*matrix)[i];
//	}
//	delete[](*matrix);
//	*matrix = newMatrix;
//	rows += 1;
//}
//void changeLine(char** matrix, int& rows, int cols, int lineNumber, char* newLine) {
//	if (lineNumber<1 || lineNumber>rows)
//	{
//		std::cout << "Invalid line number!" << std::endl;
//		return;
//	}
//	if (getCountCharactersInWord(newLine) >= cols)
//	{
//		std::cout << "The new line is way too long!" << std::endl;
//		return;
//	}
//	copyLineToMatrix(matrix,cols,lineNumber-1,newLine);
//}
//void removeLine(char*** matrix, int& rows, int cols, int lineNumber) {
//	if (lineNumber<1 || lineNumber > rows)
//	{
//		std::cout << "Invalid number!" << std::endl;
//		return;
//	}
//	char** newMatrix = new char* [rows-1];
//	for (int i = 0; i < rows-1; i++)
//	{
//		newMatrix[i] = new char[cols];
//	}
//	for (int i = 0; i < lineNumber-1; i++)
//	{
//		copyLineToMatrix(newMatrix, cols, i, (*matrix)[i]);
//	}
//	for (int i = lineNumber; i < rows; i++)
//	{
//		copyLineToMatrix(newMatrix, cols, i-1, (*matrix)[i]);
//	}
//	for (int i = 0; i < rows; i++)
//	{
//		delete[](*matrix)[i];
//	}
//	delete[](*matrix);
//	*matrix = newMatrix;
//	rows -= 1;
//}
//void swapLines(char*** matrix, int rows, int cols, int firstLineNumber, int secondLineNumber) {
//	int indexOne = firstLineNumber - 1;
//	int indexTwo = secondLineNumber - 1;
//	char* buf = (*matrix)[indexOne];
//	(*matrix)[indexOne] = (*matrix)[indexTwo];
//	(*matrix)[indexTwo] = buf;
//}
//void concatLines(char*** matrix, int& rows, int cols, int startLineNumber, int count) {
//	if (startLineNumber > rows || startLineNumber < 1 || count > rows || count < 1)
//	{
//		std::cout << "Invalid input for the line's number or the count!" << std::endl;
//		return;
//	}
//
//	char** newMatrix = new char* [rows - count + 1];
//	int newMatrixIndex = 0;
//	for (int i = 0; i < startLineNumber-1; i++)
//	{
//		newMatrix[newMatrixIndex] = new char[cols];
//		copyLineToMatrix(newMatrix, cols, newMatrixIndex, (*matrix)[i]);
//		newMatrixIndex++;
//	}
//	int totalLength = 0;
//	for (int i = 0; i < count; i++)
//	{
//		totalLength += getCountCharactersInWord((*matrix)[startLineNumber - 1 + i]);
//	}
//	int spaces;
//	if (count>0)
//	{
//		spaces = count - 1;
//	}
//	else
//	{
//		spaces = 0;
//	}
//	char* newRow = new char[totalLength+spaces+1];
//	int newRowIndex = 0;
//	
//	for (int i = 0; i < count; i++)
//	{
//		int currentRowIndex = (startLineNumber - 1) + i;
//		for (int j = 0; (*matrix)[currentRowIndex][j] != '\0';j++)
//		{
//			newRow[newRowIndex] = (*matrix)[currentRowIndex][j];
//			newRowIndex++;
//		}
//		if (i < count - 1)
//		{
//			newRow[newRowIndex] = ' ';
//			newRowIndex++;
//		}
//	}
//	if (newRowIndex>=cols)
//	{
//		newRow[cols-1] = '\0';
//	}
//	else
//	{
//		newRow[newRowIndex] = '\0';
//	}
//	newMatrix[newMatrixIndex] = new char[cols];
//	copyLineToMatrix(newMatrix, cols, newMatrixIndex, newRow);
//	delete[] newRow;
//	newMatrixIndex++;
//
//	for (int i = (startLineNumber-1)+count; i < rows; i++)
//	{
//		newMatrix[newMatrixIndex] = new char[cols];
//		copyLineToMatrix(newMatrix, cols, newMatrixIndex, (*matrix)[i]);
//		newMatrixIndex++;
//	}
//	for (int i = 0; i < rows; i++)
//	{
//		delete[](*matrix)[i];
//	}
//	delete[](*matrix);
//	*matrix = newMatrix;
//	rows = rows - count + 1;
//}
//void splitAt(char*** matrix, int& rows, int cols, int lineNumber, int position) {
//	if (lineNumber > rows || lineNumber < 1 || position > cols || position < 1)
//	{
//		std::cout << "Invalid input for the line's number or position!" << std::endl;
//		return;
//	}
//	char** newMatrix = new char* [rows + 1];
//	int newMatrixIndex = 0;
//	for (int i = 0; i < lineNumber-1; i++)
//	{
//		newMatrix[newMatrixIndex] = new char[cols];
//		copyLineToMatrix(newMatrix, cols, newMatrixIndex, (*matrix)[i]);
//		newMatrixIndex++;
//	}
//	char* firstHalf = new char[cols];
//	int count = 0;
//	int lastIndex = 0;
//	for (int j = 0 ; count < position; j++)
//	{
//		firstHalf[j] = (*matrix)[lineNumber - 1][j];
//		if (firstHalf[j] == ' ')
//		{
//			count++;
//		}
//		lastIndex++;
//	}
//	
//	firstHalf[lastIndex] = '\0';
//	newMatrix[newMatrixIndex] = new char[cols];
//	copyLineToMatrix(newMatrix, cols, newMatrixIndex, firstHalf);
//	delete[] firstHalf;
//	newMatrixIndex++;
//
//	char* secondHalf = new char[cols];
//	int index = 0;
//	for (int i = lastIndex; (*matrix)[lineNumber-1][i]!='\0'; i++)
//	{
//		secondHalf[index] = (*matrix)[lineNumber - 1][i];
//		index++;
//	}
//	secondHalf[index] = '\0';
//	newMatrix[newMatrixIndex] = new char[cols];
//	copyLineToMatrix(newMatrix, cols, newMatrixIndex, secondHalf);
//	newMatrixIndex++;
//	delete[] secondHalf;
//	for (int i = lineNumber; i < rows; i++)
//	{
//		newMatrix[newMatrixIndex] = new char[cols];
//		copyLineToMatrix(newMatrix, cols, newMatrixIndex, (*matrix)[i]);
//		newMatrixIndex++;
//	}
//	for (int i = 0; i < rows; i++)
//	{
//		delete[](*matrix)[i];
//	}
//	delete[](*matrix);
//	*matrix = newMatrix;
//	rows += 1;
//
//}
//void menu() {
//	int n, m;
//	std::cout << "Enter value for N (rows):" << std::endl;
//	do
//	{
//		std::cin >> n;
//		if (n < 1 || n > 100)
//		{
//			std::cout << "The number N should be in the range [1,100]!" << std::endl;
//		}
//		else
//		{
//			break;
//		}
//		std::cout << "Enter again for N:" << std::endl;
//	} while (n < 1 || n > 100);
//	std::cout << "Enter value for M (characters per row):" << std::endl;
//
//	do
//	{
//		std::cin >> m;
//		if (m < 50 || m > 1024)
//		{
//			std::cout << "The number M should be in the range[50,1024]!" << std::endl;;
//		}
//		else
//		{
//			break;
//		}
//		std::cout << "Enter again for M:" << std::endl;
//	} while (m < 50 || m > 1024);
//
//	char** matrix = new char* [n];
//	for (int i = 0; i < n; i++)
//	{
//		matrix[i] = new char[m];
//	}
//	std::cin.ignore();
//
//	std::cout << "Enter the text:" << std::endl;
//	enterText(matrix, n, m);
//
//	std::cout << "Enter a command:" << std::endl;
//	char* input = new char[m];
//	do
//	{
//		std::cin.getline(input, m);
//		if (stringCompare(input, "count") == 0)
//		{
//			std::cout << count(matrix, n, m) << std::endl;
//		}
//		else if (stringCompare(input, "countLines") == 0)
//		{
//			std::cout << countLines(matrix, n, m) << std::endl;
//		}
//		else if (stringCompare(input, "countLineWords") == 0)
//		{
//			int number;
//			std::cout << "Enter the line's number: " << std::endl;
//			std::cin >> number;
//			std::cin.ignore();
//			if (number<1 || number > n)
//			{
//				std::cout << "Invalid line number!" << std::endl;
//			}
//			else
//			{
//				std::cout << "Result: " << countLineWords(matrix[number - 1]) << std::endl;
//			}
//		}
//		else if (stringCompare(input, "countWord") == 0)
//		{
//			char* word = new char[m];
//			std::cout << "Enter the word: " << std::endl;
//			std::cin.getline(word, m);
//			std::cout << "Result: " << countWord(matrix, word, n, m) << std::endl;
//			delete[] word;
//		}
//		else if (stringCompare(input, "lineByWord") == 0)
//		{
//			int repetitionNum;
//			char* word = new char[m];
//			std::cout << "Enter the word: " << std::endl;
//			std::cin.getline(word, m);
//			std::cout << "Enter the repetition number: " << std::endl;
//			std::cin >> repetitionNum;
//			std::cin.ignore();
//			if (repetitionNum < 0)
//			{
//				std::cout << "Invalid input for repetition number!" << std::endl;
//			}
//			else
//			{
//				std::cout << "Line's number: " << lineByWord(matrix, word, repetitionNum, n, m) << std::endl;
//			}
//			delete[] word;
//		}
//		else if (stringCompare(input, "lineByMostOccurances") == 0)
//		{
//			char* word = new char[m];
//			std::cout << "Enter the word: " << std::endl;
//			std::cin.getline(word, m);
//			std::cout << "Line's number: " << lineByMostOccurances(matrix, word, n, m) << std::endl;
//			delete[] word;
//		}
//		else if (stringCompare(input, "printLine") == 0)
//		{
//			int line;
//			std::cout << "Enter line's number: " << std::endl;
//			std::cin >> line;
//			std::cin.ignore();
//			if (line<1 || line > n)
//			{
//				std::cout << "Invalid line number!" << std::endl;
//			}
//			else
//			{
//				printLine(matrix, line);
//			}
//		}
//		else if (stringCompare(input, "print") == 0)
//		{
//			print(matrix, n);
//		}
//		else if (stringCompare(input, "removeWord") == 0)
//		{
//			char* word = new char[m];
//			std::cout << "Enter the word: " << std::endl;
//			std::cin.getline(word, m);
//			if (word[0] == '\0')
//			{
//				std::cout << "Enter a valid word!" << std::endl;
//			}
//			else
//			{
//				removeWord(matrix, n, m, word);
//				std::cout << "Done!" << std::endl;
//			}
//		}
//		else if (stringCompare(input, "replaceWord") == 0)
//		{
//			char* word = new char[m];
//			char* toReplace = new char[m];
//			std::cout << "Enter the new word: " << std::endl;
//			std::cin.getline(word, m);
//			std::cout << "Enter the word you want to replace: " << std::endl;
//			std::cin.getline(toReplace, m);
//			if (word[0] == '\0' || toReplace[0] == '\0')
//			{
//				std::cout << "Invalid input!" << std::endl;
//			}
//			else
//			{
//				replaceWord(matrix, n, m, word, toReplace);
//				std::cout << "Done!" << std::endl;
//			}
//		}
//		else if (stringCompare(input, "addLine") == 0)
//		{
//			int lineNumber;
//			char* newLine = new char[m];
//			std::cout << "Enter line's number: " << std::endl;
//			std::cin >> lineNumber;
//			std::cin.ignore();
//			if (lineNumber <= 0 || lineNumber > n)
//			{
//				do
//				{
//					std::cout << "Invalid input for line's number!" << std::endl;
//					std::cout << "Enter line's number: " << std::endl;
//					std::cin >> lineNumber;
//				} while (lineNumber <= 0 || lineNumber > n);
//				std::cin.ignore();
//			}
//			std::cout << "Enter the new line: " << std::endl;
//			std::cin.getline(newLine, m);
//			if (newLine[0] == '\0')
//			{
//				do
//				{
//					std::cout << "Invalid input for the new line!" << std::endl;
//					std::cout << "Enter the new line: " << std::endl;
//					std::cin.getline(newLine, m);
//				} while (lineNumber <= 0 || lineNumber > n);
//			}
//			addLine(&matrix, n, m, lineNumber, newLine);
//			std::cout << "Done!" << std::endl;
//		}
//		else if (stringCompare(input, "changeLine") == 0)
//		{
//			int lineNumber;
//			char* newLine = new char[m];
//			std::cout << "Enter line's number: " << std::endl;
//			std::cin >> lineNumber;
//			std::cin.ignore();
//			if (lineNumber <= 0 || lineNumber > n)
//			{
//				do
//				{
//					std::cout << "Invalid input for line's number!" << std::endl;
//					std::cout << "Enter line's number: " << std::endl;
//					std::cin >> lineNumber;
//				} while (lineNumber <= 0 || lineNumber > n);
//				std::cin.ignore();
//			}
//			std::cout << "Enter the new line: " << std::endl;
//			std::cin.getline(newLine, m);
//			if (newLine[0] == '\0')
//			{
//				do
//				{
//					std::cout << "Invalid input for the new line!" << std::endl;
//					std::cout << "Enter the new line: " << std::endl;
//					std::cin.getline(newLine, m);
//				} while (lineNumber <= 0 || lineNumber > n);
//			}
//			changeLine(matrix, n, m, lineNumber, newLine);
//			std::cout << "Done!" << std::endl;
//		}
//		else if (stringCompare(input,"removeLine") == 0)
//		{
//			int lineNumber;
//			std::cout << "Enter line's number: " << std::endl;
//			std::cin >> lineNumber;
//			std::cin.ignore();
//			if (lineNumber <= 0 || lineNumber > n)
//			{
//				do
//				{
//					std::cout << "Invalid input for line's number!" << std::endl;
//					std::cout << "Enter line's number: " << std::endl;
//					std::cin >> lineNumber;
//					std::cin.ignore();
//				} while (lineNumber <= 0 || lineNumber > n);
//			}
//			removeLine(&matrix, n, m, lineNumber);
//			std::cout << "Done!" << std::endl;
//		}
//		else if (stringCompare(input,"swapLines") == 0)
//		{
//			int firstNum, secondNum;
//			std::cout << "Enter lines' numbers (firstNum secondNum): " << std::endl;
//			std::cin >> firstNum >> secondNum;
//			std::cin.ignore();
//
//			if (firstNum < 1 || secondNum< 1 || firstNum>n || secondNum > n)
//			{
//				do
//				{
//					std::cout << "Invalid input!" << std::endl;
//					std::cout << "Enter lines' numbers (firstNum secondNum): " << std::endl;
//					std::cin >> firstNum >> secondNum;
//					std::cin.ignore();
//				} while (firstNum <1 || secondNum< 1 || firstNum > n || secondNum > n);
//			}
//			swapLines(&matrix, n, m, firstNum, secondNum);
//			std::cout << "Done!" << std::endl;
//		}
//		else if (stringCompare(input,"concatLines") == 0)
//		{
//			int startLineNumber, count;
//			std::cout << "Enter the start line's number and the count of lines to merge number (startLinesNumber count): " << std::endl;
//			std::cin >> startLineNumber >> count;
//			std::cin.ignore();
//			if (startLineNumber > n || startLineNumber < 1 || count > n || count < 1)
//			{
//				do
//				{
//					std::cout << "Invalid input!" << std::endl;
//					std::cout << "Enter again start line's number and the count: " << std::endl;
//					std::cin >> startLineNumber >> count;
//					std::cin.ignore();
//				} while (startLineNumber > n || startLineNumber < 1 || count > n || count < 1);
//			}
//			concatLines(&matrix, n, m, startLineNumber, count);
//			std::cout << "Done!" << std::endl;
//		}
//		else if (stringCompare(input,"splitAt") == 0)
//		{
//			int linesNumber, position;
//			std::cout << "Enter the line's number and the position of the word (linesNumber position): " << std::endl;
//			std::cin >> linesNumber >> position;
//			std::cin.ignore();
//			if (linesNumber > n || linesNumber< 1 || position > m || position< 1)
//			{
//				do
//				{
//					std::cout << "Invalid input!" << std::endl;
//					std::cout << "Enter again start line's number and the position: " << std::endl;
//					std::cin >> linesNumber >> position;
//					std::cin.ignore();
//				} while (linesNumber > n || linesNumber< 1 || position > m || position < 1);
//			}
//			splitAt(&matrix, n, m, linesNumber, position);
//			std::cout << "Done!" << std::endl;
//		}
//		else
//		{
//			if (stringCompare(input, "exit") == 0)
//			{
//				std::cout << "Bye!";
//				break;
//			}
//			else
//			{
//				std::cout << "Invalid command!" << std::endl;
//			}
//		}
//		std::cout << "Enter a new command:" << std::endl;
//	} while (stringCompare(input, "exit") != 0);
//
//	std::cout << std::endl;
//	std::cout << std::endl;
//	std::cout << std::endl;
//
//	for (int i = 0; i < n; i++)
//	{
//		delete[] matrix[i];
//	}
//	delete[] matrix;
//	delete[] input;
//}
//
//int main()
//
//{
//	menu();
//	return 0;
//}