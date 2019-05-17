int num[10]={1,2,3,4,5,6,7,8,9,10};
int N;

//朴素查找：
int search(int K)
{
    for (int i = 0; i < N; i++)
        if (num[i] == K)
        {
            return i;
        }
    return -1;
}
//二分查找：
int search(int K, int L, int R)
{
    int l = L;
    int r = R;
    while (l <= r)
    {
        if(l == r && num[l] != K)
            return -1;

        int mid = (l + r) / 2;

        if (num[mid] < K)
            return search(K, mid + 1, R);

        else if (num[mid] > K)
            return search(K, L, mid - 1);

        else
            return mid;
    }
    return -1;
}
