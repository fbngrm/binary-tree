/*
 * treeiterator.h
 *
 *  Created on: Jun 11, 2012
 *      Author: o
 */

#ifndef TREEITERATOR_H_
#define TREEITERATOR_H_

template<typename T, typename O>
class Tree;

template<typename T, typename O>
class TreeNode;

// Class TreeIterator
template<typename T, typename O>
class TreeIterator {

public:
	TreeIterator<T, O>(Tree<T, O>* tree, TreeNode<T, O>* node) :
			m_tree(tree), m_node(node) {
	}

	TreeIterator<T, O>(TreeNode<T, O>* node) :
			m_tree(), m_node(node) {
	}

	TreeIterator<T, O>() :
			m_tree(), m_node() {
	}

	~TreeIterator() {
	}


	const Tree<T, O>* tree() const {
		return m_tree;
	}
	const TreeNode<T, O>* node() const {
		return m_node;
	}

	Tree<T, O>* tree() {
		return m_tree;
	}

	TreeNode<T, O>* node() {
		return m_node;
	}

	// Methods
	T& operator*() {
		return m_node->value();
	}

	T* operator->() {
		return m_node->value();
	}

	TreeIterator<T, O>& operator++() {
		// empty tree
		if (m_node == 0 || m_node == m_tree->last().node()) {
			m_node = NULL;
			return *this;
		}
		// try right
		if (m_node->m_right != 0) {
			m_node = left_most(m_node->m_right);
			return *this;
		} else if (m_node->m_up != 0) {
			m_node = up_right();
			return *this;
		} else {
			return *this;
		}
	}

	TreeNode<T, O>* left_most(TreeNode<T, O>* node) {
		assert(node != 0);
		while (node->m_left)
			node = node->m_left;
		return node;
	}

	TreeNode<T, O>* up_right() {
		bool has_parent = m_node->m_up != 0;
		// check if parent has right child
		bool has_right = has_parent ? m_node->m_up->m_right != 0 : false;
		// parent->right == this
		bool is_this = has_right ? m_node->m_up->m_right == m_node : false;
		// step up
		m_node = m_node->m_up;

		return is_this ? up_right() : m_node;
		/*
		if (is_this) {
			m_node = m_node->m_up;
			return up();
		} else {
			m_node = m_node->m_up;
			return m_node;
		}
		*/
	}

	TreeIterator<T, O>& operator--() {
		// empty tree
		if (m_node == NULL){
			m_node = m_tree->last().node();
			return *this;
		}
		// try right
		if (m_node->m_left != 0) {
			m_node = right_most(m_node->m_left);
			return *this;
		} else if (m_node->m_up != 0) {
			m_node = up_left();
			return *this;
		} else {
			return *this;
		}
	}


	TreeNode<T, O>* right_most(TreeNode<T, O>* node) {
		assert(node != 0);
		while (node->m_right)
			node = node->m_right;
		return node;
	}

	TreeNode<T, O>* up_left() {
			bool has_parent = m_node->m_up != 0;
			// check if parent has left child
			bool has_left = has_parent ? m_node->m_up->m_left != 0 : false;
			// parent->left == this
			bool is_this = has_left ? m_node->m_up->m_left == m_node : false;
			// step up
			m_node = m_node->m_up;

			return is_this ? up_left() : m_node;
		}

	bool operator==(const TreeIterator<T, O> &rhs) {
		return rhs.tree() == this->tree() && rhs.node() == this->node();
	}

	bool operator!=(const TreeIterator<T, O> &rhs) {
		return !(rhs.tree() == this->tree() && rhs.node() == this->node());
	}


private:
	Tree<T, O>* m_tree;
	TreeNode<T, O>* m_node;

};

#endif /* TREEITERATOR_H_ */
