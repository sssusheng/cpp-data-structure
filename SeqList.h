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
* 向第 i 个位置插入元素，而不是索引 i
* 有顺序要求，所以时间复杂度 O(n)
*/
template <typename T>
bool SeqList<T>::ListInsert(int i, const T& e)
{
	// 1. 顺序表已满，不能插入
	if (m_length >= m_maxSize)
	{
		std::cout << "list is full, no empty place, increase size." << std::endl;
		IncreaseSize();
	}

	// 2. 判断插入位置 i 是否合法，顺序表必须连续，不能隔空插入
	if (i < 1 || i > m_length + 1)
	{
		std::cout << "i is illegal !" << std::endl;
		return false;
	}

	// 3. 从最后一个元素开始，向插入位置 i 移动，把每个元素都向后移一位，给要插入的元素腾出位置
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
* 删除第 i 个位置的元素
* 时间复杂度 O(n)
*/
template <typename T>
bool SeqList<T>::ListDelete(int i)
{
	// 1. 顺序表为空，不能删除
	if (m_length < 1) {
		std::cout << "list is empty, can not delete" << std::endl;
		return false;
	}

	// 2. 判断删除的位置是否有元素
	if (i < 1 || i > m_length)
	{
		std::cout << "i is illegal" << std::endl;
		return false;
	}

	// 3. 从第i+1的位置开始遍历，把删除元素后面的元素都往前移动一个位置
	for (int j = i; j < m_length; ++j)
	{
		m_data[j - 1] = m_data[j];
	}
	m_length--;
	std::cout << "delete success" << std::endl;
	return true;
}


/**
* 获取第 i 个位置的元素
* 时间复杂度 O(1)
*/
template <typename T>
bool SeqList<T>::GetElem(int i, T& e)
{
	// 1. 判断顺序表是否为空
	if (m_length < 1)
	{
		std::cout << "list is empty" << std::endl;
		return false;
	}

	// 2. 判断 i 是否合法
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
* 按元素值查找其在顺序表中第一次出现的位置
* 时间复杂度 O(n)
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
* 输出顺序表的所有元素
* 时间复杂度 O(n)
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
* 获取顺序表的长度
* 时间复杂度 O(1)
*/
template <typename T>
int SeqList<T>::ListLength()
{
	return m_length;
}


/**
* 翻转顺序表
* 时间复杂度 O(n)
*/
template <typename T>
void SeqList<T>::ReverseList()
{
	// 1. 顺序表长度 <= 1，不用翻转
	if (m_length <= 1)
	{
		return;
	}

	// 2. 以中心为轴，交换位置
	T temp;
	for (int i = 0; i < m_length / 2; ++i)
	{
		temp = m_data[i];
		m_data[i] = m_data[m_length - i - 1];
		m_data[m_length - i - 1] = temp;
	}
}


/**
* 顺序表扩容
* 时间复杂度 O(n)
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