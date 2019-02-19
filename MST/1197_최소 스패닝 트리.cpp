//
// Created by SML on 2/19/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

long long ans;


class Edge{
public:
    int node1;
    int node2;
    int val;
    Edge(int node1, int node2, int val) : node1(node1), node2(node2), val(val) {}
};

bool comp(Edge e1, Edge e2){
    return e1.val < e2.val;
}

int getParent(int parent[], int node){
    if(parent[node] == node) return node;
    return getParent(parent, parent[node]);
}

//union
void unionParent(int parent[], int node1, int node2) {
    node1 = getParent(parent, node1);
    node2 = getParent(parent, node2);
    if(node1 < node2){
        parent[node2] = node1;
    }else{
        parent[node1] = node2;
    }
}

//find
bool sameParent(int parent[], int node1, int node2){
    int pNode1 = getParent(parent, node1);
    int pNode2 = getParent(parent, node2);
    return pNode1 == pNode2;
}


int main(){
    vector<Edge> vec;
    int v, e;
    cin >> v >> e;
    for (int i = 1; i <= e; ++i) {
        int a, b, val;
        cin >> a >> b >> val;
        vec.push_back(Edge(a, b, val));
    }
    sort(vec.begin(), vec.end(), comp);

    int parent[v];
    for (int i = 0; i < v; ++i) {
        parent[i] = i;
    }

    for (int i = 0, limit = vec.size(); i < limit; ++i) {
        if(!sameParent(parent, vec[i].node1 - 1, vec[i].node2 - 1)){
            ans += vec[i].val;
            unionParent(parent, vec[i].node1 - 1, vec[i].node2 - 1);
        }
    }
    cout << ans << '\n';
    return 0;
}
