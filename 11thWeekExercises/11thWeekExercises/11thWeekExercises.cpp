#include <iostream>

void returnSumOfNumOnEvenPosition(int n) {
	int* arr = new int[n];
	int* sum = new int(0);
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if ((i + 1) % 2 == 0)
		{
			*sum += arr[i];
		}
	}
	std::cout << *sum;
	delete sum;
	delete[] arr;
}
void returnArrEvenAndOddPosition(int n) {
	int* arr = new int[n];
	int oddPosition = n / 2;
	int evenPosition = 0;
	for (int i = 0; i < n; i++)
	{
		if ((i + 1) % 2 == 0)
		{
			std::cin >> arr[evenPosition++];
		}
		else
		{
			std::cin >> arr[oddPosition++];
		}
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i];
	}
	delete[] arr;
}
void returnNumOnValidPosition(int n) {
	int count = 0;
	int* arr = new int[n];
	int* arr2 = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr2[i];
		if (arr2[i] == 1)
		{
			count++;
		}
	}
	int* result = new int[count];
	int resultIndex = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr2[i] == 1)
		{
			result[resultIndex] = arr[i];
			resultIndex++;
		}
	}
	for (int i = 0; i < resultIndex; i++)
	{
		std::cout << result[i];
	}
	delete[] arr;
	delete[] arr2;
	delete[] result;
}

void longestPrefix(int n) {
	char *arr = new char[n+1];
	char* arr2= new char[n+1];
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr2[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == arr2[i])
		{
			count++;
		}
	}
	char* result = new char[count + 1];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == arr2[i])
		{
			result[i] = arr[i];
		}
	}
	std::cout << count << " ";
	for (int i = 0; i < count; i++)
	{
		std::cout << result[i];
	}
	std::cout << "\0";
}

int main()
{
	//01
	/*int n;
	std::cin >> n;
	returnSumOfNumOnEvenPosition(n);*/

	//02
	/*int n;
	std::cin >> n;
	returnArrEvenAndOddPosition(n);*/

	//03
	//int n;
	//std::cin >> n;
	//returnNumOnValidPosition(n);
	
	//04
	int n;
	std::cin >> n;
	longestPrefix(n);
}
