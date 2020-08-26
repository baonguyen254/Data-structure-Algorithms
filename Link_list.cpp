#include "Link_list.h"

using namespace std;

void List::Insert_First(Item a)
{
	Link* new_node = new Link(a,NULL);
	if (last == NULL)
	{
		last = new_node;
	}
	else {
		new_node->next = last;
		last = new_node;   // Đổi last hiện tại là new_node
	}
	
}

void List::Append(Item a)
{
	Link *new_node = new Link(a, NULL);
	if (last == NULL)
	{
		last = new_node;
	}
	else {
		Link *current = last;
		while (current->next != NULL) {
			current = current->next; // Duyệt đến cuối danh sách
		}
		current->next = new_node;	
	}
}

Item List::GetFirst()
{
	Item x;
	Link *current;
	if (!IsEmpty())
	{
		current = last;
		x = last->data;
		last = last->next;
		delete(current);
	}

	return Item(x);
}
int List::Count() const
{
	Link *temp = last;
	int count = 0;
	while (temp->next != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}
void List::Print() const
{
	if (last == NULL)
		cout << "List Empty" << endl;
	else {
		Link *current = last;
		while (current != NULL)
		{
			cout << current->data;
			cout << "  ";
			current = current->next;
		}
	}

}
//int main() {
//	List s;
//	for (int i = 0; i < 5; i++)
//	{
//		s.Append(i);
//		s.Insert_First(i);
//	}
//	s.Append(6);
//	s.Insert_First(5);
//	s.Print();
//	cout << "length of list now: " << s.Count() << endl;
//	puts("");
//	for (int i = 0; i < 5; i++) {
//		cout << "poped "<<s.GetFirst() << endl;
//		cout << " ";
//	}
//	cout << "length of list now: " << s.Count() << endl;
//
//	system("pause");
//	return 0;
//}
