#pragma once
#include "Link_list.h"
typedef int Item;

class Stack:private List {
public:
	Stack() :List(){}
	bool Push(Item x) { List::Insert_First(x); return true; }
	bool Pop(Item *px);
	bool IsEmpty() const { return List::IsEmpty(); }
};