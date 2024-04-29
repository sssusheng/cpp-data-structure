#pragma once
#ifndef SEQLIST_H
#define SEQLIST_H

#define InitSize 10
#define IncSize 5

template <typename T>
class SeqList
{

public:
	SeqList(int length = InitSize);
	~SeqList();

public:
	bool ListInsert(int i, const T& e);
	bool ListDelete(int i);
	bool GetElem(int i, T& e);
	int LocateElem(const T& e);

	void DisplayList();
	int ListLength();
	void ReverseList();

private:
	void IncreaseSize();

private:
	T* m_data;
	int m_length;
	int m_maxSize;

};

#endif // SEQLIST_H


#include <iostream>

template <typename T>
SeqList<T>::SeqList(int length)
{
	m_data = new T[length];
	m_length = 0;
	m_maxSize = length;
}

template <typename T>
SeqList<T>::~SeqList()
{
	delete[] m_data;
	m_length = 0;
}

/**
* ��� i ��λ�ò���Ԫ�أ����������� i
* ��˳��Ҫ������ʱ�临�Ӷ� O(n)
*/
template <typename T>
bool SeqList<T>::ListInsert(int i, const T& e)
{
	// 1. ˳������������ܲ���
	if (m_length >= m_maxSize)
	{
		std::cout << "list is full, no empty place, increase size." << std::endl;
		IncreaseSize();
	}

	// 2. �жϲ���λ�� i �Ƿ�Ϸ���˳���������������ܸ��ղ���
	if (i < 1 || i > m_length + 1)
	{
		std::cout << "i is illegal !" << std::endl;
		return false;
	}

	// 3. �����һ��Ԫ�ؿ�ʼ�������λ�� i �ƶ�����ÿ��Ԫ�ض������һλ����Ҫ�����Ԫ���ڳ�λ��
	for (int j = m_length; j >= i; --j)
	{
		m_data[j] = m_data[j - 1];
	}
	m_data[i - 1] = e;
	m_length++;
	std::cout << "insert success" << std::endl;
	return true;
}


/**
* ɾ���� i ��λ�õ�Ԫ��
* ʱ�临�Ӷ� O(n)
*/
template <typename T>
bool SeqList<T>::ListDelete(int i)
{
	// 1. ˳���Ϊ�գ�����ɾ��
	if (m_length < 1) {
		std::cout << "list is empty, can not delete" << std::endl;
		return false;
	}

	// 2. �ж�ɾ����λ���Ƿ���Ԫ��
	if (i < 1 || i > m_length)
	{
		std::cout << "i is illegal" << std::endl;
		return false;
	}

	// 3. �ӵ�i+1��λ�ÿ�ʼ��������ɾ��Ԫ�غ����Ԫ�ض���ǰ�ƶ�һ��λ��
	for (int j = i; j < m_length; ++j)
	{
		m_data[j - 1] = m_data[j];
	}
	m_length--;
	std::cout << "delete success" << std::endl;
	return true;
}


/**
* ��ȡ�� i ��λ�õ�Ԫ��
* ʱ�临�Ӷ� O(1)
*/
template <typename T>
bool SeqList<T>::GetElem(int i, T& e)
{
	// 1. �ж�˳����Ƿ�Ϊ��
	if (m_length < 1)
	{
		std::cout << "list is empty" << std::endl;
		return false;
	}

	// 2. �ж� i �Ƿ�Ϸ�
	if (i < 1 || i > m_length)
	{
		std::cout << "i is illegal" << std::endl;
		return false;
	}
	e = m_data[i - 1];
	std::cout << "the value of i is " << e << std::endl;
	return true;
}


/**
* ��Ԫ��ֵ��������˳����е�һ�γ��ֵ�λ��
* ʱ�临�Ӷ� O(n)
*/
template <typename T>
int SeqList<T>::LocateElem(const T& e)
{
	for (int i = 0; i < m_length; ++i)
	{
		if (m_data[i] == e)
		{
			std::cout << "find index " << i + 1 << std::endl;
			return i + 1;
		}
	}
	std::cout << "can not find" << std::endl;
	return -1;
}


/**
* ���˳��������Ԫ��
* ʱ�临�Ӷ� O(n)
*/
template <typename T>
void SeqList<T>::DisplayList()
{
	for (int i = 0; i < m_length; ++i)
	{
		std::cout << m_data[i] << "";
	}
	std::cout << std::endl;
}


/**
* ��ȡ˳���ĳ���
* ʱ�临�Ӷ� O(1)
*/
template <typename T>
int SeqList<T>::ListLength()
{
	return m_length;
}


/**
* ��ת˳���
* ʱ�临�Ӷ� O(n)
*/
template <typename T>
void SeqList<T>::ReverseList()
{
	// 1. ˳����� <= 1�����÷�ת
	if (m_length <= 1)
	{
		return;
	}

	// 2. ������Ϊ�ᣬ����λ��
	T temp;
	for (int i = 0; i < m_length / 2; ++i)
	{
		temp = m_data[i];
		m_data[i] = m_data[m_length - i - 1];
		m_data[m_length - i - 1] = temp;
	}
}


/**
* ˳�������
* ʱ�临�Ӷ� O(n)
*/
template <typename T>
void SeqList<T>::IncreaseSize()
{
	T* p = m_data;
	m_data = new T[m_maxSize + IncSize];
	for (int i = 0; i < m_length; i++)
	{
		m_data[i] = p[i];
	}
	m_maxSize = m_maxSize + IncSize;
	delete[] p;
}