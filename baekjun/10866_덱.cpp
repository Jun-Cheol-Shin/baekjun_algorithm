#include <iostream>
using namespace std;
#include <deque>

struct Node
{
	int data;
	Node* next;
};
class Deque
{
	int _currentDeckSize;
	Node* _head;
	Node* _tail;

public:
	Deque() : _head(nullptr), _tail(nullptr), _currentDeckSize(0)
	{

	}
	~Deque()
	{
		Node* d;

		while(_head)
		{ 
			d = _head;
			delete d;

			_head = _head->next;
		}
	}

	void push_front(int n)
	{
		Node* newNode = new Node();
		newNode->data = n;
		newNode->next = nullptr;

		if (_head)
		{
			newNode->next = _head;
			_head = newNode;
		}
		else
		{
			_head = _tail = newNode;
		}

		++_currentDeckSize;
	}
	void push_back(int n)
	{
		Node* newNode = new Node();
		newNode->data = n;
		newNode->next = nullptr;

		if (_tail)
		{
			_tail->next = newNode;
			_tail = newNode;
		}

		else
		{
			_head = _tail = newNode;
		}

		++_currentDeckSize;
	}
	int pop_front()
	{
		if (isEmpty()) return -1;

		--_currentDeckSize;
		Node* deleteNode = _head;

		if (_head->next == nullptr)
		{
			int retval = _head->data;
			_tail = _head = nullptr;

			delete deleteNode;

			return retval;
		}

		else
		{
			int retval = _head->data;
			_head = _head->next;

			delete deleteNode;

			return retval;
		}
	}
	int pop_back()
	{
		if (isEmpty())  return -1;

		--_currentDeckSize;
		Node* deleteNode = _tail;
		Node* prevNode = _head;


		while (prevNode->next && prevNode->next != _tail)
		{
			prevNode = prevNode->next;
		}

		int retval = _tail->data;
		delete deleteNode;

		if (_head->next == nullptr)
		{
			_tail = _head = nullptr;
		}

		else if(prevNode == _head)
		{
			_tail = _head = prevNode;
			_head->next = nullptr;
		}

		else
		{
			_tail = prevNode;
		}

		return retval;
	}
	int size()
	{
		return _currentDeckSize;
	}
	bool isEmpty()
	{
		return _currentDeckSize == 0;
	}
	int front()
	{
		return _head ? _head->data : -1;
	}
	int back()
	{
		return _tail ? _tail->data : -1;
	}
};

int main()
{

	deque<int> d;
	int n;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string command;
		cin >> command;

		if (command == "push_back")
		{
			int n;
			cin >> n;

			d.push_back(n);
		}

		else if (command == "push_front")
		{
			int n;
			cin >> n;

			d.push_front(n);
		}

		else if (command == "pop_front")
		{
			int a = -1;

			if (d.size() > 0) 
			{
				a = d.front();
				d.pop_front();
			}
			cout << a << endl;
		}

		else if (command == "pop_back")
		{
			int a = -1;
			if (d.size() > 0)
			{
				a = d.back();
				d.pop_back();
			}
			cout << a << endl;
		}

		else if (command == "front")
		{
			if (d.size() > 0) cout << d.front() << endl;
			else cout << -1 << endl;
		}

		else if (command == "back")
		{
			if (d.size() > 0) cout << d.back() << endl;
			else cout << -1 << endl;
		}

		else if (command == "size")
		{
			cout << d.size() << endl;
		}

		else if (command == "empty")
		{
			cout << d.empty() << endl;
		}
	}

	return 0;
}