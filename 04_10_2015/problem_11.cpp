#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

bool pairMinMax(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second < b.second;
}


int main() {

	ifstream in("input.txt");
	ofstream out("output.txt");


	int N;
	long long S;

	in >> N >> S;

	vector <pair <int, int> > element(N);
	vector <bool> bought(N+1, false);

	pair <int, int> temp;
	for (int i = 0; i < N; i++) {
		in >> temp.first >> temp.second;
		element[i] = temp;
	}

	sort(element.begin(), element.end(), pairMinMax);

	int count = 0;
	for (int i = 0; i < N; i++) {
		if (element[i].second > S) {
			break;
		}
		if (element[i].second <= S && bought[element[i].first] == false) {
			S -= element[i].second;
			bought[element[i].first] = true;
			count++;
		}
	}

	out << count << endl;
	
	in.close();
	out.close();

	//cin >> N;

	return 0;
}