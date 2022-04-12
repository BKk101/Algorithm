#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int W, A;
int D2[800000];
int D3[800000];
vector<int> parcel;

bool comp(vector<int> a, vector<int> b) {
	return a > b;
}

int main() {
	scanf("%d%d", &W, &A);
	for (int i = 0; i < A; i++) {
		int temp;
		scanf("%d", &temp);
		parcel.push_back(temp);
	}
	sort(parcel.begin(), parcel.end());
	for (int i = 0; i < A; i++) {
		if (parcel[i]>=W) break;
		for (int j = 0; j < A; j++) {
			if (i == j) continue;
			if (parcel[j] >= W) break;
			int idx = parcel[i] + parcel[j];
			if (idx >= W) break;

			D2[idx] = 1;
		}
	}
	
	for (int i = 0; i < A; i++) {
		if (parcel[i] >= W) break;
		int idx = W - parcel[i];
		if (D2[idx] == 1) {
			int idx2 = idx + parcel[i];
			D3[idx2] = 1;
		}
	}
	
	string answer = "NO";

	for (int i = 0; i < A; i++) {
		if (parcel[i] >= W) break;
		int idx = W - parcel[i];
		if (D3[idx] == 1) {
			answer.clear();
			answer = "YES";
			break;
		}
	}
	cout << answer;

}
