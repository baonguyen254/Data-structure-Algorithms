#include"Time.h"
void Time::Input() {
	int h, min, sec;
	cout << "Input hour, minute, second" << endl;
	cout << "hour :";
	cin >> h; set_hour(h);
	cout << "minute :";
	cin >> min; set_minute(min);
	cout << "second :";
	cin >> sec; set_second(second);

}
Time::Time(int h, int m, int s) {
	set_hour(h);
	set_minute(m);
	set_second(s);
}
void Time::_hour() {
	++hour;
	if (hour == 24) hour = 0;
}
void Time::_minute() {
	++minute;
	if (minute == 60) {
		minute = 0;
		_hour();
	}
}
void Time::incsecond() {
	++second;
	if (second == 60) {
		second = 0;
		_minute();
	}
}

void Time::set_hour(int h) {
	if (h >= 0 && h < 24)
		hour = h;
	else if (h == 24)
		hour = 0;
	else
		cout << "error!! hour: [0,23] " << endl;
}
void Time::set_minute(int m) {
	if (m >= 0 && m < 60)
		minute = m;
	else if (m == 60)
	{
		minute = 0;
		_hour();
	}
	else
		cout << "error!! minute: [0,59] " << endl;
}
void Time::set_second(int s) {
	if (s >= 0 && s < 60)
		second = s;
	else if (s == 60)
	{
		second = 0;
		_minute();
	}
	else
		cout << "error!! second: [0,59] " << endl;
}
void Time::print_12h() {
	int h;
	if (hour > 12)
		h = hour - 12;
	else
		h = hour;
	cout << (h < 10 ? "0" : "") << h << ":" << (minute < 10 ? "0" : "") << minute << ":";
	cout << (second < 10 ? "0" : "") << second << (hour < 12 ? "AM" : "PM") << endl;
}
void Time::print_24h() {
	cout << (hour < 10 ? "0" : "") << hour << ":" << (minute < 10 ? "0" : "") << minute << ":";
	cout << (second < 10 ? "0" : "") << second << endl;
}
int main() {
	Time tg;
	tg.Input();
	tg.print_12h();
	tg.print_24h();
	puts("");
	Time t(12, 59, 58);
	t.print_12h();
	t.print_24h();
	for (int i = 1; i < 5; i++)
	{
		t.incsecond();
		t.print_12h();
		t.print_24h();
	}
	puts("");
	Time t1(12,59,58);
	t1.set_second(60);
	t1.print_12h();
	t1.print_24h();
	
	system("pause");
	return 0;
}