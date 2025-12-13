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
int findSmallestNumber(const int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
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
bool isPalindrom(const int arr[], int size) {
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
        if ((a % i == 0) && (b % i== 0))
        {
            return i;
        }
    }
}
int FindGCDofElementsInArray(int arr[], int size) {
    int result = 0;
    result = GCD(arr[0], arr[1]);
    bool check = false;
    for (int i = 1; i < size-1; i++)
    {
        if (result == GCD(arr[i],arr[i+1]))
        {
            check = true;
        }
        else
        {
            check = false;
        }
    }
    if (check == true)
    {
        return result;
    }
    return 0;
}
bool isConcatOfTwoPalindroms(int arr[], int SIZE) {
    int firstElement = arr[0];
    for (int i = 1; i < SIZE; i++)
    {
        if (arr[0] == arr[i])
        {
            if (arr[i+1] == arr[SIZE - 1])
            {
                return true;
            }
        }
    }
    return false;
}
bool isSortedAscending(int arr[], int size) {
    bool check = false;
    for (int i = 0; i < size-2; i++)
    {
        if (arr[i]<=arr[i+1])
        {
            check = true;
        }
        else
        {
            check = false;
            break;
        }
    }
    return check;
}
int rfind(int arr[], int size, int value) {
    for (int i = size-1; i >= 0; i--)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}
int find(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}
bool BinarySearch(int arr[], int size, int value) {
    bool check = false;
    int left = 0, right = size - 1;
    while (left<=right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value)
        {
            check = true;
            return check;
        }
        else if (arr[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return check;
}
int longestNonDecreasingSubsequence(int arr[], int size) {
    int subsequence = 1;
    int longestSubsequence = 0;
    for (int i = 1; i < size; i++)
    {
        
        if (arr[i-1] <= arr[i])
        {
            subsequence++;
            if (longestSubsequence <= subsequence)
            {
                longestSubsequence = subsequence;
            }
        }
        else
        {
            if (size - subsequence <= subsequence)
            {
                return subsequence;
            }
            else
            {
                longestSubsequence = subsequence;
                subsequence = 1;
            }
        }
    }
    return longestSubsequence;
}
void section(int arr1[], int arr2[], int size1, int size2, int newarr[])
{   
    int k = 0;
    for (int i = 0; i < size1; i++)
    {
        bool found = false;
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            continue;
        }
        bool exists = false;
        for (int t = 0; t < k; t++)
        {
            if (newarr[t] == arr1[i])
            {
                exists = true;
                break;
            }
        }
        if (!exists)
        {
            newarr[k] = arr1[i];
            k++;
        }
    }

    for (int i = 0; i < k; i++)
    {
        std::cout << newarr[i] << " ";
    }
}
void merge(int arr1[], int arr2[], int size1, int size2, int result[])
{
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            result[k] = arr1[i];
            k++; 
            i++;
        }    
        else
        {
            result[k] = arr2[j];
            j++;
            k++;
        }    
    }
   
    while (i < size1) 
    {
        result[k++] = arr1[i++];
    }
    while (j < size2)
    {
        result[k++] = arr2[j++];
    }
    for (int i = 0; i < k; i++)
    {
        std::cout << result[i] << " ";
    }
}
bool hasUnimodalSubarray(int arr[], int start, int end) {
    int k = start;
    bool check = false;

    int i;
    for (i = start; i < end; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            check = true;
        }
        else
        {
            k = i;   
            break;
        }
    }

    if (i == end) 
    {
        return false;
    }
        

    if (!check)
    {
        return false;
    }

    if (k == end)
    {
        return false;
    }
        
    check = false;
    for (int j = k; j < end; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            check = true;
        }
        else
        {
            return false;
        }
    }

    return check;
}
void moveZeros(int arr[], int size) {
    int k = 0;
    // 0 0 1 2 3
    for (int i = 0; i < size; i++)
    {
        if (arr[i]!=0)
        {
            arr[k] = arr[i];
            k++;
        }
    }
    while (k<size)
    {
        arr[k] = 0;
        k++;
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}
int ComplementNumbersAndReturnSmallestOne(int arr[], int size) {
    int start = arr[0];
    if (!isSortedAscending(arr, size))
    {
        return -1;
    }
    if (isSortedAscending(arr,size))
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] != start + i)
            {
                return start + i;
            }
        }
    }
    return -1;
}

int main()
{
    // 1
    constexpr int SIZE = 5;
    int arr[SIZE];
    addElementsToArray(arr, SIZE);
    
    //02
    /*for (int i  = 0; i < SIZE; i++)
    {
        std::cout << arr[i];
    }*/
    /*findSmallestAndBiggestNumber(arr, SIZE);*/
    
    //03
    //int index;
    //std::cin >> index;
    //int newSize = removeElementByIndex(arr, SIZE, index);
    //for (int i = 0; i < newSize; i++)
    //{
    //    std::cout << arr[i];
    //}

    //04
    //std::cout << (isPalindrom(arr, SIZE) ? "true" : "false");
    
    //05
    //std::cout << "GCD of the elements is: " << (FindGCDofElementsInArray(arr, SIZE));

    //06
    //std::cout << (isConcatOfTwoPalindroms(arr, SIZE) ? "TRUE" : "FALSE");
    
    //07
    //std::cout << ((isSortedAscending(arr, SIZE) ? "TRUE" : "FALSE"));

    //08
    //std::cout << find(arr, SIZE, 2) << std::endl;
    //std::cout << rfind(arr, SIZE, 5);
    
    //09
    //std::cout << "Enter target: ";
    //int number;
    //std::cin >> number;
    //std::cout << ((BinarySearch(arr, SIZE, number) ? "true" : "false"));
    
    //10
    //std::cout << longestNonDecreasingSubsequence(arr, SIZE);

    //11
    /*std::cout << "Enter the second arrays elements: ";
    constexpr int SIZE2 = 3;
    int arr2[SIZE2];
    addElementsToArray(arr2, SIZE2);
    int newArr[(SIZE < SIZE2 ? SIZE2 : SIZE)];
    section(arr, arr2, SIZE, SIZE2, newArr);*/

    //12
    /*constexpr int SIZE2 = 3;
    int arr2[SIZE2];
    addElementsToArray(arr2, SIZE2);
    int mergedArr[SIZE + SIZE2];
    merge(arr, arr2, SIZE, SIZE2, mergedArr); */

    //13
    /*std::cout << "Enter start and end indexes: " << std::endl;
    int start, end;
    std::cin >> start >> end;
    std::cout << ((hasUnimodalSubarray(arr, start, end) ? "true" : "false"));*/

    //14
    //moveZeros(arr, SIZE);
    
    //15
    int result;
    result = ComplementNumbersAndReturnSmallestOne(arr, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "Smallest number is: " << result;
}

