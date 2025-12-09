#include <iostream>
int main() {
	//1
	/*int result = 1;
	int n;
	std::cin >> n;
	int b = 1;
	for (int i = 1; i <= n;	i++)
	{
		result = b * i;
		b = result;
	}
	std::cout << result;*/

	//2
	/*int n;
	int sum = 0;
	std::cin >> n;
	do {
		if (sum != 0) {
			n = sum;
			sum = 0;
		}
		while (n > 0)
		{
		sum += n % 10;
		n /= 10;
		}
	}while(sum >= 10);

	std::cout << sum;*/

	//3 
	/*int n,count = 0;
	int sum = 0;
	for (int i = 109; i <= 999; i++)
	{
		n = i;
		while (n>0)
		{
			sum += n % 10;
			n /= 10;
		}

		if (sum >= 10 && sum <= 27)
		{
			for (int j = 2; j <= sum/2; j++) {
				if (sum % j == 0)
				{
					++count;
					break;
				}
			}
			if (count == 0)
			{
				std::cout << i << std::endl;
			}
		}
		count = 0;
		sum = 0;
	}*/

	//4
	/*int n, m, count = 0, sum = 0;
	std::cin >> n >> m;

	for (int i = n; i <= m; ++i)
	{
		for (int j = 2; j <= n/2; ++j)
		{
			if (i%j==0)
			{
				count++;
				break;
			}
		}
		if (count == 0)
		{
			sum += i;
		}
		count = 0;
	}
	std::cout << sum;*/

	//5
	/*int n, m;
	std::cin >> n >> m;
	if (n < 0 || n > 255 || m < 0 || m > 255)
	{
		std::cout << "Invalid input!";
		return 0;
	}
	for (int i = n; i <= m; i++)
	{
		std::cout << (char)i;
	}*/

	//6
	/*int n;
	std::cin >> n;
	int a = 1, b = 1;
	for (int i = 1; i <= n; ++i)
	{

		std::cout << a << " ";
		int next = a + b;
		a = b;
		b = next;
	}*/

	//7
	/*int n;
	int sumOfDigits = 0;
	while (true)
	{
		std::cout << "Enter a number: ";
		std::cin >> n;
		int helper = n;
		while (n != 0) {
			sumOfDigits += n % 10;
			n /= 10;
		}
		if (((sumOfDigits + helper)%10) == 0)
		{
			std::cout << helper << " is a valid number";
			break;
		}
	}*/

	//8
	/*int hours1, min1, hours2, min2;
	std::cin >> hours1 >> min1 >> hours2 >> min2;
	int iter = hours1;
	if (hours1<hours2)
	{
		if (min1 != 0)
		{
			++iter;
		}
		while (iter <= hours2 )
		{
			std::cout << iter << " ";
			++iter;
		}
	}
	else
	{
		iter = hours2;
		if (min2 != 0)
		{
			++iter;
		}
		while (iter <= hours1-1 && min2 <= min1)
		{
			std::cout << iter << " ";
		}
	}*/

	//9
	/*int n;
	std::cin >> n;
	int sum = 0;
	int overallSum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += i;
		overallSum += sum;
	}
	std::cout << overallSum;*/

	//10 
	/*int n, input,sum = 0;
	std::cin >> n;
	if (n<0)
	{
		std::cout << "Invalid input!";
	}
	else
	{
		do
		{
			std::cin >> input;
			int count = 0;
			for (int i = 2; i < sqrt(input); i++)
			{
				if (input%i==0)
				{
					count++;
					break;
				}
			}
			if (count==0 && n%input!=0)
			{
				sum += input;
			}
		} while (input != -1);
		std::cout << sum;
	}*/

	//11
	/*int n, m;
	std::cin >> n >> m;

	for (int i = n; i < m; i++)
	{
		int sum = 0;
		for (int j = 1; j < i; j++)
		{
			if (i%j==0)
			{
				sum += j;
			}
		}
		if (i==sum)
		{
			std::cout << i<< std::endl;
		}
	}*/

	//12
	/*int n;
	bool canBe = false;
	std::cin >> n;
	for (int i = 2; i < n/2; i++)
	{
		bool isPrime = true;
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i%j == 0)
			{
				isPrime = false;
				break;
			}
		}
		int b = n - i;
		bool isPrimeB = true;
		for (int j = 2; j  < sqrt(b); j ++)
		{
			if (b%j==0)
			{
				isPrimeB = false;
				break;
			}
		}
		if (isPrime && isPrimeB)
		{
			canBe = true;
			std::cout << n << " = " << i << " + " << b << std::endl;
		}
	}
	std::cout << (canBe ? "can be" : "cannot be");*/

	//13
	/*int n;
	std::cin >> n;
	int buf = 0;
	int sum = 0;
	int max = 0;
	bool check = false;
	for (int i = 0; i < n; i++)
	{
		std::cin >> buf;
		if (buf > max)
		{
			max = buf;
		}
		sum += buf;
	}
	sum -= max;
	if (sum == max)
	{
		check = true;
	}
	std::cout << ((check) ? "yes" : "no");*/

	//14
	/*double n;
	std::cin >> n;
	double a = 0.5;
	for (int i = 0; i < n; i++)
	{
		a = (a * a + 1) / 2;
	}
	std::cout << a;*/

	//15
	/*unsigned n;
	std::cin >> n;
	int maxDiff = 0;
	int sum1 = 0,sum2 = 2;
	int count = 1;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		std::cin >> a >> b;
		sum2 = a + b;
		if (sum1 == sum2)
		{
			count++;
		}
		if (abs(sum2-sum1)>maxDiff)
		{
			maxDiff = abs(sum2 - sum1);
		}
		sum1 = a + b;
	}
	if (count == n)
	{
		std::cout << "Equal sums: " << count;
	}
	else
	{
		std::cout << "Different sums. Max Difference: " << maxDiff;
	}*/

	//16
	/*unsigned k;
	int n, m;
	bool check = false;
	std::cin >> k >> n >> m;
	for (int i = n; i < m; i++)
	{
		int a = i;
		while (a!=0)
		{
			if (a%10==0)
			{
				check = false;
				break;
			}
			if (k % (a % 10) == 0)
			{
				check = true;
				a /= 10;
			}
			else
			{
				check = false;
				break;
			}
		}

		if (check)
		{
			std::cout << i << std::endl;
		}
	}*/

	//17
	/*unsigned n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			std::cout << "$";
		}
		std::cout << std::endl;
	}*/

	//18
	/*unsigned n;
	std::cin >> n;
	std::cout << '+';
	for (int i = 0; i < n-2; i++)
	{
		std::cout << '-';
	}
	std::cout << '+';
	std::cout << std::endl;
	for (int i = 0; i < n-2; i++)
	{
		std::cout << '|';
		for (int i = 0; i < n-2; i++)
		{
			std::cout << '-';
		}
		std::cout << '|';
		std::cout << std::endl;
	}
	std::cout << '+';
	for (int i = 0; i < n - 2; i++)
	{
		std::cout << '-';
	}
	std::cout << '+';*/
	
	//19
	/*unsigned k;
	std::cin >> k;

	for (int i = 1; i < k * 2; i++)
	{
		int limit = (i < k) ? i : (2 * k - i);  
		for (int j = 1; j <= limit; j++)
		{
			std::cout << j;
		}
		int middle;
		if (i == k)
			middle = ((2 * k + 1) - 2 * limit)+k-1;   
		else
			middle = ((2 * k + 1) - 2 * limit)+k-1;

		if (i == k)
		{
			for (int h = 0; h < middle; h++)
				std::cout << "-";              
		}
		else
		{
			for (int h = 0; h < middle; h++)
				std::cout << " ";              
		}
		for (int j = limit; j >= 1; j--)
		{
			std::cout << j;
		}

		std::cout << std::endl;
	}*/
	
	//20


}


