#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
int dp[1002][1002];


int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	long l1, l2;
	string s1, s2;
// cin.ignore(); must be there when using getline(cin, s)
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		cin >> l1;
		cin >> s1;
		for(int i=1;i<=l1;i++){
			for(int j=1;j<=l1;j++){
				if(s1[i-1]==s1[j-1] && i!=j)
				{
					dp[i][j]=1+dp[i-1][j-1];
				}
				else
				{
					dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
				}
			}
		}
		cout << dp[l1][l1] << '\n';

	}
	return 0;
}
