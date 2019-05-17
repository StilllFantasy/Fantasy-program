#include <iostream>
#include <cstring>
#include <map>
using namespace std;
map<int,int>m;
map<int,int>mm;
int a[1000006];
int f[1000006];
int ff[1000006];
void GetNextval(char* p, int next[])  
{  
    int pLen = strlen(p);  
    next[0] = -1;  
    int k = -1;  
    int j = 0;  
    while (j < pLen - 1)  
    {  
       
        if (k == -1 || p[j] == p[k])  
        {  
            ++j;  
            ++k;  
            if (p[j] != p[k])  
                next[j] = k;  
            else  
               
                next[j] = next[k];  
        }  
        else  
        {  
            k = next[k];  
        }  
    }  
}  
int main()
{
    
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        int &k = m[a[i]];
        k++;
        f[i]=k;
    }
    for(int i=n;i>=1;i--)
    {
        int &k=mm[a[i]];
        k++;
        ff[i]=k;
    }   
    int ans=0;
    for(int i=1;i<n;i++)
    for(int j=i+1;j<=n;j++)
    if(f[i]>ff[j])
    ans++;
    cout<<ans;
    
    return 0;
}