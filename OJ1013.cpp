//infinite bag(war o(∩_∩)o )
#include <iostream>
#include <algorithm> //sort()函数需要
using namespace std;

struct something
{
    int a;//物品体积
    int b;//物品价值
    double s;//性价比
};

bool compare(something x,something y)
{
    return x.s > y.s;
}

int main()
{
    int v,n,i,m,value;
    cin>>v>>n;
    something w[n];
    for(i = 0;i < n;i++)
    {
        cin>>w[i].a>>w[i].b;
        w[i].s = (w[i].b * 1.0) / w[i].a;
    }

    sort(w,w+n,compare);

    m = 0;
    value = 0;
    for(i = 0;i < n;i++)
    {
        m = v/w[i].a;
        value += m*w[i].b;

        v = v%w[i].a;
        if(v == 0) break; //如果无空间，可以提前结束
    }

    cout<<value<<endl;
    return 0;
}
