#include <iostream>
using namespace std;

//template<typename T>
//class TStack
//{
//	T* data;
//	int count;
//	int StackSize;
//
//public:
//	TStack() : count(0), StackSize(2)
//	{
//		data = new T[2];
//	}
//	~TStack()
//	{
//		if (data != nullptr)
//		{
//			delete data;
//		}
//	}
//
//	void push(T n)
//	{
//		if (count <= StackSize)
//		{
//			StackSize *= 2;
//			T* temp = new T[StackSize];
//			memcpy(temp, data, StackSize * sizeof(data));
//
//			delete data;
//
//			data = temp;
//		}
//
//		data[count++] = n;
//	}
//	T pop()
//	{
//		T retval = top();
//		if (count > 0) --count;
//
//		return retval;
//	}
//	int size()
//	{
//		return count;
//	}
//	bool empty()
//	{
//		if (count > 0) return false;
//		else return true;
//	}
//	T top()
//	{
//		if (count > 0)
//		{
//			return data[count - 1];
//		}
//		else return -1;
//	}
//};

int _data[10000];
int _index = -1;
int _size = 10000;

void push(int n)
{
	_data[++_index] = n;
}

int top()
{
	if (_index < 0)return -1;
	else return _data[_index];
}

int pop()
{
	int retval = top();
	if(retval != -1)--_index;

	return retval;
}

int size()
{
	return _index + 1;
}

bool empty()
{
	return _index < 0;
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		string command;
		int number;
		cin >> command;

		if (command == "push")
		{
			cin >> number;
			push(number);
		}
		
		else if (command == "top")
		{
			cout << top() << endl;
		}
		
		else if (command == "size")
		{
			cout << size() << endl;
		}
		
		else if (command == "empty")
		{
			cout << empty() << endl;
		}

		else if (command == "pop")
		{
			cout << pop() << endl;
		}
	}

	return 0;
}