// or Q2.Create a class Matrix and Write a C++ program to perform following functions:
// a. To accept a Matrix
// b. To display a Matrix
// c. Overload unary minus ‘–‘ operator to calculate transpose of a Matrix
// d. Overload binary multiplication '*’ operator to calculate multiplication of two matrices
#include <iostream>

using namespace std;

class Matrix {
  private:
    int rows;
    int columns;
    int **data;

  public:
    Matrix() { // Default constructor
      rows = 0;
      columns = 0;
      data = NULL;
    }

    Matrix(int r, int c) { // Parameterized constructor
      rows = r;
      columns = c;
      data = new int*[rows];
      for (int i = 0; i < rows; i++) {
        data[i] = new int[columns];
      }
    }

    void acceptMatrix() { // Accept a Matrix
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          cout << "Enter value at (" << i << ", " << j << "): ";
          cin >> data[i][j];
        }
      }
    }

    void displayMatrix() { // Display a Matrix
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          cout << data[i][j] << " ";
        }
        cout << endl;
      }
    }

    Matrix operator-() { // Unary minus operator to calculate transpose of a Matrix
      Matrix result(columns, rows);

      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          result.data[j][i] = data[i][j];
        }
      }

      return result;
    }

    Matrix operator*(const Matrix& other) { // Binary multiplication operator to calculate multiplication of two matrices
      Matrix result(rows, other.columns);

      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.columns; j++) {
          result.data[i][j] = 0;
          for (int k = 0; k < columns; k++) {
            result.data[i][j] += data[i][k] * other.data[k][j];
          }
        }
      }

      return result;
    }
};

int main() {
  int m, n;
  cout << "Enter number of rows for Matrix 1: ";
  cin >> m;
  cout << "Enter number of columns for Matrix 1: ";
  cin >> n;

  Matrix matrix1(m, n);
  matrix1.acceptMatrix();

  cout << endl << "Matrix 1: " << endl;
  matrix1.displayMatrix();

  cout << endl << "Transpose of Matrix 1: " << endl;
  Matrix transpose1 = -matrix1;
  transpose1.displayMatrix();

  int p;
  cout << endl << "Enter number of columns for Matrix 2: ";
  cin >> p;

  Matrix matrix2(n, p);
  matrix2.acceptMatrix();

  cout << endl << "Matrix 2: " << endl;
  matrix2.displayMatrix();

  cout << endl << "Multiplication of Matrix 1 and Matrix 2: " << endl;
  Matrix multiplication = matrix1 * matrix2;
  multiplication.displayMatrix();

  return 0;
}
