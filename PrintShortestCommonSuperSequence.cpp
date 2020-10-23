#include <bits/stdc++.h>
using namespace std;
int dp[102][102];

int main() {
	std::ios::sync_with_stdio(false);
	int T, l1, l2;
	cin >> T;
	string s1, s2;
// cin.ignore(); must be there when using getline(cin, s)
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		cin >> l1 >> l2;
		cin >> s1 >> s2;
		//BOTTOM-UP APROACH
		//int l1 = s1.length(), l2 = s2.length();
		for (int i = 1; i <= l1; i++) {
			for (int j = 1; j <= l2; j++) {
				if (s1[i - 1] == s2[j - 1])
				{
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				}
			}
		}
		cout << l1 + l2 - dp[l1][l2] << '\n';
		int i = l1, j = l2;
		list<char> l;
		while (i != 0 && j != 0) {

			if (s1[i - 1] == s2[j - 1]) {
				l.push_front(s2[j - 1]);
				i--;
				j--;

			}
			else {
				if (dp[i][j - 1] >= dp[i - 1][j]) {
					l.push_front(s2[j - 1]);
					j--;
				}
				else {
					l.push_front(s1[i - 1]);
					i--;
				}
			}
		}
		while (i > 0) {
			l.push_front(s1[i - 1]);
			i--;
		}
		while (j > 0) {
			l.push_front(s2[j - 1]);
			j--;
		}
		for (auto it : l) {
			cout << it;
		}
		cout << '\n';
	}
	return 0;
}
