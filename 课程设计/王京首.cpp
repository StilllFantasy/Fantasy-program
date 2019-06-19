/*
    给定校园任意许多地点的距离，可以求任意两点的距离，用dijstra() ,还可任意添加地点,更新最短路
    给出任意两个地点，可以求出一个基础的的路径规划(推荐),用 A* 求次短路等...
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cstdio>
#include <windows.h>
#include <cstring>
#include <map>
using namespace std;
int N, M;
map<int, string> name;
map<string, int> numb;
struct edge
{
    int T;
    int W;
};
vector<edge> G[1000]; //正向图
vector<edge> P[1000]; //反向图
string sschool_area[100] =
    {
        "Art_Center           ",
        "Playground           ",
        "Library              ",
        "Office_Building      ",
        "Academic_hall        ",
        "1st_Restaurant       ",
        "2nd_Restaurant       ",
        "3rd_Restaurant       ",
        "1st_Teaching_Building",
        "2nd_Teaching_Building",
        "3rd_Teaching_Building",
        "Laboratory_Building  ",
        "Literature_Building  ",
        "Food_Building        ",
        "Technology_Building  ",
};
vector<string> area;
struct centence
{
    string s;
    int nubr;
    int dist;
} cet[1000];
bool cmp(centence a, centence b)
{
    if (a.dist != b.dist)
        return a.dist < b.dist;
    return a.s.length() < b.s.length();
}
int change(string s)
{
    /*
        自动补全，预测单词，输入纠错函数
    */
    int book[50][50];
    for (int i = 0; i < area.size(); i++)
    {
        cet[i].s = area[i];
        cet[i].nubr = i;
        memset(book, 0, sizeof(book));
        string a = s;
        string b = area[i];
        int la = a.length();
        int lb = b.length();
        for (int i = la; i >= 1; i--)
            a[i] = a[i - 1];
        for (int i = lb; i >= 1; i--)
            b[i] = b[i - 1];
        for (int i = 0; i <= la; i++)
            book[i][0] = i;
        for (int i = 0; i <= lb; i++)
            book[0][i] = i;
        for (int i = 1; i <= la; i++)
        {
            for (int j = 1; j <= lb; j++)
            {
                int ok = 1;
                if (a[i] == b[j])
                    ok = 0;
                book[i][j] = min(min(book[i - 1][j] + 1, book[i][j - 1] + 1), book[i - 1][j - 1] + ok);
            }
        }
        cet[i].dist = book[la][lb];
    }
    sort(cet , cet + area.size(), cmp);
    if (cet[0].dist == 0)
        return cet[1].nubr;
    cout << "> Which? press number:" << endl;
    for (int i = 0; i < 4; i++)
        cout << i << " . " << cet[i].s << endl;
    string key;
    cin >> key;
    while (key.length() > 1 || key[0] > '4' || key[0] < '0')
    {
        cout << "> Error, try again!" << endl;
        cin >> key;
    }
    return numb[area[cet[int(key[0] - '0')].nubr]];
}
int menu()
{
    system("cls");
    cout << "--------------------------------------------------" << endl;
    cout << "|              choose any keys                   |" << endl;
    cout << "|              1.Path Recommendation             |" << endl;
    cout << "|              2.Data Update                     |" << endl;
    cout << "|              3.Data Clear                      |" << endl;
    cout << "|              4.Exit                            |" << endl;
    cout << "--------------------------------------------------" << endl;
    string key;
    while (cin >> key)
    {
        if (key.length() > 1 || key[0] < '1' || key[0] > '4')
            cout << "> Error, please try again." << endl;
        else
            break;
        cin >> key;
    }
    return (int)(key[0] - '0');
}

struct school
{
    int vis[1000];
    int dis[1000];
public:
    
    struct quq
    {
        int x;
        int d;
        bool operator<(const quq &a) const
        {
            return d > a.d;
        }
    };
    
    void ready()
    {

    }
    int dijstra(int start, int end)
    {
        ready();
        int step[100];
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= 1000; i++)
            dis[i] = 9999999;
        dis[start] = 0;
        priority_queue<quq> Q;
        Q.push((quq){start, 0});
        while (!Q.empty())
        {
            quq now = Q.top();
            Q.pop();
            if (now.d != dis[now.x])
                continue;
            vis[now.x] = 1;
            for (int i = 0; i < G[now.x].size(); i++)
            {
                int x = G[now.x][i].T;
                int v = G[now.x][i].W;
                if (!vis[x] && (dis[x] > dis[now.x] + v))
                {
                    dis[x] = dis[now.x] + v;
                    Q.push((quq){x, dis[x]});
                    step[x] = now.x;
                }
            }
        }
        if (dis[end] >= 9999999)
            return -1;
        else
        {
            int ed = end;
            while (ed != start)
            {
                cout << name[ed] << "->";
                ed = step[ed];
            }
            cout << name[start] << endl;

            return dis[end];
        }
    }
} solve;
void About()
{
}
int start()
{
    while (1)
    {
        string key;
        int cas;
        system("cls");
        cout << "--------------------------------------------------" << endl;
        cout << "|           Welcome to use this platform         |" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << endl;
        getchar();
        getchar();
        system("cls");
        cout << "----------------------------------" << endl;
        cout << "|              1.Menu            |" << endl;
        cout << "|              2.Exit            |" << endl;
        cout << "|              3.About           |" << endl;
        cout << "----------------------------------" << endl;
        cin >> key;
        while (key.length() > 1 || (key[0] != '1' && key[0] != '2' && key[0] != '3'))
        {
            cout << "> Error, again please." << endl;
            cin >> key;
        }
        if (key[0] == '2')
            return 0;
        if (key[0] == '3')
        {
            About();
            Sleep(3000);
            continue;
        }
        while (1)
        {
            cas = menu();
            if (cas == 4)
                break;
            else if (cas == 3)
            {
            }
            else if (cas == 2)
            {
                system("cls");
                int es;
                cout << "> Enter data to be updated:" << endl;
                cin >> es;
                for (int i = 0; i < es; i++)
                {
                    string a, b;
                    int c;
                    cin >> a >> b >> c;
                    if (!numb[a])
                    {
                        numb[a] = ++N;
                        name[N] = a;
                        area.push_back(a);
                    }
                    if (!numb[b])
                    {
                        numb[b] = ++N;
                        name[N] = b;
                        area.push_back(b);
                    }
                    G[numb[a]].push_back({numb[b],c});
                    G[numb[b]].push_back({numb[a],c});
                }
                cout<<"> Update completed.Any key to return."<<endl;
                getchar();
                getchar();
                continue;
            }
            else if (cas == 1)
            {
                if (N == 0)
                {
                    continue;
                }
                cout << "> Where do you want to go?" << endl;
                string a, b;
                int x, y;
                cin >> a;
                x = change(a);
                cout << "> Where do you want to start?" << endl;
                cin >> b;
                y = change(b);
                int dd;
                if (dd = solve.dijstra(y, x) == -1) // 使用school类创建的solve对象中的dijstra()方法
                    cout << "> Error,try again." << endl;
                else
                    cout << "> The total distance is " << dd << endl;
                cout << "> Please press any key to return." << endl;
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
        int d;
        if (d = start() == 0)
        {
            cout << "Thank you , Bye~" << endl;
            break;
        }
    }
    return 0;
}