#include "LinkedList.h"

#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

void LinkedList::addAfter(Node* node, const ItemType& val)
{
	Node* p = new Node{ val, nullptr };
	node->next = p;
}

LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::LinkedList(const LinkedList& rhs) : head(rhs.head), count(rhs.count)
{
	if (rhs.head != nullptr)
	{
		head = new Node{ rhs.head->value, nullptr };

		Node* p = rhs.head->next; //iterator
		Node* curr = head;
		while (p != nullptr)
		{
			curr->next = new Node{ p->value, nullptr };

			curr = curr->next;
			p = p->next;
		}
	}
}

//given in class
LinkedList::~LinkedList()
{
	Node* p = head;
	while (p != nullptr)
	{
		Node* q = p->next;
		delete p;
		p = q;
	}
}

const LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
	if (this != &rhs)
	{
		LinkedList temp(rhs);
		swap(temp);
	}

	return *this;
}

//given in class
void LinkedList::insertToFront(const ItemType& val)
{
	Node* p = new Node{ val, head };
	head = p;
	++count;
}

void LinkedList::printList() const
{
	for (Node* p = head; p != nullptr; p = p->next)
	{
		cout << p->value << " ";
	}
	cout << endl;
}

bool LinkedList::get(int i, ItemType& item) const
{
	if (i < size()) {
		Node* p = head;
		while (i-- > 0)
		{
			p = p->next;
		}
		item = p->value;
		return true;
	}
	else {
		return false;
	}
}

void LinkedList::reverseList()
{
	if (size() > 1) {
		Node* prev = nullptr;
		Node* next = head->next;
		while (head->next != nullptr) {
			head->next = prev;
			prev = head;
			head = next;
			next = head->next;
		}
		head->next = prev;
	}
}

void LinkedList::printReverse() const
{
	std::string s = "";
	for (Node* p = head; p != nullptr; p = p->next) {
		s = p->value + " " + s;
	}
	cout << s << endl;
}

void LinkedList::append(const LinkedList& other)
{
	Node root;
	root.next = head;
	Node* p = &root;
	while (p->next != nullptr) {
		// go to the end of the list
		p = p->next;
	}
	for (Node* q = other.head; q != nullptr; q = q->next) {
		// create a new node with the value in the other list
		Node* newNode = new Node{ q->value, nullptr };
		p->next = newNode;
		p = newNode;
	}

	head = root.next;
	count += other.count;
}

void LinkedList::swap(LinkedList& other)
{
	Node* tempNode = head;
	head = other.head;
	other.head = tempNode;


	int tempCount = count;
	count = other.count;
	other.count = tempCount;
}

int LinkedList::size() const
{
	return count;
}