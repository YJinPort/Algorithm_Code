#include <iostream>

struct Building {
    int y;
    int num;
} Building[100001];

int result[100001];

int main()
{
    int n;
    int t = 0, y;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &y);

        while (t > 0 && Building[t - 1].y < y) result[Building[--t].num] = i;

        Building[t].y = y;
        Building[t++].num = i;
    }

    for (int i = 1; i <= n; i++) printf("%d\n", result[i]);

    return 0;
}