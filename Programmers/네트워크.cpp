#include <string>
#include <vector>
#include <queue>

using namespace std;

int visit[201];
int len;
vector<vector<int>> comp;
queue<int> que;

void ff() {
	if (que.empty()) return;
	int node = que.front();
	que.pop();
	visit[node] = 1;

	for (int i = 0; i < len; i++) {
		if (i == node) continue;
		if (comp[node][i] == 1 && visit[i] == 0) {
			que.push(i);
		}
	}
	ff();
	return;
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	len = computers.size();
	comp = computers;

	for (int i = 0; i < len; i++) {
		que = queue<int>();
		if (visit[i] == 0) {
			que.push(i);
			ff();
			++answer;
		}
	}

	return answer;
}

int main() {
	vector<vector<int>> compute;
	compute.push_back({ 1, 1, 0 });
	compute.push_back({ 1, 1, 1 });
	compute.push_back({ 0, 1, 1 });
	solution(compute.size(), compute);
}