#include <iostream>
#include <stack>
using namespace std;
int n,t[500001],ans[500001];
stack<int>s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> t[i];
	for (int i = 1; i <= n; i++) {
		while (!s.empty() && t[s.top()] < t[i]) {
			s.pop();
		}
		if (!s.empty() && t[s.top()] >= t[i]) 
			ans[i] = s.top();
		
		s.push(i);
	}
	for (int i = 1; i <= n; i++) 
		cout << ans[i] << ' ';
}