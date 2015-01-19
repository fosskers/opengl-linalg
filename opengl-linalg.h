#ifndef __opengl_linalg__
#define __opengl_linalg__

#include <GL/glew.h>

// --- //

typedef struct vector_t {
        GLfloat* v;
        size_t size;
} vector_t;

typedef struct matrix_t {
        GLfloat* m;
        size_t cols;
        size_t rows;
} matrix_t;

// --- //

/* Create a column-major Matrix */
matrix_t* ogllMCreate(size_t cols, size_t rows);

/* Create an Identity Matrix of size `dim` */
matrix_t* ogllMIdentity(size_t dim);

/* Set a value in a Matrix */
void ogllMSet(matrix_t* m, int col, int row, GLfloat f);

/* Deallocate a Matrix */
void ogllMDestroy(matrix_t* m);

/* Print a Matrix */
void ogllMPrint(matrix_t* m);

#endif
