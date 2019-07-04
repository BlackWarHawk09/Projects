#include "matrix.h"

Matrix::Matrix(int r, int c)
{
    nrows = r; ncols = c;
    m = new int*[r];
    for (int i = 0; i < r; i++)
    {
        m[i] = new int[c];
        for (int j = 0; j < c; j++)
        {
            if (i == j)
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix& obj)
{
    this->nrows = obj.nrows; this->ncols = obj.ncols;
    this->m = new int*[nrows];
    for (int i = 0; i < nrows; i++)
    {
        this->m[i] = new int[ncols];
        for (int j = 0; j < ncols; j++)
        {
            this->m[i][j] = obj.m[i][j];
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < nrows; i++)
    {
        delete[] m[i];
    }
    delete[] m;
}

Matrix& Matrix::operator= (const Matrix &right)
{
    this->ncols = right.ncols;
    this->nrows = right.nrows;
    this->m = new int*[nrows];
    for (int i = 0; i < nrows; i++)
    {
        this->m[i] = new int[ncols];
        for (int j = 0; j < ncols; j++)
        {
            this->m[i][j] = right.m[i][j];
        }
    }
    return *this;
}

int* Matrix::operator [](const int i) const
{
    return m[i];
}


Matrix Matrix::operator+ (const Matrix &right)
{
    if (ncols != right.ncols || nrows != right.nrows)
    {
        throw MatrixExeption("Can't sum matrices with different dimensions");
    }

    Matrix result(nrows, ncols);
    for (int i = 0; i < nrows; i++)
        for (int j = 0; j < ncols; j++)
            result[i][j] = m[i][j] + right.m[i][j];

    return result;
}

Matrix Matrix::operator- (const Matrix &right)
{
    if (ncols != right.ncols || nrows != right.nrows)
    {
        throw MatrixExeption("Can't subtract matrices with different dimensions");
    }

    Matrix result(nrows, ncols);
    for (int i = 0; i < nrows; i++)
        for (int j = 0; j < ncols; j++)
            result[i][j] = m[i][j] - right.m[i][j];

    return result;
}

Matrix Matrix::operator* (const Matrix &right)
{
    if (ncols != right.nrows)
    {
        throw MatrixExeption("Can't multiply matrices with dimensions A[n][q] * B[p][m], where q!=p");
    }
    Matrix result(nrows, right.ncols);
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < right.ncols; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < ncols; k++)
            {
                result[i][j] += this->m[i][k] * right[k][j];
            }
        }
    }
    return result;
}

bool Matrix::operator!= (const Matrix &right)
{
    if (ncols != right.ncols || nrows != right.nrows)
    {
        return true;
    }
    for (int i = 0; i < nrows; i++)
        for (int j = 0; j < ncols; j++)
            if (m[i][j] == right.m[i][j])
                return false;
    return true;
}

Matrix operator* (int a, const Matrix& matr)
{
    int r = matr.nrows;
    int c = matr.ncols;
    Matrix result(r, c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            result[i][j] = a * matr[i][j];
    return result;
}

Matrix Matrix::T(void)
{
    Matrix res(this->ncols, this->nrows);
    for (int i = 0; i < this->nrows; i++)
        for (int j = 0; j < this->ncols; j++)
        {
            res[j][i] = this[0][i][j];
        }
    return res;
}
