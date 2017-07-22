#include <iostream>
using namespace std;
long int len[999999] = { 1,2,8 };
int main() {
	long int ref;
	int max = 0;
	for (long int num = 4; num < 999999; ++num) {
		int count = 0;
		for (long long int op = num ; op > 1; op = (op % 2) == 0 ? op / 2 : 3 * op + 1) {
			if (op < num ) {
				count += len[op - 1];
				break;
			}
			++count;
		}
		
			len[num - 1] = count;
			if (count > max) {
				max = count;
				ref = num;
			}		
	}
        cout << max << " " << ref << endl;
}
