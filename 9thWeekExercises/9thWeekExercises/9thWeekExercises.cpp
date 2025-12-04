#include <iostream>
#include <stdbool.h>
void LetterToLower(char& letter) {
	if (letter >= 'A' && letter <= 'Z')
	{
		letter = ('a' + abs(letter - 'A'));
	}
}
void toLower(char* arr) {
	for (int i = 0; arr[i] != '\0'; i++)
	{
		LetterToLower(arr[i]);
	}
}
bool checkIfPangrama(char* arr) {
	for (int i = 0; arr[i]!='\0'; i++)
	{
		LetterToLower(arr[i]);		
	}
	bool checked[26] = { false };
	for (int i = 0; arr[i]!='\0'; i++)
	{
		checked[arr[i] - 'a'] = true;	
	}
	for (int i = 0;i <26 ; i++)
	{
		if (checked[i]!=true)
		{
			return false;
		}
	}
	return true;
	
}

// 'a' + abs(letter - 'A')


int main() {
	char arr[1024];
	std::cin.getline(arr, 1024);
	bool check = checkIfPangrama(arr);
	std::cout << check;

	return 0;
}	