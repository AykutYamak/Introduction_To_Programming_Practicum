#include <iostream>
#include <stdbool.h>
int strLen(char* arr) {
	int count = 0;
	for (int i = 0; arr[i]!='\0'; i++)
	{
		count++;
	}
	return count;
}
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
bool isPangrama(char* arr) {
	for (int i = 0; arr[i]!='\0'; i++)
	{
		LetterToLower(arr[i]);
	}
	bool checked[26] = { false };
	for (int i = 0; arr[i]!='\0'; i++)
	{
		checked[arr[i] - 'a'] = true;	
	}
	for (int i = 0;i < 26 ; i++)
	{
		if (checked[i]!=true)
		{
			return false;
		}
	}
	return true;
	
}
bool isAnagrama(char* arr, char* arr2) {
	if (strlen(arr) != strlen(arr2)) 
	{
		return false;
	}
	int count = 0, lettersCount = 0;
	char* first = arr;
	char* second = arr2;
	int size = strLen(arr);
	while(*first!='\0')
	{
		while(*second!='\0')
		{
			if (*second == *first)
			{
				count++;
			}
			second++;
		}
		lettersCount++;
		count = 0;
		second = arr2;
		first++;
	}
	if (lettersCount == size)
	{
		return true;
	}
	return false;
}
bool isPalindrome(char* arr) {
	int size = strLen(arr);
	char* left = arr;
	char* right = arr + size-1;
	while (left<right)
	{
		if (*left!=*right)
		{
			return false;
		}
		left++;
		right--;
	}
	return true;
}
bool isPalindromeHelperFunction(char* left, char* right) {
	while (left < right) {
		if (*left != *right) {
			return 0;
		}
		left++;
		right--;
	}
	return 1; 
}

int checkForSubArrayPalindrom(char* arr) {
	int maxLen = 0;
	
	for (char* start = arr; *start != '\0'; start++) {
		for (char* end = start; *end != '\0'; end++) {
			if (isPalindromeHelperFunction(start, end)) {
				int len = end - start + 1;
				if (len > maxLen) {
					maxLen = len;
				}
			}
		}
	}
	return maxLen;
}

bool areAllLettersUnique(char* arr) {
	toLower(arr);
	char* start = arr;
	while (*start!='\0')
	{
		char* check = start+1;
		while(*check!='\0')
		{
			if (*start == *check)
			{
				return false;
			}
			check++;
		}
		start++;
	}
	return true;
}

void insert(char* text, char* result,char symbol, int i) {
	for (int j = 0; j < i; j++)
	{
		result[j] = text[j];
	}
	result[i] = symbol;
	int size = strLen(text);
	for (int j = i; j <= size; j++)
	{
		result[j+1] = text[j];
	}

}
// 'a' + abs(letter - 'A')


int main() {
	//Code Fragments
	//1: 10, 13
	//2: runtime error
	//3: 3, address, 9
	//4: error
	//5: h
	//6: 7
	
	
	//Practicum Exercises
	char arr[1024];
	std::cin.getline(arr, 1024);
	//01
	/*toLower(arr);
	std::cout << arr;*/
	//02
	/*bool check = isPangrama(arr);
	std::cout << (check ? "true" : "false");*/
	//03
	//char arr2[1024];
	//std::cin.getline(arr2, 1024);
	//std::cout << (isAnagrama(arr, arr2)?"true":"false");
	//04
	/*std::cout << (isPalindrome(arr) ? "TRUE" : "FALSE");
	return 0*/;
	//05
	//std::cout << checkForSubArrayPalindrom(arr);
	//06
	//std::cout << (areAllLettersUnique(arr)?"TRUE":"FALSE");
	//07
	/*char result[1024];
	char symbol = 'm';
	int index = 7;
	insert(arr, result, symbol, index);
	int length = strLen(arr)+1;
	for (int i = 0; i < length; i++)
	{
		std::cout << result[i];
	}*/
	
	//08
	
}
