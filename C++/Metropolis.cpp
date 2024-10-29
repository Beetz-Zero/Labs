#include <iostream>
#include <cmath>
#include "grid.cpp"
using namespace std;

void switch_spin(int** grid, int rows, int cols); 

int main(){
    int rows, cols;
    int E1 = 0;
    int E2 = 0;
    int T;
    cout<<"Enter rows value:";
    cin>>rows;
    cout<<"Enter cols value:";
    cin>>cols;
    cout<<"Enter temperature value:";
    cin>>T;
    int grid[rows][cols];
    int* ptr_grid[rows];
    for (int i = 0; i < rows; i++)
    {
        ptr_grid[i] = grid[i];
    }
    cout<<endl;
    fillgrid(ptr_grid, rows, cols);
    printgrid(ptr_grid, rows, cols);
    do
    {
        E1 = grid_e(ptr_grid, rows, cols);
        switch_spin(ptr_grid, rows, cols);
        printgrid(ptr_grid, rows, cols);
        E2 = grid_e(ptr_grid, rows, cols);
        if (E1>E2){
            E1 = E2;
        }
        else if ((rand()%100)/100<= pow(exp(1),-(E2-E1/T)))
        {
            switch_spin(ptr_grid, rows, cols);
            printgrid(ptr_grid, rows, cols);
        }
    } while (!(is_uniform(ptr_grid, rows, cols)));
    printgrid(ptr_grid, rows, cols);
        return 1;
}

void switch_spin(int** grid, int rows, int cols){
    srand(time(NULL));
    int i = rand()%rows;
    int j = rand()%cols;
    grid[i][j] = (grid[i][j] == 1)?-1:1;
}