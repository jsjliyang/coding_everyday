#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
const int N=1000000;

using namespace std;
char a[N],b[N];       //定义大数组时，需要定义为静态变量或者是全局变量，因为这两种变量不压栈
int x[N],y[N],c[N];   //定义大数组时，需要定义为静态变量或者是全局变量，因为这两种变量不压栈
int len;
int d=0;
void cheng(char *a,char *b)
{

}
int main()
{
	cin>>a;
	cin>>b;

	int lena=strlen(a);
	int lenb=strlen(b);
	for(int i=0;i<lena;i++)   //倒序
		x[i]=a[lena-i-1]-'0';
	for(int i=0;i<lenb;i++)
		y[i]=b[lenb-i-1]-'0';
	for(int i=0;i<lena;i++)
		for(int j=0;j<lenb;j++)
		{
			c[i+j]+=x[i]*y[j];
			c[i+j+1]+=c[i+j]/10;
			c[i+j]%=10;
		}
	int len=lena+lenb;
	while(len>1&&c[len-1]==0)
		len--;//处理前导零
	d=len;

    for(int i=d-1;i>=0;i--)
		cout<<c[i];
    cout<<endl;
	return 0;
}
