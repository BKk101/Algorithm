#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int cnt = 0;
	int lena = lost.size();
	int lenb = reserve.size();

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());
	for (int i = 0; i < lena; i++) {
		for (int j = 0; j < lenb; j++) {
			if (lost[i] == reserve[j]) {
				// lost.erase(lost.begin()+i);
				// reserve.erase(reserve.begin()+j);
				lost[i] = -1;
				reserve[j] = -1;
			}
		}
	}

	for (int i = 0; i < lost.size(); i++) {
		if (lost[i] == -1) continue;
		for (int j = 0; j < reserve.size(); j++) {
			if (reserve[j] == -1) continue;
			else if (lost[i] - 1 == reserve[j] || lost[i] + 1 == reserve[j]) {
				reserve[j] = -1;
				cnt++;
				break;
			}
		}
	}
	answer = n - (lost.size() - cnt);
	return answer;
}

int main() {
	solution(7, { 2,3,4 }, { 1,2,3,6 });
	//solution(30, { 1, 2, 7, 9, 10, 11, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27 }, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 20, 22, 23, 24, 25, 26, 27, 28
//});
}


#endif