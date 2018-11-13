//OJ1019括号匹配
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string str[n];
    string result[n];

    for(int i = 0;i < n;i++)
    {
        cin>>str[i];
        int m = str[i].size();
        int flag = 0;
        if(str[i][0] == ')')
        {
            result[i] = "NO";
        }
        else
        {
            int flag = 0;
            for(int j = 0;j < m;j++)
            {
                if(str[i][j] == '(')
                {
                    flag ++;
                }
                else if(str[i][j] == ')')
                {
                    flag --;
                    if(flag < 0)
                    {
                        result[i] = "NO";
                        break;
                    }
                }
            }
            if(flag == 0)
                result[i] = "YES";
            else
                result[i] = "NO";
        }
    }

    for(int i = 0;i < n;i++)
        cout<<result[i]<<endl;
    return 0;
}
