#pragma once
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template <class T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;

	BinaryTreeNode(const T& x)
		:_data(x)
		, _left(NULL)
		, _right(NULL)
	{}
};

template <class T>
class BinaryTree
{
public:
	typedef BinaryTreeNode<T> Node;

	BinaryTree(const T* arr, size_t sz, const T& invalid)
	{
		size_t index = 0;
		_root = _CreatTree(arr, sz, index, invalid);
	}

	//遍历递归写法：
	void PrevOrederR()
	{
		_PrevOrderR(_root);
	}

	void MidOrderR()
	{
		_MidOrderR(_root);
	}

	void BackOrderR()
	{
		_BackOrderR(_root);
	}


	//遍历非递归
	void PrevOrderNR()
	{
		stack<Node*> s;
		Node* cur = _root;
		while (cur || !s.empty())
		{
			while (cur != NULL)
			{
				s.push(cur);
				cout << cur->_data << " ";
				cur = cur->_left;
			}
			//到最左根节点，该回溯了
			if (!s.empty())
			{
				cur = s.top();
				s.pop();
				cur = cur->_right;
			}
		}
		cout << endl;
	}

	void MidOrderNR()
	{
		stack<Node*> s;
		Node* cur = _root;

		while (cur != NULL || !s.empty())
		{
			while (cur != NULL)
			{
				s.push(cur);
				cur = cur->_left;
			}
			
			//到最左节点
			if (!s.empty())
			{
				cur = s.top();
				cout << cur->_data << " ";
				s.pop();
				cur = cur->_right;
			}
		}
		cout << endl;
	}

	void BackOrderNR()
	{
		stack<Node*> s;
		Node* cur = _root;
		Node* prev = NULL;

		while (cur != NULL || !s.empty())
		{
			while (cur != NULL)
			{
				s.push(cur);
				cur = cur->_left;
			}
			
			Node* top = s.top();
			
			if (top->_right == NULL || top->_right == prev)
			{
				cout << top->_data << " ";
				s.pop();
			}
			else
			{	//说明此时右子树还没判断，不可直接pop
				cur = top->_right;
			}
			prev = top;
		}
		cout << endl;
	}

	void LevelOrder()
	{
		queue<Node*> q;
		Node* node = _root;
		if (node != NULL)
			q.push(node);

		while (!q.empty())
		{
			Node* cur = q.front();
			cout << cur->_data << " ";
			q.pop();
			if (cur->_left != NULL)
				q.push(cur -> _left);
			if (cur->_right != NULL)
				q.push(cur->_right);
		}
		cout << endl;
	}

	//子问题
	int SizeByChildQue()
	{
		return _SizeByChildQue(_root);
	}

	int SizeByTrav()
	{
		size_t size = 0;
		_SizeByTrav(_root, size);
		return size;
	}

	int LeafSizeByChildQue()
	{
		return _LeafSizeByChildQue(_root);
	}

	int LeafSizeByTrav()
	{
		size_t size = 0;
		_LeafSizeByTrav(_root, size);
		return size;
	}

	size_t Height()
	{
		return _Height(_root);
	}
protected:

	Node* _CreatTree(const T* arr, size_t sz, size_t& index, const T& invalid)
	{
		Node* node = NULL;
		if (arr[index] != invalid)
		{
			node = new Node(arr[index]);
			node->_left = _CreatTree(arr, sz, ++index, invalid);
			node->_right = _CreatTree(arr, sz, ++index, invalid);
		}
		return node;
	}

	void _PrevOrderR(Node* node)
	{
		if (node == NULL)
			return;

		cout << node->_data << " ";
		_PrevOrderR(node->_left);
		_PrevOrderR(node->_right);
	}

	void _MidOrderR(Node* node)
	{
		if (node == NULL)
			return;
		
		_MidOrderR(node->_left);
		cout << node->_data << " ";
		_MidOrderR(node->_right);
	}

	void _BackOrderR(Node* node)
	{
		if (node == NULL)
			return;

		_BackOrderR(node->_left);
		_BackOrderR(node->_right);
		cout << node->_data << " ";
	}

	int _SizeByChildQue(Node* node)
	{
		if (node == NULL)
			return 0;
		return _SizeByChildQue(node->_left) + _SizeByChildQue(node->_right) + 1;
	}

	void _SizeByTrav(Node* node, size_t& size)
	{
		if (node == NULL)
			return;

		size++;
		_SizeByTrav(node->_left, size);
		_SizeByTrav(node->_right,size);
	}

	int _LeafSizeByChildQue(Node* node)
	{
		if (node == NULL)
			return 0;

		if (node->_left == NULL && node->_right == NULL)
		{
			return 1;
		}
		return _LeafSizeByChildQue(node->_left) + _LeafSizeByChildQue(node->_right);
	}

	void _LeafSizeByTrav(Node* node, size_t& size)
	{
		if (node == NULL)
			return;

		if (node->_left == NULL && node->_right == NULL)
			size++;

		_LeafSizeByTrav(node->_left, size);
		_LeafSizeByTrav(node->_right, size);
	}

	size_t _Height(Node* node)
	{
		if (node == NULL)
			return 0;

		size_t lHeight = _Height(node->_left);
		size_t rHeight = _Height(node->_right);

		return lHeight > rHeight ? lHeight + 1 : rHeight + 1;
	}
private:
	Node* _root;
};


/*	int arr[] = { 1,2,3,'#','#',4,'#','#',5,6 ,'#','#','#' };
	BinaryTree<int> tree1(arr, sizeof(arr) / sizeof(arr[0]), '#');*/