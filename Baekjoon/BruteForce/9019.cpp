#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
int t;
int start, finish;
queue<pair<int,string>>q;
bool visit[10000];
void bfs(int s, string com) {
	visit[s] = true;
	q.push({ s,com });
	while (!q.empty()) {
		int curNum = q.front().first;
		string curCom = q.front().second;

		q.pop();

		if (curNum == finish) {
			cout << curCom;
			break;
		}
		
		if (curNum* 2 > 9999 && !visit[(curNum * 2) % 10000]) {
			visit[curNum * 2 % 10000] = true;
			q.push({ (curNum * 2 % 10000), curCom + "D" });
		}
		else if(curNum * 2 <= 9999 && !visit[curNum * 2]){
			visit[curNum * 2] = true;
			q.push({ curNum * 2, curCom + "D" });
		}
		if (curNum == 0 && !visit[9999]) {
			visit[9999] = true;
			q.push({ 9999, curCom + "S" });
		}
		else if(curNum != 0 && !visit[curNum-1]){
			visit[curNum - 1] = true;
			q.push({ curNum - 1, curCom + "S" });
		}
		

		int lnum = curNum / 1000 + (curNum % 1000) * 10;
		if (!visit[lnum])
			q.push({ lnum, curCom + "L" });
		
		int rnum = (curNum % 10) * 1000 + (curNum / 10);
		
		if (!visit[rnum])
			q.push({ rnum, curCom + "R" });
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> start >> finish;
		bfs(start,"");
		cout << '\n';
		memset(visit, false, sizeof(visit));
		int cnt = q.size();
		while (cnt--) q.pop();
	}
}
