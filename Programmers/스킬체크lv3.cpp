#if 0

#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

stack<pair<int, int>> st;

string solution(int n, int k, vector<string> cmd) {
	
	int cur = k;
	int len = n;
	vector<int> list;

	for (int i = 0; i < n; i++) {
		list.push_back(i);
	}


	for (string s : cmd) {
		if (s[0] == 'C') {
			st.push({ cur, list[cur] });
			list.erase(list.begin() + cur);
			if (cur == len - 1) --cur;
			--len;
		}
		else if (s[0] == 'Z') {
			list.insert(list.begin() + st.top().first, st.top().second);
			if (st.top().first <= cur) ++cur;
			st.pop();
			++len;
		}
		else if (s[0] == 'U') {
			cur -= s.back() - '0';
			if (cur < 0) cur = 0;
		}
		else if (s[0] == 'D') {
			cur += s.back() - '0';
			//if (cur > len - 1) cur = len - 1;
		}
	}

	string answer(n, 'X');
	for (int i = 0; i < list.size(); i++) {
		answer[list[i]] = 'O';
	}

	return answer;
}

int main() {
	solution(8, 2, { "D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z" });
}


#endif //카카오 표편집

#if 0

#include <string>
#include <vector>
#define INF 999999
using namespace std;

int map[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 0;
	vector<int> check(n+1, 0);

	for (auto f : fares) {
		map[f[0]][f[1]] = f[2];
		map[f[1]][f[0]] = f[2];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 0) map[i][j] = INF;
			if (i == j) map[i][j] = 0;
		}
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][k] + map[k][j] < map[i][j]) {
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
	
	answer = map[s][a] + map[s][b];
	for (int i = 1; i <= n; i++) {
		if (map[s][i] + map[i][a] + map[i][b] < answer) {
			answer = map[s][i] + map[i][a] + map[i][b];
		}
	}

	return answer;
}

int main() {
	solution(6, 4, 5, 6, {{2, 6, 6}, {6, 3, 7}, {4, 6, 7}, {6, 5, 11}, {2, 5, 12}, {5, 3, 20}, {2, 4, 8}, {4, 3, 9}});
}
 
#endif //합승택시요금

#if 0

#include <string>
#include <vector>
#include <set>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
	long long answer = -1;
	set<pair<int, int>> s;

	s.insert({ x,y });
	for (int i = queries.size() - 1; i >= 0;i--) {
		set<pair<int,int>>::iterator end = s.end();
		for (auto iter = s.begin(); iter != end; iter++) {
			int nx, ny;
			if (iter->first == 0 || iter->second == 0 || iter->first == m-1 || iter->second == n-1) { //벽에 붙은 경우
				while (queries[i][1]--) {
					nx = iter->first + dx[queries[i][0]];
					ny = iter->second + dy[queries[i][0]];
					if (nx < 0) nx = 0;
					if (ny < 0) ny = 0;
					if (nx >= m) nx = n - 1;
					if (ny >= n) ny = m - 1;
					s.insert({ nx,ny });
				}
			}
			else {
				nx = iter->first + dx[queries[i][0]];
				ny = iter->second + dy[queries[i][0]];
				if (nx < 0) nx = 0;
				if (ny < 0) ny = 0;
				if (nx >= m) nx = n - 1;
				if (ny >= n) ny = m - 1;
				s.insert({ nx,ny });
			}
		}
	}

	answer = s.size();
	return answer;
}

int main() {
	solution(2, 2, 0, 0, { {2, 1},{0, 1},{1, 1},{0, 1},{2, 1} });

#endif } // 공 이동 시뮬레이션

#if 0

#include <string>
#include <vector>
#include <map>

using namespace std;

typedef struct Pos {
	int r1, c1, r2, c2;

	bool operator <(Pos a) const {
		if (r1!=a.r1) return r1 < a.r1;
		else if (r2 != a.r2) return r2 < a.r2;
		else if (c1 != a.c1) return c1 < a.c1;
		else return c2 < a.c2;
	}
}Pos;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
	int answer = 0;
	map<Pos, int> m;

	for (auto sk : skill) {
		Pos temp = { sk[1],sk[2],sk[3],sk[4] };
		if (sk[0] == 1) sk[5] *= -1;
		m[temp] += sk[5];
	}
	
	for (auto it = m.begin(); it != m.end();it++) {
		for (int i = it->first.r1; i <= it->first.r2; i++) {
			for (int j = it->first.c1; j <= it->first.c2; j++) {
				board[i][j] += it->second;
			}
		}	
	}

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] > 0) answer++;
		}
	}
	return answer;
}

