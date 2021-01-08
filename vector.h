double* allocate(int vectorLength);

void deallocate(double* vector);

void random(double* vector, int vectorLength);

void zeros(double* vector, int vectorLength);

double* set(double& vector, int vectorLength, int entry);

void print(double* vector, int vectorLength);

void add(double *firstVector, 
         int firstVectorLength, 
         double *secondVector,
         int secondVectorLength, 
         double *outputVector, 
         int outputVectorLength);

double dot(double *firstVector, 
           int firstVectorLength, 
           double *secondVector, 
           int secondVectorLength);