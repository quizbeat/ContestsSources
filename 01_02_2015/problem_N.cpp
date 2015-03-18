//
//  main.cpp
//  contest
//
//  Created by Nikita Makarov on 21/07/14.
//  Copyright (c) 2014 quiz.corp. All rights reserved.
//

#include <iomanip>
#include <limits>
#include <iostream>
#include <algorithm>


double dist(const pair<int, int> &a, const pair<int, int> &b) {
    double x, y;
    x = (a.first - b.first);
    y = (a.second - b.second);
    x *= x;
    y *= y;
    return sqrt(x + y);
}

int main() {

    more_speed
    int n, d;
    cin >> n >> d;
    vector<pair<int, int> > points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    vector<vector<int> > g(n, vector<int>());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double dis = dist(points[i], points[j]);
                if (dis <= d) {
                    g[i].push_back(j);
                }
            }
        }
    }

    int s = 0;

    queue<int> q;
    q.push(s);
    vector<bool> used (n);
    used[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (size_t i = 0; i < g[v].size(); ++i) {
            int to = g[v][i];
            if (!used[to]) {
                if (to == n - 1) {
                    cout << "y" << endl;
                    return 0;
                }
                used[to] = true;
                q.push (to);
            }
        }
    }

    cout << "n" << endl;
    return 0;
}
