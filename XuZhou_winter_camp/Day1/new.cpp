#include<iostream>
using namespace std;
long long a[100000000];
long long main()
{
    long long a,b,c,d,e,f;
    while(cin>>a>>b>>c>>d>>e>>f)
    {
        if(a||b||c||d||e||f)
        {
            long long sum=0;
            sum+=f+e+d+c/4;
            a-=11*e;
            if(b>=5*d)
            b-=5*d;
            else {
                a-=4*(5*d-b);
                b=0;
            }
            c%=4;
            if(c==0)
            {
                sum+=b/9;
                b%=9;
                if(b!=0)
                {
                    sum++;
                    a-=(36-b*4);
                }
                if(a>0)
                {
                    if(a%36==0)
                    sum+=a/36;
                    else sum+=(a/36+1);
                }
            }
            else if(c==1)
            {
                sum++;
                if(b>=5)
                {
                    b-=5;
                    a-=7;
                }
                else if(b>=0)
                {
                    b=0;
                    a-=(7+(5-b)*4);
                }
                else {
                    b=0;
                    a-=27;
                }
            }
            else if(c==2)
            {
                sum++;
                if(b>=3)
                {
                    b-=3;
                    a-=6;
                }
                else if(b>=0)
                {
                    b=0;
                    a-=(6+(3-b)*4);
                }
                else 
                {
                    b=0;
                    a-=18;
                }
            }
            else if(c==3)
            {
                sum++;
                if(b>=1)
                {
                    b--;
                    a-=5;
                }
                else 
                {
                    b==0;
                    a-=9;
                }
            }
            if(b>0)
            {
                sum+=b/9;
                b%=9;
                if(b!=0)
                {
                    sum++;
                    a-=4*(9-b);
                }
            }
            if(a>0)
            sum+=a/36;
            cout<<sum<<endl;
        }
        else break;
    }
    return 0;
}