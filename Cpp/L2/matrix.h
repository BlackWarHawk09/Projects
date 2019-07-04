#ifndef MATRIX_H_
#define MATRIX_H_
#include <exception>
#include <string>
class Matrix
{
private:
    int nrows;
    int ncols;
    int** m;

public:
    Matrix(int, int);
    Matrix(const Matrix& obj);
    ~Matrix();

    Matrix& operator= (const Matrix &right);
    int* operator[] (const int) const;
    Matrix operator+ (const Matrix &right);
    Matrix operator- (const Matrix &right);
    Matrix operator* (const Matrix &right);
    bool operator!= (const Matrix&right);


    friend Matrix operator* (int, const Matrix&);

    Matrix T(void);
};

class MatrixExeption :public std::exception
{
    std::string exc;
public:
    MatrixExeption(const char* msg) :exc(msg) {}
    const std::string what() { return exc; }
};

#endif