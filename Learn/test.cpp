#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

// vector out template
template<class T>
ostream& operator<<(ostream& os, vector<T> vect) {
    for (auto& it : vect) {
        os << it << " ";
    }
    return os;
}

// list out template
template<class T>
ostream& operator<<(ostream& os, list<T> vect) {
    for (auto& it : vect) {
        os << it << " ";
    }
    return os;
}

/*int main() {
    vector<int> p = { 4, 5, 6, 2, 3, 7 };
    std::sort(p.begin(), p.end());
    cout << p << endl;

    list<int> q = { 5, 6, 7, 2, 3, 4 };
    q.sort();//list中带sort方法
    cout << q << endl;

    return 0;
}*/