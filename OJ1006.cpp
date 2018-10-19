#include <iostream>
#include <malloc.h>
using namespace std;

int main()
{
    int n,m,i,j,p;

    cin>>n;
    int *num=(int *)malloc(n*sizeof(int));

	cin>>p;
	num[0] = p;
	for (i = 1;i < n;i++)
    {
        cin>>p;
        num[i] = num[i-1] + p;
    }

    m = 0;
    for(i = 0;i < n;i++)
    {
        if(i == 0)
        {
            p = num[1];
            for(j = 2;j < n;j++)
            {
                if(p < num[j]) p = num[j];
            }
            m = p;
        }
        else
        {
            for(j = i+1; j < n;j++)
            {
                p = num[j] - num[i - 1];
                if(p > m)  m = p;
            }
        }
    }

	if(m > 0)
        cout<<m<<endl;
    else
        cout<<"Game Over"<<endl;
	return 0;

}
