#if 0

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, Q;
int msize;
int map[64][64];
int Copy[64][64];
int visit[64][64];
int dx[] = {1,0,-1,0};
int dy[] = { 0,1,0,-1 };
int maxice;
queue<pair<int,int>> que; //x,y

void Turn(int size, int x, int y) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			map[i+y][j+x] = Copy[y+size-1 - j][x+i];
		}
	}
}

void Melt(int x, int y) {
	int cnt = 0;

	if (x - 1 >= 0 && map[y][x-1] > 0) cnt++;
	if (x + 1 < msize && map[y][x+1] > 0) cnt++;
	if (y - 1 >= 0 && map[y-1][x] > 0) cnt++;
	if (y + 1 < msize && map[y+1][x] > 0) cnt++;
	if (cnt < 3 && Copy[y][x]>0) Copy[y][x]--;
}

void ff(int x, int y) {
	pair<int, int> temp;

	while (!que.empty()) {
		temp = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = temp.first + dx[i];
			int ny = temp.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= msize || ny >= msize || visit[ny][nx] == 1 || map[ny][nx]<1 ) continue;
			visit[ny][nx] = 1;
			que.push({ nx,ny });
			maxice++;
		}
	}
}

int main() {
	cin >> N >> Q;
	msize = pow(2, N);
	vector<int> list;
	for (int i = 0; i < msize; i++) {
		for (int j = 0; j < msize; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < Q; i++) {
		int temp;
		cin >> temp;
		list.push_back(temp);
	}

	for (int k : list) {
		int S = pow(2, k);
		copy(&map[0][0], &map[0][0] + 64 * 64, &Copy[0][0]);
		for (int i = 0; i < msize; i+=S) {
			for (int j = 0; j < msize; j+=S) {
				Turn(S, j, i);
			}
		}
		copy(&map[0][0], &map[0][0] + 64 * 64, &Copy[0][0]);
		for (int i = 0; i < msize; i++) {
			for (int j = 0; j < msize; j++) {
				Melt(j, i);	
			}
		}
		copy(&Copy[0][0], &Copy[0][0] + 64 * 64, &map[0][0]);
	}

	int answer = 0;
	int answer2 = 0;
	for (int i = 0; i < msize; i++) {
		for (int j = 0; j < msize; j++) {
			answer += map[i][j];
			if (visit[i][j] == 0 && map[i][j]>0) {
				que.push({ j,i });
				visit[i][j] = 1;
				maxice = 1;
				ff(j, i);
				answer2 = max(answer2, maxice);
				
			}
		}
	}
	cout << answer << endl << answer2;
}

#endif //마법사 상어와 파이어스톰 

#if 0

#include <iostream>
#include <vector>

using namespace std;

int N;
int map[500][500];
int answer;
int cnt = 1;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };


int check(int x, int y, int r, int dir, int sand) {
	int nx, ny;
	nx = x; ny = y;
	for (int i = 0; i < r; i++) {
		nx = nx + dx[dir];
		ny = ny + dy[dir];
	}

	if (nx < 0 || ny < 0 || nx >= N || ny >= N) answer += sand;
	else map[ny][nx] += sand;
	return sand;
}

int check2(int x, int y, int fb, int rl, int sand) {
	int nx, ny;

	if (fb == 0 || fb == 2) {
		nx = x + dx[fb];
		ny = y + dy[rl];
	}
	else {
		nx = x + dx[rl];
		ny = y + dy[fb];
	}
	if (nx < 0 || ny < 0 || nx >= N || ny >= N) answer += sand;
	else map[ny][nx] += sand;
	return sand;
}


void Tornado(int x, int y, int d) {
	int s = map[y][x];
	int r = (d + 1) % 4;
	int l = d > 0 ? d - 1 : 3;
	int b = (d + 2) % 4;
	int sum = 0;

	map[y][x] = 0;
	sum += check(x, y, 2, d, s*0.05);
	sum += check(x, y, 1, r, s*0.07);
	sum += check(x, y, 2, r, s*0.02);
	sum += check(x, y, 1, l, s*0.07);
	sum += check(x, y, 2, l, s*0.02);
	sum += check2(x, y, d, r, s*0.1);
	sum += check2(x, y, d, l, s*0.1);
	sum += check2(x, y, b, r, s*0.01);
	sum += check2(x, y, b, l, s*0.01);
	check(x, y, 1, d, s - sum);
}

int main() {
	int xx, yy;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int dir = 2;
	xx = N / 2;
	yy = N / 2;
	while (1) {
		if (xx < 0 || yy < 0) break;
		for (int j = 0; j < 2; j++) {
			if (xx < 0 || yy < 0) break;
			for (int i = 0; i < cnt; i++) {
				xx = xx + dx[dir];
				yy = yy + dy[dir];
				if (xx < 0 || yy < 0) break;
				Tornado(xx, yy, dir);
			}
			dir = dir > 0 ? dir - 1 : 3;
		}
		cnt++;
	}
	cout << answer;
}

#endif // 마법사 상어와 토네이도
