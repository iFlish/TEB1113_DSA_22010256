
/*
Student ID:22010256
Lab Group: 3


*/

// This program multiplies two matrices and prints the resultant matrix.
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int row1,column1,row2,column2 = 0;

    cout<<"Enter number of rows for first matrix: ";
    cin>>row1;
    cout<<"Enter number of columns for first matrix: ";
    cin>>column1;   
    cout<<"Enter number of rows for second matrix: ";
    cin>>row2;
    cout<<"Enter number of columns for second matrix: ";
    cin>>column2;

    if(column1 != row2){
        cout<<"Matrix multiplication not possible!"<<endl;
        return 1;
    }


    vector<vector<int>> a(row1, vector<int>(column1));
    vector<vector<int>> b(row2, vector<int>(column2));
    vector<vector<int>> c(row1, vector<int>(column2, 0));

    cout<<"Enter elements of first matrix:"<<endl;
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < column1; j++){
            cout<<"row: "<<i+1<<" column:"<<j+1<<endl;
            cin>>a[i][j];
        }
    }   

    cout<<"Enter elements of second matrix:"<<endl;
    for(int i = 0; i < row2; i++){
        for(int j = 0; j < column2; j++){
                      cout<<"row: "<<i+1<<" column:"<<j+1<<endl;
            cin>>b[i][j];
        }
    }


    for(int i = 0; i < row1; i++){
        for(int j = 0; j < column2; j++){
            c[i][j] = 0;
            for(int k = 0; k < column1; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }


    cout<<"Resultant matrix after multiplication:"<<endl;
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < column2; j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }

}