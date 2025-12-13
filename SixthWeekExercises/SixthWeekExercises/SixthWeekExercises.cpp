#include <iostream>

void swap(int& a, int& b) {
	int buf = a;
	a = b;
	b = buf;
}
void swap(double& a, double& b) {
	double buf = a;
	a = b;
	b = buf;
}
void fractionReduction(int& a, int& b) {
	if (a>b)
	{
		for (int i = 2; i <= b; ++i)
		{
			while((a % i == 0) && (b % i == 0))
			{
				a /= i;
				b /= i;
			}
		}
	}
	else if (a<b)
	{
		for (int i = 2; i <= a; ++i)
		{
			while ((a % i == 0) && (b % i == 0))
			{
				a /= i;
				b /= i;
			}
		}
	}
	else
	{
		a =	1;	
		b = 1;
	}
}
void findSumOfTwoFractions(int& a, int& b,int& c, int& d,int& resultNumerator, int& resultDenominator) {
	fractionReduction(a, b);
	fractionReduction(c, d);
	if (b!=d)
	{
		a *= d;
		b *= d;
		c *= b;
		d *= b;
	}
	resultNumerator = a + c;
	resultDenominator = d;
	fractionReduction(resultNumerator, resultDenominator);
}
int power(int number, int power) {
	int result = 1;
	for (int i = 0; i < power; i++)
	{
		result *= number;
	}
	return result;
}
int getLength(int number) {
	int count = 0;
	while (number>0)
	{
		count++;
		number /= 10;
	}
	return count;
}
int removeDigitAtIndex(int& number, int index) {
	int temp = number;
	int length = getLength(number);
	int digits = 0;
	for (int i = 1; i <= length; i++)
	{
		int helper = 0;
		if (i!=index)
		{
			int digit = 0;
			helper = power(10, length - i);
			digit = (temp / helper) % 10;
			digits = digits * 10 + digit;
		}
	}
	number = digits;
	return number;
}
void divideNumberEvenAndOddDigits(int& number) {
	int resultEven = 0;
	int resultOdd = 0;
	int length = getLength(number);
	int i = 1;
	int digit, helper;
	helper = power(10, length - i);
	while (length>=i)
	{
		digit = (number / helper) % 10;
		if (i%2==0)
		{
			resultEven = resultEven * 10 + digit;
			
		}
		else
		{
			resultOdd = resultOdd * 10 + digit;
		}
		i++;
		helper /= 10;
	}
	std::cout << resultEven << " " << resultOdd;
}
void extractDigitsInRange(int& number, int i, int j) {
	if (i > j)
	{
		std::cout << -1;
		return;
	}
	int helper = power(10, j);
	int result = 0;
	for (int g = i; g <= j; g++)
	{
		result += (number / helper) % 10;
		helper /= 10;
		result *= 10;
	}
	number = result/10;
}

void swapTwoNumbersDigitsOnPosition(int& n, int& m, int k) {
	int lengthN = getLength(n);
	int lengthM = getLength(m);
	if (k > lengthN || k > lengthM)
	{
		std::cout << -1;
		return;
	}
	
	int helperN = power(10, lengthN - k);
	int helperM = power(10, lengthM - k);

	int digitN = (n / helperN) % 10;
	int digitM = (m / helperM) % 10;
	n = n - digitN * helperN + digitM * helperN;
	m = m - digitM * helperM + digitN * helperM;
}
void getTomorrowsDate(unsigned& day, unsigned& month, unsigned& year) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (month == 12 && day == 31)
		{
			month = 1;
			year++;
			day = 1;
		}
		else if (day == 31)
		{
			day = 1;
			month++;
			year++;
		}
		else
		{
			day++;
		}
	}
	else if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (month == 2)
		{
			if (year % 4 == 0 && year % 400 == 0 && year % 100 != 0)
			{
				if (day == 29)
				{
					day = 1;
					month++;
				}
			}
			else
			{
				if (day == 31)
				{
					day = 1;
					month++;
				}
				else
				{
					day++;
				}
			}
		}
		else
		{
			if (day == 31)
			{
				day = 1;
				month++;
			}
			else
			{
				day++;
			}
		}
	}
	std::cout << day << " " << month << " " << year;
}

int countSwapsToMakeNumbersEqual(int& n, int a, int b) {
	int zeroToOne = 0;
	int oneToZero = 0;

	for (int i = 0; i < n; i++) {
		int digitA = a % 10;
		int digitB = b % 10;

		if (digitA == 0 && digitB == 1) zeroToOne++;
		else if (digitA == 1 && digitB == 0) oneToZero++;

		a /= 10;
		b /= 10;
	}

	return (zeroToOne<oneToZero) ? zeroToOne : oneToZero;
}

void removeNegativeNumbers(int arr[], int size)
{
	int i = 0; 

	for (int j = 0; j < size; j++) {
		if (arr[j] >= 0) {
			arr[i] = arr[j];
			i++;
		}
	}
	for (int k = 0; k < i; k++) {
		std::cout << arr[k] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	//Introduction exercises
	//01
	//double a = 10.235;
	//double b = 20.3456;
	//swap(a, b);
	//std::cout << a << ' ' << b;
	
	//02
	/*int a = 4;
	int b = 6;*/
	//fractionReduction(a, b);
	//std::cout << a << "/" << b;

	//02 bonus
	/*int a = 4;
	int b = 6;
	int c = 5;
	int d = 5;
	int resultDenominator = 0;
	int resultNumerator = 0;
	findSumOfTwoFractions(a, b, c, d, resultNumerator, resultDenominator);
	std::cout << resultNumerator << '/' << resultDenominator;*/

	//03
	/*int a = 12345;
	int k = 3;
	std::cout << removeDigitAtIndex(a, k) << std::endl;*/
	
	//04
	/*int number = 1234567;
	divideNumberEvenAndOddDigits(number);*/
	
	//05
	/*int number = 1234567;
	extractDigitsInRange(number, 2, 5);
	std::cout << number;*/

	//06
	//int n = 1234;
	//int m = 567;
	//int k = 2;
	//std::cout << n << " " << m << " " << k << std::endl;
	//swapTwoNumbersDigitsOnPosition(n, m, k);
	//std::cout << n << " " << m;
	
	//Pract Exercises
	//01
	//unsigned day, month, year;
	//std::cin >> day >> month >> year;
	//getTomorrowsDate(day, month, year);
	
	//02
	/*int n;
	std::cin >> n;
	int a, b;
	std::cin >> a >> b;
	std::cout << countSwapsToMakeNumbersEqual(n, a, b);*/
	
	//03
	constexpr int size = 7;
	int arr[size];
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
	removeNegativeNumbers(arr, size);
	
}
