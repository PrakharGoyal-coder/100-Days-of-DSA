/*
Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists
*/
#include <stdio.h>
int adj[100][100];
int visited[100];
int recStack[100];
int n;

int dfs(int v)
{
    visited[v] = 1;
    recStack[v] = 1;
    for(int i = 0; i < n; i++)
    {
        if(adj[v][i] == 1)
        {
            if(visited[i] == 0)
            {
                if(dfs(i))
                    return 1;
            }
            else if(recStack[i] == 1)
            {
                return 1; // cycle found
            }
        }
    }
    recStack[v] = 0;
    return 0;
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }

    for(int i=0;i<n;i++)
    {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for(int i=0;i<n;i++)
    {
        if(visited[i] == 0)
        {
            if(dfs(i))
            {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}