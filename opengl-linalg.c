#include <stdlib.h>

#include "opengl-linalg.h"
#include "dbg.h"

// --- //

/* Create a column-major matrix */
matrix_t* ogllMCreate(size_t cols, size_t rows) {
        matrix_t* m = NULL;
        GLfloat* innerM;
        size_t i;

        check(cols > 0 && rows > 0, "Bad dimensions given.");

        innerM = (GLfloat*)malloc(cols * rows * sizeof(GLfloat));
        check_mem(innerM);

        // Initialize each entry to 0
        for(i = 0; i < cols * rows; i++) {
                innerM[i] = 0;
        }

        // Construct actual return value
        m = malloc(sizeof(matrix_t));
        check_mem(m);

        m->m = innerM;
        m->cols = cols;
        m->rows = rows;

        return m;

 error:
        return NULL;
}

/* Create a column-major Matrix from a given array of floats */
matrix_t* ogllMFromArray(size_t cols, size_t rows, GLfloat* fs) {
        matrix_t* m = NULL;
        size_t i;
        
        check(fs, "Null float array given.");
        check(cols > 0 && rows > 0, "Bad sizes given.");

        m = ogllMCreate(cols,rows);

        check(m, "Failed to create matrix.");

        for(i = 0; i < cols * rows; i++) {
                m->m[i] = fs[i];
        }
        
        return m;
 error:
        return NULL;
}

/* Create an Identity Matrix of size `dim` */
matrix_t* ogllMIdentity(size_t dim) {
        matrix_t* m = ogllMCreate(dim,dim);
        unsigned int i;

        for(i = 0; i < dim; i++) {
                m->m[dim * i + i] = 1;
        }

        return m;
}

void ogllMSet(matrix_t* m, size_t col, size_t row, GLfloat f) {
        if(m && m->cols >= col && m->rows >= row) {
                m->m[m->rows * col + row] = f;
        }
}

/* Scale a Matrix by some scalar */
void ogllMScale(matrix_t* m, GLfloat f) {
        size_t i;

        if(m) {
                for(i = 0; i < m->cols * m->rows; i++) {
                        m->m[i] *= f;
                }
        }
}

/* Multiply two matrices together. The number of rows
   of m2 must match the number of columns of m1.
   Returns a new matrix. */
matrix_t* ogllMMultiply(matrix_t* m1, matrix_t* m2) {
        matrix_t* newM = NULL;
        size_t i,j,k;

        // Were the matrices given valid?
        check(m1 && m2, "Null matrices given.");
        check(m1->cols == m2->rows, "Matrix sizes not compatible.");

        newM = ogllMCreate(m2->cols, m1->rows);
        check_mem(newM);

        for (i = 0; i < m1->rows; i++) {
                for (j = 0; j < m2->cols; j++) {
                        newM->m[j * (m1->rows) + i] = 0;

                        for (k = 0; k < m2->rows; k++) {
                                newM->m[j * (m1->rows) + i] +=
                                        m1->m[k * (m1->rows) + i] *
                                        m2->m[j * (m2->rows) + k];
                        }
                }
        }

        return newM;
 error:
        return NULL;
}

/* Deallocate a Matrix */
void ogllMDestroy(matrix_t* m) {
        if(m) {
                free(m->m);
                free(m);
        }
}

/* Print a Matrix */
void ogllMPrint(matrix_t* m) {
        size_t i,j;

        if(m) {
                for(i = 0; i < m->rows; i++) {
                        printf("[ ");

                        for(j = 0; j < m->cols; j++) {
                                printf("%.2f ", m->m[m->rows * j + i]);
                        }

                        printf("]\n");
                }
        }
}

/* Print Matrix values in their internal order */
void ogllMPrintLinear(matrix_t* m) {
        size_t i;

        if(m) {
                for(i = 0; i < (m->rows * m->cols); i++) {
                        printf("%.2f\n", m->m[i]);
                }
        }
}
