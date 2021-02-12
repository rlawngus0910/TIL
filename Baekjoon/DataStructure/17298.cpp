#include <iostream>
#include <stack>
using namespace std;
int n,num[1000001];
int ans[1000001];
stack <int> s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < n; i++) {
		while (!s.empty() && num[s.top()] < num[i]) {
			ans[s.top()] = num[i];
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		ans[s.top()] = -1;
		s.pop();
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
}

