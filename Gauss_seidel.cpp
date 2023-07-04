#include <iostream>
#include <cmath>

void gaussSeidelMethod(double** A, double* b, double* x, int size, double tolerance)
{
    double* x_new = new double[size];
    double error = tolerance + 1;

    while (error > tolerance) {
        error = 0.0;

        for (int i = 0; i < size; i++) {
            x_new[i] = b[i];

            for (int j = 0; j < size; j++) {
                if (j != i) {
                    x_new[i] -= A[i][j] * x_new[j];
                }
            }

            x_new[i] /= A[i][i];

            error += std::abs(x_new[i] - x[i]);
            x[i] = x_new[i];
        }
    }

    delete[] x_new;
}

int main()
{
    double** A = new double*[3];
    double* b = new double[3];
    double* x = new double[3];

    A[0] = new double[3];
    A[1] = new double[3];
    A[2] = new double[3];

    std::cout << "Enter the coefficients of the equations:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "Equation " << i + 1 << ":" << std::endl;
        for (int j = 0; j < 3; j++) {
            std::cout << "A[" << i << "][" << j << "]: ";
            std::cin >> A[i][j];
        }
        std::cout << "b[" << i << "]: ";
        std::cin >> b[i];
    }

    std::cout << "Enter the initial values of x, y, and z:" << std::endl;
    std::cout << "x: ";
    std::cin >> x[0];
    std::cout << "y: ";
    std::cin >> x[1];
    std::cout << "z: ";
    std::cin >> x[2];

    double tolerance;
    std::cout << "Enter the tolerance: ";
    std::cin >> tolerance;

    gaussSeidelMethod(A, b, x, 3, tolerance);

    std::cout << "Solution found:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "x[" << i << "] = " << x[i] << std::endl;
    }

    // Clean up memory
    delete[] A[0];
    delete[] A[1];
    delete[] A[2];
    delete[] A;
    delete[] b;
    delete[] x;

    return 0;
}
