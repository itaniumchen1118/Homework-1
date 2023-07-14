#include "LinkedList.h"

void LinkedList::addAfter(Node* node, const ItemType& val)
{
	Node* p = new Node{ val, nullptr };
	node->next = p;
}

LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::LinkedList(const LinkedList& rhs)
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
	if (head != nullptr && i < size()) {
		Node* p = head;
		for (int j = 1; j <= i; j++)
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
		p = p->next;
	}
	for (Node* q = other.head; q != nullptr; q = q->next) {
		addAfter(p, q->value);
		p = p->next;
	}
	head = root.next;
}

void LinkedList::swap(LinkedList& other)
{
	Node* temp = this->head;
	this->head = other.head;
	other.head = temp;
	temp = nullptr;
}

int LinkedList::size() const
{
	int n = 0;
	Node* p = head;
	while (p != nullptr)
	{
		n++;
		p = p->next;
	}
	return n;
}