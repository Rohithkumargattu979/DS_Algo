/*Depending on platform, the large integer data type in C will allow you to store numbers
that are tens of digits long. In this question, you will write a program that will enable you to add
non-negative integers that are at most a thousand digits long. To this end, create two strings that
can be used to store upto 1000 digit positive integers in base 10 Each digit will be a character
in the usual positional number system. Obtain these numbers as input from the user and assume
that the first number is greater than or equal to the second and that the numbers are non-negative.
Your program should compute their sum, store it in a string without padding zeros to the left and
print it. Note: You need to write the entire program in the main() function without having to write
separate functions. Further, you are not allowed to use any header file other than stdio.h
Input
The first line of input contains the integer A (0 <= A <= 10^1000) represented as a string. The second
line of input contains the integer B (A <= B <= 10^1000) represented as a string.
Output
Print a single string, representing the sum of the two integers provided to you, without zeros padded
to the left.*/

#include<stdio.h>
int main() 
{
int num1[1000], num2[1000], sum[1000];
char s1[1000], s2[1000];
int l1, l2;

//printf("Enter Number1:");
scanf("%s", s1);
//printf("Enter Number2:");
scanf("%s", s2);

/* convert character to integer*/

for (l1 = 0; s1[l1] != '\0'; l1++)
num1[l1] = s1[l1] - '0';

for (l2 = 0; s2[l2] != '\0'; l2++)
num2[l2] = s2[l2] - '0';

int carry = 0;
int k = 0;
int i = l1 - 1;
int j = l2 - 1;
for (; i >= 0 && j >= 0; i--, j--, k++) 
{
sum[k] = (num1[i] + num2[j] + carry) % 10;
carry = (num1[i] + num2[j] + carry) / 10;
}
if (l1 > l2) 
{

while (i >= 0) 
{
sum[k++] = (num1[i] + carry) % 10;
carry = (num1[i--] + carry) / 10;
}

} 
else if (l1 < l2) 
{
while (j >= 0) 
{
sum[k++] = (num2[j] + carry) % 10;
carry = (num2[j--] + carry) / 10;
}
}
else 
{
if (carry > 0)
sum[k++] = carry;
}


//printf("Result:");
for (k--; k >= 0; k--)
printf("%d", sum[k]);

return 0;
}