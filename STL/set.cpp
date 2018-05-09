#include <iostream>
#include <set>
using namespace std;
int main(int argc, char **argv) {
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	
	set<int>::iterator it = s.begin();
	while(it != s.end()) {
		cout << *(it++)  << " ";
	}
	cout << endl;
	return 0;
}
