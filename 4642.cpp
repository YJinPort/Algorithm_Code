#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Student {
    char name[20];
    int score;

    bool operator<(const Student& r)const {
        if (score == r.score) return strcmp(name, r.name) < 0;
        else return score > r.score;
    }
};

int main()
{
    Student s[50000];
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%s %d", s[i].name, &s[i].score);

    sort(s, s + n);

    for (int i = 0; i < n; i++) printf("%s %d\n", s[i].name, s[i].score);

    return 0;
}