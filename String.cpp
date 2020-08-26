#include<iostream>
#include"String.h"
#include <string>

using namespace std;

void String::set(const char * s)
{
	if (p) delete p;
	if (!s) { p = NULL; return; }
	p = new char[strlen(s) + 1];
	strcpy(p, s);
}

void String::Print() const
{
	cout << p << endl;
}

void String::Input()
{
	delete[] p;
	static char q[1000];
	cin.getline(q, 1000);
	p = _strdup(q);

}

int String::compare(String s) const
{
	return strcmp(p,s.p);
}

void String::concat(const String &b)
{
	char *q = new char[GetLength()+b.GetLength()+1];
	strcpy(q, p);
	strcat(q, b.p);
	delete[]p;
	p = q;
}

String String::UpCase() const
{
	String r = *this;
	strupr(r.p);
	return r;
}

String String::LowCase() const
{
	String r = *this;
	strlwr(r.p);
	return r;
}

void String::reverse() const
{
	strrev(p);
}

int main() {

	
	String s;
	cout << "Input string:";
	s.Input();
	s.Print();
	cout << "Your string have length: ";
	cout << s.GetLength();

	puts("\n");
	cout << "String Upper:" << endl;
	String t = s.UpCase();
	t.Print();

	puts("\n");
	cout << "String Lower:" << endl;
	String r = s.LowCase();
	r.Print();

	puts("\n");
	cout << "Concat" << endl;
	r.concat(t);
	r.Print();

	puts("\n");
	cout << "Reverse" << endl;
	s.reverse();
	s.Print();

	puts("");
	system("pause");
	return 0;
}