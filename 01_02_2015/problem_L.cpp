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

int main() {

    more_speed
    int n, M;
	cin >> n >> M;

	vector <int> num;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		num.push_back(temp);
	}

	int max_sum = 0;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++) {
			temp = num[i] + num[j];
			if(temp <= M && temp > max_sum)
				max_sum = temp;
		}

	cout << max_sum << endl;
    cin >> n;



    return 0;
}
