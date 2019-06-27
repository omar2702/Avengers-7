#pragma once
#include"Fila.h"
void merge(vector<Fila*> &vec, long long inicio, long long fin, string nombreColumna) {
	long long length = (fin - inicio) + 1;
	vector<Fila*> aux(length);
	long long mid = (fin + inicio) / 2;
	long long i = inicio;
	long long j = mid + 1;
	for (long long k = 0; i <= mid || j <= fin; k++) {
		if (i > mid || j <= fin && vec[j]->getData(nombreColumna) < vec[i]->getData(nombreColumna)) {
			aux[k] = vec[j];
			j++;
		}
		else {
			aux[k] = vec[i];
			i++;
		}
	}
	for (long long k = 0; k < length; k++) {
		vec[inicio + k] = aux[k];
	}
}

void sort(vector<Fila*> &vec, int i, int f, string nombreColumna) {
	if (i < f) {
		int mid = (f + i) / 2;
		sort(vec, i, mid, nombreColumna);
		sort(vec, mid + 1, f, nombreColumna);
		merge(vec, i, f, nombreColumna);
	}
}
