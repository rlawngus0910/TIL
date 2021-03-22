#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[100001], ansx, ansy;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int start = 0, finish = n - 1;
	int temp = 2e9 + 10;
	while (start < finish) {
		if (arr[start] + arr[finish] == 0) {
			cout << arr[start] << ' ' << arr[finish];
			return 0;
		}
		if (abs(arr[start] + arr[finish]) < temp) {
			temp = abs(arr[start] + arr[finish]);
			ansx = arr[start];
			ansy = arr[finish];
		}

		if (arr[start] + arr[finish] < 0)
			start++;
		else if (arr[start] + arr[finish] > 0)
			finish--;
	}
	cout << ansx << ' ' << ansy;
}