#include <iostream>

void addElementsToArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
}
void findSmallestAndBiggestNumber(const int arr[], int size) {
    int min = arr[0];
    int max = arr[size-1];
    for (int i = 1; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    std::cout << "Smallest number is: " << min << ' '<< std::endl << "Biggest number is : " << max;
}
int removeElementByIndex(int arr[], int size, int index) 
{
    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
    return size;
}
bool isPalindrom(int arr[], int size) {
    bool isPalindrom = true;
    for (int i = 1; i < size; i++)
    {
        if (arr[i-1] == arr[size-i])
        {
            isPalindrom = true;
        }
        else
        {
            return false;
        }
    }
    return isPalindrom;
}
int GCD(int a, int b) {
    int min = a < b ? a : b;
    for (int i = min; i > 0; i--)
    {
        if ((a%min == 0) && (b % min == 0))
        {
            return i;
        }
    }
}
int FindGCDofElementsInArray(int arr[], int size) {
    int gcdoftwonumbers = arr[0];
    for (int i = 1; i < size; i++)
    {
        GCD(gcdoftwonumbers,arr[i]);
    }
}
int main()
{
    // 1
    constexpr int SIZE = 5;
    int arr[SIZE];
    addElementsToArray(arr, SIZE);
    /*for (int i  = 0; i < SIZE; i++)
    {
        std::cout << arr[i];
    }*/
    /*findSmallestAndBiggestNumber(arr, SIZE);*/
 /*   int index;
    std::cin >> index;
    int newSize = removeElementByIndex(arr, SIZE, index);
    for (int i = 0; i < newSize; i++)
    {
        std::cout << arr[i];
    }*/
    //std::cout << (isPalindrom(arr, SIZE) ? "true" : "false");
    
}
