double** allocate(const int& numRows, const int& numCols);

void deallocate(double** matrix, int numRows, int numCols);

void random(double** matrix, int numRows, int numCols);

void zeros(double** matrix, int numRows, int numCols);

void print(double** matrix, int numRows, int numCols);

double det(int matrixDimension, double** matrix);