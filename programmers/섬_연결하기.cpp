#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> node;

int getParent(int x){
    if(node[x] == x) return x;
    return node[x] = getParent(node[x]);
}

int find(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if( a == b) return 1;
    else return 0;
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a<b) node[b] = a;
    else node[a] = b;

}

bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    sort(costs.begin(), costs.end(), compare);

    for(int i = 0; i < n; i++){
        node.push_back(i);
    }

    for(int i = 0; i < costs.size(); i++){
        if(!find(costs[i][0], costs[i][1])){
            answer += costs[i][2];
            unionParent( costs[i][0], costs[i][1]);

        }
    }

    return answer;
}

// int d[101];
// 
// int getParent(int node){
//     if(node == d[node]){
//         return node;
//     }
//     else return d[node] = getParent(d[node]);
// }
// 
// bool compare(vector<int> a, vector<int> b){
//     return a[2] < b[2];
// }
// 
// int solution(int n, vector<vector<int>> costs) {
// 
//     int answer = 0;
//     for(int i =0; i<n; i++){
//         d[i] = i;
//     }
//     sort(costs.begin(), costs.end(), compare);
//     for(int i=0; i<costs.size(); i++){
//         int start = getParent(costs[i][0]);
//         int end = getParent(costs[i][1]);
//         int cost = costs[i][2];
// 
//         if(start != end){
//             d[end] = start;
// 
//             answer += cost;
//         }
//     }
// 
// 
//     return answer;
// }
