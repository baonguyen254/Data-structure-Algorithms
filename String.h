
#pragma once
#include<string.h>
#pragma warning(disable:4996)
using namespace std;
inline char *_strdup(const char *s) {
	return strcpy(new char[strlen(s) + 1], s);
}
class String {
private:
	char *p;
public:
	String(const char *s = "NEW STRING") { p = _strdup(s); }
	String(const String &s) { p = _strdup(s.p); }
	~String() { if (p) delete p; }
	size_t GetLength() const { return strlen(p); }
	void set(const char *s);
	void Print() const;
	void Input();
	int compare(String s) const;
	void concat(const String &b);
	String UpCase() const;
	String LowCase() const;
	void reverse() const;

};
