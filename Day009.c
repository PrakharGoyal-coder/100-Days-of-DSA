/*Problem: A secret system stores code names in forward order. 
To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored
*/
#include<stdio.h>
int main()
{
    char str1[100];
    scanf("%s",str1);
    char str2[100];
    int len=0;
    for(int i=0;str1[i]!='\0';i++)
    {
        len=len+1;
    }
    int x=0;
    for(int i=len-1;i>=0;i--)
    {
        str2[x]=str1[i];
        x++;
    }
    str2[x]='\0';
    puts(str2);
    return 0;

}