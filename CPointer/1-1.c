#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char **argv)
{
    printf("\x40\n");
    printf("\x100\n");
    printf("\0123\n");
    printf("\x0123\n");
    return 0;
}
