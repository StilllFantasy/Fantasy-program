#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
#include <fstream>
#include <cstdio>
using namespace std;
map<string, int> Numb;
map<int, string> Name;
map<stack<int>, int> road_plan;
vector<int> shortroad;
struct edge
{
    int t;
    int w;
};
//vector<edge> G[10001]; //正图
vector<edge> P[10001]; //反图
vector<string> all_area;
int dis[10001];
int vis[10001];
int nxt[10001];
int M, N, D, Edges;

struct node
{
    int x;
    int d;
    bool operator<(const node &a) const
    {
        return d > a.d;
    }
};
struct nod
{
    int x;
    int h;
    int f;
    bool operator<(const nod &a) const
    {
        return f > a.f;
    }
};
struct point
{
    string name;
    int number;
    int read()
    {
        string ss;
        cin >> ss;
        if (!Numb[ss])
        {
            Numb[ss] = ++N;
            Name[N] = ss;
            all_area.push_back(ss);
        }
        return Numb[ss];
    }
    void print()
    {
        if (N == 0)
        {
            cout << "> No data, please update it first." << endl;
            getchar();
            getchar();
            return;
        }
        for (int i = 0; i < N; i++)
            cout << all_area[i] << " ";
        cout << endl;
        getchar();
        getchar();
    }
} area;
struct edgesave
{
    string a;
    string b;
    int len;
} edges[10001];
struct change_need
{
    string s;
    int x;
    double d;
} cet[1001];
bool cmp1(change_need a, change_need b)
{
    return a.d < b.d;
}
int GetKey(char l, char r, int len)
{
    string ss;
    cin >> ss;
    while (ss.length() > len || ss[0] > r || ss[0] < l)
    {
        cout << "> Error , try again!" << endl;
        cin >> ss;
    }
    return (int)(ss[0] - l + 1);
}
int change(string s)
{
    /*
        自动补全，预测单词，输入纠错函数
    */
    int book[50][50];
    for (int i = 0; i < all_area.size(); i++)
    {
        cet[i].s = all_area[i];
        cet[i].x = i;
        memset(book, 0, sizeof(book));
        string a = s;
        string b = all_area[i];
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
        cet[i].d = 1.0*book[la][lb]/(la+lb);
    }
    sort(cet, cet + all_area.size(), cmp1);
    if (cet[0].d == 0)
        return Numb[cet[0].s];
    cout << "> Which? press number:" << endl;
    for (int i = 0; i < 4; i++)
        cout << i + 1 << " . " << cet[i].s << endl;
    int key = GetKey('1', '4', 1);
    {
        return Numb[cet[key - 1].s];
    }
}

void Add()
{
    system("cls");
    int es;
    cout << "> Enter data to be updated:" << endl;
    cin >> es;
    for (int i = Edges + 1; i <= Edges + es; i++)
    {
        int x, y, c;
        x = area.read();
        y = area.read();
        cin >> c;
        P[x].push_back((edge){y, c});
        P[y].push_back((edge){x, c});
        edges[i].a = Name[x];
        edges[i].b = Name[y];
        edges[i].len = c;
    }
    Edges += es;
    cout << "> Update completed.Any key to return." << endl;
    getchar();
    getchar();
}
int menu()
{
    system("cls");
    cout << "--------------------------------------------------" << endl;
    cout << "|              choose any keys                   |" << endl;
    cout << "|              1.Path Recommendation             |" << endl;
    cout << "|              2.Data Update                     |" << endl;
    cout << "|              3.Data Clear                      |" << endl;
    cout << "|              4.City List                       |" << endl;
    cout << "|              5.Exit                            |" << endl;
    cout << "--------------------------------------------------" << endl;
    int key = GetKey('1', '5', 1);
    return key;
}

