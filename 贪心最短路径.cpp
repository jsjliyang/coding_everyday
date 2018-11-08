//参考资料算法练习
//迪杰斯特拉算法求最短路径，实际上是贪心和bfs（广度优先搜索）
#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 10000;
const int INF = 10000;
int d[MAXN];//记录v0到各定点的最小路径
int use[MAXN];//记录各节点是否已求得最短路径，0表示未求得，1表示已求得
int p[MAXN];//记录v0到个顶点最小路径的中间节点

int G[MAXN][MAXN];//图的矩阵
int N;

int main(){
    int i,j;
    cin >> N;
    //初始化图
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            cin >> G[i][j];
        }
    }

    fill(use, use+N, 0);
    fill(p, p+N, 0);
    for(i = 0; i < N; i++){
        d[i] = G[0][i];
    }
    use[0] = 1;//由于v0-v0不存在，因此当v0已求得最短路径

    for(i = 1; i < N; i++){
        int k, min = INF;//k为中间点,min为最小路径
        for(j = 0; j < N; j++){
            if(!use[j] && d[j] < min){
                min = d[j];
                k = j;
            }
        }
        use[k] = 1;
        for(int w = 0; w < N; w++){
            if(!use[w] && min + G[k][w] < d[w]){
                d[w] = min + G[k][w];
                p[w] = k;
            }
        }

    }
    //打印结果
    int t = p[N-1];
    cout << 5 << " << ";
    while(t > 0){
        cout << t << " << ";
        t = p[t];
    }
    cout << 0;
    cout << endl << d[N-1];
}

