//OJ1003
#include <iostream>
using namespace std;

int main()
{
    int l; //边长
    cin>>l;

    int p[l][l]; //存放格子
    int fx[l*l]; //格子为1，需要遍历的格子x坐标
    int fy[l*l]; //格子为1，需要遍历的格子y坐标
    int nx[l*l]; //存放繁殖后变为1的格子x坐标
    int ny[l*l]; //存放繁殖后变为1的格子y坐标
    int w = 0,nw = 0; //w和nw分别为遍历和下次遍历的次数
    int m = 0; //繁殖轮数
    int c[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; //用于上下左右繁殖的坐标变化
    int i,j;
    int x,y; //中间存放坐标数值

    for(i = 0;i < l;i++) //存放矩阵
    {
        for(j = 0;j < l;j++)
        {
            cin>>p[i][j];
            if(p[i][j] == 1)
            {
                fx[w] = i;
                fy[w] = j;
                w++;
            }
        }
    }

    while(1) //循环遍历
    {
        for(i = 0;i < w;i++) //遍历繁殖并记录下一次遍历的坐标
            {
                for(j = 0;j < 4;j++)
                    {
                        x = fx[i] + c[j][0];
                        y = fy[i] + c[j][1];

                        if(x >= 0 && y >= 0 && x < l && y < l) //没有边界溢出继续进行
                            {
                                if(p[x][y] == 0)
                                {
                                    nx[nw] = x;
                                    ny[nw] = y;
                                    nw++;
                                    p[x][y] = 1;
                                }
                            }
                    }
            }
        if(nw == 0)  break;   //本次没有进行繁殖的，循环结束
        for(i = 0; i < nw; i++) //更新需要遍历的数组
        {
            fx[i] = nx[i];
            fy[i] = ny[i];
        }
        w = nw;
        nw = 0;
        m++;   //繁殖结束，m+1
    }
    cout<<m;
    return 0;
}
