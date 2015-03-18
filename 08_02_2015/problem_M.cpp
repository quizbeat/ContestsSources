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

using namespace std;

int main() {

    more_speed
    ifstream in("mosaic.in");
    ofstream out("mosaic.out");

	int N, M;

	in >> M >> N;

	int answ;

	if(N < 3 || M < 3) {
		out << "0" << endl;
		return 0;
	}

	if((N - 2)*(M - 2) % 2 == 0)
		answ = (N - 2)*(M - 2) / 2;
	else
		answ = (N - 2)*(M - 2) / 2 + 1;

	out << answ << endl;

	int k = 2;
	for(int i = 2; i < M; i++) {
		for(int j = k; j < N; j+=2) {
			out << (i - 1)*N + j << " ";
		}
		if(k == 2)
			k = 3;
		else k = 2;
	}

	//cin >> N;


    in.close();
    out.close();

    return 0;
}
