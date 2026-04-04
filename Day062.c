/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* adj[100];

struct node* createNode(int v)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = v;
    newnode->next = NULL;
    return newnode;
}

void addEdge(int u, int v)
{
    struct node* newnode = createNode(v);
    newnode->next = adj[u];
    adj[u] = newnode;

    newnode = createNode(u);
    newnode->next = adj[v];
    adj[v] = newnode;
}

int main()
{
    int n,m,u,v;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter number of edges: ");
    scanf("%d",&m);

    for(int i=0;i<n;i++)
        adj[i]=NULL;

    printf("Enter edges (u v):\n");

    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);
        addEdge(u,v);
    }

    printf("\nAdjacency List:\n");

    for(int i=0;i<n;i++)
    {
        struct node* temp=adj[i];
        printf("%d: ",i);

        while(temp!=NULL)
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }

        printf("NULL\n");
    }
    return 0;
}