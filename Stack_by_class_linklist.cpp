#include "Stack_by_class_linklist.h"
#include <iostream>
using namespace std;
bool Stack::Pop(Item *px)
{
	if(IsEmpty())
		return false;
	*px = GetFirst();
	return true;
}
void Sum_numeral(int n) {
	Stack s;
	int x;
	int sum = 0;
	int save;
	while (n) {
		save = n % 10;
		sum += save;
		s.Push(save);
		n /= 10;
	}
	while (s.Pop(&x)) {
		cout << x;
		if(!s.IsEmpty())cout << " + ";
	}
	cout << " = " << sum;

}
void Fact(int n) {
	int save = n;
	int x;
	Stack s;
	for (int i = 2; i < sqrt(n); i++) {
		while (n % i == 0) {
			s.Push(i);
			n /= i;
		}
	}
	if (n > 1) s.Push(n);
	cout << save << " = ";
	while (s.Pop(&x)) {
		cout << x;
		if (!s.IsEmpty()) cout << " * ";
	}


}
int main() {

	int x;
	cout << "BAI 10 " << endl;
	cout << "Prime Factor: " << endl;
	cout << "Input number: ";
	cin >> x;
	Fact(x);
	puts("\n");
	cout << "BAI 11 " << endl;
	cout << "Sum numeral: " << endl;
	cout << "Input number: ";
	cin >> x;
	Sum_numeral(x);

	puts("");
	system("pause");
	return 0;
}
