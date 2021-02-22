#include <iostream>
#include <algorithm>
using namespace std;
int n,num[101];
long long d[101][1001];
long long go(int val,int idx) {
	if (idx == n - 1) {
		if (val == num[n]) 
			return 1;
		else 
			return 0;
	}
	if (val > 20 || val < 0) 
		return 0;
	if (d[idx][val] != 0) 
		return d[idx][val];

	d[idx][val] += go(val + num[idx + 1], idx + 1);
	d[idx][val] += go(val - num[idx + 1], idx + 1);

	return d[idx][val];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> num[i];
	cout << go(num[1],1);
}