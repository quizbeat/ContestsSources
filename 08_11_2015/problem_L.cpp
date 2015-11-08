//
//  main.cpp
//  opencup
//
//  Created by Nikita Makarov on 08/11/15.
//  Copyright © 2015 Nikita Makarov. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int n, k, m;
    cin >> n >> k >> m;
    
    vector< vector<int> > g(n + 1, vector<int>());
    
    vector<bool> side_effect(n + 1, false);
    
    int func_num;
    for (int i = 0; i < k; i++) {
        cin >> func_num;
        side_effect[func_num] = true;
    }
    
    int a, b;
    int count = k;
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        
        g[b].push_back(a);
        
        if (!side_effect[a] && side_effect[b]) {
            side_effect[a] = true;
            count++;
            
            queue<int> q;
            q.push(a);
            
            vector<bool> used(n + 1);
            used[a] = true;
            
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (size_t i = 0; i < g[v].size(); ++i) {
                    int to = g[v][i];
                    if (!used[to]) {
                        
                        used[to] = true;
                        
                        if (!side_effect[to]) {
                            side_effect[to] = true;
                            count++;
                            q.push(to);
                        }
                        
                    }
                }
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}