int main() {
	solution({ {5, 5, 5, 5, 5},{5, 5, 5, 5, 5},{5, 5, 5, 5, 5},{5, 5, 5, 5, 5} }, { {1, 0, 0, 3, 4, 4},{1, 2, 0, 2, 3, 2},{2, 1, 0, 3, 1, 2},{1, 0, 1, 3, 3, 1} });
}

#endif //파괴되지 않은 건물


#if 0

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
struct cmp {
	bool operator()(pair<int, int> a, pair<int,int> b) {
		return a.second > b.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> que;


int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int time = 0;
	int idx = 0;

	//que.push({ jobs[0][0], jobs[0][1] });


	while (!que.empty() || idx < jobs.size()) {
		
		if (que.empty() && jobs[idx][0] >= time) { //비어있는 경우
			time = jobs[idx][0];
			time += jobs[idx][1];
			answer += jobs[idx][1];
			idx++;
		}
		else if (!que.empty() && (idx < jobs.size() || jobs[idx][0] >= time)) { // 대기 작업 처리 경우
			while (!que.empty()) {
				pair<int, int> temp = que.top();
				que.pop();
				time += temp.second;
				answer += time - temp.first;
			}
		}
		else if (que.empty() && jobs[idx][0] < time) {
			time = jobs[idx][1];
		}
		else if (!que.empty() && jobs[idx][0] < time) { // 작업중, 큐 넣기
			que.push({ jobs[idx][0], jobs[idx][1] });
			idx++;
		}
	
	}
	
	return answer/jobs.size();
}

int main() {
	solution({ {0, 3},{1, 9},{2, 6} });
}

 
#endif // 디스크 컨트롤러

#if 0 

#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct Pos {
	int x1, y1, x2, y2;
}Pos;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int visit[101][101][101][101];

Pos turn(Pos a, int x, int y, int dir, vector<vector<int>> board) {
	Pos res = { -1,-1,-1,-1 };
	int N = board.size();
	if (a.x1 == a.x2) { // 세로
		if (dir == 1 || dir == 3) return res;
		if (x == a.x1) {
			int nx = a.x1 + dx[dir];
			int ny = a.y1 + dy[dir];
			if (nx < 1 || ny < 1 || nx > N || ny > N) return res;
			if (board[a.y2-1][nx-1] == 1) return res;
			res = { x,y,nx,ny };
		}
		else if (x == a.x2) {
			int nx = a.x2 + dx[dir];
			int ny = a.y2 + dy[dir];
			if (nx < 1 || ny < 1 || nx > N || ny > N) return res;
			if (board[a.y1-1][nx-1] == 1) return res;
			res = { x,y,nx,ny };
		}
	}
	else { // 가로
		if (dir == 0 || dir == 2) return res;
		if (x == a.x1) {
			int nx = a.x1 + dx[dir];
			int ny = a.y1 + dy[dir];
			if (nx < 1 || ny < 1 || nx > N || ny > N) return res;
			if (board[ny-1][a.x2-1] == 1) return res;
			res = { x,y,nx,ny };
		}
		else if (x == a.x2) {
			int nx = a.x2 + dx[dir];
			int ny = a.y2 + dy[dir];
			if (nx < 1 || ny < 1 || nx > N || ny > N) return res;
			if (board[ny-1][a.x1-1] == 1) return res;
			res = { x,y,nx,ny };
		}
	}
	
	return res;
}

queue<pair<Pos, int>> que;

