#include<iostream>
using namespace std;

bool mark[5000001];
int prime[5000001];
int num[5000001]={0};
int primesize;


int main()
{
    primesize=0; //初始化
    for(int i=2;i <= 20000;i++)
    {
        if(mark[i]==true) continue;
        prime[primesize++]=i;
        for(int j=i*i;j<=5000000;j+=i)
        {
            mark[j]=true;
        }
    }

    int n;
    cin>>n;
    cout<<n<<"=";
    for(int i=0;i<primesize;i++){
        if(n%prime[i]==0){
            do{
                n=n/prime[i];
                num[i]++;
            }while(n%prime[i]==0);
        }
    }
    for(int i=0;i<primesize;i++){
        if(num[i]!=0){
            cout<<prime[i]<<"("<<num[i]<<")";
        }
    }
    return 0;
}
