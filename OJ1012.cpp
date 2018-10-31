//动态规划
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    const int maxn = 200003;
    static int d[maxn]; //d[i]代表以i为结尾的序列的最长长度
    static long long times[maxn],cou[maxn];//times[i]表示以i为结尾的序列的个数，cou[i]表示长度为i的序列的个数

    int s,t;
    cin>>s>>t;

    int i,j,next,len;

    for(i = s;i <= t;i++)       //初始化
    {
        d[i] = 1;
        times[i] = 1;
    }
    for(i = 1;i <= (t-s+1);i++)
        cou[i] = 0;

    len = 1;
    for(i = s;i <= t;i++) //遍历每个数作为起点
    {
        for(j = 1;j <= 100;j++) //j代表增长率的数字部分
        {
            if( (i*j)%100 == 0) //要满足增长部分也为自然数
            {
                next = i + i*j/100;
                if( next <= t ) //找到了一个符合要求的自然数
                    {
                        if(d[i]+1 > d[next]) //判断长度加1后，与以next为结尾的最长序列长度大小关系
                        {
                            d[next] = d[i] + 1;     //若加1后更大，将加1后的值更新到d[next]
                            times[next] = times[i]; //以next为结尾的序列个数与以i为结尾的序列个数相同
                        }
                        else if(d[i]+1 == d[next]) //若加1后与以next为结尾的最长序列长度相同，最长长度不变，个数得增加
                        {
                            times[next] += times[i];
                        }
                        len = max(len,d[next]);  //更新长度
                        cou[d[i]+1] += times[i]; //长度加1，对应长度的序列个数增加
                    }
            }
        }
    }

    cout<<len<<endl;
    cout<<cou[len]<<endl;
    return 0;
}
