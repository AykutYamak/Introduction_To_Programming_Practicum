#include <iostream>
int main() {
	//ex 11
	/*int a, b, c, d;
	std::cout << "First interval: ";
	std::cin >> a >> b;
	std::cout << "Second interval: ";
	std::cin >> c >> d;
	std::cout << (a > c || b > d);*/
	
	////ex 12
	//int a, b, c, d, e;
	//std::cin >> a >> b >> c >> d >> e;
	//std::cout << (a + 1 == b && b + a == c && c + b == d && d + c == e);
	
	//ex 13
	/*int a;
	std::cin >> a;
	int sum = a * (a + 1) / 2;
	std::cout << (sum);*/
	
	//ex 14
	//int n;
	//int sum = 0;
	//std::cin >> n;
	//for (int i = 1; i <= n; i++)
	//{
	//	if (i%3==0)
	//	{
	//		sum += i;
	//	}
	//}
	//std::cout << sum;

	//ex 15
	/*int n, c;
	std::cin >> n >> c;
	c = c + n;
	n = c - n;
	c = c - n;
	std::cout << "First number : " << n << std::endl;
	std::cout << "Second number : " << c;*/
	//ex 16
	//int a,b;
	//std::cin >> a >> b;
	//std::cout << ((a < b) ? a : b);
		
	//ex 17
	int n;
	std::cin >> n;
	if (n/10==0)
	{
		std::cout << n;
	}
	else if (n/100==0)
	{
		std::cout << (n % 10) + 1;
	}
	else
	{
		std::cout << n / 10;
	}


}