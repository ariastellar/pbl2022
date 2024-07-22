#include<stdio.h>

void dijkstra(int n,int v,int cost[10][10],int dist[])
{
    int i,u=0,w,count,min,flag[10];
    for(i=1;i<=n;i++)
    {
        flag[i]=0;
        dist[i]=cost[v][i];
    }

    flag[v]=1;
    dist[v]=0;
    count=1;

    while(count<n)
    {
        min=999;
        for(w=1;w<=n;w++)
        {
            if(dist[w]<min && !flag[w])
            {
                min=dist[w];
                u=w;
            }
        }

        flag[u]=1;
        count++;

        for(w=1;w<=n;w++)
        {
            if(dist[u]+cost[u][w]<dist[w] && !flag[w])
            {
                dist[w]=dist[u]+cost[u][w];
            }
        }
    }
}

int main()
{
    int i,j,v,n,cost[10][10],dist[10];
    printf("Enter the no of node: ");
    scanf("%d",&n);

    printf("\nEnter the Cost Matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0 && i !=j)
            {
                cost[i][j]=999;
            }
        }
    }

    printf("\nenter the Source Vertex: \n");
    scanf("%d",&v);

    dijkstra(n,v,cost,dist);
    printf("The Shortest Path From the Source Vertex: \n");
    for(j=1;j<=n;j++)
    {
    if(j!=v)
    {
        printf("%d -> %d: %d\n",v,j,dist[j]);
    }
    }
    return 0;
}