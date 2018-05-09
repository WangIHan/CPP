#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int main(int argc, char **argv) {
	int a[] = {1,1,2,3,4};
	int size  = sizeof(a) / sizeof(int);
	
	do {
		for(int i = 0; i < size; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	} while (next_permutation(a, a+size));
	//int a[] = {1,2,3,4,5,6};
	int b[] = {0,0,0,0,1};
	int c = 0;
	do {
		int sum = 0;
		for(int i = 0; i < 5; i++) {
			if(b[i] == 1)
				sum += a[i];
		}
		if(sum == 6)
			c++;
		
	} while (next_permutation(b,b+6));
	system("color a");
	cout << "c = " << c << endl;
	return 0;
}
