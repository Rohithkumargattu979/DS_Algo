/*Shirogane wants to impress Kaguya and so he tells her that given a set of letters from the english
alphabet, he can enumerate all possible words of length K using only those letters in 1 second or
less. Obviously, this is an impossible task so he asks you, Ishigami, to bail him out so that he
doesn't look stupid in front of Kaguya.
Input
The first line consists of two space-separated integers N and K, the number of letters you can use,
and the length of each word respectively (it is guaranteed that N^K ≤ 105 and sum of lengths of
all possible words does not exceed 10^5). The second line contains a string of N distinct lowercase
English alphabets (no capital letters or special characters) representing the possible letters that you
can use. Note that you cannot use any character or letter not present in the string.
Output
print N^K lines, each line containing a distinct string of length K. Two strings are considered
distinct if they differ in at least one position.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1000000
char output[max]; 
int printoutput(char string[max],int p,int n)
{
  
  for(int i=0;i<strlen(string);i++)
  {
    output[n]=string[i];
    if(n==p-1)
    {
      printf("%s\n",output);
    }
    else
      printoutput(string,p,n+1);
  }
}
int main()
{
   int a,b;
   scanf("%d %d", &a,&b);
   char array[max];
   scanf("%s",array);
   printoutput(array,b,0);
 
}