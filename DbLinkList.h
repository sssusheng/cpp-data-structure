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
* ��� i ��λ�ò���Ԫ�� e
* ʱ�临�Ӷ� O(n)
*/
template <typename T>
bool DbLinkList<T>::ListInsert(int i, const T& e)
{
	if (i < 1 || i >(m_length + 1))
	{
		std::cout << "Ԫ��" << e << "�����λ��" << i << "���Ϸ����Ϸ���λ����1��" << m_length + 1 << "֮��!" << std::endl;
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
	std::cout << "�ɹ���λ��Ϊ" << i << "������Ԫ��" << e << "!" << std::endl;
	return true;
}

/**
* ɾ���� i ��λ��Ԫ��
* ʱ�临�Ӷ� O(n)
*/
template <typename T>
bool DbLinkList<T>::ListDelete(int i)
{
	if (m_length < 1)
	{
		std::cout << "��ǰ˫����Ϊ�գ�����ɾ���κ�����!" << std::endl;
		return false;
	}
	if (i < 1 || i > m_length)
	{
		std::cout << "ɾ����λ��" << i << "���Ϸ����Ϸ���λ����1��" << m_length << "֮��!" << std::endl;
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
	std::cout << "�ɹ�ɾ��λ��Ϊ" << i << "��Ԫ�أ���Ԫ�ص�ֵΪ" << del_node->data << "!" << std::endl;
	m_length--;
	delete del_node;
	return true;
}

/**
* ��ȡ�� i ��λ��Ԫ��
* ʱ�临�Ӷ� O(n)
*/
template <typename T>
bool DbLinkList<T>::GetElem(int i, T& e)
{
	if (m_length < 1)
	{
		std::cout << "��ǰ˫����Ϊ�գ����ܻ�ȡ�κ�����!" << std::endl;
		return false;
	}

	if (i < 1 || i > m_length)
	{
		std::cout << "��ȡԪ�ص�λ��" << i << "���Ϸ����Ϸ���λ����1��" << m_length << "֮��!" << std::endl;
		return false;
	}

	DbNode<T>* curr_node = m_head;
	for (int j = 0; j < i; ++j)
	{
		curr_node = curr_node->next;
	}
	e = curr_node->data;
	std::cout << "�ɹ���ȡλ��Ϊ" << i << "��Ԫ�أ���Ԫ�ص�ֵΪ" << e << "!" << std::endl;
	return true;
}

/**
* Ѱ�ҵ�һ��ֵΪ e ��Ԫ��λ��
* ʱ�临�Ӷ� O(n)
*/
template <typename T>
int DbLinkList<T>::LocateElem(const T& e)
{
	DbNode<T>* curr_node = m_head;
	for (int i = 1; i <= m_length; ++i)
	{
		if (curr_node->next->data == e)
		{
			std::cout << "ֵΪ" << e << "��Ԫ����˫�����е�һ�γ��ֵ�λ��Ϊ" << i << "!" << std::endl;
			return i;
		}
		curr_node = curr_node->next;
	}
	std::cout << "ֵΪ" << e << "��Ԫ����˫������û���ҵ�!" << std::endl;
	return -1;
}

/**
* ���˫��������Ԫ��
* ʱ�临�Ӷ� O(n)
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
* ��ȡ������ĳ���
* ʱ�临�Ӷ� O(1)
*/
template <typename T>
int DbLinkList<T>::ListLength()
{
	return m_length;
}

/**
* �ж�˫�����Ƿ�Ϊ��
* ʱ�临�Ӷ� O(1)
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
* ��ת˫����
* ʱ�临�Ӷ� O(n)
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