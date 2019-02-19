//
// Created by SML on 2/19/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int parent[1001];
int ans;

class Edge{
public:
    int node1;
    int node2;
    int dist;
    Edge(int node1, int node2, int dist) : node1(node1), node2(node2), dist(dist) {}
};

vector<Edge> v;

bool comp(Edge e1, Edge e2){
    return e1.dist < e2.dist;
}

int getParent(int node){
    if(parent[node] == node) return node;
    return getParent(parent[node]);
}

bool sameParent(int node1, int node2){
    return getParent(node1) == getParent(node2);
}

void unionParent(int node1, int node2){
    node1 = getParent(node1);
    node2 = getParent(node2);
    if(node1 < node2){
        parent[node2] = node1;
    }else{
        parent[node1] = node2;
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(Edge(a, b, c));
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    for (int i = 0, limit = v.size(); i < limit; ++i) {
        if(!sameParent(v[i].node1, v[i].node2)){
            ans += v[i].dist;
            unionParent(v[i].node1, v[i].node2);
        }
    }
    cout << ans << "\n";
    return 0;
}