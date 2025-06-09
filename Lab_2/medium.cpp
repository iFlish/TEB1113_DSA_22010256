/*
Student ID:22010256
Lab Group: 3


*/

// This program rotates a square matrix 90 degrees anti-clockwise.


#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<vector<int>> res(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[n - j - 1][i] = mat[i][j];
        }
    }


    mat = res;
}

int main() {
    int n;
    cout << "Enter the size of square matrix (n x n): ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    cout << "Enter " << n * n << " elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Element at row " << i + 1 << ", column " << j + 1 << ": ";
            cin >> mat[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    for (auto& row : mat) {
        for (int x : row) cout << x << ' ';
        cout << endl;
    }

    rotateMatrix(mat);

    cout << "\nMatrix after 90-degree anti-clockwise rotation:\n";
    for (auto& row : mat) {
        for (int x : row) cout << x << ' ';
        cout << endl;
    }

    return 0;
}
