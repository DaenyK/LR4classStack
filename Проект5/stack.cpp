#include "Stack.h"

template<typename type>
Stack<type>::Stack()
{
	els = nullptr;
	length = 0;
	buf_size = 0;
}

template<typename type>
Stack<type>::Stack(type * arr, int n)
{
	this->length = n;
	this->els = new type[length];
	this->buf_size = length;
	for (int i = 0; i < length; i++)
		this->els[i] = arr[i];
}

template<typename type>
Stack<type>::Stack(const Stack<type> & obj)
{
	this->length = obj.length;
	this->buf_size = obj.length;
	this->els = new type[length];
	for (int i = 0; i < length; i++)
		this->els[i] = obj.els[i];
}

template<typename type>
Stack<type>::~Stack()
{
	delete[]els;
}

template<typename type>
type & Stack<type>::top() 
{
	return els[length - 1];
}

template<typename type>
void Stack<type>::push(type e)
{
	if (buf_size == 0)
	{
		buf_size = 2;
		els = new type[buf_size];
	}

	else if (buf_size <= length)
	{
		buf_size *= 2;
		type * temp = new type[buf_size];
		for (int i = 0; i < length; i++)
			temp[i] = els[i];
		delete[] els;
		els = temp;
	}
	els[length++] = e;
}

template<typename type>
void Stack<type>::pop()
{
	length--;
}

template<typename type>
size_t Stack<type>::size()
{
	return size_t(length);
}

template<typename type>
bool Stack<type>::empty()
{
	return (size() == 0);
}

template<typename type>
void Stack<type>::operator[](type e)
{
	if (buf_size == 0)
	{
		buf_size = 2;
		els = new type[buf_size];
	}
	else if (buf_size <= length)
	{
		buf_size *= 2;
		type * temp = new type[buf_size];
		for (int i = 0; i < length; i++)
		{
			temp[i] = els[i];
		}
		delete[] els;
		els = temp;
	}
	els[length++] = e;
}

template<typename type>
void Stack<type>::operator=(type e)
{
	els = e;
}