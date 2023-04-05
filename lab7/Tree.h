#pragma once
#include <stdlib.h>
#include <stdio.h>


template<typename T>
class TreeNode {
public:
	TreeNode<T>* operator [] (size_t index) {
		return m_children[index];
	}
	const T& Data() const {
		return m_data;
	}
	TreeNode(const T& value) : m_data(value), m_parent(nullptr), m_children(nullptr), m_childrenCount(0) {}
	TreeNode() : TreeNode(T()) {}
	TreeNode(const TreeNode& copy) : m_data(copy.m_data), m_parent(nullptr), m_children(nullptr), m_childrenCount(0) {}

	void deleteChildren() {
		for (size_t i = 0; i < m_childrenCount; ++i) {
			delete m_children[i];
		}
		delete[] m_children;
		m_childrenCount = 0;
		m_children = nullptr;
	}
	~TreeNode() {
		deleteChildren();
	};

	void deleteChild(TreeNode<T>* child) {
		bool ok = false;
		for (size_t i = 0; i < m_childrenCount; ++i) {
			if (m_children[i] == child) {
				ok = true;
				delete m_children[i];
				continue;
			}
			if (ok && i <= 1) {
				m_children[i - 1] = m_children[i];
			}
		}
		--m_childrenCount;
	};

	void addNode(TreeNode<T>* child) {
		child->setParent(this);
		TreeNode<T>** newChildren = new TreeNode<T>*[m_childrenCount + 1];
		memcpy(newChildren, m_children, m_childrenCount * sizeof(TreeNode<T>*));
		newChildren[m_childrenCount] = child;
		++m_childrenCount;
		delete[] m_children;
		m_children = newChildren;
	}

	void addNode(TreeNode<T>* child, size_t idx) {
		if (idx > m_childrenCount) {
			throw;
		}
		child->setParent(this);
		TreeNode<T>** newChildren = new TreeNode<T>*[m_childrenCount + 1];
		for (size_t i = 0; i < idx; ++i) {
			newChildren[i] = m_children[i];
		}
		newChildren[idx] = child;
		for (size_t i = idx; i < m_childrenCount; ++i) {
			newChildren[i + 1] = m_children[i];
		}
		++m_childrenCount;
		delete[] m_children;
		m_children = newChildren;
	}	

	void setParent(TreeNode<T>* parent) {
		m_parent = parent;
	}

	TreeNode<T>* Parent() {
		return m_parent;
	}

	size_t childrenCount() const {
		return m_childrenCount;
	}

	size_t countRec() {
		if (childrenCount() == 0) return 1;
		int sum = 0;
		for (size_t i = 0; i < childrenCount(); ++i) {
			sum += (*this)[i]->countRec();
		}
		return sum + 1;
	}

	TreeNode<T>* Find(const T& value, bool(*equals)(const T& lhs, const T& rhs) = nullptr) {
		if ( (equals != nullptr && equals(Data(), value)) || (equals == nullptr && Data() == value)) {
			return this;
		}
		else {
			if (childrenCount() == 0) {
				return nullptr;
			}
			for (size_t i = 0; i < childrenCount(); ++i) {
				TreeNode<T>* tmp = m_children[i]->Find(value, equals);
				if (tmp != nullptr) {
					return tmp;
				}
			}
			return nullptr;
		}
	}
	void Sort(bool (*compare)(const T&, const T&) = nullptr) {
		for (size_t i = 0; i < childrenCount() - 1; ++i) {
			for (size_t j = i; j < childrenCount(); ++j) {
				if (  (compare != nullptr && !compare(m_children[i]->Data(), m_children[j]->Data())) || m_children[i]->Data() > m_children[j]->Data() ) {
					auto tmp = m_children[i];
					m_children[i] = m_children[j];
					m_children[j] = tmp;
				}
			}
		}
	}

private:
	T m_data;
	TreeNode<T>* m_parent;
	TreeNode<T>** m_children;
	size_t m_childrenCount;
	
};

template<typename T>
class Tree {
private:
	TreeNode<T>* m_root;
public:
	friend class TreeNode<T>;
	Tree() : m_root(nullptr) {}
	~Tree() {
		delete_node(m_root);
	};
	TreeNode<T>* root() {
		return m_root;
	}
	void add_node(TreeNode<T>* parent, const T& value) {
		if (parent != nullptr) {
			TreeNode<T>* t = new TreeNode<T>(value);
			parent->addNode(t);
		}
		else {
			m_root = new TreeNode<T>(value);
		}
	}
	TreeNode<T>* get_node(TreeNode<T>* parent, size_t idx) {
		return (*parent)[idx];
	}
	void delete_node(TreeNode<T>* node) {
		if (node == nullptr) {
			return;
		}
		if (node->Parent() == nullptr) {
			delete node;
		}
		else {
			TreeNode<T>* tmp = node->Parent();
			tmp->deleteChild(node);
		}
	}
	void insert(TreeNode<T>* parent, const T& value, size_t idx) {
		if (parent == nullptr) {
			return;
		}
		TreeNode<T>* t = new TreeNode<T>(value);
		parent->addNode(t, idx);
	}
	size_t count(TreeNode<T>* node) const {
		return node->countRec();
	}

	TreeNode<T>* find(const T& val, bool(*equals)(const T& lhs, const T& rhs) = nullptr) {
		return root()->Find(val, equals);
	}

	void sort(TreeNode<T>& node, bool (*compare)(const T&, const T&) = nullptr) {
		node->Sort(compare);
	}
};
