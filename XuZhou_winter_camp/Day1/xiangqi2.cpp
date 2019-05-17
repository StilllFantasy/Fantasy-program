#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char map[30][30];
int n,xx,yy;
int dx[5]={1,-1,0,0};
int dy[5]={0,0,1,-1};
int hx[10]={2,2,-2,-2,-1,1,-1,1};
int hy[10]={-1,1,-1,1,2,2,-2,-2};
int lx[10]={1,1,-1,-1,0,0,0,0};
int ly[10]={0,0,0,0,1,1,-1,-1};
struct hor
{
    int mx;
    int my;
}M[100];
int hornum=0;
int car(int x,int y)
{
    int ok=0;
    for(int i=x+1;i<=10;i++)
    {
        if(map[i][y]=='R')
        {
            ok++;
            break;
        }
        if(map[i][y]!='R'&&map[i][y]!=' ')
        {
            break;
        }
    }
    for(int i=x-1;i>=1;i--)
    {
        if(map[i][y]=='R')
        {
            ok++;
            break;
        }
        if(map[i][y]!='R'&&map[i][y]!=' ')
        {
            break;
        }
    }
    for(int i=y+1;i<=9;i++)
    {
        if(map[x][i]=='R')
        {
            ok++;
            break;
        }
        if(map[x][i]!='R'&&map[x][i]!=' ')
        {
            break;
        }
    }
    for(int i=y-1;i>=1;i--)
    {
        if(map[x][i]=='R')
        {
            ok++;
            break;
        }
        if(map[x][i]!='R'&&map[x][i]!=' ')
        {
            break;
        }
    }
    if(ok)
    return true;
    else return false;
}
int pao(int x,int y)
{
    int ok=0;
    int a=0;
    for(int i=x+1;i<=10;i++)
    {
        if(map[i][y]=='C'&&a==1)
        {
            ok++;
            break;
        }
        if(map[i][y]!=' ')
        {
            a++;
        }
    }
    int b=0;
    for(int i=x-1;i>=1;i--)
    {
        if(map[i][y]=='C'&&b==1)
        {
            ok++;
            break;
        }
        if(map[i][y]!=' ')
        {
            b++;
        }
    }
    int c=0;
    for(int i=y+1;i<=9;i++)
    {
        if(map[x][i]=='C'&&c==1)
        {
            ok++;
            break;
        }
        if(map[x][i]!=' ')
        {
            c++;
        }
    }
    int d=0;
    for(int i=y-1;i>=1;i--)
    {
        if(map[x][i]=='C'&&d==1)
        {
            ok++;
            break;
        }
        if(map[x][i]!=' ')
        {
            d++;
        }
    }
    if(ok)
    return true;
    else return false;
}
int jiang(int x,int y)
{
    int ok=0;
    for(int i=x+1;i<=10;i++)
    {
        if(map[i][y]=='G')
        {
            ok=1;
            break;
        }
        if(map[i][y]!=' ')
        {
            break;
        } 
    }
    if(ok)
    return true;
    else return false;
}
int house(int x,int y)
{
    int ok=0;
    for(int i=1;i<=hornum;i++)
    {
        for(int j=0;j<8;j++)
        {
            int X1,X2,Y1,Y2;
            X1=M[i].mx+hx[j];
            Y1=M[i].my+hy[j];
            X2=M[i].mx+lx[j];
            Y2=M[i].my+ly[j];
            if((map[X2][Y2]==' ')&&(X1==x)&&(Y1==y))
                ok++;
        }
    }
    if(ok)
    return true;
    else return false;
}
int move(int x,int y)
{
    if(x>3||x<1||y<4||y>6)
        return false;
    if(car(x,y)||house(x,y)||jiang(x,y)||pao(x,y))
    return false;
    else return true;
}
void print()
{
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=9;j++)
        if(map[i][j]==' ')
        cout<<'-';
        else cout<<map[i][j];
        cout<<endl;
    }
}
int fly()
{
    for(int i=xx+1;i<=10;i++)
    {
        if(map[i][yy]=='G')
        return true;
        if(map[i][yy]!=' ')
        return false;
    }
}
void start()
{
    hornum=0;
    for(int i=0;i<=20;i++)
    for(int j=0;j<=20;j++)
    map[i][j]=' ';
}
int main()
{
    while(scanf("%d%d%d",&n,&xx,&yy))
    {
        if(!n)
        break;
        start();
        for(int i=1;i<=n;i++)
        {
            int a,b;
            char c;
            cin>>c>>a>>b;
            map[a][b]=c;
            if(c=='H')
            {
                hornum++;
                M[hornum].mx=a;
                M[hornum].my=b;
            }
        }
        bool ansok=false;
        if(fly())
        ansok=true;
        for(int i=0;i<4;i++)
        {
            if(move(xx+dx[i],yy+dy[i]))
            {
                ansok=true;
            }
        }
        if(ansok)
        cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}

/*

*/