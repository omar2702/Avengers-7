Informe del Trabajo Final del curso de Algoritos y Estrcutura de Datos.
=======================================================================

I) Intruducción
---------------
a)Motivación:
Nuestra motivación consiste en desarrollar una biblioteca que nos permita el manejo de Data Frames, esto es lograble gracias a los conocimientos adquiridos en el curso de Algoritmos y Estructura de Datos los cuales nos permitirán desarrollar esto. Esta biblioteca nos permitirá buscar dependiendo de los datos o parámetros que el usuario escoja. Además que nos permitirá hacer inventarios en el desarrollo de una biblioteca para el manejo de Data Frames es considerado esencial en anejo de estructura de datos, sabiendo que los datos que almacenará este pueden ser varios y en grandes cantidades. El desarrollo de esta biblioteca está fundamentado en la utilización de textos planos para exportar e importar, para la búsqueda de datos en columnas y también en filas.

b)Problema:
En la actualidad existen diversas bibliotecas que nos permiten de alguna manera el uso de datos a grandes escalas pero a lo que se punta este proyecto es lograr lo mencionado anteriormente pero de un manera óptima y sobre todo eficiente, debido a la urgencia de evitar grandes pérdidas de dinero. Por ello es que mediante el desarrollo de nuestro pensamiento innovador, al momento de diseñar una biblioteca c++ para el manejo de dataframes teniendo en cuenta las restricciones impuestas por los recursos computacionales.

c)Solución:
Implementar listas doblemente enlazadas simples podemos desear recorrer la lista hacia adelante y hacia atrás, o dado un elemento, podemos desear conocer rápidamente los elementos anterior y siguiente. En tales situaciones podríamos desear darle a cada celda sobre una lista un puntero a las celdas siguiente y anterior en la lista tal. Otra ventaja de las listas doblemente enlazadas es que podemos usar un puntero a la celda que contiene el i-ésimo elemento de una lista para representar la posición i, mejor que usar el puntero a la celda anterior aunque lógicamente, también es posible la implementación similar a la expuesta en las listas simples haciendo uso de la cabecera. El único precio que pagamos por estas características es la presencia de un puntero adicional en cada celda y consecuentemente procedimientos algo más largos para algunas de las operaciones básicas de listas.

d)Conclusión:

II)Objetivos
------------

III)Marco Teorico
-----------------
I.   DataFrame, es una hoja de datos, en lo que cada fila corresponde a un sujeto y cada columna a una variable. La estructura de un DataFrame es muy similar a la de una matriz. La diferencia es que una matríz sólo admite valores numéricos, mientras que un DataFrame podemos incluir datos alfanuméricos.

II.	 Árbol, un árbol consta de un conjunto finito de elementos, denominados nodo y un conjunto finito de líneas dirigidas, denominadas ramas, que conectan los nodos.

III. Árbol Binario, es un árbol de orden 2. Se conoce el nodo de la izquierda como hijo izquierdo y el nodo de la derecha como hijo derecho. Un árbol binario es una estructura recursiva. Se divide en tres subconjuntos disjuntos:
a)	Nodo raíz
b)	Subárbol izquierdo
c)	Subárbol derecho
               Para ello necesitaos la estructura del Nodo que es lo siguie

struct{ int elem; Nodo *der; Nodo *izq;
___
Sabiendo esto la estructura del árbol binario es lo siguiente:

