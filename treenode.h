/*
 * treenode.h
 *
 *  Created on: Jun 11, 2012
 *      Author: o
 */

#ifndef TREENODE_H_
#define TREENODE_H_

template<typename T, typename O = Less<T> >
class Tree;

template<typename T, typename O = Less<T> >
class TreeIterator;

template<typename T, typename O = Less<T> >
class TreeNode {

	friend class Tree<T, O> ;
	friend class TreeIterator<T, O> ;

public:

	TreeNode(T value) :
			m_up(0), m_left(0), m_right(0), m_value(value) {
	}

	TreeNode(TreeNode<T, O>* up, T value) :
			m_up(up), m_left(0), m_right(0), m_value(value) {
	}

	TreeNode(TreeNode<T, O>* up, Tree<T, O>* left, Tree<T, O>* right, T value) :
			m_up(up), m_left(left), m_right(right), m_value(value) {
	}

	~TreeNode() {
		delete m_left;
		delete m_right;
	}


	// Methods
	T& value() {
		return m_value;
	}

	TreeNode<T, O>* find(const T& value) {
		if (value < m_value && m_left != 0) {
			return m_left->find(value);
		} else if (value > m_value && m_right != 0) {
			return m_right->find(value);
		} else if (value == m_value) {
			return this;
		} else {
			return 0;
		}
	}

	TreeNode<T, O>* findFirst() {
		if (m_left != 0) {
			return m_left->findFirst();
		}
		return this;
	}

	TreeNode<T, O>* findLast() {
		if (m_right != 0) {
			return m_right->findLast();
		}
		return this;
	}

	TreeNode<T, O>* insertValue(const T& value) {
		O orderT;
		if (orderT(value, m_value)) {
			if (m_left != 0) {
				return m_left->insertValue(value);
			} else {
				TreeNode<T, O>* n = new TreeNode<T, O>(this, value);
				this->m_left = n;
				return n;
			}
		} else if (!orderT(value, m_value)) {
			if (m_right != 0) {
				return m_right->insertValue(value);
			} else {
				TreeNode<T, O>* n = new TreeNode<T, O>(this, value);
				this->m_right = n;
				return n;
			}
		} else {
			return 0;
		}
	}

	void pre_order() {

		if (m_left != 0) {
			m_left->pre_order();
		}
		if (m_right != 0) {
			m_right->pre_order();
		}
		cout << "delete: " << m_value << ", ";
		return;
	}

	void clear() {
		if (m_left != 0) {
			m_left->clear();
		}
		if (m_right != 0) {
			m_right->clear();
		}
		//cout << "delete: " << m_value << ", ";
		m_left = 0;
		m_right = 0;
		m_up = 0;
		return;
	}

protected:
	TreeNode<T, O>* m_up;
	TreeNode<T, O>* m_left;
	TreeNode<T, O>* m_right;
	T m_value;
};

#endif /* TREENODE_H_ */
