#include<iostream>

void fillgrid(int** grid, int rows, int cols){ // Рандомно заполняем массив
    srand(time(NULL));
    for (int i = 0; i < rows; i++){ 
        for (int j = 0; j < cols; j++){
            grid[i][j] = (rand()%2 == 1) ?  1: -1;
        }
    }
}

void printgrid(int** grid, int rows, int cols){ // Выводим массив
    for (int i = 0; i < rows; i++){ 
        for (int j = 0; j < cols; j++){
            (grid[i][j]==1)? std::cout<< "+ ": std::cout<< "- "; 
        } 
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

int grid_m(int** grid, int rows, int cols){ // Считаем M
    int M = 0;
    for (int i = 0; i < rows; i++){ 
        for (int j = 0; j < cols; j++){
            M += grid[i][j];
        } 
    }
    return M;
}

int grid_e(int** grid, int rows, int cols){ // Считаем E
    int n = 0;
    int k = 0;
    int E = 0;
    for (int i = 0; i < rows; i++){ 
        for (int j = 0; j < cols; j++){
            n = (i-1<0)?  rows-1 : i;
            k = (j-1<0)?  cols-1 : j;
            n = (i == rows-1)?  0 : i;
            k = (j == cols-1)?  0 : j;
            E += (grid[n][k]*grid[n][k+1])+(grid[n][k]*grid[n+1][k]);
        }
    }
    return E;
}

int is_uniform(int** grid, int rows, int cols){
    int sum = rows*cols;
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            count += (grid[0][0]==grid[i][j])?1:0;
        }
    }
    if (sum == count){
        return 1;
    }
    else return 0;
}