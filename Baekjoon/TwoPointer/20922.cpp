#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
int arr[200001];
int num[100001];
bool visit[200001];
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	int start = 1;
	int finish = 1;
	int ans = 0;
	while (finish <= n) {
		if (!visit[finish]) {
			visit[finish] = true;
			num[arr[finish]]++;
		}
		if (num[arr[finish]] <= k) {
			ans = max(ans, finish - start + 1);
			finish++;
		}
		else {
			num[arr[start]]--;
			start++;
		}
	}
	cout << ans;
}