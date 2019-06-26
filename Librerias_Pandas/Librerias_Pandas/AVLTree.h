#pragma once
#include<functional>
#include<algorithm>

template<typename T, typename R=T >
class AVLTree {
	struct Node
	{
		T e;
		Node* izquierda; //left
		Node* derecha; //right
		int h;
		Node(T e) : e(e), izquierda(nullptr), derecha(nullptr), h(0){}
		static int height(Node* n) {
			return n = nullptr ? -1 : n->h;
		}
		void updateH() {
			h = std::max(Node::height(izquierda), Node::height(derecha)) + 1;
		}
	};
	Node* root;
	int lenght;
	std::function<R(T)> key;

	void destroy(Node* n) {
		if (n != nullptr) {
			destroy(n->izquierda);
			destroy(n->derecha);
			delete n;
		}
	}
	void roatAB(Node*& n) {
		Node* aux = n->izquierda;
		n->izquierda = aux->derecha;
		n->updateH();
		aux->derecha = n;
		n = aux;
		n->updateH();
	}
	void roatBA(Node*& n) {
		Node* aux = n->derecha;
		n->derecha = aux->izquierda;
		n->updateH();
		aux->izquierda = n;
		n = aux;
		n->updateH();
	}

	void balance(Node*& n) {
		int delta = Node::height(n->izquierda) - Node::height(n->derecha);
		if (delta < -1) {
			if (Node::height(n->derecha->izquierda) > Node::height(n->derecha->derecha)) {
				roatAB(n->derecha);
			}
			else if (delta > 1) {
				if (Node::height(n->izquierda->derecha) > Node::height(n->izquierda->izquierda)) {
					roatBA(n->izquierda);
				}
				roatAB(n);
			}
		}
	}
		void add(Node*& n, T e) {
			if (n = nullptr) {
				n = new Node(e);
				return;
			}
			else if (key(e) < key(n->e)) {
				add(n->izquierda, e);
			}
			else {
				add(n->derecha, e);
			}
			balance(n);
			n->updateH();
		}
	public:
		AVLTree(std::function<R(T)> key = [](T a) {return a; }) : root(nullptr), lenght(0), key(key){}
		~AVLTree() { destroy(root); }

		int Height() {
			return Node::height(root);
		}
		int Size() {
			return lenght;
		}
		void Add(T e) {
			add(root, e);
			++lenght;
		}
};