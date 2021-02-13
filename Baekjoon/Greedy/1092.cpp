#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
vector <int> cr;
vector <int> box;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0,c; i < n; i++) {
		cin >> c;
		cr.push_back(c);
	}
	cin >> m;
	for (int i = 0, b; i < m; i++) {
		cin >> b;
		box.push_back(b);
	}
	sort(cr.begin(), cr.end());
	sort(box.begin(), box.end());
	if (cr[n - 1] < box[m - 1]) {
		cout << "-1";
		return 0;
	}
	int ans = 0;
	while (1) {
		ans++;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = box.size() - 1; j >= 0; j--) {
				if (cr[i] >= box[j]) {
					box.erase(box.begin() + j);
					break;
				}
			}
		}
		if (box.size() == 0) break;
	}
	cout << ans;
}