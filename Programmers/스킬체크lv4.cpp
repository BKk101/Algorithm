#if 0

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

struct cmp2 {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first > b.first;
	}
};

int solution(int n, vector<int> cores) {
	int answer = 0;
	int time = 0;
	int cnt = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> que;
	vector<pair<int, int>> src;

	n -= cores.size();
	for (int i = 0; i < cores.size(); i++) {
		que.push({ cores[i], i+1 });
	}

	while (n > 0) {
		time++;
		cnt = 0;
		while (!que.empty() && time % que.top().first == 0) {
			pair<int, int> temp = que.top();
			src.push_back(temp);
			que.pop();
		}
		sort(src.begin(), src.end(), cmp);
		for (int i = 0; n > cnt && i < src.size();i++) {
			que.push(src[i]);
			cnt++;
			answer = src[i].second;
		}
		src.clear();
		n -= cnt;
		/*for (int i = 0; n > cnt && i < cores.size(); i++) {
			if (time % cores[i] == 0) {
				src[i] = 0;
			}
			if (src[i] == 0) {
				src[i] = 1;
				cnt++;
				answer = i + 1;
			}
		}*/
	}
	return answer;
}


int main() {
	solution(6, { 1, 2, 3});
}
#endif // 선입선출 스케쥴링

#if 0

#include <string>
#include <vector>

using namespace std;


int solution(int n, vector<vector<int>> edges) {
	int answer = 0;
	vector<vector<int>> map(n+1, vector<int> (n+1,0));

	for (auto i : edges) {
		map[i[0]][i[1]] = 1;
		map[i[1]][i[0]] = 1;
	}

	return answer;
}

int main() {
	solution(4, { {1,2},{2,3} });
}

#endif // 트리 트리오 중간값