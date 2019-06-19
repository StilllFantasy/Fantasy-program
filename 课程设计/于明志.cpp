/*
    kruscal + lca , 给定一个国家的建设计划，许多条铁路，求把这些城市都链接起来需要多少里程，
    建树图之后还可以求两城市之间的距离
    可以输出连接两个城市之间的道路（不一定是最优路线），沿路经过的城市
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <stack>
#include <windows.h>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int dep[1000];
int fah[1000];
int dis[1000];
map<string, int> numb;
map<int, string> name;
int N, M;
vector<int> road;
struct edg
{
    int t;
    int w;
};
vector<edg> G[1000];
struct edge
{
    int A;
    int B;
    int W; 
    int K;
} E[1000];
int getkey(char l, char r)
{
    string s;
    cin >> s;
    while (s.length() > 1 || s[0] > r || s[0] < l)
    {
        cout << ">-:Error, try again!" << endl;
        cin >> s;
    }
    return (int)(s[0] - l + 1);
}
int lca(int x, int y)
{
    //cout<<dep[x]<<" "<<dep[y]<<endl;
    while (dep[x] > dep[y])
        x = fah[x];
    while (dep[x] < dep[y])
        y = fah[y];
    while (x != y)
    {
        x = fah[x];
        y = fah[y];
    }
    return x;
}
bool cmp(edge a, edge b)
{
    return a.W < b.W;
}
bool cmp2(edge a, edge b)
{
    return a.K < b.K;
}
int find(int x)
{
    if (x == fah[x])
        return x;
    return fah[x] = find(fah[x]);
}
void dfs(int x, int f, int d, int s)
{
    fah[x] = f;
    dep[x] = d;
    dis[x] = s;
    for (int i = 0; i < G[x].size(); i++)
        if (!dep[G[x][i].t])
        {
            dfs(G[x][i].t, x, d + 1, s + G[x][i].w);
        }
}
struct Solve
{
    int ans = 0;
    int build()
    {
        for (int i = 1; i <= N; i++)
            fah[i] = i;
        sort(E + 1, E + 1 + M, cmp);
        for (int i = 1; i <= M; i++)
        {
            int fa = find(E[i].A);
            int fb = find(E[i].B);
            if (fa != fb)
            {
                fah[fa] = fb;
                G[E[i].A].push_back({E[i].B, E[i].W});
                G[E[i].B].push_back({E[i].A, E[i].W});
                ans += E[i].W;
                road.push_back(E[i].K);
            }
        }
        for (int i = 1; i <= N; i++)
        {
            fah[i] = 0;
            dis[i] = 0;
            dep[i] = 0;
        }
        dfs(1, 1, 1, 0);
        return ans;
    }
    void detail()
    {
        sort(E + 1, E + M + 1, cmp2);
        cout << ">:- Total construction of " << road.size() << " roads" << endl;
        for (int i = 0; i < road.size(); i++)
        {
            cout << i + 1 << " . " << name[E[road[i]].A] << "<---->" << name[E[road[i]].B] << "    " << E[road[i]].W << endl;
        }
    }

    void check(int x, int y)
    {
        int f = lca(x, y);
        cout << ">:- the lca is " << name[f] << endl;
        cout << ">:- The distance of this two cities is " << dis[x] + dis[y] - 2 * dis[f] << endl;
        stack<int> s;
        queue<int> q;
        cout << "Route : ";
        while (x != f)
        {
            q.push(x);
            x = fah[x];
        }
        q.push(f);
        while (y != f)
        {
            s.push(y);
            y = fah[y];
        }
        cout << name[q.front()];
        q.pop();
        while (!q.empty())
        {
            cout << "-->" << name[q.front()];
            q.pop();
        }
        while (!s.empty())
        {
            cout << "-->" << name[s.top()];
            s.pop();
        }
        cout << endl;
    }
    void print()
    {
        //system("cls");
        cout << "----------City List-----------" << endl;
        for (int i = 1; i <= N; i++)
            cout << i << "." << name[i] << endl;
        cout << endl;
    }
} solve;
struct point
{
    string name;
    int distance(int to)
    {
    }
} P[1000];
int start()
{
    system("cls");
    cout << "-----------------------------" << endl;
    cout << "|           Welcome         |" << endl;
    cout << "-----------------------------" << endl;
    getchar();
    system("cls");
    while (1)
    {
        cout << "-----------------------------" << endl;
        cout << "|          1.Start          |" << endl;
        cout << "|          2.About          |" << endl;
        cout << "|          3.Exit           |" << endl;
        cout << "-----------------------------" << endl;
        int key = getkey('1', '3');
        if (key == 2)
        {
            system("cls");
            cout << "-------------------------" << endl;
            cout << "|     By Yu_Mingzhi     |" << endl;
            cout << "-------------------------" << endl;
            Sleep(3000);
            return 1;
        }
        if (key == 3)
            return -1;
        else
        {
            if (N)
            {
                cout << ">-: Whether to clear previous data?(Y/N)" << endl;
                string s;
                cin >> s;
                while (s.length() > 1 || (s[0] != 'Y' && s[0] != 'N'))
                {
                    cout << ">:- Error,try again!" << endl;
                    cin >> s;
                }
                if (s[0] == 'Y')
                {
                    for (int i = 1; i <= N; i++)
                    {
                        G[i].clear();
                        dep[i] = 0;
                        fah[i] = 0;
                        dis[i] = 0;
                        name.clear();
                        numb.clear();
                    }
                    N = 0;
                    cout << ">:- Clear Successfull!!!" << endl;
                }
            }
            cout << ">-: Please input some plans of the road:" << endl;
            cin >> M;
            for (int i = 1; i <= M; i++)
            {
                string a, b;
                int w;
                cin >> a >> b >> w;
                if (!numb[a])
                {
                    numb[a] = ++N;
                    name[N] = a;
                }
                if (!numb[b])
                {
                    numb[b] = ++N;
                    name[N] = b;
                }
                E[i].A = numb[a];
                E[i].B = numb[b];
                E[i].W = w;
                E[i].K = i;
            }

            for (int i = 0; i < 15; i++)
            {
                Sleep(88);
                cout << "-";
            }
            cout << endl;
            cout << ">:- OK, Loading completed!" << endl;
            cout << endl;
            solve.print();
            cout << ">:- The total mileage required for construction is " << solve.build() << " kilometres." << endl;
            solve.detail();
            cout << ">:- Any key to continue." << endl;
            getchar();
            getchar();
            cout << ">:- Now,You can ask me the distance between any two cities." << endl;
            while (1)
            {
                system("cls");
                solve.print();
                cout << ">:- Input the name of two cities. (exit)" << endl;
                string a, b;
                cin >> a >> b;
                if (a == "exit" || b == "exit")
                {
                    cout << ">:- Successful exit!!!" << endl;
                    break;
                }
                while (!numb[a] || !numb[b])
                {
                    cout << "Error,try again" << endl;
                    cin >> a >> b;
                }
                solve.check(numb[a], numb[b]);
                getchar();
                getchar();
            }
        }
    }
}

int main()
{
    while (1)
    {
        int key;
        if (key = start() == -1)
        {
            cout << "Thanks, Bye~" << endl;
            break;
        }
    }
    return 0;
}