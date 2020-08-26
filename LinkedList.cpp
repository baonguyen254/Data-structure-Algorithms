#include<stdio.h>
#include<stdlib.h>
#include <iostream>
struct Node {
	int data;
	struct Node *next;
};
struct linkedlist {
	struct Node *first;
};
void Print(struct linkedlist list)
{
	struct Node *current = list.first;
	while (current != NULL)
	{
		printf("%3d", current->data);
		current = current->next;
	}
	printf("\n");
}
int search(struct linkedlist list, int value)
{
	struct Node *current = list.first;
	int count = 0;
	while (current != NULL)
	{
		if (current->data == value)
		{
			return count;
			break;
		}
		else
		{
			current = current->next;
			count++;
		}
	}
	return -1;
}
void Read(struct linkedlist list, int index)
{
	struct Node *current = list.first;
	int count = 0;
	while (current != NULL)
	{
		//printf("%d\n", current->data);

		if (count == index)
		{
			printf("%d\n", current->data);
			break;
		}
		current = current->next;
		count++;
	}

}

void insert(struct linkedlist *list, int value)
{
	struct Node *node = (struct Node *) malloc(sizeof(struct Node));
	node->data = value;
	node->next = NULL;
	if (list->first == NULL) //empty
	{
		list->first = node;
	}
	else // not empty
	{
		node->next = list->first;
		list->first = node;
	}
}
void Insert_index(struct linkedlist *list, int value, int index)
{
	struct Node *node = (struct Node *) malloc(sizeof(struct Node));
	node->data = value;
	node->next = NULL;
	struct Node *current = list->first;
	int count = 0;
	if (index == 0)
		insert(list, value);
	else
		if (index < 0)
			return;
		else
		{
			while (current != NULL)
			{
				if (count == index - 1)
				{
					node->next = current->next;
					current->next = node;
					break;
				}
				current = current->next;
				count++;
			}
		}
}
void Deletehead(struct linkedlist *list)
{
	if (list->first == NULL)
	{
		printf("Nothing to delete");
		return;
	}
	else
	{
		struct Node *next = list->first->next;
		free(list->first);
		list->first = next;
	}
}
void Delete(struct linkedlist *list, int index)
{
	struct Node *current = list->first;
	int count = 0;
	if (index == 0)
	{
		Deletehead(list);
	}
	else
	{
		while (current != NULL)
		{
			if (count == index - 1)
			{
				struct Node *next = current->next->next;
				free(current->next);
				current->next = next;
			}
			current = current->next;
			count++;
		}
	}
}
void Deletevalue(struct linkedlist *list, int value)
{
	struct Node *current = list->first;
	int index = search(*list, value);
	if (index != -1)
	{
		Delete(list, index);
	}

}
int main()
{
	struct linkedlist list;
	list.first = NULL;
	insert(&list, 3);
	insert(&list, 2);
	insert(&list, 0);
	Insert_index(&list, 1, 1);
	Deletehead(&list);
	Delete(&list, 2);
	Deletevalue(&list, 2);
	Print(list);
	Read(list, 2);
	int value = 1;
	printf("index of %d in list: %d\n", value, search(list, value));

	return 0;
}
