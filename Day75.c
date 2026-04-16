/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.
*/
#include <stdio.h>

#define MAX 1000

int longestZeroSumSubarray(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Arrays to store prefix sums and their first index
    int prefix[MAX];
    int index[MAX];
    int size=0;

    for (int i=0;i<n;i++) 
    {
        sum+=arr[i];

        // Case 1: sum is 0
        if(sum==0) 
        {
            maxLen = i + 1;
        }

        // Check if sum already exists
        int found=0;
        for (int j=0;j<size;j++) 
        {
            if (prefix[j]==sum) 
            {
                int len=i-index[j];
                if (len>maxLen) 
                {
                    maxLen=len;
                }
                found = 1;
                break;
            }
        }

        // If not found, store it
        if (!found) 
        {
            prefix[size] = sum;
            index[size] = i;
            size++;
        }
    }

    return maxLen;
}

int main() 
{
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", longestZeroSumSubarray(arr, n));
    return 0;
}