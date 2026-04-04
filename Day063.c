/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order
*/
#include<stdio.h>

int visited[100];

void DFS(int v, int n, int adj[n][n])
{
    visited[v] = 1;
    printf("%d ", v);

    for(int i = 0; i < n; i++)
    {
        if(adj[v][i] == 1 && visited[i] == 0)
        {
            DFS(i, n, adj);
        }
    }
}

int main()
{
    int n,s;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int adj[n][n];

    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d",&s);

    for(int i=0;i<n;i++)
        visited[i]=0;

    printf("DFS Traversal: ");
    DFS(s,n,adj);

    return 0;
}