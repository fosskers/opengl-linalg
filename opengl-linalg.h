#ifndef __opengl_linalg__
#define __opengl_linalg__

#include <GL/glew.h>

// --- //

typedef struct matrix_t {
        GLfloat* m;
        size_t cols;
        size_t rows;
} matrix_t;

// --- //

// --- VECTORS --- //

/* Create a Vector filled with zeros */
matrix_t* ogllVCreate(size_t size);

/* Create a Vector from a given array of floats */
matrix_t* ogllVFromArray(size_t size, GLfloat* fs);

// --- MATRICES --- //

/* Create a column-major Matrix of all 0s */
matrix_t* ogllMCreate(size_t cols, size_t rows);

/* Create a column-major Matrix from a given array of floats */
matrix_t* ogllMFromArray(size_t cols, size_t rows, GLfloat* fs);

/* Create an Identity Matrix of size `dim` */
matrix_t* ogllMIdentity(size_t dim);

/* Set a value in a Matrix */
void ogllMSet(matrix_t* m, size_t col, size_t row, GLfloat f);

/* Scale a Matrix by some scalar */
void ogllMScale(matrix_t* m, GLfloat f);

/* Multiply two matrices together. The number of rows
   of m2 must match the number of columns of m1.
   Returns a new matrix. */
matrix_t* ogllMMultiply(matrix_t* m1, matrix_t* m2);

/* Deallocate a Matrix */
void ogllMDestroy(matrix_t* m);

/* Print a Matrix */
void ogllMPrint(matrix_t* m);

/* Print Matrix values in their internal order */
void ogllMPrintLinear(matrix_t* m);

#endif
