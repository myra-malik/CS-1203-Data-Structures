#include <stdio.h>
#include <stdbool.h>

//swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print the permutations
void permutations(int perm[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", perm[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    

    //setting values in the array
    int perm[8];
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
    }

    int c[8] = {0};  //counters for each position
    int i = 1;
    permutations(perm, n);

    while (i < n) {
        if (c[i] < i) {
            if (i % 2 == 0) {
                swap(&perm[0], &perm[i]);
            } else {
                swap(&perm[c[i]], &perm[i]);
            }
            permutations(perm, n);
            c[i]++;
            i = 1;
        } else {
            c[i] = 0;
            i++;
        }
    }

    return 0;
}