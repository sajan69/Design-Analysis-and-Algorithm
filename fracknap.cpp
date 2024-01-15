#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent items in the knapsack
struct Item {
    int weight;
    int value;
    float ratio; // value-to-weight ratio
};

// Function to compare two items based on their ratio
int cmp(const void* a, const void* b) {
    struct Item* itemA = (struct Item*) a;
    struct Item* itemB = (struct Item*) b;
    return (int) (itemB->ratio - itemA->ratio);
}

// Function to solve the Fractional Knapsack problem using a greedy approach
float fractionalKnapsack(int W, struct Item arr[], int n) {
    // Sort the items based on their value-to-weight ratio
    qsort(arr, n, sizeof(struct Item), cmp);

    int curWeight = 0;  // Current weight in the knapsack
    float totalValue = 0.0; // Total value in the knapsack

    // Traverse the sorted array and add items to the knapsack until it is full
    for (int i = 0; i < n; i++) {
        // If adding the entire item exceeds the knapsack capacity, add a fraction of the item
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            totalValue += arr[i].value;
        } else {
            int remainingWeight = W - curWeight;
            totalValue += arr[i].ratio * remainingWeight;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);

    // Create an array of items
    struct Item arr[n];
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].weight, &arr[i].value);
        arr[i].ratio = (float) arr[i].value / arr[i].weight;
    }

    float totalValue = fractionalKnapsack(W, arr, n);
    printf("The maximum value in the knapsack is: %.2f", totalValue);

    return 0;
}
