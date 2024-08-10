#include <stdio.h>

#include <stdlib.h>

int c[20], count = 0;

int place(int k, int col);
void queen(int k, int n);

int main() {
    int n;
    printf(" - N Queens Problem Using Backtracking -");
    printf("\n\nEnter number of Queens: ");
    scanf("%d", &n);

    if (n == 2 || n == 3) {
        printf("No solution exists\n");
    } else {
        queen(1, n);
    }

    return 0;
}

int place(int k, int col) {
    int i;
    for (i = 1; i <= k - 1; i++) {
        if ((c[i] == col) || (abs(c[i] - col) == abs(i - k)))
            return 0;
    }
    return 1; 
}

void queen(int k, int n) {
    int col;
    for (col = 1; col <= n; col++) {
        if (place(k, col)) {
            c[k] = col; 
            if (k == n) { 
                printf("\n\nSolution %d:\n\n", ++count);
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) { 
                        if (c[i] == j)
                            printf("\tQ"); 
                        else
                            printf("\t-"); 
                    }
                    printf("\n");
                }
            } else {
                queen(k + 1, n);
            }
        }
    }
}
