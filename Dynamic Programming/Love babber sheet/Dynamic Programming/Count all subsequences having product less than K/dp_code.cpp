// CPP program to find number of subarrays having
// product less than k.
#include <bits/stdc++.h>
using namespace std;

// Function to count numbers of such subsequences
// having product less than k.
int dp[100 + 1][100 + 1];
int productSubSeqCount(vector<int> &arr, int k)
{
	int n = arr.size();
	// int dp[k + 1][n + 1];
	// memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
	
			// number of subsequence using j-1 terms
			dp[i][j] = dp[i][j - 1];

			// if arr[j-1] > i it will surely make product greater
			// thus it won't contribute then
			if (arr[j - 1] <= i)

				// number of subsequence using 1 to j-1 terms
				// and j-th term
				dp[i][j] += dp[i/arr[j-1]][j-1] + 1;
		}
	}
	return dp[k][n];
}

// Driver code
int main()
{
	vector<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);
    int n=4;
	int k = 10;
    memset(dp, 0, sizeof(dp));
	cout << productSubSeqCount(A, k) << endl;
    for(int i=0;i<=k;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
