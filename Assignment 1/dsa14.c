/* With Amazon's yearly sale going on, you wish to buy as many goods as your wish with you
limited pocket money you have collected till date. As the sale time is running out, you decide to
write a simple program that will help you buy as many goods as possible without exceeding your
budget. Hint: Think in terms of subsets and how subsets can visualized with binary numbers.
Input
The first line contains a single integer M (0 ≤ M ≤ 10^9) that denotes your pocket money. The
following line contains another integer N (1 ≤ N ≤ 25) denoting the number of goods that are for
sale in Amazon. The last line of input contains N space-separated integers (0 ≤ Pi ≤ 10^9) denoting
the prices of the goods for sale.
Output
Print a single integer X, denoting the maximum number of goods you can buy without exceeding
your budget. */
#include<stdio.h>
int main()
{
    int m, n, temp, maxgoods = 0, sum = 0;
    scanf("%d",&m);
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) 
        {
 
            for (int j = i + 1; j < n; ++j)
            {
 
                if (a[i] > a[j]) 
                {
 
                    temp =  a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        for(int i = 0; i<n; i++)
        {
            sum = sum + a[i];
            if(m>=sum)
             maxgoods++;
        }

        printf("%d\n", maxgoods);


}
