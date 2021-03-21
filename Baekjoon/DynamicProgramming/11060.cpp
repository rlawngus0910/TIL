#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[1001], dp[1001];
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	fill(dp, dp + n + 1, 1e9);
	dp[1] = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= arr[i];j++) {
			if (i + j >= 1000) break;
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	if (dp[n] == 1e9) cout << "-1";
	else cout << dp[n];
}