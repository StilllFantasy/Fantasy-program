#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char s1[1000050]="hat";
char s2[1000050];
int Next[1000050];
int len1,len2;
void get(int len1)
{
	int i=0,j=-1;
	Next[i]=-1;
	while(i<len1) 
    {
		if(j==-1||s1[i]==s1[j]) 
        {
			Next[++i]= ++j;
		}
		else j=Next[j];
	}
}
void Get(int len)  
{  
    Next[0] = -1;  
    int k = -1;  
    int j = 0;  
    while (j < len - 1)  
    {  
       
        if (k == -1 || s1[j] == s1[k])  
        {  
            ++j;  
            ++k;  
            if (s1[j] != s1[k])  
                Next[j] = k;  
            else  
               
                Next[j] = Next[k];  
        }  
        else  
        {  
            k = Next[k];  
        }  
    }  
}  
int kmp(int pos,int len1,int len2)
{
	int i=pos,j=0,ans=0;
	while(i<len2) 
    {
		if(s2[i]==s1[j]||j==-1) 
        {
            i++;
            j++;
        }
		else 
            j=Next[j];

		if(j==len1) 
        {
			ans++;
			j=Next[j-1];
			i--;
		}
	}
	return ans;
}
char s[100000];
int main()
{
	/*
    int t;
	
    len1=strlen(s1);
    get(len1);

    while(scanf("%s",s2))
    {
        len2=strlen(s2);
        if(kmp(0,len1,len2)&&len1<len2)
        printf("%s\n",s2);
    }
    */

    while(scanf("%s",s))
    {
        if(strlen(s)<=3)
        continue;
        for(int i=0;i+2<strlen(s);i++)
        {
            if(s[i]=='h'&&s[i+1]=='a'&&s[i+2]=='t')
            {
                printf("%s\n",s);
            }
        }
    }

	return 0;

}