int solution(vector<vector<int>> board) {
	int answer = 0;
	int N = board.size();

	que.push({ {1,1,2,1}, 0 });
	while (!que.empty()) {
		pair<Pos, int> temp = que.front();
		que.pop();
		if ((temp.first.x1 == N && temp.first.y1 == N) || (temp.first.x2 == N && temp.first.y2 == N)) {
			answer = temp.second;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx1 = temp.first.x1 + dx[i]; int ny1 = temp.first.y1 + dy[i];
			int nx2 = temp.first.x2 + dx[i]; int ny2 = temp.first.y2 + dy[i];
			if (!(nx1 < 1 || nx2 < 1 || nx1 > N || nx2 > N || ny1 < 1 || ny2 < 1 || ny1 > N || ny2 > N) && visit[ny1][nx1][ny2][nx2] == 0) {
				que.push({ {nx1,ny1,nx2,ny2}, temp.second + 1 });
				visit[ny1][nx1][ny2][nx2] = 1;
			}
			Pos np1 = turn(temp.first, temp.first.x1, temp.first.y1, i, board);
			Pos np2 = turn(temp.first, temp.first.x2, temp.first.y2, i, board);
			if (np1.x1 != -1 && visit[np1.y1][np1.x1][np1.y2][np1.x2] == 0) {
				que.push({ np1, temp.second + 1 });
				visit[np1.y1][np1.x1][np1.y2][np1.x2] = 1;
			}
			if (np2.x1 != -1 && visit[np2.y1][np2.x1][np2.y2][np2.x2] == 0) {
				que.push({ np2, temp.second + 1 });
				visit[np2.y1][np2.x1][np2.y2][np2.x2] = 1;
			}
		}

	}

	return answer;
}

int main() {
	solution({ {0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0} });
}

#endif // 블록이동하기

#if 0

#include <string>
#include <vector>
#include <queue>

using namespace std;

int visit[200];

void ff(int idx, vector<vector<int>> computers) {
	queue<int> que;

	que.push(idx);
	while (!que.empty()) {
		int temp = que.front();
		que.pop();
		for (int i = 0; i < computers.size(); i++) {
			if (i == temp) continue;
			if (visit[i] == 0 && computers[temp][i] == 1) {
				que.push(i);
				visit[i] = 1;
			}
		}
	}
}


int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			ff(i, computers);
			answer++;
		}
	}

	return answer;
}

int main()
{
	solution(3, { {1, 1, 0},{1, 1, 1},{0, 1, 1} });
}

#endif //네트워크

#if 0

#include <string>
#include <vector>

using namespace std;

int map[60][60];
int N,M;

bool check(int y, int x, vector<vector<int>> key) {
	int m = key.size();
	bool answer = true;
	for (int i = y; i < y + m; i++) {
		for (int j = x; j < x + m; j++) {
			map[i][j] += key[i-y][j-x];
		}
	}
	for (int i = m; i < m + N; i++) {
		for (int j = m; j < m + N; j++) {
			if (map[i][j] == 0 || map[i][j] > 1) {
				answer = false;
				break;
			}
		}
	}
	for (int i = y; i < y + m; i++) {
		for (int j = x; j < x + m; j++) {
			map[i][j] -= key[i-y][j-x];
		}
	}
	return answer;
}

vector<vector<int>> turn(int t, vector<vector<int>> key) {
	int m = key.size();
	vector<vector<int>> res = key;

	for (int k = 0; k < t; k++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				res[i][j] = key[m-1-j][i];
			}
		}
		key = res;
	}
	return res;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	M = key.size();
	N = lock.size();

	for (int i = M; i < M + N; i++) {
		for (int j = M; j < M + N; j++) {
			map[i][j] = lock[i - M][j - M];
		}
	}

	for (int i = 0; i < M + N; i++) {
		for (int j = 0; j < M + N; j++) {
			for (int k = 0; k < 4; k++) {
				if (check(i, j, turn(k, key))) {
					return true;
				}
			}
		}
	}
	return answer;
}

int main() {
	solution({ {0, 0, 0},{1, 0, 0},{0, 1, 1} }, { {1, 1, 1},{1, 1, 0},{1, 0, 1} });
}

#endif //자물쇠와 열쇠

#if 0

#include <iostream>
#include <vector>
using namespace std;

int N, W;

int check(int s, int e) {
	//if ((e - s + 1) < (2 * W + 1)) return 1;
	if ((e - s + 1) % (2 * W + 1) != 0) return 1 + (e - s + 1) / (2 * W + 1);
	else return (e - s + 1) / (2 * W + 1);
}

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int s;
	N = n;
	W = w;
	s = 1;
	for (int i : stations) {
		if (i - w > s) {
			answer += check(s, i - w - 1);
		}
		s = i + w + 1;
	}
	if (s <= n) {
		answer += check(s, n);
	}
	return answer;
}

