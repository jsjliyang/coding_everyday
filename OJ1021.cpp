//OJ1021
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

int main(){

    int i, j;
    int n;

    cin >> n;
    int mountain[n*n];
    memset(mountain,0,sizeof(mountain));

    int h = 1;
    int x = 0;
    int y = 0;

    for (int len = n - 1; len > 0; len-= 2)
    {
        for (i = 0; i < len; ++i)
        {
            mountain[x * n + (y + i)] = h + i;
            mountain[(x + i) * n +  (n - 1 - y)] = h + len + i;
            mountain[(n - 1 - x) * n + (n - 1 - y - i)] = h + 2 * len + i;
            mountain[(n - 1 - x - i) * n + (y)] = h + 3 * len + i;
        }

        h += 4 * len;
        x ++;
        y ++;
    }

    if(n % 2 == 1)
        mountain[n * n / 2] = n * n;

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j){
            cout << setw(6) << mountain[i * n + j];
        }
        cout << endl;
    }

    return 0;
}
