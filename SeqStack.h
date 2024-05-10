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
* ˳��ջ������� ��ջ
* �������ʱ�临�Ӷ� O(1) ջ������������� ʱ�临�Ӷ� O(n)
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
* ˳��ջɾ������ ��ջ
* ʱ�临�Ӷ� O(1)
*/
template <typename T>
bool SeqStack<T>::Pop(T& e)
{
	if (Empty() == true)
	{
		std::cout << "��ǰ˳��ջΪ�գ����ܽ��г�ջ����!" << std::endl;
		return false;
	}

	e = m_data[m_top];
	m_top--;
	return true;
}

/**
* ��ȡջ��Ԫ�� �����ڳ�ջ
* ʱ�临�Ӷ� O(1)
*/
template <typename T>
bool SeqStack<T>::GetTop(T& e)
{
	if (Empty() == true)
	{
		std::cout << "��ǰ˳��ջΪ�գ����ܶ�ȡջ��Ԫ��!" << std::endl;
		return false;
	}

	e = m_data[m_top];
	return true;
}

/**
* ���˳��ջ������Ԫ��
* ʱ�临�Ӷ� O(n)
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
* ��ȡ˳��ջ�ĳ���
* ʱ�临�Ӷ� O(1)
*/
template <typename T>
int SeqStack<T>::ListLength()
{
	return m_top + 1;
}

/**
* �ж�˳��ջ�Ƿ�Ϊ��
* ʱ�临�Ӷ�ΪO(1)
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
* �ж�˳��ջ�Ƿ�����
* ʱ�临�Ӷ�ΪO(1)
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
* ˳��ջ����
* ʱ�临�Ӷ� O(n)
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
