#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<vector<int>> number;
int visit[501][501];

int calc(int depth, int idx) {
	if (idx < 0) return 0;
	if (number[depth].size() <= idx) return 0;
	if (visit[depth][idx] != -1) return visit[depth][idx];
	if (depth == 0) {
		visit[depth][idx] = number[depth][idx];
		return number[depth][idx];
	}
	int rtn = max(calc(depth - 1, idx - 1), calc(depth - 1, idx));
	visit[depth][idx] = rtn;
	return rtn;
}

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int len = triangle.size();

	for (int i = 0; i < len; i++) {
		number.push_back(triangle[i]);
		for (int j = 0; j < len; j++) {
			visit[i][j] = -1;
		}
	}

	for (int i = 0; i < len; i++) {
		max(answer, calc(len - 1, i));
	}

	return answer;
}

int main() {
	solution({ {7},{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5} });
}