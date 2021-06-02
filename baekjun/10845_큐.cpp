#include <iostream>
using namespace std;
#define MAX 10000
#include <string>

int front_ = -1;
int rear_ = -1;
int q[MAX];
const int q_size = MAX;

void push(int n)
{

	if (rear_ + 1 < q_size)
	{
		q[++rear_] = n;
	}

}

bool IsEmpty()
{
	return rear_ == front_;
}

int pop()
{
	if (!IsEmpty())
	{
		return q[++front_];
	}

	else
	{
		return -1;
	}
}

int size()
{
	return abs(rear_ - front_);
}


int front()
{
	if (!IsEmpty())
	{
		return q[front_ + 1];
	}
	else
	{
		return -1;
	}
}

int back()
{
	if (!IsEmpty())
	{
		return q[rear_];
	}
	else
	{
		return -1;
	}
}


int main()
{

	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; ++i)
	{
		string command;
		cin >> command;

		if (command == "push")
		{
			int a;
			cin >> a;
			push(a);
		}

		else if (command == "front")
		{
			cout << front() << endl;
		}

		else if (command == "back")
		{
			cout << back() << endl;
		}

		else if (command == "size")
		{
			cout << size() << endl;
		}

		else if (command == "empty")
		{
			cout << IsEmpty() << endl;
		}

		else if (command == "pop")
		{
			cout << pop() << endl;
		}
	}
}