
#include <iostream>
int absoluteValue(int number)
{
	if (number < 0)
		return -number;
	else
		return number;
}
bool IsDigit(char symbol) {
	return symbol >= '0' && symbol <= '9';
}
bool isLower(char symbol) {
	return symbol >= 'a' && symbol <= 'z';
}
bool isUpper(char symbol) {
	return symbol >= 'A' && symbol <= 'Z';
}
char toUpper(char symbol) {
	if (symbol >= 'a' && symbol <= 'z')
	{
		return symbol - 'a' + 'A';
	}
}
char toLower(char symbol) {
	if (symbol >= 'A' && symbol <= 'Z')
	{
		return symbol - 'A' + 'a';
	}
}
int toNumber(char symbol) {
	if (IsDigit(symbol))
	{
		return symbol - '0';
	}
}
char toCharacter(int symbol) {
	if (symbol >=0 && symbol<=9)
	{
		return symbol + '0';
	}
}
int getLength(int num) {
	int count = 0;
	do
	{
		count++;
		num /= 10;
	} while (num != 0);
	return count;
}
int getDigitOnPosition(int n, unsigned int position) {
	int number = 0;
	int length = getLength(n);
	for (int i = length; i >= position; i--)
	{
		if (i == position)
		{
			number = n % 10;
		}
		n /= 10;
	}
	return number;
}
int lcm(int number1, int number2) {
	int i = 1;
	while (true)
	{
		if ((number1*i)%number2==0)
		{
			return number1 * i;
		}
		else
		{
			i++;
		}
	}
}
int concat(unsigned int first, unsigned int second) {
	int count = getLength(second);
	for (int i = 0; i < count; i++)
	{
		first = (first * 10) + getDigitOnPosition(second, i+1);
	}
	return first;
}
int sumInInterval(int m, int n) {
	if (m>n)
	{
		return 0;
	}
	/*for(int i = m+1; i < n; i++){
		m+=i;
	}
	return m;
	*/

	return n * (n + 1) / 2 - (m - 1) * m / 2;
}
bool isSquareRoot(int number) {
	int floorNum = floor(sqrt(number));
	int ceilNum = ceil(sqrt(number));
	if (floorNum == ceilNum)
	{
		return true;
	}
	return false;
}
int getPerimeter(int a, int b, int c)
{
	if ((a+b<c) || (a+c<b) || (c+b<a))
	{
		return 0;
	}
	return a + b + c;
}
int getArea(int a, int b,int c) {
	if ((a + b < c) || (a + c < b) || (c + b < a))
	{
		return 0;
	}
	return (a * b) / 2;
}
unsigned int sortDigits(unsigned int number) {
	int numberLength = getLength(number);
	char digits[4];
	for (int i = 0; i < numberLength; i++)
	{
		digits[i] = number % 10;
		number /= 10;
	}
	for (int i = 0; i < numberLength; i++)
	{
		for (int j = i+1; j < numberLength; j++)
		{
			if (digits[j] < digits[i])
			{
				int buf = digits[i];
				digits[i] = digits[j];
				digits[j] = buf;
			}
		}
	}
	number = 0;
	for (int i = 0; i < numberLength; i++)
	{
		number += digits[i];
		number *= 10;

	}
	number /= 10;
	return number;
}
bool isDivisibleByValue(int number, int divisor) {
	int realNumber = number;
	while (number != 0)
	{
		number /= divisor;
		if (number*divisor == realNumber)
		{
			return true;
		}
	}
	
	return false;
}
int getRemainder(int first, int second) {
	if (second == 0)
	{
		std::cout << "Divison by 0 is not allowed!";
		return 0;
	}
	int quotient = first / second;
	int remainder = first - (second * quotient);
	return remainder;
}
int getDivision(int first, int second) 
{
	int result = 0;
	if (first<0 || second < 0)
	{
		first = absoluteValue(first);
		second = absoluteValue(second);
	}
	if (second != 0)
	{
		while (first>=second)
		{
			first -= second;
			result++;
		}
	}
	else
	{
		std::cout << "Divison by 0 is not allowed!";
		return 0;
	}
	return result;
}
int squareRootToLower(int number) {
	int i = 0;
	if (number == 0 || number < 0)
	{
		return 0;
	}
	else
	{
		
		while ((i+1)*(i+1)<=number)
		{
			i++;
		}
	}
	return i;
}
bool isPerfect(unsigned number) {
	int sum = 0;
	int helper = number / 2;
	if (number  == 0)
	{
		return true;
	}
	for (int i = 1; i <= helper; i++)
	{
		if (number%i == 0)
		{
			sum += i;
		}
	}
	if (sum == number)
	{
		return true;
	}
	return false;
}
bool isAnArmstrongNumber(int number) {
	if (number >=0 && number <= 9)
	{
		return true;
	}
	int n = getLength(number);
	int sum = 0;
	int wholeNumber = number;
		while (number!=0)
	{
		int multiplier = number % 10;
		int helper = number % 10;
		for (int i = 1; i < n; i++)
		{
			helper *= multiplier;
		}
		sum += helper;
		number /= 10;
	}
	if (sum == wholeNumber)
	{
		return true;
	}
	return false;
}
void Collatz(int n) {
	int i = 0;
	while(i<500 && n!=1)
	{
		std::cout << n << " ";
		if (n%2==0)
		{
			n /= 2;
		}
		else
		{
			n = 3 * n + 1;
		}
		i++;
	}
	if (n==1)
	{
		std::cout << 1;
	}
}
int factorial(int n)
{
	int result = 1;
	for (int i = 2; i <= n; i++)
		result *= i;
	return result;
}

