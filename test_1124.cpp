#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int testCase;
	int member[200001];
	int N, all = 0, max = 0, tmp = 0;
	int op = 0;

	cin >> testCase;

	for (int i = 1; i <= testCase; i++) {
		cin >> N;
		max = 0;
		all = 0;
		for (int j = 0; j < N; j++) {
			cin >> member[j];
			all += member[j];
		}

		for (int x = 0; x < N; x++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					if (k == j) continue;
					tmp += member[k];
				}

				if (abs(tmp) >= abs(all)) {
					max = abs(tmp);
				}
				
				if (j == N - 1 && max == 0) max = abs(all);

				tmp = 0;
			}
			op += max;
		}
		cout << "#" << i << " " << op << endl;
		op = 0;
	}

	return 0;
}