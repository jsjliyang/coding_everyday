#include <iostream>
#include <stdio.h>
using namespace std;

double dealwith(int hand,int price,int flag)
{
    int dealnum = hand*100;
    double totalprice = dealnum*price*1.0;//乘以1.0转换为double

    double sxf = max(totalprice*0.002,5.0);
    double trans = dealnum/1000.0;
    double communication = 1.0;
    double tax = totalprice*0.001;

    if(flag == 1)
        return (-1.0)*(totalprice + sxf + trans + communication);
    else
        return totalprice - (sxf + trans + communication + tax);
}


int main()
{
    int m,n;
    double income = 0.00;
    int i,j;

    cin>>m;
    int deal[m][3];
    for(i = 0; i < m;i++)
    {
        cin>>deal[i][0];
        cin>>deal[i][1];
        cin>>deal[i][2];
    }

    cin>>n;
    int price[n][2];
    for(j = 0;j < n;j++)
    {
        cin>>price[j][0];
        cin>>price[j][1];
    }

    int p = 0;

    for(i = 0;i < m;i++)
    {
        for(j = 1;j < n;j++)
        {
            if(deal[i][0] < price[j][0] && deal[i][0] >= price[j-1][0])
            {
                p = price[j-1][1];
                break;
            }
            else
                p = price[j][1];
        }
        double dealnum = dealwith(deal[i][1],p,deal[i][2]);
        income += dealnum;
    }

    printf("%.2f\n",income);

    return 0;
}