int binomial(int n, int k)
{
	return factorial(n) / (factorial(k) * factorial(n - k));
}

void printPascalTriangle(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			std::cout << " ";
		}
		for (int k = 0; k <= i; k++)
		{
			std::cout << binomial(i, k) << " ";
		}
		std::cout << std::endl;
	}
}
int main()
{
	// 1 
	/*int num;
	std::cin >> num;
	int absoluteValueOfNum = absoluteValue(num);
	std::cout << absoluteValueOfNum << std::endl;*/
	// 2
	/*char num;
	std::cin >> num;
	bool isDigit = IsDigit(num);
	std::cout << (isDig[it ? "true" : "false") << std::endl;*/
	// 3.1
	//char a;
	//std::cin >> a;
	//std::cout << toUpper(a);
	// 3.2
	//char a;
	//std::cin >> a;
	//std::cout << toLower(a);
	// 4
	/*int a;
	a = 3;
	char b;
	b = '3';
	std::cout << toNumber(b);
	std::cout << toCharacter(a);*/
	// 5
	/*int a = 0;
	std::cout << getLength(a);*/
	// 6
	//int a;
	//std::cin >> a;
	//std::cout << getDigitOnPosition(a, 6);
	
	// 7
	/*int a, b;
	std::cin >> a >> b;
	std::cout << lcm(a, b);*/
	
	// 8
	// 
	//int a, b;
	//std::cin >> a >> b;
	//std::cout << concat(a, b);

	// 9
	//std::cout << sumInInterval(10, 15);
	
	// 10
	//std::cout << (isSquareRoot(25) ? "true" : "false");
	
	// 11
	//int a, c, b;
	//std::cin >> a >> b >> c;
	//int p = getPerimeter(a, b, c);
	//std::cout << "The perimeter is: " << p << std::endl;
	//int area = getArea(a, b, c);
	//std::cout << "The area is: " << area << std::endl;

	// 12
	/*unsigned int number;
	std::cin >> number;
	unsigned int sortedDigitsNumber = sortDigits(number);
	std::cout << sortedDigitsNumber;*/
	
	// 13
	/*int number, divisor;
	std::cin >> number >> divisor;
	bool result = isDivisibleByValue(number, divisor);
	std::cout << (result ? "true" : "false");*/
	
	//14 
	//int first, second;
	//std::cin >> first >> second;
	//int remainder = getRemainder(first, second);
	//std::cout << remainder;
	
	//15
	//int a, b;
	//std::cin >> a >> b;
	//std::cout << getDivision(a,b);
	
	//16
	/*int a;
	std::cin >> a;
	int result = squareRootToLower(a);
	std::cout << result;*/
	
	//17
	//int a;
	//std::cin >> a;
	//std::cout << (isPerfect(a) ? "true" : "false");
	
	//18
	/*int a;
	std::cin >> a;
	std::cout << ((isAnArmstrongNumber(a)) ? "true" : "false");*/

	//19
	//int a;
	//std::cin >> a;
	//Collatz(a);
	
	//20
	printPascalTriangle(5);
}


