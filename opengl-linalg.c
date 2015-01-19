#include <stdlib.h>

#include "opengl-linalg.h"
#include "dbg.h"

// --- //

/* Create a column-major matrix */
matrix_t* ogllMCreate(size_t cols, size_t rows) {
        matrix_t* m = NULL;
        GLfloat** innerM;
        unsigned int i,j;

        check(cols > 0 && rows > 0, "Bad dimensions given.");

        innerM = (GLfloat**)malloc(cols * sizeof(GLfloat*));
        check_mem(innerM);

        // Allocate columns
        for(i = 0; i < cols; i++) {
                innerM[i] = (GLfloat*)malloc(rows * sizeof(GLfloat));
                check_mem(innerM[i]);
        }

        // Initialize each entry to 0
        for(i = 0; i < cols; i++) {
                for(j = 0; j < rows; j++) {
                        innerM[i][j] = 0;
                }
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

/* Create an Identity Matrix of size `dim` */
matrix_t* ogllMIdentity(size_t dim) {
        matrix_t* m = ogllMCreate(dim,dim);
        unsigned int i;

        for(i = 0; i < dim; i++) {
                m->m[i][i] = 1;
        }
        
        return m;
}

/* Deallocate a Matrix */
void ogllMDestroy(matrix_t* m) {
        unsigned int i;

        if(m) {
                for(i = 0; i < m->cols; i++) {
                        free(m->m[i]);
                }

                free(m->m);
                free(m);
        }
}

/* Print a Matrix */
void ogllMPrint(matrix_t* m) {
        unsigned int i,j;

        if(m) {
                for(i = 0; i < m->rows; i++) {
                        printf("[ ");

                        for(j = 0; j < m->cols; j++) {
                                printf("%.2f ", m->m[j][i]);
                        }

                        printf("]\n");
                }
        }
}
