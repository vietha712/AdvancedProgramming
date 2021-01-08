#include "vector.h"
#include <cstdlib>
#include <iostream>
#include <cassert>

using namespace std;

double* allocate(int vectorLength)
{
    double* vector;

    vector = new double [vectorLength];

    return vector;
}

void deallocate(double* vector)
{
    delete[] vector;
}

void random(double* vector, int vectorLength)
{
    int i;

    for(i = 0; i < vectorLength; ++i)
    {
        vector[i] = rand() % 10;
    }
}

void zeros(double* vector, int vectorLength)
{
    int i;

    for(i = 0; i < vectorLength; ++i)
    {
        vector[i] = 0;
    }
}

double& set(double* vector, int vectorLength, int entry)
{
    assert(vectorLength > entry);

    return vector[entry];
}

void print(double* vector, int vectorLength)
{
    int i;

    for(i = 0; i < vectorLength; ++i)
    {
        cout << vector[i] << " ";
    }
    cout << endl;
}

void add(double *firstVector, 
         int firstVectorLength, 
         double *secondVector,
         int secondVectorLength, 
         double *outputVector, 
         int outputVectorLength)
{
    int i;

    assert(firstVectorLength == secondVectorLength);

    for(i = 0; i < outputVectorLength; ++i)
    {
        outputVector[i] = firstVector[i] + secondVector[i];
    }
}

double dot(double *firstVector, 
           int firstVectorLength, 
           double *secondVector, 
           int secondVectorLength)
{
    int i;
    double product(0.0);
    double output;

    assert(firstVectorLength == secondVectorLength);

    for(i = 0; i < secondVectorLength; ++i)
    {
        product = firstVector[i] * secondVector[i];
        output += product;
    }

    return output;
}