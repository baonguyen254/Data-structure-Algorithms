#pragma once
#include<iostream>
typedef int Item;

class Link {
	friend class List;
	Link *next;
	Item data;
	Link(Item d, Link *p) :data(d) { next = p; }
};

class List {
	Link *last;
public:
	List() { last = NULL; }
	List(Item a) { last = new Link(a, NULL); last->next = last; }
	~List() { CleanUp(); }
	void Insert_First(Item a);
	void Append(Item a);
	Item GetFirst();
	void CleanUp() { delete[]last; };
	bool IsEmpty() const { return last == NULL; }
	int Count() const;
	void Print() const;

	
};