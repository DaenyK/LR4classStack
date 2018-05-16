#include "Stack.h"
#include "Stack.cpp"

void main()
{
	setlocale(LC_ALL, "");

	int arr[5] = { 8, 3, 1, 4, 7 };
	Stack<int>s(arr, 3);
	s.push(88);
	s.push(99);

	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}

	system("pause");
}