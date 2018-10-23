#include<iostream>
using namespace std;

int main()
{
    int m = 0;
    int p[12],n;
    int s = 0;
    int i;
    for(i = 0;i<12;i++)
    {
        cin>>p[i];
    }
    for(i = 0;i < 12;i++)
    {
        m += 300;
        if(m < p[i])
        {
            cout<<"-"<<i+1<<endl;
            break;
        }
        n = (m - p[i])/100;
        if(n > 0)
        {
            m -= n*100;
            s += n*100;
        }
        m -= p[i];
    }
    if(i >= 12)
        cout<<m+s*1.2<<endl;
    return 0;
}
