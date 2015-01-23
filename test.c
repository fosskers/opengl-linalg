// Testing opengl-linalg

#include <stdlib.h>

#include "opengl-linalg.h"
#include "dbg.h"

// --- //

int main(int argc, char** argv) {
        int i;
        GLfloat A[4] = {1,2,3,4};
        GLfloat B[6] = {5,6,2,3,1,7};
        matrix_t* m = ogllMIdentity(4);
        matrix_t* n = ogllMFromArray(2,2,A);
        check(m, "Matrix didn't create properly.");

        puts("/* Altered ID Matrix */");
        ogllMSet(m,3,0,7);
        ogllMPrint(m);
        ogllMDestroy(m);

        puts("");

        puts("/* Created from Array */");
        m = ogllMFromArray(3,2,B);
        ogllMPrint(m);

        puts("");

        puts("/* Product of two matrices */");
        matrix_t* prod = ogllMMultiply(n,m);
        ogllMPrint(prod);
        printf("cols: %d rows: %d\n", prod->cols, prod->rows);

        ogllMDestroy(m);
        ogllMDestroy(n);
        ogllMDestroy(prod);
        
        return EXIT_SUCCESS;

 error:
        return EXIT_FAILURE;
}
