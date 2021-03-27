#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[10002];
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	sort(arr + 1, arr + n + 1);
	long long ans = 0;
	for (int i = 1; i <= n - 2; i++) {
		// 숫자 하나 선택
		int temp = arr[i];
		int start = i + 1;
		int finish = n;
		int max_idx = n;
		// 투 포인터
		while (start < finish) {
			// 세 수의 합이 0이라면
			if (arr[start] + arr[finish] + temp == 0) {
				// 고른 두 수가 같으면
				if (arr[start] == arr[finish]) {
					ans += finish - start;
				}
				// 고른 두 수가 다르다면
				else {
					max_idx = lower_bound(arr + start, arr + n, arr[finish]) - arr;
					// arr[finish] 와 같은 수를 세어준다. 
					ans += finish - max_idx + 1;
				}
				start++;
			}
			// 0보다 작으면 start 증가
			else if (arr[start] + arr[finish] + temp < 0) {
				start++;
			}
			// 0보다 크면 finish 감소
			else {
				finish--;
			}
		}
	}
	cout << ans;

}