#if 0

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;


int solution(vector<vector<int>> routes) {
	int answer = 0;
	int temp = -99999;

	sort(routes.begin(), routes.end());
	for (int i = 0; i < routes.size(); i++) {
		if (routes[i][0] > temp) {
			answer++;
			temp = routes[i][1];
		}
		else if (routes[i][1] <= temp) temp = routes[i][1];
	}
	return answer;
}

void print(vector<vector<int>> routes, int answer) {
	int t = solution(routes);
	if (t == answer) cout << "정답" << endl;
	else cout << "틀림" << endl;
}


int main() {
	print({ {-20,15}, {-14, -5}, {-18, -13}, {-5, -3} }, 2);
	print({ {-2, -1}, {1, 2}, {-3, 0} }, 2);
	print({ {0, 0} }, 1);
	print({ {0, 1}, {0, 1}, {1, 2} }, 1);
	print({ {0, 1}, {2, 3}, {4, 5}, {6, 7} }, 4);
	print({ {-20, 15}, {-14, -5}, {-18, -13}, {-5, -3} }, 2);
	print({ {-20, 15}, {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} }, 2);
	return 0;
}
#endif