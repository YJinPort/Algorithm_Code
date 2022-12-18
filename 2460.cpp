#include <stdio.h>

int main() {
	int n, maxScore = 0;
	int num1 = 0, num2 = 0, num3 = 0;
	int n1Cnt3 = 0, n1Cnt2 = 0;
	int n2Cnt3 = 0, n2Cnt2 = 0;
	int n3Cnt3 = 0, n3Cnt2 = 0;
	int student[1005][3] = { {0}, };

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &student[i][j]);
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0) {
				num1 += student[j][i];
				if (student[j][i] == 3) n1Cnt3++;
				else if (student[j][i] == 2) n1Cnt2++;
			}
			if (i == 1) {
				num2 += student[j][i];
				if (student[j][i] == 3) n2Cnt3++;
				else if (student[j][i] == 2) n2Cnt2++;
			}
			if (i == 2) {
				num3 += student[j][i];
				if (student[j][i] == 3) n3Cnt3++;
				else if (student[j][i] == 2) n3Cnt2++;
			}
		}
	}

	if (maxScore <= num1) maxScore = num1;
	if (maxScore <= num2) maxScore = num2;
	if (maxScore <= num3) maxScore = num3;

	if (num1 > num2 && num1 > num3) printf("1 %d", num1);
	else if (num2 > num1 && num2 > num3) printf("2 %d", num2);
	else if (num3 > num1 && num3 > num2) printf("3 %d", num3);
	else {
		if (num1 == num2 && num2 != num3) {
			if (n1Cnt3 > n2Cnt3) printf("1 %d", num1);
			else if (n1Cnt3 == n2Cnt3) {
				if (n1Cnt2 > n2Cnt2) printf("1 %d", num1);
				else if (n1Cnt2 == n2Cnt2) printf("0 %d", maxScore);
				else printf("2 %d", num2);
			}
			else printf("2 %d", num2);
		}
		else if (num1 == num3 && num3 != num2) {
			if (n1Cnt3 > n3Cnt3) printf("1 %d", num1);
			else if (n1Cnt3 == n3Cnt3) {
				if (n1Cnt2 > n3Cnt2) printf("1 %d", num1);
				else if (n1Cnt2 == n3Cnt2) printf("0 %d", maxScore);
				else printf("3 %d", num3);
			}
			else printf("3 %d", num3);
		}
		else if (num2 == num3 && num2 != num1) {
			if (n2Cnt3 > n3Cnt3) printf("2 %d", num2);
			else if (n2Cnt3 == n3Cnt3) {
				if (n2Cnt2 > n3Cnt2) printf("2 %d", num2);
				else if (n2Cnt2 == n3Cnt2) printf("0 %d", maxScore);
				else printf("3 %d", num3);
			}
			else printf("3 %d", num3);
		}
		else printf("0 %d", maxScore);
	}

	return 0;
}