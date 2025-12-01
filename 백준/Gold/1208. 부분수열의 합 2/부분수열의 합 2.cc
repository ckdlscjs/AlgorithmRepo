#include <iostream>

using namespace std;
const int bias = 4'000'000;
int N = 0, S = 0;
long long cnt = 0;
int seq[41];
int ps[8'000'005];

void lg(int mid, int sum) {
	if (mid == N / 2) {
		ps[sum + bias]++;
		return;
	}

	lg(mid + 1, sum + seq[mid]);
	lg(mid + 1, sum);
}

void rg(int mid, int sum) {
	if (mid == N) {
		cnt += ps[S - sum + bias];
		return;
	}

	rg(mid + 1, sum + seq[mid]);
	rg(mid + 1, sum);
}


int main() {
	cin >> N >> S;
	for (int i = 0; i < N; ++i) {
		cin >> seq[i];
	}

	lg(0, 0);
	rg(N/2, 0);	

	cout << ((S == 0) ? cnt - 1 : cnt);
}