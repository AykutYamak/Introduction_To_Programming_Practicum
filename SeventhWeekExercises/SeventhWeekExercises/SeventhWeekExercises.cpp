#include <iostream>
void PlusOne(char* arr, const int SIZE, int k) {
	for (int i = SIZE-1; i >= 0; i--)
	{
		int digit;
		if (arr[i] >= '0' && arr[i] <= '9')
		{
			digit = arr[i] - '0';
		}
		else
		{
			digit = arr[i] - 'A' + 10;
		}
		if (digit<k-1)
		{
			digit++;
			if (digit<10)
			{
				arr[i] = digit + '0';
			}
			else
			{
				arr[i] = digit - 10 + 'A';
			}
			return;
		}
		else
		{
			arr[i] = '0';
		}
		
	}
}
void MinusOne(char* arr, const int SIZE, int k) {
	for (int i = SIZE - 1; i >= 0; i--)
	{
		int digit;
		if (arr[i] >= '0' && arr[i] <= '9')
		{
			digit = arr[i] - '0';
		}
		else
		{
			digit = arr[i] - 'A' + 10;
		}
		if (digit > 0)
		{
			digit--;
			if (digit < 10)
			{
				arr[i] = digit + '0';
			}
			else
			{
				arr[i] = digit - 10 + 'A';
			}
			return;
		}
		else
		{
			if (k - 1 < 10)
			{
				arr[i] = (k - 1) + '0';
			}
			else
			{
				arr[i] = (k - 1) - 10 + 'A';
			}

		}

	}
}

void AddCharArrays(char* arr, char* arr2, const int size, int k, char* res, int sizeRes) {
	int carry = 0;
	for(int i = size-1; i >= 0; i--)
	{
		int digit;
		if (arr[i] >= '0' && arr[i] <= '9')
		{
			digit = arr[i] - '0';
		}
		else
		{
			digit = arr[i] - 'A' + 10;
		}
		int digit2;
		if (arr2[i] >= '0' && arr2[i] <= '9')
		{
			digit2 = arr2[i] - '0';
		}
		else
		{
			digit2 = arr2[i] - 'A' + 10;
		}
		int sum = digit + digit2 + carry;
		sum = sum % k;
		carry = sum/k;
		if (sum < 10)
		{
			res[i] = sum + '0';
		}
		else
		{
			res[i] = sum - 10 + 'A';
		}
	}
}
void reverse(int arr[], int size) {
	for (int i = 0; i < size/2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}
}
void reverseCharArray(char arr[], int size) {
	for (int i = 0; i < size / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}
}
void ToBinaryNumber(int number) 
{
	int arr[32] = {};
	int i = 0;
	while (number > 0)
	{
		arr[i] = number % 2;
		number /= 2;
		i++;
	}
	reverse(arr, 32);
	for (int i = 0; i < 32; i++)
	{
		std::cout << arr[i];
	}
}

void fromBaseTenToBaseK(int number, int k) {
	char arr[32];
	if(number == 0) 
	{
		std::cout << '0';
		return;
	}

	int i = 0;
	if (k<=16 && k > 0)
	{
			while (number!=0)
			{
				int digit = number % k;
				if (digit < 10)
				{
					arr[i] = digit + '0';
				}
				else
				{
					arr[i] = digit - 10 + 'A';
				}
				i++;
				number /= k;
			}
	}
	else
	{
		return;
	}
	reverseCharArray(arr, i);
	int start = 0;
	for (int j = 0; j < i; j++)
	{
		if ((arr[j]>= '0' && arr[j]<='9') || (arr[j] >= 'A' && arr[j]<='F'))
		{
			start = j;
			break;
		}
	}
	for (int h = start; h < i; h++)
	{
		std::cout << arr[h];
	}
}

int reverseNumber(int number) {
	int result = 0;
	while (number!=0)
	{
		result += number % 10;
		result *= 10;
		number / 10;
	}
	return number;
}

int fromBaseThreeToBaseEight(int number) {
	int result = 0;
	while (number!=0)
	{
		int digit = 0;
		digit = number % 8;
		result += digit;
		result *= 10;
		number /= 8;
	}
	result = reverseNumber(result);
	return result;
}
int main() {
	constexpr int size = 3;
	char arr[size] = { '0','1','1'};
	//Introduction Exercises
	//01
	/*PlusOne(arr, 2, 16);
	for (int i = 0; i < 3; i++)
	{
		std::cout << arr[i];
	}*/

	//02
	/*MinusOne(arr, 2, 16);
	for (int i = 0; i < 2; i++)
	{
		std::cout << arr[i];
	}*/
	
	//03
	/*char arr2[size] = { '0','0', '1' };
	constexpr int size2 = 3;
	char res[size2] = {};
	AddCharArrays(arr, arr2, size, 2, res, size2);
	for (int i = 0; i < size2; i++)
	{
		std::cout << res[i];
	}*/

	//
	// 
	// 
	// 
	//Pract Exercises
	//
	// 
	// 
	//01
	/*ToBinaryNumber(10);*/
	
	//02
	//fromBaseTenToBaseK(0, 2);
	
	//03
	int number = 11120;
	number = fromBaseThreeToBaseEight(number);
	std::cout << number;
}