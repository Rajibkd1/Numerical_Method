#include <iostream>
#include <vector>

using namespace std;

// Function to perform Gaussian elimination
void gaussianElimination(vector<vector<double>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size() - 1; // Last column is the constant terms

    for (int i = 0; i < rows - 1; i++) {
        // Partial Pivoting
        int maxRow = i;
        for (int j = i + 1; j < rows; j++) {
            if (matrix[j][i] > matrix[maxRow][i])
                maxRow = j;
        }
        swap(matrix[i], matrix[maxRow]);

        // Forward Elimination
        for (int j = i + 1; j < rows; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < cols + 1; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
}

// Function to print the matrix
void printMatrix(const vector<vector<double>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n; // Number of variables

    cout << "Enter the number of variables: ";
    cin >> n;

    // Create the matrix
    vector<vector<double>> matrix(n, vector<double>(n + 1));

    // Input the matrix
    cout << "Enter the augmented matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Matrix before Gaussian elimination:" << endl;
    printMatrix(matrix);

    // Perform Gaussian elimination
    gaussianElimination(matrix);

    cout << "Matrix after Gaussian elimination:" << endl;
    printMatrix(matrix);

    return 0;
}
