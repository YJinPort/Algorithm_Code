#include<iostream>
using namespace std;

int main()
{
	int n, count = 0;
	int arr[100][100];
	int x = -1, y = -1;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (i % 3 == 0)		//0~9�� ���ڸ� ����ϹǷ� 3���� ���� �������� Ȱ���Ѵ�.
			{
				arr[++x][++y] = (count++) % 10;
			}
			else if (i % 3 == 1)
			{
				arr[x][--y] = (count++) % 10;
			}
			else if (i % 3 == 2)
			{
				arr[--x][y] = (count++) % 10;
			}
		}
	}

	//���
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}