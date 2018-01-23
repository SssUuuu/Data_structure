#pragma once
////开放定址法的哈希表
#include <vector>
//
//利用状态来判断当前是否有数据
//enum State
//{
//	EMPTY = 1,
//	EXITS = 2,
//	DELET = 3,
//};
//
//
//template<class K,class V>
//struct HashNode
//{
//	K _key;
//	V _value;
//	State _state;
//
//	HashNode()
//		:_state(EMPTY)
//	{}
//};
//
//template<class K>
//struct _HashFunc
//{
//	size_t operator()(const K& key)
//	{
//		return key;
//	}
//};
//
//template<>
//struct _HashFunc<string>
//{
//	//字符串哈希算法
//	static size_t BKDRHash(const char * str)
//	{
//		unsigned int seed = 131; // 31 131 1313 13131 131313
//		unsigned int hash = 0;
//		while (*str)
//		{
//			hash = hash * seed + (*str++);
//		}
//		return (hash & 0x7FFFFFFF);
//	}
//
//	size_t operator()(const string& key)
//	{
//		return BKDRHash(key.c_str());
//	}
//};
//
//
//template<class K, class V, class __HashFunc = _HashFunc<K>>
//class HashTable
//{
//	typedef HashNode<K, V> Node;
//public:
//	HashTable()
//		:_size(0)
//	{}
//
//	bool Insert(const K& key, const V& value)
//	{
//		CheckCapacity();
//		size_t hash = HashFunc(key);
//		size_t index = hash;
//		size_t i = 1;
//
//		while (_tables[index]._state == EXITS)
//		{
//			if (_tables[index]._key == key)
//				return false;
//
//			//线性探测
//			//++index;
//			//if (index == _tables.size())
//			//	index = 0;

//			//二次探测
//			index = (hash + i*i) % _tables.size();
//			i++;
//		}
//		_tables[index]._key = key;
//		_tables[index]._value = value;
//		_tables[index]._state = EXITS;
//		++_size;
//		return true;
//	}
//
//	Node* Find(const K& key)
//	{
//		size_t index = HashFunc(key);
//		while (_tables[index]._state != EMPTY)
//		{
//			if (_tables[index]._key == key)
//			{
//				if (_tables[index]._state != DELET)
//					return &_tables[index];
//				else
//					return NULL;
//			}
//			++index;
//			if (index == _tables.size())
//				index = 0;
//		}
//		return NULL;
//	}
//
//	bool Remove(const K& key)
//	{
//		Node* ret = Find(key);
//		if (ret)
//		{
//			ret._state = DELET;
//			--size;
//			return true;
//		}
//		else
//			return false;
//	}
//
//protected:
//	void CheckCapacity()
//	{
//		if (_tables.size() == 0)
//		{
//			_tables.resize(GetNextPrime(1));
//		}

//		//负载因子控制在0.7，超过就
//		else if ((_size*10)/_tables.size() >= 7)
//		{
//			HashTable<K, V> NewTable;
//			NewTable._tables.resize(GetNextPrime(_tables.size()));
//			for (size_t i = 0; i < _tables.size(); i++)
//			{
//				if (_tables[i]._state == EXITS)
//				{
//					NewTable.Insert(_tables[i]._key, _tables[i]._value);
//				}
//			}
//			_tables.swap(NewTable._tables);
//		}
//	}
//
//	size_t HashFunc(const K& key)
//	{
//		__HashFunc func;
//		return func(key) % _tables.size();
//	}
//
//	size_t GetNextPrime(size_t size)
//	{
//		const int _PrimeSize = 28;
//		static const unsigned long _PrimeList[_PrimeSize] =
//		{
//			53ul,         97ul,         193ul,       389ul,       769ul,
//			1543ul,       3079ul,       6151ul,      12289ul,     24593ul,
//			49157ul,      98317ul,      196613ul,    393241ul,    786433ul,
//			1572869ul,    3145739ul,    6291469ul,   12582917ul,  25165843ul,
//			50331653ul,   100663319ul,  201326611ul, 402653189ul, 805306457ul,
//			1610612741ul, 3221225473ul, 4294967291ul
//		};
//
//		for (int i = 0; i < _PrimeSize; ++i)
//		{
//			if (_PrimeList[i] > size)
//			{
//				return _PrimeList[i];
//			}
//		}
//
//		return _PrimeList[_PrimeSize - 1];
//	}
//
//private:
//	vector<Node> _tables;
//	size_t _size;
//};
//

	