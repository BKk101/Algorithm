#if 0

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int check(char a, char b) {
	if (a < b) {
		return min(b - a, 1 + 'Z' - b);
	}
	else {
		return min(a - b, 1 + 'Z' - a);
	}
}

int move(int idx, string name) {
	int cnt = 1;
	int rcnt = -1;
	int len = name.size();

	int i = (idx + 1) % len;
	while (name[i] == 'A') {
		++i%len;
		cnt++;
	}
	i = (idx - 1 + len) % len;
	while (name[i] == 'A') {
		(--i+len)%len;
		rcnt--;
	}
	if (cnt < abs(rcnt)) return cnt;
	else return rcnt;
}

int solution(string name) {
	int answer = 0;
	int cnt = 0;
	int idx = 0;

	for (int i = 0; i < name.size(); i++) {
		if (name[i] != 'A') cnt++;
	}
	for (int i = 0; i < cnt; i++) {
		answer += check('A', name[idx]);
		int mv = move(idx, name);
		answer += abs(mv);
		idx = (idx + mv+name.size()) % name.size();
	}

	return answer;
}

int main() {
	solution("JAN");
}


#endif