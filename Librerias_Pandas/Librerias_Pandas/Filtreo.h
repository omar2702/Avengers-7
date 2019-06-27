#pragma once
#include"Fila.h"
#include <map>
/////Metodos Filtrear
bool mayor(string v1, string v2) {
	if (v1 > v2) return 1;
	return 0;
}

bool mayor_igual(string v1, string v2) {
	if (v1 >= v2) return 1;
	return 0;
}

bool menor(string v1, string v2) {
	if (v1 < v2) return 1;
	return 0;
}

bool menor_igual(string v1, string v2) {
	if (v1 <= v2) return 1;
	return 0;
}
bool igual(string v1, string v2) {
	if (v1 == v2) return 1;
	return 0;
}
bool inicia(string v1, string v2) {
	for (long long i = 0; i < v2.size(); i++) {
		if (v1[i] != v2[i]) return 0;
		return 1;
	}
}
bool finaliza(string v1, string v2) {
	if (v1[v1.size() - 1] == v2[0]) return 1;
	return 0;
}
bool contenido(string v1, string v2) {
	for (long long i = 0; i < v1.size(); i++) {
		if (v1[i] == v2[0]) return 1;
	}
	return 0;
}
bool noContenido(string v1, string v2) {
	for (long long i = 0; i < v1.size(); i++) {
		if (v1[i] == v2[0]) return 0;
	}
	return 1;
}

bool compare(string nc1, string op1, string val1, Fila* f) {
	if (nc1 == "") return 1;
	else if (op1 == ">") return mayor(f->getData(nc1), val1);
	else if (op1 == ">=") return mayor_igual(f->getData(nc1), val1);
	else if (op1 == "<") return menor(f->getData(nc1), val1);
	else if (op1 == "<=") return menor_igual(f->getData(nc1), val1);
	else if (op1 == "=") return igual(f->getData(nc1), val1);
	else if (op1 == "iniciaCon") return inicia(f->getData(nc1), val1);
	else if (op1 == "finalizaCon") return finaliza(f->getData(nc1), val1);
	else if (op1 == "conteins") return contenido(f->getData(nc1), val1);
	else if (op1 == "noConteins") return noContenido(f->getData(nc1), val1);
}