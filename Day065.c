/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO
*/

#include <stdio.h>
int visited[100];
int adj[100][100];
int n;

int dfs(int v, int parent)
{
    visited[v]=1;
    for(int i=0;i<n;i++)
    {
        if(adj[v][i]==1)
        {
            if(visited[i]==0)
            {
                if(dfs(i,v))
                    return 1;
            }
            else if(i!=parent)
            {
                return 1; // cycle found
            }
        }
    }
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
        visited[i] = 0;

    if(dfs(0, -1))
        printf("YES");
    else
        printf("NO");

    return 0;
}