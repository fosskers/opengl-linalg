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
        GLfloat z[3] = {0,0,1};
        matrix_t* id = ogllMIdentity(4);
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
        matrix_t* prod = ogllMMultiplyP(n,m);
        ogllMPrint(prod);
        debug("cols: %d rows: %d", prod->cols, prod->rows);
        log_info("Product of incompatable matrices");
        ogllMMultiplyP(m,n);

        log_info("Sum of two matrices");
        matrix_t* sum = ogllMAddP(n,o);
        ogllMPrint(sum);

        log_info("Copying a matrix");
        matrix_t* copy = ogllMCopy(m);
        ogllMPrint(copy);

        log_info("Testing Matrix equality");
        printf("Equal? %d\n", ogllMEqual(copy,copy));
        printf("Equal? %d\n", ogllMEqual(copy,sum));

        log_info("Transpose");
        matrix_t* trans = ogllMTranspose(prod);
        ogllMPrint(trans);

        log_info("Rotating a Matrix");
        ogllMPrint(id);
        ogllM4Rotate(id,tau/2, 0,0,1);
        ogllMPrint(id);

        log_info("Cross Product");
        matrix_t* v = ogllVFromArray(4,C);
        matrix_t* cross = ogllVCrossP(v,v);
        ogllMPrint(cross);

        debug("Destroying Matrices...");

        ogllMDestroy(v);
        ogllMDestroy(cross);
        ogllMDestroy(m);
        ogllMDestroy(n);
        ogllMDestroy(o);
        ogllMDestroy(prod);
        ogllMDestroy(sum);
        ogllMDestroy(copy);
        ogllMDestroy(trans);
        
        return EXIT_SUCCESS;

 error:
        return EXIT_FAILURE;
}
