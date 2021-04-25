#include<vector>
#include <iostream>
using namespace std;
int main() {
	vector<vector<int>> myvector(6,vector<int> (3,5));
	for (vector<int>& vec : myvector) {
		for (int& aa : vec) {
			cout << aa << " ";
		}
		cout << endl;
	}
}