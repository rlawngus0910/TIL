#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
int num[10001];
int ans[10001];
vector <int> a;
bool check(int mid) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (num[i] >= mid) {
			ans[i] = mid;
		}
		else {
			ans[i] = num[i];
		}
		sum += ans[i];
	}
	if (sum > m) return false;
	else return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		sum += num[i];
	}
	sort(num, num + n);
	cin >> m;
	if (sum <= m) {
		cout << num[n - 1];
		return 0;
	}
	int start = 0;
	int finish = m;
	while (start < finish) {
		int mid = (start + finish) / 2;
		//cout << start << ' ' << finish << '\n';
		//cout << mid << '\n';
		if (check(mid)) {
			a.push_back(ans[n - 1]);
			start = mid + 1;
		}
		else {
			finish = mid;
		}
	}
	cout << a[a.size() - 1];
}