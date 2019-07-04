#pragma once
//#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>

// me mate pensando en como llevar el indice con el numero al momento de rotar
// pero solo era aplicar la suma de indices en la busqueda del numero
using namespace std;

template <typename T, typename R = T>
class AVL {
	struct Node {
		T e;
		Node* R;
		Node* L;
		int h;
		vector<T> elementos;
		Node(T e) : e(e), R(nullptr), L(nullptr), h(0) {}
		static int altu(Node* a) {
			if (a == nullptr) return -1;
			else return a->h;
		}

		void updateH() {
			h = std::max(Node::altu(L), Node::altu(R)) + 1;
		}
	};
	Node* root;
	int l;
	std::function<R(T)> key;



public:
	AVL(std::function<R(T)> key = [](T a) {return a; }) : root(nullptr), key(key), l(0) {}
	~AVL() {}
private:
	void RotAB(Node*& a) {
		Node* aux = a->L;
		a->L = aux->R;
		a->updateH();
		aux->R = a;
		a = aux;
		a->updateH();
	}
	void RotBA(Node*& a) {
		Node* aux = a->R;
		a->R = aux->L;
		a->updateH();
		aux->L = a;
		a = aux;
		a->updateH();
	}

	void balance(Node*& a) {
		int delta = Node::altu(a->L) - Node::altu(a->R);
		if (delta < -1) {
			if (Node::altu(a->R->L) > Node::altu(a->R->R)) {
				RotAB(a->R);
			}
			RotBA(a);
		}
		else if (delta > 1) {
			if (Node::altu(a->L->R) > Node::altu(a->L->L)) {
				RotBA(a->L);
			}
			RotAB(a);
		}
	}

	void Add(Node*& a, T e) {
		if (a == nullptr) {
			a = new Node(e);
			a->elementos.push_back(e);
			return;
		}
		else if (key(e) < key(a->e)) {
			Add(a->L, e);
		}
		else if (key(e) > key(a->e)) {
			Add(a->R, e);
		}
		else if (key(e) == key(a->e)) {
			a->elementos.push_back(e);
			//cout << key(e) << endl;
			return;
		}
		balance(a);
		a->updateH();
	}
	int buscarIND(T e, Node* a, int ind) {
		if (a == nullptr) {

			return 0;

		}
		else if (key(a->e) == key(e)) {

			return ind;
		}
		else if (key(e) < key(a->e)) {
			return buscarIND(e, a->L, ind * 2);
		}
		else {
			return buscarIND(e, a->R, ind * 2 + 1);
		}
	}
	vector<T> Buscarr(R e, Node* a) {
		if (a == nullptr) return a->elementos;
		else if (key(a->e) == e) {
			return a->elementos;
		}
		else if (e < key(a->e)) {
			return Buscarr(e, a->L);
		}
		else {
			return Buscarr(e, a->R);
		}
	}
	Node* Buscar(T e, Node* a) {
		if (a == nullptr) return a;
		else if (key(a->e) == key(e)) {
			return a;
		}
		else if (key(e) < key(a->e)) {
			return Buscar(e, a->L);
		}
		else {
			return Buscar(e, a->R);
		}
	}
	void enOrder(Node* a) {
		if (a != nullptr) {
			enOrder(a->L);
			cout << key(a->e) << endl;
			enOrder(a->R);
		}
	}
public:
	void add(T e) {
		Add(root, e);
	}
	void ord() {
		enOrder(root);
	}
	int buscarINDX(T e) {

		int ar = buscarIND(e, root, 1);
		return ar;
	}
	vector<T> Busc(R e) {
		vector<T> fi = Buscarr(e, root);
		return fi;
	}
};
