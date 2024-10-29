#include <iostream>
#include "grid.cpp"
using namespace std;

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