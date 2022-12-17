#include <iostream>

int n, cnt = 0;
int chessPan[15];

bool check(int x) {
	for (int i = 0; i < x; i++) {
		if (chessPan[i] == chessPan[x] || abs(chessPan[x] - chessPan[i]) == x - i) 
            return false;
	}
    return true;
}

void queen(int q) {
	if (q == n) cnt++;
	else {
		for (int i = 0; i < n; i++) {
			chessPan[q] = i;
			if (check(q)) queen(q + 1);
		}
	}
}

int main() {

	scanf("%d", &n);

	queen(0);

    printf("%d", cnt);
}