#include <iostream>
void print(int** arr, int ROWS, int COLS);

int main(){
    int ROWS;
    int COLS;
    std::cin>>ROWS;
    std::cin>>COLS;
    int arr[ROWS][COLS] = {};
    int* ptr_arr[ROWS] = {};
    for(int i=0; i<ROWS; i++)
    {
        for (int j = 0; i < COLS; i++)
        {
            ptr_arr[i] = arr[i];
        }
    }
    print(ptr_arr,ROWS,COLS);

    return 0;
}

void print(int** arr, int ROWS, int COLS)
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