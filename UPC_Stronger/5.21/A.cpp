#include <iostream>
#include <cmath>
#include <complex>
using namespace std;
const double eps=1e-8;
struct point
{
    double x,y;
    point(){}
    point(double _x,double _y)
    {
        x=_x;
        y=_y;
    }
    double operator ^(const point &b) const
    {
        return x*b.y-y*b.x;
    }  
    point operator -(const point &b) const
    {
        return point (x-b.x,y-b.y);
    }
    double operator *(const point &b) const
    {
        return x*b.x+y*b.y;
    }
};

int sgn(double x)
{
    if(fabs(x)<eps)
    return 0;
    if(x<0)
    return -1;
    else return 1;
}
struct Line
{
    point s,e;
    Line (){}
    Line (point _s,point _e)
    {
        s=_s;
        e=_e;
    }
    int seg(Line v)
    {
        int d1=sgn((e-s)^(v.s-s));
        int d2=sgn((e-s)^(v.e-s));
        int d3=sgn((v.e-v.s)^(s-v.s));
        int d4=sgn((v.e-v.s)^(e-v.s));
        if(((d1^d2)==-2) &&((d3^d4)==-2)) return 2;
        return ((d1==0 &&sgn((v.s-s)*(v.s-e))<=0)||
                (d2==0 &&sgn((v.e-s)*(v.e-e))<=0)||
                (d3==0 &&sgn((s-v.s)*(s-v.e))<=0)||
                (d4==0 &&sgn((e-v.s)*(e-v.e))<=0));
    }
};
int main()
{
    int n;
    cin>>n;
    Line A[200];
    for(int i=0;i<n;i++)
    {
        cin>>A[i].s.x>>A[i].s.y>>A[i].e.x>>A[i].e.y;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
    if(A[i].seg(A[j])!=0)
    ans++;
    cout<<ans;
}