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
	int n,count = 0; 
	int sum = 0;
	for (int i = 109; i <= 999; i++)
	{
		n = i;
		while (n>0)
		{
			sum += n % 10;
			n /= 10;
		}
		
		if (sum >= 10 && sum <= 99)
		{
			for (int j = 2; j <= i/2; j++) {
				if (i % j == 0) 
				{
					count++; 
					break;

				}
			}
			if (count == 0)
			{
				std::cout << i << std::endl;
				count = 0;
				sum = 0;
			}
		}
		sum = 0;
	}
}