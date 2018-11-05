
//货箱装载的贪心算法
void containerLoading(container* c,int capacity,int numberOfContainers,int* x)
{
    //令x[i] = 1，当且仅当货箱i(i > 1)已装载
    heapSort(c,numberOfContainers);//堆排序法，按重量递增排列

    int n = numberOfContainers;

    for(int i = 1;i <= n;i++) x[i] = 0; //初始化x

    for(int i = 1;i <= n && c[i].weight <= capacity;i++)
    {
        x[c[i].id] = 1;
        capacity -= c[i].weight; //剩余容量
    }
}

//快速排序算法
void QiickSort(int *arr,int left,int right)
{
    int f,t;
    int rtemp,ltemp;

    ltemp = left;
    rtemp = right;
    f = arr[(left + right)/2]; //确定分界值
    while(ltemp<rtemp)
    {
        while(arr[ltemp] < f)
            ++ltemp;
        while(arr[rtemp] > f)
            --rtemp;
        if(ltemp <= rtemp)
        {
            t = arr[ltemp];
            arr[ltemp] = arr[rtemp];
            arr[rtemp] = t;
            --rtemp;
            ++ltemp;
        }
    }
    if(ltemp == rtemp)
    {
        ltemp++;
    }

    if(left < rtemp)
        QuickSort(arr,left,ltemp-1);   //递归
    if(ltemp < right)
        QuickSort(arr,rtemp+1,right);  //递归
}
