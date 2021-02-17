#include <iostream>
#include <algorithm>
using namespace std;
int num[1001],dp[1001];
int n;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	dp[1] = num[1];
	int ans = dp[1];
	for (int i = 2; i <= n; i++) {
		bool check = false;
		for (int j = i - 1; j >= 1; j--) {
			if (num[i] > num[j]) {
				check = true;
				dp[i] = max(dp[i], num[i] + dp[j]);
			}
		}
		if (!check) dp[i] = num[i];
		ans = max(ans, dp[i]);
	}
	cout << ans;
}