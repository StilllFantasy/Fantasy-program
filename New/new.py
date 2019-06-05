import random

n1=1
n2=1
n3=1
n4=1


while(1):
    print("--------------------------------")
    print("             Welcome")
    print("--------------------------------")
    print("每次选择一个数字，让它减1，")
    print("谁先把四个数减到0为赢")
    ok=1
    while(ok):
        A=a=random.randint(1,10)
        B=b=random.randint(1,10)
        C=c=random.randint(1,10)
        D=d=random.randint(1,10)
        n1=a%2+b%2+c%2+d%2
        a=int(a/2)
        b=int(b/2)
        c=int(c/2)
        d=int(d/2)
        n2=a%2+b%2+c%2+d%2
        a=int(a/2)
        b=int(b/2)
        c=int(c/2)
        d=int(d/2)
        n3=a%2+b%2+c%2+d%2
        a=int(a/2)
        b=int(b/2)
        c=int(c/2)
        d=int(d/2)
        n4=a%2+b%2+c%2+d%2
        a=int(a/2)
        b=int(b/2)
        c=int(c/2)
        d=int(d/2)
        if(n1%2==0):
            if(n2%2==0):
                if(n3%2==0):
                    if(n4%2==0):
                        ok=0
                        break
    print("Good luck!!!")
    print(A,B,C,D)
    S=A+B+C+D
    step=1;
    
    while(S>0):
        if(step%2==1)
            print("It is your turn!")
            s=input()
            step=step+1
            if(s==1)
                A=A-1
            if(s==2)
                B=B-1
            if(s==3)
                C=C-1
            if(s==4)
                D=D-1
        print('#',step,':',A,B,C,D)
        if(step%2==0)

            print()

    break