#include<stdio.h>
#define ROWS 3
#define COLS 3

void print(int arr[ROWS][COLS]);
void print2(int** arr, int rows, int cols);

int main()
{
    int arr[ROWS][COLS] = {};
    // print(arr);
    int* ptr_arr[ROWS] = {};
    for(int i=0; i<ROWS; i++)
    {
        ptr_arr[i] = arr[i];
    }
    print2(ptr_arr, ROWS,COLS);

}

void print(int arr[ROWS][COLS])
{
    for(int i = 0; i<ROWS; i++)
    {
        for(int j = 0; j<COLS; j++)
        {
            printf("%d ", arr[i][j]);
        }
    printf("\n");
    }
}
void print2(int** arr, int rows, int cols)
{
     for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
    printf("\n");
    }

}