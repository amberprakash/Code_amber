num = input()
n = len(num)

a = []
first=int(num)
for i in range(n):
    for j in range(1, n+1):
        x = int(num[0:j])
        if(first % x == 0):
            a.append(x)
    b=num[n-1:n]
    num=b+num
    num=num[0:n]
    first=int(num)



for i in range(len(a)):
    if i==len(a)-1:
        print(a[i])
    else:
        print(a[i],end=" ")    
