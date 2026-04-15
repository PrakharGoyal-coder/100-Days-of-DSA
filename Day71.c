/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/
#include <stdio.h>
#define SIZE 100

int hashTable[SIZE];
int m;

// initialize table
void init() {
    for (int i = 0; i < SIZE; i++) 
    {
        hashTable[i] = -1;
    }
}

// hash function
int hash(int key) 
{
    return key % m;
}

// insert using quadratic probing
void insert(int key) 
{
    int h = hash(key);

    for (int i = 0; i < m; i++) 
    {
        int idx = (h + i * i) % m;

        if (hashTable[idx] == -1) 
        {
            hashTable[idx] = key;
            return;
        }
    }
}

// search using quadratic probing
int search(int key) 
{
    int h = hash(key);

    for (int i = 0; i < m; i++) 
    {
        int idx = (h + i * i) % m;

        if (hashTable[idx] == key)
            return 1;

        if (hashTable[idx] == -1)
            return 0;
    }
    return 0;
}

int main() 
{
    int q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    init();

    while(q--) 
    {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if (op[0] == 'I') 
        {
            insert(key);
        } 
        else if (op[0] == 'S') 
        {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}