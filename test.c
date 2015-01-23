// Testing opengl-linalg

#include <stdlib.h>

#include "opengl-linalg.h"
#include "dbg.h"

// --- //

int main(int argc, char** argv) {
        int i;
        GLfloat B[6] = {5,6,2,3,1,7};
        matrix_t* m = ogllMIdentity(4);
        check(m, "Matrix didn't create properly.");

        ogllMSet(m,3,0,7);
        ogllMPrint(m);
        ogllMDestroy(m);

        puts("");
        
        m = ogllMFromArray(3,2,B);
        ogllMPrint(m);
        ogllMPrintLinear(m);
        ogllMSet(m,2,1,99);
        ogllMPrint(m);
        ogllMPrintLinear(m);
        ogllMDestroy(m);
        
        return EXIT_SUCCESS;

 error:
        return EXIT_FAILURE;
}
