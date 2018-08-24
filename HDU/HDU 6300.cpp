#include<bits/stdc++.h>
using namespace std;
const int maxn = 3000 + 7;

struct node {
    int x, y, id;
}a[maxn];
bool cmp(node a, node b) {
    return a.x < b.x;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n; scanf("%d", &n);
        int m = 3*n;
        for(int i = 1; i <= m; ++i) {
            int x,y;
            scanf("%d%d", &a[i].x,&a[i].y);
            a[i].id = i;
        }
        sort(a+1,a+1+m, cmp);
        for(int i = 1; i <= m; i += 3) {
            printf("%d %d %d\n", a[i].id, a[i+1].id, a[i+2].id);
        }
    }
    return 0;
}
