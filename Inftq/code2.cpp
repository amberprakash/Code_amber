#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int maxcount = 0;
    int maxnum = 0;
    while (num > 0)
    {
        int a = num % 100;

        int count = 0;
        for (int i = 1; i <= sqrt(a); i++)
        {
            if (a % i == 0)
            {
                count++;
            }
        }
        if(count==maxcount){
            if(a>maxnum){
                maxnum=a;
            }
        }
        if (count > maxcount)
        {
            maxcount = count;
            maxnum=a;  
        }

        num = num / 10;
    }
    cout << maxnum;
    return 0;
}