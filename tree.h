#ifndef TREE_H_
#define TREE_H_

#include "treenode.h"
#include "treeiterator.h"

template<typename T, typename O >
class TreeIterator;

template<typename T, typename O >
class TreeNode;

// Class Tree
template<typename T, typename O >
class Tree {

public:

	typedef TreeIterator<T, O> iterator;
	typedef TreeNode<T, O> node;

	Tree(node* root) :
			m_root(root) {
	}

	Tree() :
			m_root(0) {
	}

	~Tree() {
		delete m_root;
	}


	const node* root() const {
		return m_root;
	}
	node* root() {
		return m_root;
	}

	iterator insert(const T& value) {
		if (m_root == 0) {
			m_root = new node(value);
			return iterator(this, m_root);
		} else {
			return iterator(this, m_root->insertValue(value));
		}
	}

	void clear(){
		m_root->clear();
		m_root = 0;
	}

	iterator begin() {
		if (m_root == 0) {
			return iterator();
		}
		//return iterator(this, m_root);
		return first();
	}

	iterator end() {
		if (m_root == 0) {
			return iterator();
		}
		return iterator(this, NULL);
	}

	iterator first() {
		if (m_root == 0) {
			return iterator();
		}
		return iterator(this, m_root->findFirst());
	}

	iterator last() {
		if (m_root == 0) {
			return iterator();
		}
		return iterator(this, m_root->findLast());
	}

	iterator find(const T& value) {
		if (m_root == 0) {
			return iterator();
		}
		return iterator(this, m_root->find(value));
	}

	void pre_order(){
		cout << "preorder: ";
		if(m_root != 0){
			m_root->pre_order();
		}
	}

private:
	node* m_root;
};

#endif /* TREE_H_ */
