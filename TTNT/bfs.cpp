#include <bits/stdc++.h>
using namespace std;

// 10 12
// s a
// s b
// a c
// a d
// b e
// b f
// e d
// c g
// d h
// f i
// i h
// h g


int n, m;
vector<char> adj[128]; // mang cac vector de luu dsach ke
bool visited[128]; // mang ktra cac dinh xem da duoc duyet

void nhap() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        char x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        //adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void bfs(char u) {
    //Buoc khoi tao:
    queue<char> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()) {
        char v = q.front(); // lay dinh dau hang doi
        q.pop();
        cout << v << " ";
        for(char x : adj[v]) {
            if(!visited[x]) {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main() {
    nhap();
    bfs('s');

    return 0;
}