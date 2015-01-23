// Testing opengl-linalg

#include <stdlib.h>

#include "opengl-linalg.h"
#include "dbg.h"

// --- //

int main(int argc, char** argv) {
        int i;
        GLfloat A[4] = {1,2,3,4};
        GLfloat B[6] = {5,6,2,3,1,7};
        GLfloat C[4] = {5,6,7,8};
        matrix_t* m = ogllMIdentity(4);
        matrix_t* n = ogllMFromArray(2,2,A);
        matrix_t* o = ogllMFromArray(2,2,C);
        check(m, "Matrix didn't create properly.");

        log_info("Altered ID Matrix");
        ogllMSet(m,3,0,7);
        ogllMPrint(m);
        ogllMDestroy(m);

        log_info("Created from Array");
        m = ogllMFromArray(3,2,B);
        ogllMPrint(m);

        log_info("Product of two matrices");
        matrix_t* prod = ogllMMultiply(n,m);
        ogllMPrint(prod);
        printf("cols: %d rows: %d\n", prod->cols, prod->rows);

        log_info("Sum of two matrices");
        matrix_t* sum = ogllMAdd(n,o);
        ogllMPrint(sum);
        
        ogllMDestroy(m);
        ogllMDestroy(n);
        ogllMDestroy(o);
        ogllMDestroy(prod);
        ogllMDestroy(sum);
        
        return EXIT_SUCCESS;

 error:
        return EXIT_FAILURE;
}
