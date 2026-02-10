/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards
*/
#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    scanf("%s",str);
    str[strcspn(str,"\n")]='\0';
    int len=0;
    char str2[100];
    strcpy(str2,str);
    for(int i=0;str[i]!='\0';i++)
    {
        len++;
    }
    for(int i=0,j=len-1;i<j;i++,j--)
    {
        char ch=str2[i];
        str2[i]=str2[j];
        str2[j]=ch;
    }
    if(strcmp(str,str2)==0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");

    }
    return 0;
}