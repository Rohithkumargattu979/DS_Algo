#include<stdio.h>
int div(int n)
{
    int c = 0;
    for(int i =2; i<n; i++)
    {
        if(n%i == 0)
        {
            c++;
        }
    }
    return c;
}
int rec(int n)
{
    int d = div(n);
    //printf("%d ", d);
    
    int m1,m2, count = 0;
    for(int i = n-1; i>=2; i--)
    {
        if(n%i == 0)
        {
            count++;
            if(count == 1)
            {
                m1 = n/i;
                //printf("%d ", m1);
            }
            if(count == 2)
            {
                m2 = n/i;
                //printf("%d ", m1);
                break;
            }
        }
    }
    if(d<=1)
    {
        return n;
    }
    else{
        return rec(m1) + rec(m2);
    }

}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", rec(n));
    return 0;
}