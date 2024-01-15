#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n+1][W+1];
 
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i==0 || w==0) {
                K[i][w] = 0;
            } else if (wt[i-1] <= w) {
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            } else {
                K[i][w] = K[i-1][w];
            }
        }
    }
    return K[n][W];
}

int main() {
    int n, W, i;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int val[n], wt[n];
    printf("Enter the value and weight of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &val[i], &wt[i]);
    }
    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);
    int max_val = knapsack(W, wt, val, n);
    printf("The maximum value that can be put in a knapsack of capacity %d is %d\n", W, max_val);
    return 0;
}
