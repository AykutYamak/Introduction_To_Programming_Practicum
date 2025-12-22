#include <iostream>
int twoPowered(int k) {
	if (k < 0 || k > 31)
	{
		return -1;
	}
	
	return 1 << k;
}

int returnBitOnPosition(int n, int m) {
	return (n >> m)&1;
}

int getNumberAfterChangedBitOnPosition(int n, int position) {
	return n ^ (1<<position);
}

int returnNumber(int x, int m, int n) {
	return (x >> (m-n+1)) & ((1 << n) - 1);
}

int encode(int number, int key) {
	return number ^ key;
}
int decode(int code, int key){
	return code ^ key;
}

void swap(int* a, int* b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int main()
{
    //01
	/*int k = 3;
	std::cout << twoPowered(k);*/
	
	//02
	/*int n = 9;
	int m = 2;
	std::cout << returnBitOnPosition(n, m);*/
	
	//03
	/*int n = 5;
	int position = 0;
	std::cout << getNumberAfterChangedBitOnPosition(n, position);*/
	
	//04
	int x = 16;
	int m = 4;
	int n = 3;
	std::cout << returnNumber(x, m, n);
}		