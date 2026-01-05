#include <stdio.h>

int main() {
    int a[3][3];
    int sparse[10][3];
    int i, j, k = 1, count = 0;

    /* Read matrix */
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    /* Count non-zero elements */
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (a[i][j] != 0)
                count++;
        }
    }

    /* Header row */
    sparse[0][0] = 3;      // number of rows
    sparse[0][1] = 3;      // number of columns
    sparse[0][2] = count; // non-zero elements

    /* Sparse matrix conversion */
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (a[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = a[i][j];
                k++;
            }
        }
    }

    /* Display sparse matrix */
    for (i = 0; i <= count; i++) {
        printf("%d %d %d\n",
               sparse[i][0],
               sparse[i][1],
               sparse[i][2]);
    }

    return 0;
}
