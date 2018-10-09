#include<stdio.h>

int main()
{
    int h,hd,n,i,s[1000],j = 0;
    scanf("%d%d%d",&h,&hd,&n);
    for(i = 0;i < n;i++)
    {
        scanf("%d",&s[i]);
        if(s[i] <= h+hd) j++;
    }
    printf("%d",j);
    return 0;
}
