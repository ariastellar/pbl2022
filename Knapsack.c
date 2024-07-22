#include<stdio.h>

int max(int a, int b)
{
    return (a>b)? a:b;
}

int knaps(int capacity,int wt[],int val[],int n)
{
    int i,j;
    int dp[n+1][capacity+1];

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=capacity;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(wt[i-1]<=j)
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][capacity];
}

int main() {
    int n, capacity;

    // Get the number of items
    printf("Enter the number of items:\n");
    scanf("%d", &n);

    int val[n];   // Array to store values of items
    int wt[n];    // Array to store weights of items

    // Input the value and weight for each item
    printf("Enter the value and weight for each item\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d value:\n", i + 1);
        scanf("%d", &val[i]);
        printf("Item %d weight:\n", i + 1);
        scanf("%d", &wt[i]);
    }

    // Input the maximum capacity of the knapsack
    printf("Enter the capacity of the knapsack:\n");
    scanf("%d", &capacity);

    // Compute the maximum value that can be achieved
    printf("The maximum value that can be obtained is %d\n", knaps(capacity, wt, val, n));

    return 0;
}