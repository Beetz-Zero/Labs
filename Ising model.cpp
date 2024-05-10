#include <iostream>
using namespace std;

void fillgrid(int** grid, int rows, int cols); 
void printgrid(int** grid, int rows, int cols);
int grid_m(int** grid, int rows,int cols);
int grid_e(int** grid, int rows, int cols);

int main(){
    int sval,cval;
    int M = 0;
    int E = 0;
    printf("|Grid edges resoulution|\n");
    cout<<"Enter rows value: ";
    cin >> sval;
    cout << "Enter cols value: ";
    cin >> cval;
    int grid[sval][cval];
    int* ptr_grid[sval];
    for (int i = 0; i < sval; i++)
    {
        ptr_grid[i] = grid[i];
    }
    cout<<"|-----------------------|\n";
    fillgrid(ptr_grid,sval,cval);
    printgrid(ptr_grid,sval,cval);
    M = grid_m(ptr_grid,sval,cval);
    E = grid_e(ptr_grid,sval,cval);
    cout<<"M:"<<M<<endl;
    cout<<"E:"<<E<<endl;
    return 0;
}

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
            (grid[i][j]==1)? cout<< "+ ": cout<< "- "; 
        } 
        cout<<endl;
    }
}

int grid_m(int** grid, int rows, int cols){ // Считаем M
    int M;
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