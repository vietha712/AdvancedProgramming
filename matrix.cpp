#include "matrix.h"
#include <cstdlib>
#include "constants.h"

double** allocate(const int& numCols, const int& numRows)
{
    double **matrix;
    int i;

    matrix = new double* [numRows];

    for(i = 0; i < numCols; ++i)
    {
        matrix[i] = new double [numCols];
    }

    return matrix;
}

void deallocate(double** matrix, int numCols, int numRows)
{
    int i;

    for(i = 0; i < numCols; ++i)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void random(double** matrix, int numRows, int numCols)
{
    int i,j;

    for(i = 0; i < numRows; ++i)
    {
        for(j = 0; j < numCols; ++j)
        {
            matrix[i][j] = rand() % 10;
        }
    }
}

void zeros(double** matrix, int numRows, int numCols)
{
    int i,j;

    for(i = 0; i < numRows; ++i)
    {
        for(j = 0; j < numCols; ++j)
        {
            matrix[i][j] = 0.0;
        }
    }
}

void print(double** matrix, int numRows, int numCols)
{
    int i,j;

    for(i = 0; i < numRows; ++i)
    {
        for(j = 0; j < numCols; ++j)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
    
    cout << endl;
}

// ma
static void getCoFactor(double** matrix, 
                        double** tempMatrix, 
                        int matrixRows,
                        int matrixCols,
                        int dimension)
{
    int i, j;
    int indexRow, indexCol;
 
    // Looping for each element of the matrix
    for indexRow = 0; indexRow < dimension; ++indexRow)
    {
        for (indexCol = 0, i = 0, j = 0; indexCol < dimension; ++indexCol) 
        {
            //  Copying into temporary matrix only those
            //  element which are not in given row and
            //  column
            if (indexRow != matrixRows && indexCol != matrixCols) 
            {
                tempMatrix[i][j++] = matrix[indexRow][indexCol];
 
                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1) 
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

double det(int matrixDimension, double** matrix)
{
    double determinant = 0;
    // temporary matrix to store cofactors
    double tempMatrix[DIMENSION_SQUARE_MATRIX][DIMENSION_SQUARE_MATRIX];
    // multiplier sign
    int sign = 1;
    int i;

    // early return to reduce the complexity
    if(1 == matrixDimension)
    {
        return matrix[0][0];
    }

    for(i = 0; i < matrixDimension; ++i)
    {
        getCoFactor(matrix, tempMatrix, 0, i, matrixDimension);

        determinant += (sign * matrix[0][i] * det(matrixDimension - 1, tempMatrix));

        sign = -sign;
    }

    return determinant;
}






