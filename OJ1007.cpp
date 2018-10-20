#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int pa[210],pb[210];
    int i,j,na,nb,ma,mb,flag;
    char q;
    char f1,f2;
    pa[0] = 0;
    pb[0] = 0;

    for(i = 1;i < 210;i++)
    {
        q = getchar();
        if(q == '.' )
        {
            na = i - 1;
            pa[i] = 10;
        }
        else if(q >= '0' && q <= '9')
            pa[i] = q - '0';
        else
        {
            ma = i - na - 2;
            i--;
            break;
        }
    }
    for(j = 1;j < 210;j++)
    {
        q = getchar();
        if(q == '.' )
        {
            nb = j - 1;
            pb[j] = 10;
        }
        else if(q >= '0' && q <= '9')
            pb[j] = q - '0';
        else if(q == '\n')
        {
            mb = j - nb - 2;
            j--;
            break;
        }
    }
    //求小数部分和
    flag = 0;
    if(ma >= mb)
    {
        while(1)
        {
            i = i - (ma - mb);
            pa[i] = pa[i] + pb[j] + flag;
            if(pa[i] >= 10)
            {
                pa[i] = pa[i] - 10;
                flag = 1;
            }
            else flag = 0;
            i--;
            j--;
            if(j == nb+1)
                break;
        }
        f2 = 'a';
    }
    else if(ma < mb)
    {

        while(1)
        {
            j = j - (mb - ma);
            pb[j] = pa[i] + pb[j] + flag;
            if(pb[j] >= 10)
            {
                pb[j] = pb[j] - 10;
                flag = 1;
            }
            else flag = 0;
            i--;
            j--;
            if(i == na+1)
                break;
        }
        f2 = 'b';
    }
    //求整数部分和
    if(na >= nb)
    {
        i = na;
        j = nb;
        while(1)
        {
            pa[i] = pa[i] + pb[j] + flag;
            if(pa[i] >= 10)
            {
                pa[i] = pa[i] - 10;
                flag = 1;
            }
            else flag = 0;
            i--;
            j--;
            if(j == 0)
            {
                while(flag == 1)
                {
                    pa[i] = pa[i] + flag;
                    if(pa[i] >= 10)
                        {
                            pa[i] = pa[i] - 10;
                            flag = 1;
                        }
                    else flag = 0;
                    i--;
                    if (i < 0) break;
                }
                break;
            }
        }
        f1 = 'a';
    }
    else if(na < nb)
    {
        i = na;
        j = nb;
        while(1)
        {
            pb[j] = pa[i] + pb[j] + flag;
            if(pb[j] >= 10)
            {
                pb[j] = pb[j] - 10;
                flag = 1;
            }
            else flag = 0;
            i--;
            j--;
            if(i == 0)
            {
                while(flag == 1)
                {
                    pb[j] = pb[j] + flag;
                    if(pb[j] >= 10)
                        {
                            pb[j] = pb[j] - 10;
                            flag = 1;
                        }
                    else flag = 0;
                    j--;
                    if (j < 0) break;
                }
                break;
            }
        }
        f1 = 'b';
    }
    //输出整数部分
    if(f1 == 'a')
    {
        if (pa[0] == 1) cout<<pa[0];
        for(i = 1;i <= na;i++)
            cout<<pa[i];
    }
    else if(f1 == 'b')
    {
        if (pb[0] == 1) cout<<pb[0];
        for(j = 1;j <= nb;j++)
            cout<<pb[j];
    }

    cout<<'.';

    //输出小数部分
    if(f2 == 'a')
    {
        for(i = na+2;i <= na+ma+1;i++)
            cout<<pa[i];
    }
    else if(f2 == 'b')
    {
        for(j = nb+2;j <= nb+mb+1;j++)
            cout<<pb[j];
    }
    cout<<endl;
	return 0;
}
