#include <iostream>
void func(char* arr, const int SIZE, int k) {
	for (int i = SIZE-1; i >= 0; i--)
	{
		if (arr[i]>='1')
		{
			arr[i - 1]++;
			arr[i] = '0';
		}
		else
		{
			arr[i - 1]++;
			break; 
		}
	}
	
}
void func2(char* arr, const int SIZE, int k) {
	for (int i = SIZE - 1; i >= 0; i--)
	{
		if (arr[i] == '1')
		{
			arr[i] = '0';
			for (int j = SIZE-1; j >= i+1; j--)
			{
				arr[j] = '1';
			}
			break;
		}
	}
}
int main() {
	const int size = 1024;
	char arr[1024] = { '0','1','1' };
	
	func2(arr, 3, 2);
	for (int i = 0; i < 3; i++)
	{
		std::cout << arr[i];
	}
}