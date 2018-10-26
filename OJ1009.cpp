#include <iostream>
#include <stdio.h>
using namespace std;


double buy(int hand,int price)
{
    int dealnum = hand*100;
    double totalprice = dealnum*price*1.0;//乘以1.0转换为double

    double sxf = max(totalprice*0.002,5.0);
    double trans = dealnum/1000.0;
    double communication = 1.0;

    return totalprice + sxf + trans + communication;
}

double sale(int hand,int price)
{
    int dealnum = hand*100;

    double totalprice = dealnum*price*1.0;//乘以1.0转换为double
    double sxf = max(totalprice*0.002,5.0);
    double trans = dealnum/1000.0;
    double communication = 1.0;
    double tax = totalprice*0.001;

    return totalprice - sxf - trans - communication - tax;
}


int main()
{
    int m,n;
    double income = 0.00;

    cin>>m;
    int deal[m][3];
    for(int i = 0; i < m;i++)
    {
        cin>>deal[i][0];
        cin>>deal[i][1];
        cin>>deal[i][2];
    }

    cin>>n;
    int price[n][2];
    for(int i = 0;i < n;i++)
    {
        cin>>price[i][0];
        cin>>price[i][1];
    }

    int p = 0;
    int flag = 0;
    for(int i = 0;i<m;i++)
    {
        int j = 1;
        for(int j = 1;j < n;j++)
        {
            if(deal[i][0] <= price[j][0] && deal[i][0] >= price[j-1][0])
                {
                    p = price[j-1][1];
                    flag = deal[i][2];
                    /*if(deal[i][2] == 1)
                    {
                        double buynum = buy(deal[i][1],price[j-1][1]);
                        income -= buynum;
                        break;
                    }
                    else if(deal[i][2] == 2)
                        {
                            double salenum = sale(deal[i][1],price[j-1][1]);
                            income += salenum;
                            break;
                        }*/
                }
            else
            {
                p = price[j][1];
                flag = deal[i][2];
                    /*if(deal[i][2] == 1)
                    {
                        double dealnum = buy(deal[i][1],price[j][1]);
                        income -= dealnum;
                        break;
                    }
                    else if(deal[i][2] == 2)
                        {
                            double dealnum = sale(deal[i][1],price[j][1]);
                            income += dealnum;
                            break;
                        }*/
            }
            if(flag == 1)
            {
                double dealnum = buy(deal[i][1],p);
                income -= dealnum;
                break;
            }
            else
            {
                double dealnum = sale(deal[i][1],p);
                income += dealnum;
                break;
            }
        }
    }

    printf("%.2f\n",income);

    return 0;
}
