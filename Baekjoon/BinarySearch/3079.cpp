#include <iostream>
#include <algorithm>
using namespace std;
long long n, m, ans;
long long t[100001];
long long maxVal;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		maxVal = max(t[i], maxVal);
	}
	long long start = 0;
	long long finish = maxVal * m;
	while (start <= finish) {
		long long mid = (start + finish) / 2;
		long long temp = 0;
		for (int i = 0; i < n; i++) {
			temp += mid / t[i];
		}
		if (temp < m) {
			start = mid + 1;
		}
		else if (temp >= m) {
			ans = mid;
			finish = mid - 1;
		}
	}
	cout << ans;
}