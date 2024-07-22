#include<stdio.h>

void main()
{
    int i,j,k,m=0,n,a[10][10],que[10],flag[10];
    printf("enter the no of vertices: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        que[i]=0;
        flag[i]=0;
    }

    printf("enter the matrix: ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j])
                flag[j]++;
            
        }
    }

    for(k==0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(!flag[i])
            {
                flag[i]=-1;
                que[++m]=i;

                for(j=0;j<n;j++)
                {
                    if(a[i][j] && flag[j]>0)
                        flag[j]--;
                }
            }
        }
    }

    if(m==n)
    {
        printf("Topologiccal Order is: \n");
        {
            for(i=0;i<n;i++)
            {
                printf("%d",que[i]);
            }
        }
    }
    else{
        printf("No Topological Order");
    }
}