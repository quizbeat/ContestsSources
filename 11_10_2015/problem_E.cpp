#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

bool pairMinMax(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second < b.second;
}


int main() {

	int input;

	ifstream in("next-partition.in");
	ofstream out("next-partition.out");


	int K;

	in >> K;

	vector <int> A(K);
	int N = 0;
	int temp;

	for (int i = 0; i < K; i++) {
		in >> temp;
		A[i] = temp;
		N += temp;
	}

	bool flag1 = false;
	bool flag2 = false;
	int sum = 0;

	sort(A.begin(), A.end());
	int iMarked = 0;

	for (int i = 0; i < K - 1; i++) {
		sum += A[i];
		if (A[i + 1] - A[i] >= 2) {
			iMarked = i + 1;
			A[i + 1]--;
			sum++;
			flag1 = true;
			break;
		}
	}

	//  1 1 1 2 3 4

	if (!flag1) {
		for (int i = 0; i < K - 2; i++) {
			for (int j = i + 2; j < K; j++) {
				if (A[i] + 1 > A[i + 1]) {
					break;
				}
				if (A[j] - A[i] > 2) {
					break;
				}
				if (A[j] - A[i] == 2 && A[j] - 1 >= A[j - 1]) {
					A[j]--;
					A[i]++;
					flag2 = true;
					break;
				}
			}
		}
	}

	// 1 1 2 2 2 4
	// 1 1 1 3 3 3
	// 1 1 1 2 2 5

	//out << iMarked << endl;

	if (flag1) {
		sum -= iMarked;
		for (int i = iMarked - 1; i >= 0; i--) {
			if (sum > 0) {
				temp = A[iMarked];
				if (sum+1 >= temp) {
					A[i] = temp;
					sum = sum - temp + 1;
				}
				else {
					A[i] = sum + 1;
					sum = 0;
				}
			}
			else A[i] = 1;
		}
		out << K << endl;
		for (int i = K - 1; i >= 0; i--) {
			out << A[i] << " ";
		}
	}
	else if (flag2) {
		out << K << endl;
		for (int i = K - 1; i >= 0; i--) {
			out << A[i] << " ";
		}
	} else {
		out << -1;
	}




	
	in.close();
	out.close();

	//cin >> input;

	return 0;
}