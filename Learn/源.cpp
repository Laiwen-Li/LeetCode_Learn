#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
vector<double> vec = { 1,3.5,5.6,8,3.8 };

template<class T>
ostream& operator<< (ostream& os, vector<T> vect) {
	for (auto& it : vect) {
		os << it << " ";
	}
	return os;
}

bool cmp(const int& a, const int& b) {
	return a > b;
}

struct Student
{
	int sno;
	string sname;
	Student(int num, string str) {
		sno = num;
		sname = str;
	}

	Student() {
		sno = 0;
		sname = "";
	}

	friend ostream& operator<< (ostream& os, Student a) {
		os << a.sno << " " << a.sname << "\n";
		return os;
	}

	bool operator<(Student& a) {
		return sno < a.sno;
	}
};

/*int main()
{
	//sort(vec.begin(),vec.end(), greater<double>());
	//cout << vec;
	vector<Student> students(11);
	for (int i = 0; i < students.size(); ++i) {
		students[i].sno = i;
		students[i].sname = i+ 'a';
	}

	sort(students.begin(), students.end(), greater<Student>());
	cout << students;

	return 0;
}*/