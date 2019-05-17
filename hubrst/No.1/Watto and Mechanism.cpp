cout<<a[i]<<"fdsa ";
        for (int j = 1; j <= sqrt(a[i]); i++)
        {
            if (a[i] % j == 0)
                c[a[i]][++c[a[i]][0]] = j;
        }
        int zz = c[a[i]][0];
        if (sqrt(a[i]) * sqrt(a[i]) == a[i])
            zz--;
        for (int j = zz; j >= 1; j--)
        {
            c[a[i]][++c[a[i]][0]] = a[i] / c[a[i]][j];
            cout<<a[i]<<endl;
        }