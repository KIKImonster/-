RT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
//hash开散列
//哈希表存放节点指针，每一个哈希表的位置都是一个单链表，所有产生相同哈希位置的数据都会存入一个单链表
using namespace std;
template <class K>
struct keyOfValue1
{
	const K& operator()(const K& data)
	{
		return data;
	}
};


template <class V>
struct HashNode
{
	V _data;
	HashNode<V>* _next;

	HashNode(const V& data)
		:_data(data)
		, _next(nullptr)
	{}

};
template <class>
struct _HashIterator
{
	//封装节点
	typedef HashNode<V> Node;
	typedef _HashIterator<V> Self;
	typedef HashTable<K, V, KeyOfValue> hTable;
	Node* node;
	hTable _ht;
	//哈希表指针
	_HashIterator(Node* node, hTable* _pht)
		:_node(node)
		, _pht(pht);
	{}
	V& operator*()
	{
		return _node->_data;
	}
	V* operator ->()
	{
		return &_node->_data;
	}
	bool operator != (const Self& it)
	{
		return _node != it._node;
	}
};
//define hashtable
template <class K, class V, class keyOfValue>
class HashTable
{
public:
	typedef HashNode<V> Node;

	bool insert(const V& data)
	{
		//首先检查容量
		//checkCapacity()
		keyOfValue kov;
		int idx = kov(data) % _ht.size();//计算哈希位置
		//判断当前桶中是否存在key重复的元素
		Node* cur = _ht[idx];
		while (cur)
		{
			Node* next = cur->_next;
			if (kov(cur->_data) == kov(data))
				return false;
			cur = cur->_next;
		}//遍历桶内元素
		//单链表头插
		cur = new Node(data);
		cur->_next = _ht[idx];
		_ht[idx] = cur;

		++_size;
		return true;
	}
	/*void checkCapacity()
	{
		if (_size == _ht.size())
		{
			int newC = _ht.size() == 0 ? 10 : 2 * _ht.size();
			HashTable<K, V, keyOfValue> newHT(newC);
			for (int i = 0; i < _ht.size(); ++i)
			{
				Node* cur = _ht[i];
				while (cur)
				{
					Node* next = cur->_next;
					newHT.insert(cur->_data);
					delete cur;
					cur = next;
				}
				_ht[i] = nullptr;
			}
			swap(_ht, newHT._ht);
		}
	}*/
	void checkCapacity()
	{
		if (_size == _ht.size())
		{
			int newC = _ht.size() == 0 ? 10 : 2 * _ht.size();
			vector<Node>* newHt(newC);
			newHt.resize(newC);
			KeyOfValue kov;
			for (int i = 0; i < _ht.size(); ++i)
			{
				Node* cur = _ht[i];
				while (cur)
				{
					Node* next = cur->_next;
				  idx = kov(cur->_data) % newHt.size();
				  //头插
				  cur->_next = newHt[idx];
				  newHt[idx] = cur;

				  cur = next;

				}
				_ht[i] = nullptr;
			}
			swap(_ht, newHT._ht);
		}
	}
	Node* find(const K& key)
	{
		keyOfValue kov;
		idx = key % _ht.size();
		Node* cur = _ht[idx];
		while (cur)
		{
			if (kov(cur->_data) == key)
				return cur;
			cur = cur->_next;
		}
		return nullptr;

	}
	bool erase(const K& key)
	{
		Node* cur = find(key);
		if (cur){
			cur 
			delete ;
			_size--;
			return true;
		}
		return false;

		
	}
	bool erase(const K& key)
	{
		int idx = key% _ht.size();
		keyOfValue kov;
		Node* cur = _ht[idx];
		Node* prev = nullptr;
		while (cur)
		{
			if (kov(cur->_data) == key)
			{
				if (prev)
					prev->_next = cur->_next;
				else
					_ht[idx] = cur->_next;

				delete cur;
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
private:
	vector<Node*> _ht;
	size_t _size = 0;
};

void test()
{

}
int main()
{

}

template<class K>
class UnorderedSet
{
	struct setKeyOfValue
	{
		const K& operator()(const K& data)
		{
			return data;
		}
	};
public:
	typedef typename HashTable<K, K, setKeyOfValue>::iterator iterator;

	pair<iterator, bool> insert(const K& key)
	{
		return _ht.insert(key);
	}
	iterator begin()
	{
		return _ht.begin();
	}
	iterator end()
	{
		return _ht.end();
	}


private:
	HashTable<K, K, setKeyOfValue> _ht;

};
