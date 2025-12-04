#include <iostream>

int main()
{
	//Code snippets
	//1 They are not that smart!
	//2 Undefined
	//3 undefined behavior
	//4 unknown
	//5 third 

	//Introduction Exercises
	//1
	/*int n;
	std::cin >> n;
	if (n == 0)
	{
		std::cout << 0;
	}
	else if (n > 0)
	{
		std::cout << "positive";
	}
	else
	{
		std::cout << "negative";
	}*/

	//2
	/*int a, b;
	std::cin >> a >> b;
	std::cout << ((a < b) ? b : a);*/

	//3 
	/*int n;
	std::cin >> n;
	switch (n) {
	case 1: std::cout << "Monday";break;
	case 2: std::cout << "Tuesday";break;
	case 3: std::cout << "Wednesday";break;
	case 4: std::cout << "Thursday";break;
	case 5: std::cout << "Friday"; break;
	case 6: std::cout << "Saturday";break;
	case 7: std::cout << "Sunday";break;
	default: std::cout << "ha ha problem";break;
	}*/

	//4 
	/*int year;
	std::cin >> year;
	bool check = false;
	if (year%4==0)
	{
		check = true;
		if (year%100 == 0)
		{
			check = false;
		}
		if (year%400==0)
		{
			check = true;
		}
	}
	std::cout << ((check) ? "true" : "false");*/

	//5
	/*int a, b, c;
	std::cin >> a >> b >> c;

	if (a < b && c < b)
	{
		if (a < c)
		{
			std::cout << a << " " << c << " " << b;
		}
		else
		{
			std::cout << c << " " << a << " " << b;
		}
	}
	else if (b < a && c < a)
	{
		if (b < c)
		{
			std::cout << b << " " << c << " " << a;
		}
		else
		{
			std::cout << c << " " << b << " " << a;

		}
	}
	else if (b < c && a < c)
	{
		if (b < a)
		{
			std::cout << b << " " << a << " " << c;
		}
		else
		{
			std::cout << a << " " << b << " " << c;
		}
	}*/

	//5.5
	/*int a, b, c;
	std::cin >> a >> b >> c;

	if (a < b && c < b)
	{
		if (a < c)
		{
			std::cout << (b * 10 + c) * 10 + a;
		}
		else
		{
			std::cout << (b * 10 + a )* 10 + c;
		}
	}
	else if (b < a && c < a)
	{
		if (b < c)
		{
			std::cout << (a * 10 + c) * 10 + a;
		}
		else
		{
			std::cout << (a * 10 + b) * 10 + a;
		}
	}
	else if (b < c && a < c)
	{
		if (b < a)
		{
			std::cout << (((c * 10) + a) * 10 + b);
		}
		else
		{
			std::cout << (((c * 10) + b)*10 + a);
		}
	}*/

	//6
	/*float n;
	std::cin >> n;
	if (floor(n) == n)
	{
		std::cout << "Integer";
	}
	else
	{
		std::cout << "Not an integer";
	}*/

	//7
	/*char a;
	std::cin >> a;
	if (a >= 'a' && a <= 'z')
	{
		if (a == 'a' || a == 'y' || a == 'o' || a == 'e' || a == 'u' || a == 'i')
		{
			std::cout << "Lowercase Vowel" << std::endl;
			a = ('A' + abs(a - 'a'));
			std::cout << a;
		}
		else
		{
			std::cout << "Lowercase suglasna" << std::endl;
			a = ('A' + abs(a - 'a'));
			std::cout << a;
		}
	}
	else if (a >= 'A' && a <= 'Z')
	{
		if (a == 'A' || a == 'Y' || a == 'O' || a == 'E' || a == 'U' || a == 'I')
		{
			std::cout << "Uppercase Vowel" << std::endl;
			a = ('a' + abs(a - 'A'));
			std::cout << a;
		}
		else
		{
			std::cout << "Uppercase suglasna"<< std::endl;
			a = ('a' + abs(a - 'A'));
			std::cout << a;
		}
	}*/

	//8
	/*int n;
	std::cin >> n;
	if (n >=0 && n <= 12)
	{
		if (n % 2 == 0)
		{
			for (int i = n; i <= 12; i++)
			{
				if (i % 2 == 0)
				{
					std::cout << i << " " ;
				}
			}
		}
		else
		{
			for (int i = n; i <= 12; i++)
			{
				if (i%2!=0)
				{
					std::cout << i << " ";
				}
			}
		}
	}*/

	//9
	/*bool check = false;
	double a, b, c;
	std::cin >> a >> b >> c;
	if (a+b>c && c+a>b && b+c>a)
		check = true;
	std::cout << ((check) ? "true" : "false");*/

	//10
	/*double a, b, c;
	std::cin >> a >> b >> c;
	if (a < c && b > c)
	{
		if (a == c || b == c)
		{
			std::cout << "The number is within the given interval.The interval is closed.";

		}
		else
		{
			std::cout << "The number is within the given interval.The interval is open.";
		}
	}
	else
	{
		std::cout << "The number isn't within the given interval.";
	}*/

	//11
	/*int n;
	std::cin >> n;
	int newNum1 = 10;
	int newNum2 = 10;
	if (n<0)
	{
		std::cout << "Invalid number!";
	}
	else
	{
		newNum1 += n % 10;
		n /= 10;
		newNum2 += n % 10;
		n /= 10;
		newNum2 = (newNum2 + (n % 10) * 10) - 10;
		n /= 10;
		newNum1 = (newNum1 + (n % 10) * 10) - 10;
		if (newNum1 == newNum2)
		{
			std::cout << newNum1 << "=" << newNum2;
		}
		else if (newNum1 < newNum2)
		{
			std::cout << newNum1 << "<" << newNum2;

		}
		else
		{
			std::cout << newNum1 << ">" << newNum2;
		}
	}*/

	//12
	/*int day, month;
	std::cin >> day >> month;
	if (month > 12 || day > 31 || day < 1 || month < 1)
	{
		std::cout << "Invalid month or day";
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 11)
	{
		if (day == 31)
		{
			std::cout << 1 << " " << ++month;
		}
		else
		{
			std::cout << ++day << " " << month;
		}
	}
	else
	{
		if (day == 30)
		{
			std::cout << 1 << " " << ++month;
		}
		else
		{
			std::cout << ++day << " " << month;
		}
	}*/
	
	//13
	/*double a, b;
	std::cin >> a >> b;
	char operation;
	double result = 0;
	std::cin >> operation;
	if (operation == '+')
	{
		result = a + b;
	}
	else if (operation == '*')
	{
		result = a * b;
	}
	else if (operation == '-')
	{
		result = a - b;
	}
	else if (operation == '/')
	{
		if (b == 0)
		{
			std::cout << "На 0 не се дели!";
		}
		else
		{
			result = a / b;
		}
	}
	std::cout << result;*/

	//14
	/*bool check = false;
	int num1,num2,num3,num4,num5;
	std::cin >> num1 >> num2 >> num3 >> num4 >> num5;
	if ((num2 >= num1 && num2 >= num3) || (num2 <= num1 && num2 <= num3))
	{
		if ((num3 >= num2 && num3 >= num4) || (num3 <= num2 && num3 <= num4))
		{
			if ((num4 >= num3 && num4 >= num5) || (num4 <= num3 && num4 <= num5))
			{
				check = true;
			}
		}
	}
	std::cout << (check ? "is a zigsaw" : "is not a zigsaw");*/

	//15
	//easy one

	//16
	/*bool check1 = false, check2 = false, check3 = false, check4 = false;
	char a, b, c, d, e;
	std::cin >> a >> b;
	if (a <'A' || a > 'Z' || b< 'A' || b> 'Z')
	{
		std::cout << "Invalid input";
	}

	std::cin >> c >> d;
	if (c<'a' || c>'z' || d<'a' || d>'z')
	{
		std::cout << "Invalid input";
	}
	std::cin >> e;
	if ((e>=(a-'A' + 'a') && e <= (b - 'A' + 'a')) || (e >= c && e <= d))
	{
		check1 = true;
	}
	if (b-'A' + 'a' > c)
	{
		if (e<=c && e>=b - 'A' + 'a')
		{
			check2 = true;
		}
	}
	if ((e>= (a - 'A' + 'a') && e<= (b - 'A' + 'a'))&& (!check2))
	{
		check3 = true;
	}
	if (check3)
	{
		check4 = true;
	}
	else if (check1 && !check2 && !check3)
	{
		check4 = true;
	} 
	std::cout << check1 << "," << check2 << "," << check3 << "," << check4;*/

	//Week 2 DONE
}
