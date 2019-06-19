#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const int MAX_STUDENT_NUM = 5;
class student
{
public:
    void inid();
    void inname();
    void inregulargrade();
    void infinalexam();
    int getid();          // 获得学号
    static void heading() //输出成绩标题
    {
        cout << setw(10) << "学号" << setw(10) << "姓名"
             << "平时" << setw(10) << "期末" << endl;
    }
    void output();
    double totalmark();

private:
    int id;
    char name[20];
    double regulargrade;
    double finalexam;
};
/*输入学号*/
void student::inid()
{
    cout << "请输入学号(1-40):";
    cin >> id;
    while (id < 1 || id > 40)
    {
        cout << "输入学号有误，请重新输入学号：" << endl;
        cin >> id;
    }
}
/*输入学生姓名*/
void student::inname()
{
    cin.ignore(80, '\n');
    cout << "请输入姓名:";
    cin.getline(name, 20);
    /*如果不忽略将无法输入名字*/
}
/*输入学生平时成绩*/
void student::inregulargrade()
{
    cout << "请输入平时成绩(0-100):";
    cin >> regulargrade;
    while (regulargrade < 0 || regulargrade > 100)
    {
        cout << "输入错误，请重新输入" << endl;
        cout << "请输入平时成绩(0-100):";
        cin >> regulargrade;
    }
}
/*输入学生期末成绩*/
void student::infinalexam()
{
    cout << "请输入期末成绩(0-100):";
    cin >> finalexam;
    while (finalexam < 0 || finalexam > 100)
    {
        cout << "输入错误，请重新输入" << endl;
        cout << "请输入期末成绩(0-100):";
        cin >> finalexam;
    }
}
/*获取学号*(未知用法） */
int student::getid()
{
    return id;
}
/*输出学生信息*/
void student::output()
{
    cout << setw(10) << id << setw(10) << name << setiosflags(ios::fixed) << setprecision(1) << setw(10) << regulargrade << setw(10) << finalexam << endl;
}
/*计算总成绩*/
double student::totalmark()
{
    return regulargrade * 0.5 + finalexam * 0.5;
}
/*录入学生信息*/
void input(student stu[], int &num)
{
    double score; //学生成绩
    int i = 0;    //人数
    string str;   //用来判断是否继续输入的字符串(定义叫str的字符串）
    //先看学生数是否已经到达上限
    if (num == MAX_STUDENT_NUM)
    {
        cout << "人数达到" << MAX_STUDENT_NUM << "人上线，无法插入\n";
    }
    else
    {
        /*
            先输入学号，然后在已经保存的学生里检查是否有相同的学号，
            如果有相同的学号，则提示非法，然后再重复输入学号
            如果学号输入恰当，则再依次输入学生的名字，平时分和期末分
            此时录入完成，提示用户是否还需要再次录入，如果再次录入则重复以上步骤
        */
        i = num; //当前数组元素个数
        while (true)
        {
            stu[i].inid();
            for (int j = 0; j < num; j++)
            {
                if (stu[i].getid() == stu[j].getid())
                {
                    cout << "学号不允许重复，学号已存在\n";
                    stu[i].inid();
                }
            }
            stu[i].inname();
            stu[i].inregulargrade();
            stu[i].infinalexam();
            i++;
            num = i;
            cout << "继续输入学生数据请按y:";
            cin >> str;
            if (i = MAX_STUDENT_NUM)
            {
                cout << "人数已达到" << MAX_STUDENT_NUM << "人上限，无法再输入：\n";
                break;
            }
            if (str == "y")
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }
}
/*输出显示成绩信息*/
void output(student stu[], int num)
{
    if (num != 0)
    {
        stu[0].heading(); //学生信息标题
        for (int i = 0; i < num; i++)
        {
            stu[i].output();
        }
    }
    else
    {
        cout << "暂无成绩信息，请选择1=录入成绩信息" << endl;
    }
}
/*根据总评排序*/
void line(student stu[], int num)
{
    if (num != 0)
    {
        int i, j, k;
        student temp;
        for (i = 0; i < num; i++)
        {
            for (j = 0; j < num - i - 1; j++)
            {
                if (stu[j].totalmark() < stu[j + 1].totalmark())
                {
                    temp = stu[j];
                    stu[j] = stu[j + 1];
                    stu[j + 1] = temp;
                }
            }
        }
        stu[0].heading(); //学生信息标题
        for (k = 0; k < num; k++)
        {
            stu[k].output();
        }
        cout << endl;
    }
    else
    {
        cout << "暂无成绩信息，请选择1=录入学生信息" << endl;
    }
}
/*根据学号查找学生信息*/
void search(student stu[], int num)
{
    int id;
    string str;
    while (true)
    {
        cout << "请输入要查找的学号：";
        cin >> id;
        int flag = 0;
        if (id >= 1 && id <= 40)
        {
            for (int i = 0; i < num; i++)
            {
                if (stu[i].getid() == id)
                {
                    flag++;
                }
            }
            if (flag == 0)
            {
                cout << "没有该学号的学生信息" << endl;
            }
            else
            {
                stu[0].heading();
                for (int i = 0; i < num; i++)
                {
                    if (stu[i].getid() == id)
                    {
                        stu[i].output();
                    }
                }
            }
            cout << "继续查找请按y:";
            cin >> str;
            if (str == "y")
            {
                continue;
            }
            else
            {
                break;
            }
        }
        else
        {
            cout << "输入学号有误，请重新输入（1-40）\n"
                 << endl;
            cout << "继续请按y:";
            cin >> str;
            if (str == "y")
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }
}
/*删除学生省略*/
/*统计人数*/
void statistics(student stu[], int num)
{
    int i, a[5] = {0};
    for (i = 0; i < num; i++)
    {
        if (stu[i].totalmark() >= 90 && stu[i].totalmark() <= 100)
        {
            a[0] += 1;
        }
        else if (stu[i].totalmark() >= 80 && stu[i].totalmark() < 90)
        {
            a[1] += 1;
        }
        else if (stu[i].totalmark() >= 70 && stu[i].totalmark() < 80)
        {
            a[2] += 1;
        }
        else if (stu[i].totalmark() >= 60 && stu[i].totalmark() < 70)
        {
            a[3] += 1;
        }
        else
        {
            a[4] += 1;
        }
    }
    cout << "     100~90    89~80    79~70    69~60     <60" << endl;
    for (i = 0; i < 5; i++)
    {
        cout << setw(9) << a[i];
    }
    cout << endl;
}
/* 主菜单*/
void menu()
{
    cout << "        ---->---->---->---->---->---->---->---->---->---->\n";
    cout << "                欢迎来到卢业飞是第一名的成绩管理系统      \n";
    cout << "                1=录入成绩                  2=显示成绩    \n";
    cout << "                3=排序总分                  4=查找学生    \n";
    cout << "                5=插入学生                  6=统计人数    \n";
    cout << "                                0=退出                    \n";
    cout << "        ---->---->---->---->---->---->---->---->---->---->\n";
    cout << "来选择吧：";
}
int main()
{
    int x = 0;
    student stu[MAX_STUDENT_NUM];
    string a; //用来判断菜单选择，用string
    menu();
    while (cin >> a)
    {
        if (a == "1")
        {
            cout << "录入成绩：" << endl;
            input(stu, x);
            menu();
        }
        else if (a == "2")
        {
            cout << "显示成绩：" << endl;
            output(stu, x);
            menu();
        }
        else if (a == "3")
        {
            cout << "成绩排序：" << endl;
            line(stu, x);
            menu();
        }
        else if (a == "4")
        {
            cout << "查询学生：" << endl;
            search(stu, x);
            menu();
        }
        else if (a == "5")
        {
            cout << "插入学生：" << endl;
            input(stu, x);
            menu();
        }
        else if (a == "6")
        {
            cout << "统计人数：" << endl;
            statistics(stu, x);
            menu();
        }
        else if (a == "0")
        {
            cout << "退出成功" << endl;
            return 0;
        }
        else
        {
            cout << "输入非法，请重新输入：" << endl;
        }
    }
    return 0;
}
