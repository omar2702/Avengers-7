#include <iostream>
#include <conio.h>
#include"DataFrame.h"
#include <ctime>

using namespace std;

int main() {

	srand(time(NULL)); //Para crear valores aleatorios

	/*

	dataframe* d1 = new dataframe();

	row* r1 = new row(0);

	column* co1 = new column("valor");

	column* co2 = new column("doble");

	column* co3 = new column("largo");

	column* co4 = new column("simbolo");

	cell* c = new cell("value1");

	cell* c2 = new cell("8.945");

	cell* c3 = new cell("51399874603214");

	cell* c4 = new cell("==+%#*&");

	r1->push_back(c);

	r1->push_back(c2);

	r1->push_back(c3);

	r1->push_back(c4);

	d1->push_back(r1);

	co1->push_back(&c);

	co2->push_back(&c2);

	co3->push_back(&c3);

	co4->push_back(&c4);



	cout << r1->getIndex() << "\t" << r1->at(0)->getType() << "\t" << r1->at(0)->getDataS()<<endl;

	cout << r1->getIndex() << "\t" << r1->at(1)->getType() << "\t" << r1->at(1)->getDataD() << endl;

	cout << r1->getIndex() << "\t" << r1->at(2)->getType() << "\t" << r1->at(2)->getDataS() << endl;

	cout << r1->getIndex() << "\t" << r1->at(2)->getType() << "\t" << r1->at(2)->getDataL() << endl;

	cout << r1->getIndex() << "\t" << r1->at(3)->getType() << "\t" << r1->at(3)->getDataS() << endl;

	cout << co1->getName() << "\t" << co1->at(0)->getDataS() << endl;

	cout << co2->getName() << "\t" << co2->at(0)->getDataD() << endl;

	cout << co3->getName() << "\t" << co3->at(0)->getDataL() << endl;

	cout << co4->getName() << "\t" << co4->at(0)->getDataS() << endl;

	*/



	//driver* driver1 = new driver();

	//driver1->addFile("exampledb.csv"); //

	//

	////cout<<driver1->mdataframe.atCo(0)->at(0)->getDataS();

	//driver1->print();



	//Código que se utilizaba con las clases anteriores (Cell.h, Row.h, Dataframe.h) se conserva porque

	//posteriormente se usará la parte de manejo de archivos





	DataFrame *dataF = new DataFrame();

	dataF->agregar_Fila();

	dataF->agregar_Fila();

	dataF->mostrar();


	_getch();
	return 0;
}