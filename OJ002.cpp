#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    int l,w,a,b;  //l,w为花生园的长和宽；a,b为给定区域的长和宽
    int p[1000][1000]; //二维数组存放数据
    int i = 0,j = 0,m = 0,s = 0;  //i,j用于循环，m存放区域和最大值，s存放区域和

    scanf("%d%d",&l,&w);
    for(i=0;i<l;i++)  //将矩阵数据按前缀和的思想转换为新的矩阵
    {
        for(j=0;j<w;j++)
        {

            scanf("%d",&p[i][j]);
            if(j>0 && i>0)
                p[i][j] = p[i][j] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
        }
    }

    scanf("%d%d",&a,&b);
    for(i = a-1;i<l;i++)  //循环求每个小区域的和，进行比较，选出最大的
    {
        for(j = b-1;j<w;j++)
        {
            if(i == a-1 && j== b-1)
                s = p[i][j];
            else
                s = p[i][j] - p[i][j-b] - p[i-a][j] + p[i-a][j-b];
            if(m < s)
                m = s;
        }
    }

    printf("%d",m);
    return 0;
}
