#include <iostream>
#include <conio.h>
#include"Driver.h"

#include <ctime>

using namespace std;

void e() {
	cout << endl;
}

int main() {


	Columna* c1 = new Columna("Nombres", 0);

	c1->agregar("Hector");

	c1->agregar("Hector");

	c1->agregar("Juan");

	c1->agregar("Carlos");

	Columna* c2 = new Columna("Telefono", 1);

	c2->agregar("998562311");

	c2->agregar("998562311");

	c2->agregar("997543245");

	c2->agregar("946336751");

	Fila* f1 = new Fila(0);

	Fila* f2 = new Fila(1);

	Fila* f3 = new Fila(2);

	f1->a�adir_Col(c1);

	f1->a�adir_Col(c2);

	f2->a�adir_Col(c1);

	f2->a�adir_Col(c2);

	f3->a�adir_Col(c1);

	f3->a�adir_Col(c2);

	cout << f1->getData("Nombres"), e();

	cout << f1->getData("Telefono"), e();

	cout << f2->getData("Nombres"), e();

	cout << f2->getData("Telefono"), e();

	cout << f3->getData("Nombres"), e();

	cout << f3->getData("Telefono"), e();

	

	DataFrame* d1 = new DataFrame("Dataframe1");

	Columna* c1 = new Columna("Nombres", 0);

	Columna* c2 = new Columna("Apellidos", 1);

	Columna* c3 = new Columna("Edad", 2);

	Columna* c4 = new Columna("Altura", 3);

	Columna* c5 = new Columna("Vivo", 4);

	Fila* f1 = new Fila(0);

	c1->agregar("Hector");

	c2->agregar("Suzuki");

	c3->agregar("18");

	c4->agregar("1.70");

	c5->agregar("true");

	f1->a�adir_Col(c1);

	f1->a�adir_Col(c2);

	f1->a�adir_Col(c3);

	f1->a�adir_Col(c4);

	f1->a�adir_Col(c5);

	Fila* f2 = new Fila(1);

	c1->agregar("Carlos");

	c2->agregar("Mazzarri");

	c3->agregar("23");

	c4->agregar("1.75");

	c5->agregar("true");

	f2->a�adir_Col(c1);

	f2->a�adir_Col(c2);

	f2->a�adir_Col(c3);

	f2->a�adir_Col(c4);

	f2->a�adir_Col(c5);

	Fila* f3 = new Fila(2);

	c1->agregar("Juan");

	c2->agregar("Leyva");

	c3->agregar("18");

	c4->agregar("1.70");

	c5->agregar("true");

	f3->a�adir_Col(c1);

	f3->a�adir_Col(c2);

	f3->a�adir_Col(c3);

	f3->a�adir_Col(c4);

	f3->a�adir_Col(c5);



	d1->a�adir_columna(c1);

	d1->a�adir_columna(c2);

	d1->a�adir_columna(c3);

	d1->a�adir_columna(c4);

	d1->a�adir_columna(c5);

	d1->a�adir_Fila(f1);

	d1->a�adir_Fila(f2);

	d1->a�adir_Fila(f3);



	d1->PrintD();

	Driver d1;

	/*d1.addFile("exampledb.csv");

	d1.getDF(0)->PrintD(), e();*/

	//cout << d1.getDF(0)->atF(0)->getData("Nombres");

	/*for (auto i = 0; i < d1.getDF(0)->counterFil; i++) {

		for (auto it = d1.getDF(0)->atF(i)->getColmap()->begin(); it != d1.getDF(0)->atF(i)->getColmap()->end(); ++it) {

			cout << (*it).second->getData(i) << " ";

		}

		e();

	}*/

	/*DataFrame* df2 = new DataFrame(d1.getDF(0)->atF(0)->getColmap());

	d1.vDF.push_back(df2);

	d1.getDF(1)->PrintD(), e();

	_getch();*/

	//d1.addFile("FL_insurance_sample.csv");

	//d1.getDF(1)->printD();

	//_getch();
}