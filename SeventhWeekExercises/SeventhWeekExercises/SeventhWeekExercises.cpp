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
		result = result * 10 + number % 10;
		number /= 10;
	}
	return result;
}
int power(int number,int power) {
	if (number == 0)
	{
		return 0;
	}
	if (power == 0)
	{
		return 1;
	}
	int result = 1;
	for (int i = 0; i < power; i++)
	{
		result *= number;
	}
	return result;
}
int fromBaseThreeToBaseEight(int number) {
	int helperNumber = 0;
	int position = 0;

	while (number != 0) {
		int digit = number % 10;
		helperNumber += digit * power(3, position);
		position++;
		number /= 10;
	}

	int result = 0;
	while (helperNumber != 0) {
		result = result * 10 + (helperNumber % 8);
		helperNumber /= 8;
	}

	return reverseNumber(result);
}
void fromBaseTwelveToBaseThirteen(char number[],int size) {
	int helperNumber = 0;
	int position = 0;
	char arr[1024];
	int i = 0;
	while (number[i] != '\0') {
		if (number[i] == 'A') {
			int digit = 10;
			helperNumber = helperNumber * 12 + digit;
			i++;
			continue;
		}
		else if (number[i] == 'B')
		{
			int digit = 11;
			helperNumber = helperNumber * 12 + digit;
			i++;
			continue;
		}
		int digit = number[i]-'0';
		helperNumber = helperNumber * 12 + digit;
		i++;
	}
	i = 0;
	while (helperNumber != 0) {
		if (helperNumber%13 == 10)
		{
			arr[i] = 'A';
			helperNumber /= 13;
			i++;
			continue;
		}
		else if (helperNumber%13 == 11)
		{
			arr[i] = 'B';
			helperNumber /= 13;
			i++;
			continue;
		}
		else if (helperNumber%13 == 12)
		{
			arr[i] = 'C';
			helperNumber /= 13;
			i++;
			continue;
		}
		arr[i] = helperNumber % 13 + '0';
		helperNumber /= 13;
		i++;
	}
	reverseCharArray(arr, i);
	int length = i;
	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i];
	}

}
void reverseBinaryBitsInArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 0)
		{
			arr[i] = 1;
		}
		else if (arr[i] == 1 || arr[i] == -1)
		{
			arr[i] = 0;
		}
		else
		{
			return;
		}
	}
}
void multiplyByMinusOneReturnBinary(int number[], int size) {
	int j = size - 1;
	int decimal = 0;
	for (int i = 0; i < size; i++)
	{
		decimal += number[i] * power(2, j);
		j--;
	}
	decimal *= -1;
	int result[8];
	int i = 0;
	while (i!=size)
	{
		result[i] = decimal % 2;
		decimal /= 2;
		i++;
	}
	reverseBinaryBitsInArray(result, size);
	reverse(result, size);
	char resultHelper[8];
	for (int i = 0; i < size; i++)
	{
		resultHelper[i] = result[i] + '0';
	}
	PlusOne(resultHelper, size, 2);
	for (int j = 0; j < i; j++)
	{
		std::cout << resultHelper[j];
	}
}
bool isPalindromInBaseK(unsigned int number, int k) {
	if (k < 2 || k > 16)
	{
		return false;
	}
	if (number == 0)
	{
		return true;
	}
	int arr[32] = {};
	int count = 0;
	while (number > 0)
	{
		arr[count] = number % k;
		number /= k;
		count++;
	}
	for (int i = 0, j = count-1; i < j; i++,j--)
	{
		if (arr[i] != arr[j])
		{
			return false;
		}
	}
	return true;
}
bool areEqual(int number[], int number2[], int size1, int size2, int k, int n) {
	if (k < 10)
	{

	}
}

int main() {
	/*constexpr int size = 3;
	char arr[size] = { '0','1','1'};*/
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

	


	//Pract Exercises
	//
	// 
	// 
	//01
	/*ToBinaryNumber(10);*/
	
	//02
	//fromBaseTenToBaseK(0, 2);
	
	//03
	/*int number = 11120;
	number = fromBaseThreeToBaseEight(number);
	std::cout << number;*/
	
	//04
	/*char arr2[2];
	arr2[0] = 'A';
	arr2[1] = '\0';
	fromBaseTwelveToBaseThirteen(arr2, 2);*/
	
	//05
	/*constexpr int size = 8;
	int number[size] = { 1,1,1,1,1,1,1,1 };
	multiplyByMinusOneReturnBinary(number,size);*/
	
	//06
	unsigned number = 585;
	int k = 2;
	std::cout << (isPalindromInBaseK(number, k)? "true" : "false");
}