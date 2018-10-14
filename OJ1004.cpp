//OJ1004
#include <iostream>
using namespace std;

int main()
{
    int M,T,U,F,D;
    cin>>M>>T>>U>>F>>D;
    char a; //存放上下平坡值
    int t = 0;//所用时间
    int i = 0;

    int s[T],x[T]; //分别记录上山下山时每一段路所需时间
    for(i = 0;i<T;i++)
    {
        cin>>a;
        if(a == 'u')
        {
            s[i] = U;
            x[i] = D;
        }
        else if(a == 'f')
        {
            s[i] = F;
            x[i] = F;
        }
        else if(a == 'd')
        {
            s[i] = D;
            x[i] = U;
        }
        else
            cout<<"输入错误"<<endl;
    }

    i = 0;
    while(1)
    {
        t = t + s[i] + x[i]; //计算时间
        if(t < M)
            i++;
        else if(t == M)
        {
            cout<<i+1<<endl;
            break;
        }
        else if(t > M)
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;

}
