/*这种方法是将要计算的矩阵撕成竖条，将矩阵横向移动，减去上竖条，再加下竖条就是新矩阵的值。
横向移动结束后，将矩阵下移，重新计算矩阵的和，再次橫移。
可以减少计算的次数，相当于每次都是在一个一维数组中进行。*/
//特别注意：题目中说l和a、w和b分别是长、宽，因此在矩阵中i表示行数，j表示列数，因此l和a与j、w和b与i对应。
//但是题目给例子的时候将l作为了矩阵的行数，w作为了矩阵的列数，因此在这里我将w和l、a和b的赋值顺序做了对调。
//我觉得是题意与实例之间的对应出现了差错。题目的异义。

#include <iostream>
using namespace std;

int a,b;
int p[1000][1000];//p是矩阵
int t[1000];//t是竖条

int sitiao(int h,int v) //撕条，计算选取竖条的和。h是第几行，v是第几列。
{
    int sum = 0;
    if(h>0)  //竖条下移。如果不是第一行，将之前的竖条减去最上面的数字，加再下移的数字。
    {
        sum = t[v] - p[h-1][v] + p[h+b-1][v];
        return sum;
    }
    for(int k = h;k<b+h;k++)  //如果竖条第一个数字在第一行，只能循环计算。
        sum = sum + p[k][v];
    return sum;
}

int main()
{
    int l,w; //l,w分别为长和宽
    int m = 0;  //用于存放最大值
    int juzhen = 0;//用于存放小矩阵的和
    int i,j;

    cin>>w>>l;
    for(i = 0;i<w;i++)//矩阵输入
    {
        for(j = 0;j<l;j++)
            cin>>p[i][j];
    }

    cin>>b>>a;
    for(i = 0;i <= w-b;i++)
    {
        juzhen = 0;
        for(int s = 0;s < a;s++)//每次橫移前小矩阵初始化
        {
            t[s] = sitiao(i,s);
            juzhen = juzhen + t[s];
        }
        if(juzhen > m)
            m = juzhen;
        for(j = a;j < l;j++) //逐渐橫移
        {
            t[j] = sitiao(i,j);
            juzhen = juzhen + t[j] - t[j-a];
            if(juzhen > m)
                m = juzhen;
        }
    }
    cout<<m<<endl;
    return 0;
}
