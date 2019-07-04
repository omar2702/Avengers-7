#include "AVL.h"
//#include <bits/stdc++.h>
#include "miniDF.h"
using namespace std;
/*
int main() {
	int a; cin >> a;
	AVL<int>* f = new AVL<int>();
	int b;
	vector<int> we(a);
	for (int i = 0; i < a; i++) {
		cin >> we[i];
		f->add(we[i]);
	}
	//f->ord();
	for (auto a : we) {
		cout << f->buscarINDX(a) << " ";
	}
	cout << endl;
	cin >> b;

	cout << endl;
	system("pause");
	return 0;
}*/


int main() {
	int a, b;
	cin >> a >> b;
	miniDF* ayuda = new miniDF(b, a);
	for (int i = 0; i < a; i++) {
		vector<int> wii(b);
		for (int j = 0; j < b; j++) {
			cin >> wii[j];
		}
		ayuda->añadirFila(wii);
	}
	//ayuda->mostrar();
	int c;
	cin >> c;
	while (c--) {
		int f, t; cin >> f >> t;
		ayuda->act(f, t);
	}
	ayuda->mostrar();
	int z; cin >> z;
}
