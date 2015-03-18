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
    ifstream in("kingofguess.in");
    //ofstream out("mosaic.out");
	int X;
	int N;
	int Y;
	int mid;
	int step = 0;

	in >> N >> X >> Y;

	while(true) {
		step++;
		mid = (X + Y)/2;
		if(mid == N) {
			cout << step << endl;
			//cin >> N;
			return 0;
		}
		if(mid > N)
			Y = mid;
		if(mid < N)
			X = mid;
	}


	//cin >> N;


    //in.close();
    //out.close();

    return 0;
}
