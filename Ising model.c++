#include <iostream>
using namespace std;

int main(){
    int sval,cval;
    int m = 0;
    int e = 0;
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
            (rand()%2 == 1) ? grid[i][j] = 1: grid[i][j] = -1;
        }
    }
    for (int i = 0; i < sval; i++){ // Выводим массив
        for (int j = 0; j < cval; j++){
            (grid[i][j]==1)? cout<<"+ ": cout<<"- "; 
        } 
        cout<<endl;
    }
    for (int i = 0; i < sval; i++){ // Считаем M
        for (int j = 0; j < cval; j++){
            m += grid[i][j];
        } 
    }
    int n = 0;
    int k = 0;
    for (int i = 0; i < sval; i++){ // Считаем E
        for (int j = 0; j < cval; j++){
            (i-1<0)? n = sval-1 :n = i;
            (j-1<0)? k = cval-1 :k = j;
            (i == sval-1)? n = 0 :n = i;
            (j == cval-1)? k = 0 :k = j;
            e += (grid[n][k]*grid[n][k+1])+(grid[n][k]*grid[n+1][k]);
        }
    }
    cout<<"M:"<<m<<endl;
    cout<<"E:"<<e<<endl;
    return 0;
}
