#include <iostream>
using namespace std;

int main(){
    int sval,cval;
    int M = 0;
    int E = 0;
    printf("|Sieve edges resoulution|\n");
    cout<<"Enter string value: ";
    cin >> sval;
    cout << "Enter column value: ";
    cin >> cval;
    cout<<"|-----------------------|\n";
    srand(time(NULL));
    int grid[sval][cval];
    for (int i = 0; i < sval; i++){ // Рандомно заполняем массив
        for (int j = 0; j < cval; j++){
            /*grid[i][j] = 1;*/
            grid[i][j] = (rand()%2 == 1) ?  1: -1;
        }
    }
    for (int i = 0; i < sval; i++){ // Выводим массив
        for (int j = 0; j < cval; j++){
            (grid[i][j]==1)? cout<< "+ ": cout<< "- "; 
        } 
        cout<<endl;
    }
    for (int i = 0; i < sval; i++){ // Считаем M
        for (int j = 0; j < cval; j++){
            M += grid[i][j];
        } 
    }
    int n = 0;
    int k = 0;
    for (int i = 0; i < sval; i++){ // Считаем E
        for (int j = 0; j < cval; j++){
            n = (i-1<0)?  sval-1 : i;
            k = (j-1<0)?  cval-1 : j;
            n = (i == sval-1)?  0 : i;
            k = (j == cval-1)?  0 : j;
            E += (grid[n][k]*grid[n][k+1])+(grid[n][k]*grid[n+1][k]);
        }
    }
    cout<<"M:"<<M<<endl;
    cout<<"E:"<<E<<endl;
    return 0;
}
