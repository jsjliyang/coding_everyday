#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXNUM 1000000
int main()
{
    static int pa[MAXNUM],pb[MAXNUM];//定义大数组时，需要定义为静态变量或者是全局变量，因为这两种变量不压栈
    int i,j,la,lb,flag;
    char q;
    char f1,f2;
    pa[0] = 0;
    pb[0] = 0;

    for(i = 1;i < MAXNUM;i++)
    {
        q = getchar();

        if(q >= '0' && q <= '9')
            pa[i] = q - '0';
        else
        {
            la = i - 1;
            break;
        }
    }
    for(j = 1;j < MAXNUM;j++)
    {
        q = getchar();
        if(q >= '0' && q <= '9')
            pb[j] = q - '0';
        else
        {
            lb = j - 1;
            break;
        }
    }

   flag = 0;
   if(la >= lb)
    {
        i = la;
        j = lb;
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
    else
    {
        i = la;
        j = lb;
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

    if(f1 == 'a')
    {
        if (pa[0] == 1) cout<<pa[0];
        for(i = 1;i <= la;i++)
            cout<<pa[i];
    }
    else if(f1 == 'b')
    {
        if (pb[0] == 1) cout<<pb[0];
        for(j = 1;j <= lb;j++)
            cout<<pb[j];
    }

    cout<<endl;
	return 0;
}
