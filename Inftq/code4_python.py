def solve(n):
    if n==1:
        return 0
    temp=0;
    if n%2==0:
        x=n/2
        temp=1+solve(x)
    else:
        x=(n*3)+1
        temp=1+solve(x)

    return temp            


line=input().split();
a=[]
a=list(map(int,line))
for i in range(len(a)):
    if(i==len(a)-1):
        print(solve(a[i])+1)
    else:
        print(solve(a[i])+1,end=",")
 


