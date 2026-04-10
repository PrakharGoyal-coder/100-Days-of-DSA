/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
*/
#include <stdio.h>
#define MAX 10
int queue[MAX], front = -1, rear = -1;
void enqueue(int x) 
{
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() 
{
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isEmpty() {
    if (front == -1 || front > rear)
        return 1;
    return 0;
}

int main() 
{
    int n, i, j;
    int adj[MAX][MAX];
    int indegree[MAX] = {0};
    int topo[MAX], k = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Calculate indegree of each vertex
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            if (adj[i][j] == 1)
                indegree[j]++;
        }
    }

    // Enqueue vertices with indegree 0
    for (i = 0; i < n; i++) 
    {
        if (indegree[i] == 0)
            enqueue(i);
    }

    while (!isEmpty()) 
    {
        int v = dequeue();
        topo[k++] = v;

        for (j = 0; j < n; j++) 
        {
            if (adj[v][j] == 1) 
            {
                indegree[j]--;
                if (indegree[j] == 0)
                    enqueue(j);
            }
        }
    }

    printf("Topological Order: ");
    for (i = 0; i < k; i++) {
        printf("%d ", topo[i]);
    }

    return 0;
}