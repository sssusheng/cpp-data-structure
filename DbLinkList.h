#pragma once
#ifndef DBLINKLIST_H
#define DBLINKLIST_H

template <typename T>
struct DbNode
{
	T data;
	DbNode<T> *prior;
	DbNode<T> *next;
};

template <typename T>
class DbLinkList
{
public:
	DbLinkList();
	~DbLinkList();

public:
	bool ListInsert(int i, const T& e);
	bool ListDelete(int i);
	bool GetElem(int i, T& e);
	int LocateElem(const T& e);
	void DisplayList();
	int ListLength();
	bool Empty();
	void ReverseList();

private:
	DbNode<T>* m_head;
	int m_length;
};

#endif // !DBLINKLIST_H


#include <iostream>

template <typename T>
DbLinkList<T>::DbLinkList()
{
	m_head = new DbNode<T>;
	m_head->prior = nullptr;
	m_head->next = nullptr;
	m_length = 0;
}

template <typename T>
DbLinkList<T>::~DbLinkList()
{
	DbNode<T>* curr_node = m_head->next;
	DbNode<T>* temp_node;
	while (curr_node != nullptr)
	{
		temp_node = curr_node;
		curr_node = curr_node->next;
		delete temp_node;
	}
	delete m_head;
	m_head = nullptr;
	m_length = 0;
}

/**
* 向第 i 个位置插入元素 e
* 时间复杂度 O(n)
*/
template <typename T>
bool DbLinkList<T>::ListInsert(int i, const T& e)
{
	if (i < 1 || i >(m_length + 1))
	{
		std::cout << "元素" << e << "插入的位置" << i << "不合法，合法的位置是1到" << m_length + 1 << "之间!" << std::endl;
		return false;
	}

	DbNode<T>* curr_node = m_head;
	for (int j = 0; j < (i - 1); ++j)
	{
		curr_node = curr_node->next;
	}
	DbNode<T>* node = new DbNode<T>;
	node->data = e;
	node->next = curr_node->next;
	node->prior = curr_node;
	if (curr_node->next != nullptr)
	{
		curr_node->next->prior = node;
	}
	curr_node->next = node;
	m_length++;
	std::cout << "成功在位置为" << i << "处插入元素" << e << "!" << std::endl;
	return true;
}

/**
* 删除第 i 个位置元素
* 时间复杂度 O(n)
*/
template <typename T>
bool DbLinkList<T>::ListDelete(int i)
{
	if (m_length < 1)
	{
		std::cout << "当前双链表为空，不能删除任何数据!" << std::endl;
		return false;
	}
	if (i < 1 || i > m_length)
	{
		std::cout << "删除的位置" << i << "不合法，合法的位置是1到" << m_length << "之间!" << std::endl;
		return false;
	}

	DbNode<T>* curr_node = m_head;
	for (int j = 0; j < (i - 1); ++j)
	{
		curr_node = curr_node->next;
	}
	DbNode<T>* del_node = curr_node->next;
	DbNode<T>* del_next_node = del_node->next;
	curr_node->next = del_node->next;
	if (del_next_node != nullptr)
	{
		del_next_node->prior = curr_node;
	}
	std::cout << "成功删除位置为" << i << "的元素，该元素的值为" << del_node->data << "!" << std::endl;
	m_length--;
	delete del_node;
	return true;
}

/**
* 获取第 i 个位置元素
* 时间复杂度 O(n)
*/
template <typename T>
bool DbLinkList<T>::GetElem(int i, T& e)
{
	if (m_length < 1)
	{
		std::cout << "当前双链表为空，不能获取任何数据!" << std::endl;
		return false;
	}

	if (i < 1 || i > m_length)
	{
		std::cout << "获取元素的位置" << i << "不合法，合法的位置是1到" << m_length << "之间!" << std::endl;
		return false;
	}

	DbNode<T>* curr_node = m_head;
	for (int j = 0; j < i; ++j)
	{
		curr_node = curr_node->next;
	}
	e = curr_node->data;
	std::cout << "成功获取位置为" << i << "的元素，该元素的值为" << e << "!" << std::endl;
	return true;
}

/**
* 寻找第一个值为 e 的元素位置
* 时间复杂度 O(n)
*/
template <typename T>
int DbLinkList<T>::LocateElem(const T& e)
{
	DbNode<T>* curr_node = m_head;
	for (int i = 1; i <= m_length; ++i)
	{
		if (curr_node->next->data == e)
		{
			std::cout << "值为" << e << "的元素在双链表中第一次出现的位置为" << i << "!" << std::endl;
			return i;
		}
		curr_node = curr_node->next;
	}
	std::cout << "值为" << e << "的元素在双链表中没有找到!" << std::endl;
	return -1;
}

/**
* 输出双链表所有元素
* 时间复杂度 O(n)
*/
template <typename T>
void DbLinkList<T>::DisplayList()
{
	DbNode<T>* curr_node = m_head->next;
	while (curr_node != nullptr)
	{
		std::cout << curr_node->data << " ";
		curr_node = curr_node->next;
	}
	std::cout << std::endl;
}

/**
* 获取单链表的长度
* 时间复杂度 O(1)
*/
template <typename T>
int DbLinkList<T>::ListLength()
{
	return m_length;
}

/**
* 判断双链表是否为空
* 时间复杂度 O(1)
*/
template <typename T>
bool DbLinkList<T>::Empty()
{
	if (m_head->next == nullptr)
	{
		return true;
	}
	return false;
}

/**
* 翻转双链表
* 时间复杂度 O(n)
*/
template <typename T>
void DbLinkList<T>::ReverseList()
{
	if (m_length <= 1)
	{
		return;
	}

	DbNode<T>* curr_node = m_head->next->next;
	m_head->next->next = nullptr;

	DbNode<T>* temp_node;
	while (curr_node != nullptr)
	{
		temp_node = curr_node;
		curr_node = curr_node->next;

		temp_node->prior = m_head;
		temp_node->next = m_head->next;
		m_head->next->prior = temp_node;
		m_head->next = temp_node;
	}
}