#include <iostream>
#include <cstring>
using namespace std;
int t,n,ans;
int arr[100001];
bool visit[100001];
bool finish[100001];
void dfs(int idx) {
	visit[idx] = true;

	if (!visit[arr[idx]]) dfs(arr[idx]);

	else if (!finish[arr[idx]]) {
		for (int i = arr[idx]; i != idx; i = arr[i]) {
			ans++;
		}
		ans++;
	}

	finish[idx] = true;
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		memset(finish, false, sizeof(finish));
		memset(visit, false, sizeof(visit));
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!visit[i])
				dfs(i);
		}
		cout << n - ans << '\n';
	}
}