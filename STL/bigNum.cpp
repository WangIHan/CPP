#include <iostream>
#include <string>
#include <deque>
#include <functional>
#include <algorithm>
#include <iterator>
using namespace std;
class BigNum {
	deque<int> v;
public:
	BigNum(){}
	BigNum(string strNum) {
		copy(strNum.begin(), strNum.end(), back_inserter(v));
		transform(v.begin(), v.end(), v.begin(), bind2nd(minus<int> (), '0'));
	}
	deque<int>::iterator begin() {
		return v.begin();
	}
	deque<int>::iterator end() {
		return v.end();
	}
	int size() {
		return v.size();
	}
	back_insert_iterator<deque<int> > Back_Inserter() {
		return back_inserter(v);
	}
	void push_front(int n) {
		v.push_front(n);
	}
	void push_back(int n) {
		v.push_back(n);
	}
	void adjust() {
		int nSize = v.size();
		
		for(int i = nSize - 1; i >= 1; i--) {
			int value = v[i];
			if(value < 10) continue;
			v[i] = value % 10;
			v[i-1] += value/10;
		}
		
		int value = v[0];
		if(value > 10) {
			v[0] = value % 10;
			value = value / 10;
			while(value > 0) {
				v.push_front(value % 10);
				value / 10;
			}
		}
		nSize = v.size();
	}
	BigNum Add(BigNum & m) {
		BigNum result;
		int n = size() - m.size();
		if(n >= 0) {
			transform(begin()+n, end(), m.begin(), result.Back_Inserter(), plus<int> ());
			for(int i = n-1; i >= 0; i--) {
				result.push_front(* (begin() + i));
			}
		}
		else {
			transform(begin(), end(), m.begin()-n, result.Back_Inserter(), plus<int> ());
			for(int i = -n-1; i >=0; i++) {
				result.push_front(* (m.begin() + i));
			}
		}
		result.adjust();
		return result;
	}
	BigNum Multiply(BigNum & m) {
		BigNum result("0");
		BigNum mid;
		for(int i = 0; i < m.size(); i++) {
			mid = *this;
			for(int j = 0; j < i; j++) {
				mid.push_back(0);
			}
			transform(mid.begin(), mid.end(), mid.begin(), 
			bind2nd(multiplies<int> (), * (m.begin() + i)));
			result = mid.Add(result);
		}
		return result;
	}
};

int main() {
	BigNum m1("1234567890");
	BigNum m2("99999999998");
	BigNum result = m1.Add(m2);
	cout << "the result of m1 and m2: ";
	copy(result.begin(), result.end(), ostream_iterator<int> (cout));
	cout << endl;
	
	BigNum m3("99");
	BigNum m4("99999");
	BigNum m5 = m3.Multiply(m4);
	cout << "the result of m3 and m4 is: ";
	copy(m5.begin(), m5.end(), ostream_iterator<int> (cout));
	cout << endl;
	return 0;
}












































