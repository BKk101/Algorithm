#if 0

#include <vector>
#include <queue>
using namespace std;

int visit[101][101];
int map[101][101];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

typedef struct pos {
	int x, y, cnt;
}pos;

queue<pos> que;

int solution(vector<vector<int> > maps)
{
	int answer = 0;
	int X = maps[0].size();
	int Y = maps.size();

	que.push({ 1,1,1 });

	while (!que.empty()) {
		pos temp = que.front();
		que.pop();
		if (temp.x == X && temp.y == Y) {
			answer = temp.cnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = temp.x + dx[i];
			int ny = temp.y + dy[i];
			if (nx<1 || ny<1 || nx>X || ny>Y || visit[ny][nx] == 1 || maps[ny-1][nx-1] == 0) continue;
			que.push({ nx,ny,temp.cnt + 1 });
			visit[ny][nx] = 1;
		}
	}
	if (answer == 0) answer = -1;

	return answer;
}

int main() {
	solution({ {1, 0, 1, 1, 1},{1, 0, 1, 0, 1},{1, 0, 1, 1, 1},{1, 1, 1, 0, 1},{0, 0, 0, 0, 1} });
}

#endif

#if 0

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int len = number.size();


	while (number.size() != len - k) {
		char Min = '9';
		int idx = -1;
		for (int i = 0; i < k + 1; i++) {
			if (number[i] < Min) {
				Min = number[i];
				idx = i;
			}
		}
		if (idx > 0) {
			string temp = number;
			number = temp.substr(0, idx) + temp.substr(idx + 1);
		}
		else
			number = number.substr(idx + 1);
	}
	answer = number;
	return answer;
}

int main() {
	solution("1924", 2);
}


#endif