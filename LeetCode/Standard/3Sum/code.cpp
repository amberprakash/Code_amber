#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int target = -nums[i];
        int front = i + 1;
        int back = n - 1;
        while (front < back)
        {
            int sum = nums[front] + nums[back];
            if (sum < target)
            {
                front++;
            }
            else if (sum > target)
            {
                back--;
            }
            else
            {
                vector<int> triplet = {nums[i], nums[front], nums[back]};
                ans.push_back(triplet);
                while (front < back && triplet[1] == nums[front])
                {
                    front++;
                }
                while (front < back && triplet[2] == nums[back])
                {
                    back--;
                }
            }
        }
        while (i + 1 < n && nums[i] == nums[i + 1])
        {
            i++;
        }
    }

    for(auto x:ans){
        cout<<"["<<x[0]<<","<<x[1]<<","<<x[2]<<"]"<<endl;
    }
    return 0;
}