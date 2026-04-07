/*
Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order
*/
#include <stdio.h>

int queue[100], front = -1, rear = -1;
int visited[100];

void enqueue(int x)
{
    if(rear == 99)
        return;
    if(front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue()
{
    return queue[front++];
}

int isEmpty()
{
    if(front > rear)
        return 1;
    return 0;
}

int main()
{
    int n, i, j, count, adj[100][100];
    int source;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d",&source);

    for(i=0;i<n;i++)
        visited[i] = 0;

    enqueue(source);
    visited[source] = 1;

    printf("BFS Traversal: ");

    while(!isEmpty())
    {
        int v = dequeue();
        printf("%d ", v);

        for(i=0;i<n;i++)
        {
            if(adj[v][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    return 0;
}