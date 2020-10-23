// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

int dp[1001][1001];
class Solution{
		

	public:
	int minOperations(string str1, string str2)
	{
		memset(dp, 0, sizeof(dp));
		int mx = 0, m, n;
		m = str1.length();
		n = str2.length();
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (str1[i - 1] == str2[j - 1]) {

						dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

				}
				//cout << dp[i][j] << " ";
			}
		//	cout << '\n';
		}
		return m + n - 2 * dp[m][n];
	}
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
