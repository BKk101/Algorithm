#if 0

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

bool cmp2(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> m1;
	map<string, vector<pair<int, int>>> m2;

	for (int i = 0; i < genres.size(); i++) {
		m1[genres[i]] += plays[i];
		m2[genres[i]].push_back({ plays[i], i });
	}

	vector<pair<string, int>> v1(m1.begin(), m1.end());
	sort(v1.begin(), v1.end(), cmp);

	for (auto i : v1) {
		vector<pair<int, int>> vec(m2[i.first].begin(), m2[i.first].end());
		sort(vec.begin(), vec.end(), cmp2);
		for (int i = 0; i < vec.size(); i++) {
			if (i > 1) break;
			answer.push_back(vec[i].second);
		}
	}
	return answer;
}


#endif