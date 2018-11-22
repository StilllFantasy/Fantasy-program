
for(int i=2;i<n;i++)
{
    if(i<n/2)
    {
        for(int j=1;j<i;j++)
        {
            if(a[color[j]].size()==1||a[color[j]][a[color[j]].size()-1]<=i)
            continue;
            for(int k=0;k<a[color[j]].size();k++)
            {
                if(j+a[color[j]][k]>2*i)
                break;
                if(a[color[j]][k]>i&&(2*i==a[color[j]][k]+j))
                {
                    tot=(tot+((goal[a[color[j]][k]]+goal[j])*(j+a[color[j]][k]))%10007)%10007;
                    break;
                }
            }

        }
    }
    else
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[color[j]].size()==1||a[color[j]][0]>=i||a[color[j]][0]+j>2*i)
            continue;
            for(int k=0;k<a[color[j]].size();k++)
            {
                if(a[color[j]][k]+j>2*i)
                break;
                if(a[color[j]][k]<i&&(2*i==a[color[j]][k]+j))
                {
                    tot=(tot+((goal[a[color[j]][k]]+goal[j])*(j+a[color[j]][k]))%10007)%10007;
                    break;
                }
            }

        }
    }

}

cout<<tot;
