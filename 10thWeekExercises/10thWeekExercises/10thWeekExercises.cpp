#include <iostream>
constexpr int M = 3;
constexpr int N = 3;

int x = -1;
int y = -1;

int matrix[M][N];
int matrix2[M][N];


void print(int matrix[][N], unsigned rows, unsigned cols) {
    for (unsigned i = 0; i < rows; i++)
    {
        for (unsigned j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void InsertChar(char matrix[][N], unsigned rows, unsigned cols) {
    for (unsigned i = 0; i < rows; i++)
    {
        for (unsigned j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << std::endl;
}
void Insert(int matrix[][N], unsigned rows, unsigned cols) {
    for (unsigned i = 0; i < rows; i++)
    {
        for (unsigned j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << std::endl;
}
int findSmallestElement(int matrix[][N], unsigned rows, unsigned cols) {
    int min = INT_MAX;
    for (unsigned i = 0; i < rows; i++)
    {
        for (unsigned j = 0; j < cols; j++)
        {
            if (min > matrix[i][j])
            {
                min = matrix[i][j];
            }
        }
    }
    return min;
}
void printGlavenDiagonalIposleVtorostepenniq(int matrix[N][N]) {
    for (unsigned i = 0; i < N; i++)
    {
        std::cout << matrix[i][i] << " ";
    }
    std::cout << std::endl;
    for (unsigned i = 0; i < N; i++)
    {
        std::cout << matrix[i][N - i - 1] << " ";
    }
}
void printZigZag(int matrix[][N],int rows, int cols) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i%2!=0)
            {
                std::cout << matrix[i][N - j - 1] << " ";
            }
            else
            {
                std::cout << matrix[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}
void findCoordinates(int matrix[][N], int rows, int cols, int n, int &x, int &y) {
    for (unsigned i = 0; i < rows; i++)
    {
        for (unsigned j = 0; j < cols; j++)
        {
            if (matrix[i][j]==n)
            {
                x = i;
                y = j;
            }
        }
    }
    if (x == -1 && y == -1)
    {
        std::cout << x << "," << y;
    }
    else
    {
        std::cout << x << "," << y;
    }   
}
void sum(int matrix[M][N], int matrix2[M][N], int rows, int cols) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = matrix[i][j] + matrix2[i][j];
        }
    }
}
void sumWithoutTouchingTheMatrix(int matrix[M][N], int matrix2[M][N],int rows, int cols) {
    int matrixSum[M][N];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrixSum[i][j] = matrix[i][j] + matrix2[i][j];
        }
    }
    print(matrixSum, M, N);
}
bool isUpper(char a) {
    if (a>='A' && a<='Z')
    {
        return true;
    }
    return false;
}
void findStringWithTheMostUppercaseLetters(char matrix[M][N],int rows, int cols) {
    char arr[N];
    int row = 0;
    int count = 0;
    int buf = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (isUpper(matrix[i][j]))
            {
                count++;
            }
        }
        if (buf < count)
        {
            buf = count;
            row = i;
        }   
        count = 0;
    }
    for (int i = 0; i < cols; i++)
    {
        std::cout << matrix[row][i] << " ";
    }

}
int main()
{

    //01
   /* 
    Insert(matrix, M, N);
    print(matrix, M, N);*/

    //02
    /*
    Insert(matrix, M, N);
    std::cout << findSmallestElement(matrix, M, N);*/
    
    //03
    /*Insert(matrix, M, N);
    printGlavenDiagonalIposleVtorostepenniq(matrix);*/
    
    //04
    /*Insert(matrix, M, N);
    printZigZag(matrix,M,N);*/
    
    //05
    /*Insert(matrix, M, N);
    findCoordinates(matrix, M, N, 6, x, y);*/
    
    //06
    //Insert(matrix, M, N);
    //Insert(matrix2, M, N);
    /*sum(matrix, matrix2, M, N);
    print(matrix,M,N);*/
    //sumWithoutTouchingTheMatrix(matrix, matrix2, M, N);
    
    //07
    //char charMatrix[M][N];
    //InsertChar(charMatrix, M, N);
    //findStringWithTheMostUppercaseLetters(charMatrix,M,N);

    //08
}
