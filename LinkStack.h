#pragma once
#ifndef LINKSTACK_H
#define LINKSTACK_H

template <typename T>
struct LinkStackNode
{
	T data;
	LinkStackNode<T>* next;
};

template <typename T>
class LinkStack
{
public:
	LinkStack();
	~LinkStack();

public:
	bool Push(const T& e);
	bool Pop(T& e);
	bool GetTop(T& e);

	void DisplayList();
	int ListLength();
	bool Empty();

private:
	LinkStackNode<T>* m_top;
	int m_length;
};

#endif // !LINKSTACK_H

/**
* 
*/
template <typename T>
LinkStack<T>::LinkStack()
{
	m_top = nullptr;
	m_length = 0;
}

/**
* 链表栈
*/
template <typename T>
LinkStack<T>::~LinkStack()
{
	T temp;
	while (Pop(temp) == true)
	{

	}
}

/**
* 链表栈 入栈
* 时间复杂度 O(1)
*/
template <typename T>
bool LinkStack<T>::Push(const T& e)
{
	LinkStackNode<T>* node = new LinkStackNode<T>;
	node->data = e;
	node->next = m_top;
	m_top = node;
	m_length++;
	return true;
}

/**
* 链表栈 出栈
* 时间复杂度 O(1)
*/
template <typename T>
bool LinkStack<T>::Pop(T& e)
{
	if (Empty() == true)
	{
		return false;
	}
	LinkStackNode<T>* del_node = m_top;
	m_top = m_top->next;
	m_length--;
	e = del_node->data;
	delete del_node;
	return true;
}

/**
* 链表栈 读取栈顶元素
* 时间复杂度 O(1)
*/
template <typename T>
bool LinkStack<T>::GetTop(T& e)
{
	if (Empty() == true)
	{
		return false;
	}
	e = m_top->data;
	return true;
}

/**
* 输出链式栈中的所有元素
* 时间复杂度 O(n)
*/
template <typename T>
void LinkStack<T>::DisplayList()
{
	if (Empty() == true)
	{
		return;
	}
	LinkStackNode<T>* node = m_top;
	while (node != nullptr)
	{
		std::cout << node->data << std::endl;
		node = node->next;
	}
	std::cout << std::endl;
}

/**
* 获取链式栈的长度
* 时间复杂度 O(1)
*/
template <typename T>
int LinkStack<T>::ListLength()
{
	return m_length;
}

/**
* 判断链式栈是否为空
* 时间复杂度 O(1)
*/
template <typename T>
bool LinkStack<T>::Empty()
{
	if (m_top == nullptr)
	{
		return true;
	}
	return false;
}