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
		// ���� �ϳ� ����
		int temp = arr[i];
		int start = i + 1;
		int finish = n;
		int max_idx = n;
		// �� ������
		while (start < finish) {
			// �� ���� ���� 0�̶��
			if (arr[start] + arr[finish] + temp == 0) {
				// �� �� ���� ������
				if (arr[start] == arr[finish]) {
					ans += finish - start;
				}
				// �� �� ���� �ٸ��ٸ�
				else {
					max_idx = lower_bound(arr + start, arr + n, arr[finish]) - arr;
					// arr[finish] �� ���� ���� �����ش�. 
					ans += finish - max_idx + 1;
				}
				start++;
			}
			// 0���� ������ start ����
			else if (arr[start] + arr[finish] + temp < 0) {
				start++;
			}
			// 0���� ũ�� finish ����
			else {
				finish--;
			}
		}
	}
	cout << ans;

}