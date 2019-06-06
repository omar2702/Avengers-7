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
En vase a lo que hemos aprendido, podemos crear base de datos eficientes que son problemas actuales de mayor requisito para varias empresas.

II)Objetivos
------------
•	Describir que es indexación en base-0.

•	Manipular y extraer datos usando encabezados de columnas e índices.

•	Usar ‘slicing’ para seleccionar conjuntos de datos de un ‘DataFrame’.

•	Emplear etiquetas e índices enteros para seleccionar rangos de datos en un ‘DataFrame’.

•	Reasignar valores dentro de subconjuntos de datos de un ‘DataFrame’.

•	Crear una copia de un ‘DataFrame’.

•	Consultar/Seleccionar un subconjunto de datos usando un conjunto de criterios utilizando los siguientes operadores: =, !=, >, <, >=, <=.


III)Marco Teorico
-----------------
I.DataFrame, es una hoja de datos, en lo que cada fila corresponde a un sujeto y cada columna a una variable. La estructura de un DataFrame es muy similar a la de una matriz. La diferencia es que una matríz sólo admite valores numéricos, mientras que un DataFrame podemos incluir datos alfanuméricos.

II.Árbol, un árbol consta de un conjunto finito de elementos, denominados nodo y un conjunto finito de líneas dirigidas, denominadas ramas, que conectan los nodos.

III.Árbol Binario, es un árbol de orden 2. Se conoce el nodo de la izquierda como hijo izquierdo y el nodo de la derecha como hijo derecho. Un árbol binario es una estructura recursiva. Se divide en tres subconjuntos disjuntos:
a)	Nodo raíz
b)	Subárbol izquierdo
c)	Subárbol derecho
       
IV.Árbol Binario de búsqueda (ABB), no tiene valores duplicados en los nodos y además, tiene la característica de que:
1.	Los valores en cualquier subárbol izquierdo son menores que el valor en su nodo padre.
2.	Los valores en cualquier subárbol derecho son mayores que el valor en su nodo padre.
Es una de las tantas formas de indexar la información, se usa más en bases de datos para poder ejecutar las querys más rápido.
El sistema responde más rápido por que no tiene que hacer validaciones por cada elemento, sino más bien por bloques, si el criterio especificado entra en el rango de este nodo corresponde entonces miro adentro para sustraerlo.

V.Ordenamiento de vectores, debido a que las estructuras de datos son utilizadas para almacenar información, para poder recuperar esa información de manera eficiente es deseable que aquella esté ordenada. Existen varios métodos para ordenar las diferentes estructuras de datos básicas.
Hay métodos muy simples de implementar que son útiles en los casos en dónde el número de elementos a ordenar no es muy grande (ejemplo, menos de 500 elementos). Por otro lado hay métodos sofisticados, más difíciles de implementar pero que son más eficientes en cuestión de tiempo de ejecución
Los métodos simples son: insertion sort (o por inserción directa) selection sort, bubble sort, y shellsort, en dónde el último es una extensón al insertion sort, siendo más rápido. Los métodos más complejos son el quick-sort, el heap sort, radix y address-calculation sort. El ordenar un grupo de datos significa mover los datos o sus referencias para que queden en una secuencia tal que represente un orden, el cual puede ser numérico, alfabético o incluso alfanumérico, ascendente o descendente.


IV) Cronograma
---------------
Los cronogramas podran ser visualizados en Github Milestones

VI) Plan de trabajo detallado
-----------------------------
El proyeto estará disponible para todos los integrantes del grupo; no obsante, constará de 3 copias y uno principal gracias a que GitHub nos permite crear nuevas ramas podemos cambiar el código continuamente y mostralo a los demás integrantes del grupo. Ademas de esto, GitHub nos permite utilizar herramientas como los milestones e issues los cuales nos permitiran asignar tareas y completarlas progresivamente. Los milestones son tareas en paquetes, de esta manera estarán elaborados los entregables e hitos se encontraran dentro de los issues. De esta manera nuestro plan de trabajo serpa eficiente y podremos ver el avance de cada integrante.
