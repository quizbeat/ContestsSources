#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

#define LL long long
#define ULL  unsigned long long


using namespace std;

int main() {

	vector <vector <int> > k(5, vector <int> (101, 0) );

	vector <int> allK;

	set <int> elements;
	int temp = 0;
	for(int i = 0; i < 5; i++) { 
		for(int j = 0; j < 5; j++) {
			cin >> temp;
			k[i][temp]++;
			elements.insert(temp); 
		}
	}
	
	pair <int, int> tempPair;  // зубья, количество вилок
	vector <pair <int, int> > tempForI;
	set < vector < pair <int, int> > > count;
	
	for(int i = 0; i < 5; i++) {
		for(set<int>::iterator it = elements.begin(); it != elements.end(); it++) {
			tempPair.first = *it;
			tempPair.second = k[i][*it];
			tempForI.push_back(tempPair);
		}
		count.insert(tempForI);
		tempForI.clear();
	}



	/*int maxCount = 0;
	set <int> count;
	for(set<int>::iterator it = elements.begin(); it != elements.end(); it++) {
		for(int i = 0; i < 5; i++) {
			count.insert(k[i][*it]);
		}
		if(count.size() > maxCount) {
			maxCount = count.size();
		}
		count.clear();
	}*/

	cout <<	count.size() << endl;

	//cin >> temp;
	
	return 0;

}