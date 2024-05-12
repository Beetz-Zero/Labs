#include <iostream>
void print(int** arr, int ROWS, int COLS);
int** init_matrix(int rows,int cols);

int main(){
    int ROWS;
    int COLS;
    std::cin>>ROWS;
    std::cin>>COLS;
    int** ptr_arr = init_matrix(ROWS,COLS);
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
int** init_matrix(int rows,int cols){
    int arr[rows][rows] = {};
    int* ptr_arr[rows] = {};
    for(int i=0; i<rows; i++)
    {
        for (int j = 0; i < cols; i++)
        {
            ptr_arr[i] = arr[i];
        }
    }
    return ptr_arr;
}