#include <iostream>

int reverseNum(int n) {
	int digit = 0;
	int reversedNum = 0;
	while (n>0)
	{
		digit = n % 10;
		reversedNum += digit;
		reversedNum *= 10;
		n /= 10;
	}
	reversedNum /= 10;
	return reversedNum;
}

char toUpper(char input) {
	char a = 'a';
	return input - 'a' + 'A';
}



bool isPalindrom(unsigned int number) {
	unsigned int original_n = number;
	unsigned int reversed_n = 0;
	while (number > 0 && (number %10!=0 && number !=0))
	{
		int lastDigit = number % 10;
		reversed_n = reversed_n * 10 + lastDigit;
		number /= 10;
	}
	reversed_n /= 10;
	return original_n == reversed_n;
}
int main()
{
	int arr[5] = { 1,2,3,4,5 };
	std::cout << arr;
}