void About()
{
    system("cls");
    cout << "------------------------------------------" << endl;
    cout << ">>> Designed by Wang_Jingshou & WuChen <<<" << endl;
    cout << "------------------------------------------" << endl;
    getchar();
    getchar();
    system("cls");
    cout << "-----------------------------------------" << endl;
    cout << ">>> Technical support : StilllFantasy <<<" << endl;
    cout << "-----------------------------------------" << endl;
    getchar();
    return;
}
class solve
{

public:
    int S;
    stack<int> stk;
    int solve_dis(int T, int K)
    {
        while (!stk.empty())
            stk.pop();
        priority_queue<node> Q;
        memset(vis, 0, sizeof(vis));
        memset(dis, 0x7f, sizeof(dis));
        dis[S] = 0;
        vis[S] = 1;
        vis[K] = 1;
        Q.push((node){S, 0});
        while (!Q.empty())
        {
            node p = Q.top();
            Q.pop();
            if (dis[p.x] != p.d)
                continue;
            vis[p.x] = 1;
            for (int i = 0; i < P[p.x].size(); i++)
                if (!vis[P[p.x][i].t] && dis[P[p.x][i].t] > dis[p.x] + P[p.x][i].w)
                {
                    dis[P[p.x][i].t] = dis[p.x] + P[p.x][i].w;
                    nxt[P[p.x][i].t] = p.x;
                    Q.push((node){P[p.x][i].t, dis[P[p.x][i].t]});
                }
        }
        if (dis[T] >= 99999)
            return -1;
        else
        {
            int xx = T;
            //cout << S << " to " << T << " is " << dis[T] << endl;
            //string road_hash="";

            while (xx != S)
            {
                stk.push(xx);
                xx = nxt[xx];
                if (K == 0)
                    shortroad.push_back(xx);
            }
            stk.push(S);
            if (road_plan[stk] == 1)
            {
                //cout<<K<<" "<<"is old "<<endl;
                return -1;
            }
            road_plan[stk] = 1;
            return 0;
        }
    }
    void print(int T)
    {
        double dists = 1.0 * dis[T];
        if (stk.empty())
            return;

        cout << "[ Distance:";
        if (dists >= 1000)
            printf("%.2f KM ] ", dists / 1000.0);
        else
            printf("%.2f M ] ", dists);
        cout << "[ Time : ";
        printf("%.2f minutes ] ", dists / 80);
        cout << "[ " << Name[stk.top()];
        stk.pop();
        while (!stk.empty())
        {
            cout << "-->" << Name[stk.top()];
            stk.pop();
        }
        cout << " ]" << endl;

        //cout<<dis[T]<<" "<<stk.size()<<endl;
    }
} place[10001];
int start()
{
    while (1)
    {
        int key;
        int cas;
        system("cls");
        cout << "--------------------------------------------------" << endl;
        cout << "|           Welcome to use this platform         |" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << endl;
        getchar();
        while (1)
        {
            system("cls");
            cout << "----------------------------------" << endl;
            cout << "|              1.Menu            |" << endl;
            cout << "|              2.Exit            |" << endl;
            cout << "|              3.About           |" << endl;
            cout << "----------------------------------" << endl;
            key = GetKey('1', '3', 1);
            if (key == 1)
            {
                while (1)
                {
                    cas = menu();
                    if (cas == 1)
                    {
                        if (N == 0)
                        {
                            cout << "> No data, please update it first." << endl;
                            getchar();
                            getchar();
                        }
                        else
                        {
                            string a, b;
                            int x, y;
                            cout << "> Where do you want to go?" << endl;
                            cin >> a;
                            x = change(a);
                            cout << "> Where do you want to start?" << endl;
                            cin >> b;
                            y = change(b);
                            //x=Numb[a];
                            //y=Numb[b];
                            road_plan.clear();
                            shortroad.clear();
                            int road_cnt = 1;
                            if (place[y].solve_dis(x, 0) != -1)
                            {
                                road_cnt++;
                                cout << "> This is the shortest road:" << endl;
                                place[y].print(x);
                            }

                            for (int j = 0; j < shortroad.size(); j++)
                            {
                                int i = shortroad[j];
                                if (i != x && i != y)
                                {
                                    ///cout<<x<<" "<<y<<" "<<i<<endl;
                                    if (place[y].solve_dis(x, i) != -1)
                                    {
                                        if (road_cnt == 1)
                                        {
                                            road_cnt++;
                                            cout << "> This is the shortest road:" << endl;
                                        }
                                        else
                                            cout << "> In addition, you can bypass the " << Name[i] << "." << endl;
                                        place[y].print(x);
                                    }
                                    else
                                        continue;
                                }
                                if (road_cnt > 3)
                                    break;
                            }

                            getchar();
                            getchar();
                        }
                    }
                    else if (cas == 2)
                    {
                        Add();
                        for (int i = 1; i <= N; i++)
                            place[i].S = i;
                    }
                    else if (cas == 3)
                    {
                        cout << "> Are yuo sure ?! (Y?N)" << endl;
                        string s;
                        cin >> s;
                        while (s.length() > 1 || (s[0] != 'Y' && s[0] != 'N'))
                        {
                            cout << "> Error, try again." << endl;
                            cin >> s;
                        }
                        if (s[0] == 'N')
                            continue;
                        for (int i = 1; i <= N; i++)
                        {
                            P[i].clear();
                            Numb.clear();
                            Name.clear();
                            dis[i] = 0;
                            nxt[i] = 0;
                            vis[i] = 0;
                        }
                        N = 0;
                        cout << "> OK, Clear Successfull, any key to return." << endl;
                        getchar();
                        getchar();
                    }
                    else if (cas == 4)
                    {
                        area.print();
                    }
                    else if (cas == 5)
                    {
                        break;
                    }
                }
            }
            else if (key == 2)
            {
                return -1;
            }
            else if (key == 3)
            {
                About();
                continue;
            }
        }
    }
}
void start_read()
{
    ifstream file("data.data");
    file >> Edges;
    int x, y, c;
    for (int i = 1; i <= Edges; i++)
    {
        file >> edges[i].a >> edges[i].b >> edges[i].len;
        if (!Numb[edges[i].a])
        {
            Numb[edges[i].a] = ++N;
            Name[N] = edges[i].a;
            all_area.push_back(edges[i].a);
        }
        if (!Numb[edges[i].b])
        {
            Numb[edges[i].b] = ++N;
            Name[N] = edges[i].b;
            all_area.push_back(edges[i].b);
        }
        x = Numb[edges[i].a];
        y = Numb[edges[i].b];
        c = edges[i].len;
        P[x].push_back({y, c});
        P[y].push_back({x, c});
    }
}
int main()
{
    //start_read();
    while (1)
    {
        if (D = start() == -1)
        {
            cout << "> Thanks, Good Bye~" << endl;
            break;
        }
    }

    return 0;
}
