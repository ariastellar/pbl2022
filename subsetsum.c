#include <stdio.h>

void printSubsets(int arr[], int n, int index, int subset[], int subsetSize, int sum, int targetSum) {
    int b=1;
    if (sum == targetSum) {
        printf("\nSubset %d:\n", &b++);
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }
    
    if (index == n) return;

    // Include the current element
    subset[subsetSize] = arr[index];
    printSubsets(arr, n, index + 1, subset, subsetSize + 1, sum + arr[index], targetSum);

    // Exclude the current element
    printSubsets(arr, n, index + 1, subset, subsetSize, sum, targetSum);
}

int main() {
    int n, targetSum;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    int subset[n];
    printf("Subsets that sum to %d:\n", targetSum);
    printSubsets(arr, n, 0, subset, 0, 0, targetSum);

    return 0;
}
