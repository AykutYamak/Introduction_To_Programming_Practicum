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
		for (int i = 2; i < b; ++i)
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
		for (int i = 2; i < a; ++i)
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
	for (int i = 0; i < power; i++)
	{
		number *= number;
	}
	return number;
}
int removeDigitAtIndex(int& number, int index) {
	//TODO:

	return 0;
}
int main()
{
	/*double a = 10.235;
	double b = 20.3456;
	swap(a, b);*/
	//std::cout << a << ' ' << b;
	
	//int a = 5;
	//int b = 5;
	//int c = 5;
	//int d = 5;
	//int resultDenominator = 0;
	//int resultNumerator = 0;
	//findSumOfTwoFractions(a, b, c, d, resultNumerator, resultDenominator);
	//std::cout << resultNumerator << ' ' << resultDenominator;

	 
	//std::cout << tool;

}
