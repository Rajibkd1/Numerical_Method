#include <iostream>
#include <cmath>

void jacobiMethod(double** A, double* b, double* x, int size, int maxIterations, double tolerance)
{
    double* x_new = new double[size];
    int iteration = 0;
    double error = tolerance + 1;

    while (iteration < maxIterations && error > tolerance) {
        error = 0.0;

        // Perform one iteration of Jacobi method
        for (int i = 0; i < size; i++) {
            x_new[i] = b[i];

            for (int j = 0; j < size; j++) {
                if (j != i) {
                    x_new[i] -= A[i][j] * x[j];
                }
            }

            x_new[i] /= A[i][i];

            // Calculate the error
            error += std::abs(x_new[i] - x[i]);
        }

        // Update the solution vector
        for (int i = 0; i < size; i++) {
            x[i] = x_new[i];
        }

        std::cout << "Iteration " << iteration + 1 << ": ";
        for (int i = 0; i < size; i++) {
            std::cout << "x[" << i << "] = " << x[i] << " ";
        }
        std::cout << std::endl;

        iteration++;
    }

    if (iteration >= maxIterations) {
        std::cout << "Maximum iterations reached without convergence." << std::endl;
    } else {
        std::cout << "Solution converged after " << iteration << " iterations." << std::endl;
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

    int maxIterations;
    double tolerance;

    std::cout << "Enter the maximum number of iterations: ";
    std::cin >> maxIterations;

    std::cout << "Enter the tolerance: ";
    std::cin >> tolerance;

    jacobiMethod(A, b, x, 3, maxIterations, tolerance);

    // Clean up memory
    delete[] A[0];
    delete[] A[1];
    delete[] A[2];
    delete[] A;
    delete[] b;
    delete[] x;

    return 0;
}
