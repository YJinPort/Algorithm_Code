#include <iostream>
#include <algorithm>

using namespace std;

int solution[100001];
int result[2];
int n, plusNum;
int a = 200000001, minNum = 0;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> solution[i];
	}

	sort(solution + 0, solution + n);

	while (minNum < n) {
		if (minNum == (n - 1)) break;
		plusNum = solution[minNum] + solution[n-1];
		if (abs(plusNum) < a) {
			a = abs(plusNum);
			result[0] = solution[minNum];
			result[1] = solution[n-1];
		}
		if (plusNum == 0) break; 
		else if (plusNum < 0) minNum += 1;
		else n -= 1;
	}

	sort(result + 0, result + 2);

	cout << result[0] << " " << result[1];

	return 0;
}