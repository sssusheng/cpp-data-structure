#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H

template <typename T>
struct Node
{
	T data;
	Node<T>* next;
};


template <typename T>
class LinkList
{

public:
	LinkList();
	~LinkList();

public:
	bool ListInsert(int i, const T &e);
	bool ListDelete(int i);
	bool GetElem(int i, T& e);
	int LocateElem(const T& e);
	void DisplayList();
	int ListLength();
	bool Empty();
	void ReverseList();

private:
	Node<T>* m_head;
	int m_length;

};

#endif // LINKLIST_H


#include <iostream>


template <typename T>
LinkList<T>::LinkList()
{
	m_head = new Node<T>;
	m_head->next = nullptr;
	m_length = 0;
}

/**
* 释放单链表
* 时间复杂度 O(n)
*/
template <typename T>
LinkList<T>::~LinkList()
{
	Node<T>* curr_node = m_head->next;
	Node<T>* temp_node;
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
bool LinkList<T>::ListInsert(int i, const T& e)
{
	if (i < 1 || i >(m_length + 1))
	{
		std::cout << "insert i is illegal" << std::endl;
		return false;
	}

	Node<T>* curr_node = m_head;
	for (int j = 0; j < (i - 1); ++j)
	{
		curr_node = curr_node->next;
	}
	Node<T> *node = new Node<T>;
	node->data = e;
	node->next = curr_node->next;
	curr_node->next = node;
	
	m_length++;
	std::cout << "insert success" << std::endl;
	return true;
}

/**
* 删除第 i 个位置元素
* 时间复杂度 O(n)
*/
template <typename T>
bool LinkList<T>::ListDelete(int i)
{
	if (m_length < 1)
	{
		std::cout << "list is empty, error" << std::endl;
		return false;
	}

	if (i < 1 || i > m_length)
	{
		std::cout << "delete i is illegal" << std::endl;
		return false;
	}

	Node<T>* curr_node = m_head;
	for (int j = 0; j < (i - 1); ++j)
	{
		curr_node = curr_node->next;
	}
	Node<T>* del_node = curr_node->next;
	curr_node->next = del_node->next;
	m_length--;
	std::cout << "delete success" << std::endl;
	return true;
}

/**
* 获取第 i 个位置元素
* 时间复杂度 O(n)
*/
template <typename T>
bool LinkList<T>::GetElem(int i, T& e)
{
	if (m_length < 1)
	{
		std::cout << "list is empty, error" << std::endl;
		return false;
	}

	if (i < 1 || i > m_length)
	{
		std::cout << "getelem i is illegal" << std::endl;
		return false;
	}

	Node<T>* curr_node = m_head;
	for (int j = 0; j < i; ++j)
	{
		curr_node = curr_node->next;
	}
	e = curr_node->data;
	std::cout << "get success:" << i << " " << e << std::endl;
	return true;
}

/**
* 寻找第一个值为 e 的元素位置
* 时间复杂度 O(n)
*/
template <typename T>
int LinkList<T>::LocateElem(const T& e)
{
	Node<T>* curr_node = m_head;
	for (int i = 1; i <= m_length; ++i)
	{
		if (curr_node->next->data == e)
		{
			std::cout << "locate success" << std::endl;
			return i;
		}
		curr_node = curr_node->next;
	}
	std::cout << "no e, locate error" << std::endl;
	return -1;
}

/**
* 输出单链表所有元素
* 时间复杂度 O(n)
*/
template <typename T>
void LinkList<T>::DisplayList()
{
	Node<T>* curr_node = m_head->next;
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
int LinkList<T>::ListLength()
{
	return m_length;
}

/**
* 判断单链表是否为空
* 时间复杂度 O(n)
*/
template <typename T>
bool LinkList<T>::Empty()
{
	if (m_head != nullptr)
	{
		return true;
	}
	return false;
}

/**
* 翻转单链表
* 时间复杂度 O(n)
*/
template <typename T>
void LinkList<T>::ReverseList()
{
	if (m_length <= 1)
	{
		return;
	}

	Node<T>* curr_node = m_head->next->next;
	m_head->next->next = nullptr;

	Node<T>* temp_node;
	while (curr_node != nullptr)
	{
		temp_node = curr_node;
		curr_node = curr_node->next;
		
		temp_node->next = m_head->next;
		m_head->next = temp_node;
	}
}
