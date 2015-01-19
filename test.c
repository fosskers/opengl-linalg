// Testing opengl-linalg

#include <stdlib.h>

#include "opengl-linalg.h"
#include "dbg.h"

// --- //

int main(int argc, char** argv) {
        int i;
        matrix_t* m = ogllMIdentity(4);
        check(m, "Matrix didn't create properly.");

        ogllMSet(m,3,0,7);
        ogllMPrint(m);
        ogllMDestroy(m);
        
        return EXIT_SUCCESS;

 error:
        return EXIT_FAILURE;
}
