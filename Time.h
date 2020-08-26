#include<iostream>
using namespace std;

class Time {
private:
	int hour, minute, second;
	void _hour();
	void _minute();
	
public:
	Time() { hour = 0, minute = 0, second = 0; }
	Time(int h, int m, int s);
	void print_12h();
	void print_24h();
	void set_hour(int);
	void set_minute(int);
	void set_second(int);
	int get_hour() const { return hour; }
	int get_minute() const { return minute; }
	int get_second() const { return second; }
	void incsecond();
	void Input();
};