int main() {
	solution(16, { 9 }, 2);
}

#endif //기지국 설치

#if 0

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;
	if (n > s) {
		answer.push_back(-1);
		return answer;
	}
	int q = s / n;
	int r = s % n;
	while (n-- > r) {
		answer.push_back(q);
	}
	
	while (r-- > 0) {
		answer.push_back(q + 1);
	}
	sort(answer.begin(), answer.end());
	return answer;
}

#endif // 최고의 집합

#if 0

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

map<string, vector<string>> m;
map<string, vector<string>> v;
int N;
vector<string> answer;


bool dfs(string s, int cnt) {
	if (cnt == N) {
		answer.push_back(s);
		return true;
	}
	for (int i = 0; i < m[s].size(); i++) {
		if (v[s][i] == "1") continue;
		answer.push_back(s);
		v[s][i] = "1";
		if (dfs(m[s][i], cnt + 1)) return true;
		v[s][i] = m[s][i];
		answer.pop_back();
	}
	return false;
}

vector<string> solution(vector<vector<string>> tickets) {	
	N = tickets.size();
	
	for (auto t : tickets) {
		m[t[0]].push_back(t[1]);
		sort(m[t[0]].begin(), m[t[0]].end());
	}
	v = m;
	dfs("ICN", 0);
	return answer;
}

int main() {
	solution({ {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL","SFO"} });
}

#endif //여행경로

#if 0

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<int, int> cnt;

bool cmp(pair<int, int> a, pair<int, int> b ) {
	return a.second > b.second;
}

#if 0
int solution(vector<int> a) {
	
	if (a.size() < 2) return 0;

	for (int i : a) {
		cnt[i]++;
	}
	vector<pair<int, int>> v(cnt.begin(), cnt.end());
	sort(v.begin(), v.end(), cmp);
	int answer = v[0].second;
		int flag = 0;
		int st = v[0].first;
		int i;
		for (i = 0; i < a.size(); i++) {
			if (a[i] != st) flag = 1;
			else {
				if (flag == 0) {
					if (i + 1 >= a.size() || (i + 1 < a.size() && a[i + 1] == st)) {
						answer--;
					}
					else i++;
				}
				else {
					flag = 0;
				}
			}
		}
		if (answer < 0) return 0;
		else return 2 * answer;
}
#endif

#if 1
int solution(vector<int> a) {
	int answer = 0;
	if (a.size() < 2) return 0;

	for (int i : a) {
		cnt[i]++;
	}
	vector<pair<int, int>> v(cnt.begin(), cnt.end());
	sort(v.begin(), v.end(), cmp);


	for (int j = 0; j < v.size(); j++) {
		int flag = 0;
		int st = v[j].first;
		int i;
		int res = v[j].second;
		for (i = 0; i < a.size(); i++) {
			if (a[i] != st) flag = 1;
			else {
				if (flag == 0) {
					if (i + 1 >= a.size() || (i + 1 < a.size() && a[i + 1] == st)) {
						res--;
					}
					else i++;
				}
				else {
					flag = 0;
				}
			}
		}
		if (res > 0) return 2 * (res);
	}

	return answer;
}
#endif

int main() {
	//solution({ 5, 2, 3, 3, 5, 3 });
	//solution({ 0, 3, 3, 0, 7, 2, 0, 2, 2, 0 });
	solution({ 1, 1, 1, 1, 1, 1, 2, 3, 2, 4 });
}


#endif // 스타수열

#if 0

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int check(string a, string b) {
	int res = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) res++;
	}
	return res;
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	queue<pair<string, int>> que;
	vector<int> visit(words.size(), 0);

	if (find(words.begin(), words.end(), target) == words.end()) return 0;
	que.push({ begin, 0 });
	while (!que.empty()) {
		pair<string, int> temp = que.front();
		que.pop();
		if (temp.first == target) {
			return temp.second;
		}
		for (int i = 0; i < words.size();i++) {
			if (visit[i] == 1) continue;
			if (check(temp.first, words[i]) == 1) {
				que.push({ words[i], temp.second + 1 });
				visit[i] = 1;
			}
		}
	}
	return answer;
}

#endif // 단어변환?
