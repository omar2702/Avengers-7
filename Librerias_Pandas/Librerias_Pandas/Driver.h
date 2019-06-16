#pragma once

#include <fstream>

#include <sstream>

#include "DataFrame.h"

class driver {

public:

	dataframe mdataframe;

public:

	driver() {}

	~driver() {}

	int addFile(string filename) {

		ifstream f(filename);

		string line, num;

		long long counter = 0;

		if (!f.is_open()) {

			cout << endl << "El archivo no se logro abrir" << endl;

			return 0;

		}





		stringstream s(line);

		long long colNum = 0;

		while (getline(s, num, ',')) {

			columna* auxCo = new columna(num.c_str());

			mdataframe.push_backCO(auxCo);

			colNum++;

		}


		while (f >> line) {

			stringstream ss(line);

			fila* auxR = new fila(counter);

			while (getline(ss, num, ',')) {

				camp* auxC = new camp(num.c_str());

				auxR->push_back(auxC);

			}

			mdataframe.push_back(auxR);

			/*

			for (long long i = 0; i < colNum; i++) {

				mdataframe.atCo(i)->push_back(mdataframe.at(counter)->at(i));

			}*/

			counter++;

		}



		f.close();

		/*

		camp* auxC = new cell("value1");

		fila* auxR = new fila(0);

		auxR->push_back(auxC);

		mdataframe.insert(auxR, 0);*/

		return 0;

	}

	//dataframe at() { return mdataframe; }

	void print() {

		mdataframe.PrintD();

	}

};
