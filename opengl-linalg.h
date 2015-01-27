#ifndef __opengl_linalg__
#define __opengl_linalg__

#include <GL/glew.h>
#include <stdbool.h>

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

/* Make a copy of a given Matrix */
matrix_t* ogllMCopy(matrix_t* m);

/* Create an Identity Matrix of size `dim` */
matrix_t* ogllMIdentity(size_t dim);

/* Are two Matrices equal? */
bool ogllMEqual(matrix_t* m1, matrix_t* m2);

/* Set a value in a Matrix */
void ogllMSet(matrix_t* m, size_t col, size_t row, GLfloat f);

/* Scale a Matrix by some scalar */
void ogllMScale(matrix_t* m, GLfloat f);

/* Add two same-sized Matrices together. Returns a new Matrix. */
matrix_t* ogllMAdd(matrix_t* m1, matrix_t* m2);

/* The values of m2 are added to m1 */
matrix_t* ogllMAddInPlace(matrix_t* m1, matrix_t* m2);

/* Multiply two matrices together. The number of rows of m2 must match
   the number of columns of m1. Returns a new Matrix. */
matrix_t* ogllMMultiply(matrix_t* m1, matrix_t* m2);

/* Multiply two 4x4 matrices together in place. Affects `m1`. */
matrix_t* ogllM4MultiplyInPlace(matrix_t* m1, matrix_t* m2);

/* Transpose a Matrix. Returns a new Matrix. */
matrix_t* ogllMTranspose(matrix_t* m);

/* Rotate a 4x4 Matrix by `r` radians. Returns a new Matrix. */
matrix_t* ogllM4Rotate(matrix_t* m, GLfloat r);

/* Rotate a 4x4 Matrix in place by `r` radians. */
matrix_t* ogllM4RotateInPlace(matrix_t* m, GLfloat r);

/* Adds translation factor to a transformation Matrix (in place) */
matrix_t* ogllM4TranslateInPlace(matrix_t* m, GLfloat x, GLfloat y, GLfloat z);

/* Produces a Perspective Projection Matrix.
   fov  := Field of View. Vertical eye angle, usually (tau/8).
   aspr := Aspect Ratio. Screen (width/height).
   n    := Distance from camera to near-clipping plane.
   f    := Distance from camera to far-clipping plane. */
matrix_t* ogllMPerspective(GLfloat fov, GLfloat aspr, GLfloat n, GLfloat f);

/* Deallocate a Matrix */
void ogllMDestroy(matrix_t* m);

/* Print a Matrix */
void ogllMPrint(matrix_t* m);

/* Print Matrix values in their internal order */
void ogllMPrintLinear(matrix_t* m);

#endif
