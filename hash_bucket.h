#pragma once
#include <vector>
using namespace std;

template<class K, class V>
struct HashNode
{
	K _key;
	V _value;
	HashNode<K, V>* _next;

	HashNode(const K& key,const V& value)
		:_key(key)
		,_value(value)
		,_next(NULL)
	{}
};


template <class K>
struct _HashFunc
{
	size_t operator()(const K& key)
	{
		return key;
	}
};

template <class K, class V, class __HashFunc =_HashFunc<K>>
class HashBucket
{
	typedef HashNode<K, V> Node;
protected:
	vector<Node*> _tables;
	size_t _size;

public:
	HashBucket()
		:_size(0)
	{}

	void Resize(size_t size)
	{
		_tables.resize(GetNextPrime(size));
	}

	bool Insert(const K& key,const V& value)
	{
		CheckCapacity();
		size_t index = GetIndex(key, _tables.size());
		Node* cur = _tables[index];
		//确定key唯一
		while (cur)
		{
			if (cur->_key == key)
				return false;
			cur = cur->_next;
		}

		//进行头插
		Node* newNode = new Node(key, value);
		newNode->_next = _tables[index];
		_tables[index] = newNode;
		++_size;
		return true;
	}

	Node* find(const K& key)
	{
		size_t index = GetIndex(key,_tables.size());
		Node* cur = _tables[index];
		while (cur)
		{
			if (cur->_key == key)
				return cur;
			cur = cur->_next;
		}
		return NULL;
	}


	bool Remove(const K& key)
	{
		size_t index = GetIndex(key,_tables.size());
		Node* cur = _tables[index];
		Node* prev = NULL;

		//先处理头
		if (cur && cur->_key == key)
		{
			_tables[index] = cur->_next;
			delete cur;
			--_size;
			return true;
		}
		//使用替代删除法
		while (cur)
		{
			if (cur->_key == key)
			{
				prev->_next = cur->_next;
				delete cur;
				--_size;

				return true;
			}
			else
			{
				prev = cur;
				cur = cur->_next;
			}
		}
		return false;
	}


protected:

	void CheckCapacity()
	{
		if (_size == _tables.size())
		{
			vector<Node*> newTable;
			newTable.resize(GetNextPrime(_size), NULL);
			//将旧表中的所有节点插入新表中
			for (size_t i = 0; i < _size; ++i)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					size_t index = GetIndex(cur->_key, newTable.size());

					//进行头插
					cur->_next = _tables[index];
					_tables[index] = cur;

					cur = next;
				}
			}
			_tables.swap(newTable);
		}
	}

	size_t GetIndex(const K& key, size_t size)
	{
		__HashFunc func;
		return func(key) % size;
	}

	//素数表
	size_t GetNextPrime(size_t size)
	{
		const int _PrimeSize = 28;
		static const unsigned long _PrimeList[_PrimeSize] =
		{
			53ul,         97ul,         193ul,       389ul,       769ul,
			1543ul,       3079ul,       6151ul,      12289ul,     24593ul,
			49157ul,      98317ul,      196613ul,    393241ul,    786433ul,
			1572869ul,    3145739ul,    6291469ul,   12582917ul,  25165843ul,
			50331653ul,   100663319ul,  201326611ul, 402653189ul, 805306457ul,
			1610612741ul, 3221225473ul, 4294967291ul
		};
	
		for (int i = 0; i < _PrimeSize; ++i)
		{
			if (_PrimeList[i] > size)
			{
				return _PrimeList[i];
			}
		}
	
		return _PrimeList[_PrimeSize - 1];
	}

	size_t HashFunc(const K& key)
	{
		__HashFunc func;
		return func(key) % _tables.size();
	}
	
};