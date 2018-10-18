#include <iostream>
using namespace std;

bool isnine(int a[])  //检测矩阵中的元素是否是1-9的全部元素
{
	bool flag = true;
	int b[10] = {0,0,0,0,0,0,0,0,0,0};
	int i,j;
	for (i = 0; i < 9; i++)
    {
        j = a[i];
        if(1 <= j && j <= 9);
        else
        {
            flag = false;
            break;
        }

        if(b[j] == 0)
            b[j] = j;
        else if(b[j] == j)
        {
            flag = false;
            break;
        }
    }
	return flag;
}
string issudoku()   //判断数独是否符合规则
{
	string si;
	int su[9][9], s[9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> su[i][j];
	bool flag = true;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			s[j] = su[i][j];
		if (!isnine(s))
		{
			flag = false;
			break;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			s[j] = su[j][i];
		if (!isnine(s))
		{
			flag = false;
			break;
		}
	}
	for (int i = 0; i < 9; i += 3)
		for (int j = 0; j < 9; j += 3)
		{
		for (int m = 0; m < 3; m++)
			for (int n = 0; n < 3; n++)
				s[3 * m + n] = su[i + m][j + n];
		if (!isnine(s))
		{
			flag = false;
			break;
		}
		}
	if (flag)
		si = "Right";
	else
		si = "Wrong";
	return si;
}
int main()
{
	int n;
	cin >> n;
	string s[20];
	for (int i = 0; i < n; i++)
		s[i] = issudoku();
	for (int i = 0; i < n; i++)
		cout << s[i] << endl;
	return 0;

}
