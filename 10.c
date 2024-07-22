#include<stdio.h>
#include<stdbool.h>
#define MAX 20
void printBoard(int board[MAX][MAX],int n)
{
    int i;
    for(i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%c ",board[i][j]?'Q':'.');
    printf("\n");
    }
}
bool isSafe(int board[MAX][MAX],int n, int row,int col)
{
    int i,j;
    for(i=0;i<col;i++)
        if(board[row][i])
            return false;
    for(i=row,j=col; i>=0 && j>=0; i--,j--)
        if(board[i][j])
            return false;
    for(i=row,j=col; i<n&&j>=0; i++,j--)
        if(board[i][j])
            return false;
    return true;
}
bool solve(int board[MAX][MAX],int n, int col)
{
    if(col>=n)
        return true;
    for(int i=0;i<n;i++)
    {
        if(isSafe(board,n,i,col))
        {
            board[i][col]=1;
            if(solve(board, n, col+1))
                return true;
            board[i][col]=0;
        }
    }
    return false;
}
void NQ(int n)
{
    int board[MAX][MAX]={0};
    if(!solve(board,n,0))
        printf("No Solution.");
    else
        printBoard(board,n);
}
int main()
{
    int n;
    printf("Number of queens (<20):\n");
    scanf("%d",&n);
    NQ(n);
    return 0;
}
