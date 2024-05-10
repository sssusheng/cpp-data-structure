#pragma once
#ifndef SEQSTACK_H
#define SEQSTACK_H

#define InitSize 10
#define IncSize 5

template <typename T>
class SeqStack
{
public:
	SeqStack(int length = InitSize);
	~SeqStack();

public:
	bool Push(const T& e);
	bool Pop(T& e);
	bool GetTop(T& e);
	void DisPlayList();
	int ListLength();
	bool Empty();
	bool Full();

private:
	void IncreaseSize();

private:
	T* m_data;
	int m_maxSize;
	int m_top;
};

#endif // SEQSTACK_H

template <typename T>
SeqStack<T>::SeqStack(int length)
{
	m_data = new T[length];
	m_maxSize = length;
	m_top = -1;
}

template <typename T>
SeqStack<T>::~SeqStack()
{
	delete[] m_data;
}

/**
* 顺序栈添加数据 入栈
* 正常添加时间复杂度 O(1) 栈满了扩容再添加 时间复杂度 O(n)
*/
template <typename T>
bool SeqStack<T>::Push(const T& e)
{
	if (Full() == true)
	{
		IncreaseSize();
	}
	m_top++;
	m_data[m_top] = e;
	return true;
}

/**
* 顺序栈删除数据 出栈
* 时间复杂度 O(1)
*/
template <typename T>
bool SeqStack<T>::Pop(T& e)
{
	if (Empty() == true)
	{
		std::cout << "当前顺序栈为空，不能进行出栈操作!" << std::endl;
		return false;
	}

	e = m_data[m_top];
	m_top--;
	return true;
}

/**
* 读取栈顶元素 类似于出栈
* 时间复杂度 O(1)
*/
template <typename T>
bool SeqStack<T>::GetTop(T& e)
{
	if (Empty() == true)
	{
		std::cout << "当前顺序栈为空，不能读取栈顶元素!" << std::endl;
		return false;
	}

	e = m_data[m_top];
	return true;
}

/**
* 输出顺序栈的所有元素
* 时间复杂度 O(n)
*/
template <typename T>
void SeqStack<T>::DisPlayList()
{
	for (int i = m_top; i >= 0; --i)
	{
		std::cout << m_data[i] << " ";
	}
	std::cout << std::endl;
}

/**
* 获取顺序栈的长度
* 时间复杂度 O(1)
*/
template <typename T>
int SeqStack<T>::ListLength()
{
	return m_top + 1;
}

/**
* 判断顺序栈是否为空
* 时间复杂度为O(1)
*/
template <typename T>
bool SeqStack<T>::Empty()
{
	if (m_top == -1)
	{
		return true;
	}
	return false;
}

/**
* 判断顺序栈是否已满
* 时间复杂度为O(1)
*/
template <typename T>
bool SeqStack<T>::Full() 
{
	if (m_top >= m_maxSize - 1)
	{
		return true;
	}
	return false;
}

/**
* 顺序栈扩容
* 时间复杂度 O(n)
*/
template <typename T>
void SeqStack<T>::IncreaseSize()
{
	T* p = m_data;
	m_data = new T[m_maxSize + IncSize];
	for (int i = 0; i < m_top; i++)
	{
		m_data[i] = p[i];
	}
	m_maxSize = m_maxSize + IncSize;
	delete[] p;
}
