#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>

class S21Matrix {
    friend S21Matrix operator*(const double value, const S21Matrix& other);
    friend S21Matrix operator*(const S21Matrix& other, const double value);

 private:
    int _rows, _cols;
    double** _matrix;

 private:
    /* accessory function mutrix */
    bool eq_matrix_loop(const S21Matrix& other);
    S21Matrix calculate_minor(int rows, int cols);
    void init_matrix();
    void checkMinusZero();
    void delate_matrix();

 public:
    /* constructor mutrix */
    S21Matrix();
    S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& other);
    S21Matrix(S21Matrix&& other);
    ~S21Matrix();

    /* accessor and mutator */
    int getRows() const;
    int getCols() const;
    void setRows(int number);
    void setCols(int number);

    /* overload the following operators */
    S21Matrix operator+(const S21Matrix& other);
    S21Matrix operator-(const S21Matrix& other);
    S21Matrix operator*(const S21Matrix& other);
    bool operator==(const S21Matrix& other);
    S21Matrix& operator=(const S21Matrix& other);
    S21Matrix& operator+=(const S21Matrix& other);
    S21Matrix& operator-=(const S21Matrix& other);
    S21Matrix& operator*=(const S21Matrix& other);
    S21Matrix& operator*=(const double value);
    double& operator()(int row, int col);

    /* operations on matrix */
    bool eq_matrix(const S21Matrix& other);
    void sum_matrix(const S21Matrix& other);
    void sub_matrix(const S21Matrix& other);
    void mul_number(const double num);
    void mul_matrix(const S21Matrix& other);
    S21Matrix transpose();
    S21Matrix calc_complements();
    double determinant();
    S21Matrix inverse_matrix();

    /* other functions */
    void fill_matrix();
};

#endif  // SRC_S21_MATRIX_OOP_H_
