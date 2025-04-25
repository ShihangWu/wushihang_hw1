#include "algebra.h"
#include <stdio.h>
#include <math.h>

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{
    // ToDo
    if ((a.rows == b.rows) && (a.cols == b.cols))
    {
        int rows = a.rows;
        int cols = a.cols;
        Matrix c = create_matrix(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j  < cols; j++)
            {
                c.data[i][j] = a.data[i][j] + b.data[i][j];
            }
        }
        return c;
    }
    else
    {
        printf("Error Matrix a and b must have the same rows and cols.\n");
    }

    return create_matrix(0, 0);
}

Matrix sub_matrix(Matrix a, Matrix b)
{
    // ToDo
    if ((a.rows == b.rows) && (a.cols == b.cols))
    {
        int rows = a.rows;
        int cols = a.cols;
        Matrix c = create_matrix(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j  < cols; j++)
            {
                c.data[i][j] = a.data[i][j] - b.data[i][j];
            }
        }
        return c;
    }
    else
    {
        printf("Error Matrix a and b must have the same rows and cols.\n");
    }

    return create_matrix(0, 0);
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    // ToDo
    if (a.cols == b.rows)
    {
        int rows = a.rows;
        int cols = b.cols;
        int same = a.cols;
        Matrix c = create_matrix(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j  < cols; j++)
            {
                for (int k = 0; k < same; k++)
                {
                    c.data[i][j] = c.data[i][j] + a.data[i][k] * b.data[k][j];
                }
            }
        }
        return c;
    }
    else
    {
        printf("Error: The number of cols of matrix a must be equal to the number of rows of matrix b.\n");
    }

    return create_matrix(0, 0);
}

Matrix scale_matrix(Matrix a, double k)
{
    // ToDo
    int rows = a.rows;
    int cols = a.cols;
    Matrix b = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            b.data[i][j] = a.data[i][j] * k;
        }
    }
    return b;

    return create_matrix(0, 0);
}

Matrix transpose_matrix(Matrix a)
{
    // ToDo
    int rows = a.rows;
    int cols = a.cols;
    Matrix b = create_matrix(cols, rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            b.data[j][i] = a.data[i][j];
        }
    }
    return b;

    return create_matrix(0, 0);
}

double det_matrix(Matrix a)
{
    // ToDo
    if (a.rows == a.cols)
    {
    if (a.rows == 1 && a.cols == 1) {
        return a.data[0][0];
    }
    
    // 行列式的基本情况：2x2矩阵
    if (a.rows == 2 && a.cols == 2) {
        return a.data[0][0] * a.data[1][1] - a.data[0][1] * a.data[1][0];
    }
    
    // 对于大于2x2的矩阵，使用递归展开
    double determinant = 0;
    
    // 遍历矩阵的每一列
    for (int j = 0; j < a.cols; j++) {
        // 创建子矩阵，去掉第一行和第j列
        Matrix submatrix;
        submatrix.rows = a.rows - 1;
        submatrix.cols = a.cols - 1;
        
        // 填充子矩阵的数据
        for (int row = 1; row < a.rows; row++) {
            int sub_col = 0;
            for (int col = 0; col < a.cols; col++) {
                if (col == j) continue;  // 跳过第j列
                submatrix.data[row - 1][sub_col] = a.data[row][col];
                sub_col++;
            }
        }
        
        // 递归计算行列式，并加权
        determinant += ((j % 2 == 0 ? 1 : -1) * a.data[0][j] * det_matrix(submatrix));
    }
    
    return determinant;
    }
    else
    {
        printf("Error: The matrix must be a square matrix.\n");
    }


    return 0;
}

Matrix inv_matrix(Matrix a)
{
    // ToDo
    return create_matrix(0, 0);
}

int rank_matrix(Matrix a)
{
    // ToDo
    return 0;
}

double trace_matrix(Matrix a)
{
    // ToDo
    int rows = a.rows;
    int cols = a.cols;
    if (rows == cols)
    {
        double trace;
        for (int i = 0; i < rows; i++)
        {
            trace = trace + a.data[i][i];
        }
        return trace;
    }
    else
    {
        printf("Error: The matrix must be a square matrix.\n");
    }

    return 0;
}

void print_matrix(Matrix a)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}