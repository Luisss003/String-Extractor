#include <stdio.h>
#include "operations.h"

int main(int argc, char *argv[]) {
    FILE *fp = fopen(argv[1], "rb");

    extract_strings(fp, argv[1]);
    return 0;
}

