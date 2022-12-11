#include <iostream>
using namespace std;
#include <math.h>
#include <fstream>
void HBowSwap(int a,int b)
{
    srand(time(0));
    int s = 5;              // Размер матрицы
    int** arr;
    arr = new int* [s];
    int g;
    int k;

    for(int i = 0; i < s; i++)
    {
        arr[i] = new int [s];
    }
    if (a > b)
    {
        g = abs(a) + 1;
        k = abs(b) + 1;
    }
    else
    {
        g = abs(b) + 1;
        k = abs(a) + 1;
    }
    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < s; j++)
        {
            arr[i][j] = rand() % g - rand() % k;
        }
    }
    cout<<"Изначальная матрица: "<<endl;
    for(int i = 0;i < s;i++)
    {
        for(int j = 0;j < s;j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }

    int maxred = g;
    int indexred[2];
    for(int i = 0;i < s;i++)
    {
        for(int j = 0;j < s;j++)
        {
            if((i == j and i >= floor(s / 2.0)) or (i == s - j - 1 and i < j) or (i >= floor(s / 2.0) and i < j))
            {
                if (arr[i][j] > 0 and arr[i][j] < maxred)
                {
                    maxred = arr[i][j];
                    indexred[0] = i;
                    indexred[1] = j;
                }
            }
        }
    }

    int maxnegativegreen = g * -1;
    int indexgreen[2];

    for(int i = 0;i < s;i++)
    {
        for(int j = 0;j < s;j++)
        {
            if((i == j and i <= floor(s / 2.0)) or (i == s - j - 1 and i > j) or (i <= floor(s / 2.0) and i > j))
            {
                if (arr[i][j] < 0 and arr[i][j] > maxnegativegreen)
                {
                    maxnegativegreen = arr[i][j];
                    indexgreen[0] = i;
                    indexgreen[1] = j;
                }
            }
        }
    }

    cout<<endl<<"Минимальный положительный в красной зоне: "<<maxred<<endl<<"Максимальный отрицательный в зеленой зоне: "<<maxnegativegreen<<endl;

    int red = arr[indexred[0]][indexred[1]];
    int green = arr[indexgreen[0]][indexgreen[1]];

    arr[indexred[0]][indexred[1]] = green;
    arr[indexgreen[0]][indexgreen[1]] = red;

    cout<<endl;

    for(int i = 0;i < s;i++)
    {
        for(int j = 0;j < s;j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
    delete [] arr;
}

int VecMatrProd(int n,int m,int T)
{
    int s = 5;              // Размер матрицы и векторов
    int** A;
    A = new int* [s];
    int** C;
    C = new int* [s];
    int *B = new int[s];
    int *D = new int[s];

    std::ofstream input;
    input.open("numbers.txt");
    srand(time(0));

    for(int i = 0;i < 70;i++)
    {
        input<<rand() % 15 - 7<<endl;
    }
    input.close();

    std::ifstream output;
    output.open("numbers.txt");
    for (int k = 0;k < 4;k++)
    {
        switch(k)
        {
            case 0:
                cout<<"Matrix A:"<<endl;
                for(int i = 0;i < s;i++)
                {
                    A[i]=new int[s];
                    for (int j = 0;j < s;j++)
                    {
                        output>>A[i][j];
                        cout<<A[i][j]<<' ';
                    }
                    cout<<endl;
                }
                cout<<endl;
            break;

            case 1:
                cout<<"Matrix C:"<<endl;
                for(int i = 0;i < s;i++)
                {
                    C[i]=new int[s];
                    for (int j = 0;j < s;j++)
                    {
                        output>>C[i][j];
                        cout<<C[i][j]<<' ';
                    }
                    cout<<endl;
                }
                cout<<endl;
            break;

            cout<<endl;

            case 2:
                cout<<"Vector B:"<<endl;
                for(int i = 0;i < s;i++)
                {
                    output>>B[i];
                    cout<<B[i]<<' ';
                }
                cout<<endl<<endl;
            break;

            case 3:
                cout<<"Vector D:"<<endl;
                for(int i = 0;i < s;i++)
                {
                    output>>D[i];
                    cout<<D[i]<<' ';
                }
                cout<<endl<<endl;
            break;
        }
    }
    output.close();
    return 5 * A[n][m] * B[m] + pow(C[m][n],T) * D[m];
}

int main()
{
    HBowSwap(-5,7);
    cout<<endl<<"Второе задание: "<<endl<<endl;
    cout<<VecMatrProd(0,0,2);
    return 0;
}