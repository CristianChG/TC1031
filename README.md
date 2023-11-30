# TC1031


# Proyecto: Almacen de productos
El proyecto consiste en un sistema de almacenamiento que utiliza un árbol AVL para organizar y gestionar productos. Los productos se cargan desde un archivo CSV al inicio del programa y se almacenan en un vector. Cada producto tiene información como ID, nombre, precio, categoría y stock.
El sistema ofrece diversas funcionalidades, como mostrar todos los productos, ordenarlos por diferentes criterios (ID, nombre, precio), buscar un producto por su ID, introducir un nuevo producto, eliminar un producto por su ID y modificar la información de un producto existente.
La implementación del árbol AVL permite una búsqueda eficiente de productos por ID, así como la capacidad de mantener el conjunto de productos ordenado según el ID. El programa también gestiona la persistencia de los datos, guardando los cambios en el archivo CSV al agregar, eliminar o modificar productos.
El menú principal del programa guía al usuario a través de las diferentes opciones disponibles, proporcionando una interfaz para interactuar con el sistema de almacenamiento.

## Descripción del avance 1

Mostrar todos los productos:

Funcionamiento:
Esta opción muestra en la consola toda la información de los productos almacenados en el vector de productos del almacén. Recorre el vector y presenta los detalles de cada producto, incluyendo ID, nombre, precio, categoría y stock.
Método asociado: mostrarTodosLosProductos()
Complejidad: O(n), donde n es el número de productos. La complejidad es lineal en función del número de productos almacenados, ya que se debe recorrer todo el vector para mostrar cada producto.
Descripción: Recorre el vector de productos e imprime en la consola la información de cada producto de manera formateada.


Mostrar productos ordenados:

Funcionamiento:
Esta opción permite al usuario elegir entre tres criterios de ordenamiento: por ID, por nombre o por precio. Utiliza el algoritmo QuickSort para ordenar el vector de productos según el criterio seleccionado y luego muestra la lista ordenada.
Métodos asociados:
ordenarPorNombre(int inicio, int fin)
ordenarPorPrecio(int inicio, int fin)
Método auxiliar particionPorNombre(int inicio, int fin) para QuickSort por nombre.
Método auxiliar particionPorPrecio(int inicio, int fin) para QuickSort por precio.
Complejidad:
QuickSort por nombre: O(n log n), donde n es el número de productos.
QuickSort por precio: O(n log n), donde n es el número de productos.
Descripción: Utiliza el algoritmo QuickSort para ordenar los productos según el criterio seleccionado. La opción permite ordenar por ID, nombre o precio, brindando flexibilidad al usuario.

Ambas opciones proporcionan al usuario información detallada sobre los productos almacenados. La primera muestra todos los productos sin ningún orden específico, mientras que la segunda opción permite al usuario ordenar la lista según diferentes criterios, mejorando la usabilidad y la visualización de la información.

## Descripción del avance 2

Buscar producto:
Funcionamiento:
Esta opción permite al usuario buscar un producto por su ID. Utiliza el árbol AVL para realizar una búsqueda eficiente. Muestra la información del producto si se encuentra o informa al usuario que el producto no existe.
Métodos asociados:
buscarPorID(int idBuscado) en la clase ArbolAVL.
buscarPorID(NodoAVL *nodo, int idBuscado) en la clase ArbolAVL.
Complejidad:
En promedio: O(log n), donde n es el número de productos.
En el peor caso: O(n), donde n es el número de productos (en caso de que el árbol no esté balanceado).
Descripción: Utiliza la propiedad de búsqueda eficiente de los árboles AVL para encontrar un producto por su ID. Muestra la información del producto si se encuentra, de lo contrario, informa al usuario que el producto no existe.


Introducir nuevo producto:
Funcionamiento:
Permite al usuario introducir un nuevo producto con su información, incluyendo ID, nombre, precio, categoría y stock. Agrega el nuevo producto al árbol AVL para mantener la estructura balanceada y lo guarda en el vector de productos y en el archivo de productos CSV.
Métodos asociados:
insertar(const Producto &producto) en la clase ArbolAVL.
insertar(NodoAVL *raiz, const Producto &producto) en la clase ArbolAVL.
cargarProductosDesdeArchivo(const std::string &archivoProductos) en la clase Almacen.
Complejidad:
En promedio (para inserción en árbol AVL): O(log n), donde n es el número de productos.
Para la actualización del archivo CSV y el vector de productos: O(1).
Descripción: Permite al usuario agregar un nuevo producto proporcionando la información necesaria. Utiliza el árbol AVL para mantener la eficiencia en la búsqueda y la inserción y actualiza tanto el vector de productos como el archivo CSV.


Eliminar producto:
Funcionamiento:
Permite al usuario eliminar un producto por su ID. Utiliza el árbol AVL para eliminar el producto de manera eficiente, además de actualizar el vector de productos y el archivo CSV.
Métodos asociados:
eliminar(int id) en la clase ArbolAVL.
eliminar(NodoAVL *raiz, int id) en la clase ArbolAVL.
Complejidad:
En promedio (para eliminación en árbol AVL): O(log n), donde n es el número de productos.
Para la actualización del archivo CSV y el vector de productos: O(n), donde n es el número de productos (debido a la búsqueda y eliminación en el vector).
Descripción: Utiliza el árbol AVL para eliminar eficientemente un producto por su ID. Actualiza el vector de productos y el archivo CSV para reflejar los cambios.
Estas opciones brindan al usuario la capacidad de buscar productos por ID, introducir nuevos productos y eliminar productos existentes, todo de manera eficiente gracias al uso del árbol AVL. Además, se encargan de actualizar tanto la estructura de datos en memoria como la persistencia en el archivo de productos CSV.

### Cambios sobre el primer avance
1. Escribe la lista de cambios realizados sobre el planteamiento original: Argumenta la razón por la que decidiste el cambio. Estos argumentos puedes retomarlos más adelante en tu argumentación de competencias.
2. Cambio 2: Razón del cambio
3. Cambio 3: Razón del cambio
4. etc...: etc...

## Descripción del avance 3
Modificar producto:
Funcionamiento:
Esta opción permite al usuario modificar la información de un producto existente, identificado por su ID. Utiliza el árbol AVL para buscar eficientemente el producto por su ID, realiza la modificación tanto en el árbol como en el vector de productos y actualiza el archivo CSV.
Métodos asociados:
buscarPorID(int idBuscado) en la clase ArbolAVL.
buscarPorID(NodoAVL *nodo, int idBuscado) en la clase ArbolAVL.
eliminar(int id) en la clase ArbolAVL (para eliminar el producto antes de la modificación).
insertar(const Producto &producto) en la clase ArbolAVL (para insertar el producto modificado).
Complejidad:
En promedio (para búsqueda y modificación en árbol AVL): O(log n), donde n es el número de productos.
Para la actualización del archivo CSV y el vector de productos: O(n), donde n es el número de productos (debido a la búsqueda y eliminación en el vector).
Descripción: Utiliza el árbol AVL para buscar eficientemente un producto por su ID, permite al usuario seleccionar el atributo a modificar (nombre, precio, categoría o stock) y actualiza tanto el árbol como el vector de productos y el archivo CSV con los cambios realizados.
Descripción completa del Árbol AVL y su interacción con el Main:

Árbol AVL:
Descripción:
Un árbol AVL es un tipo de árbol binario de búsqueda que se autogestiona para mantener su equilibrio. Cada nodo en el árbol AVL tiene un factor de equilibrio asociado, que es la diferencia entre las alturas de sus subárboles izquierdo y derecho. El factor de equilibrio de cada nodo debe ser -1, 0 o 1 para que el árbol sea AVL. Si esta propiedad se viola después de una inserción o eliminación, se realizan rotaciones para restaurar el equilibrio.
Métodos y propiedades:
insertar(const Producto &producto): Inserta un nuevo nodo en el árbol AVL manteniendo su balance. Se utiliza para agregar productos al árbol.
eliminar(int id): Elimina un nodo del árbol AVL según el ID del producto. Se utiliza para eliminar productos del árbol.
buscarPorID(int idBuscado): Busca un nodo en el árbol AVL según el ID del producto. Se utiliza para buscar productos por ID.
recorridoInorden(): Realiza un recorrido inorden del árbol AVL, que proporciona los elementos en orden ascendente según sus ID.
rotarIzquierda(NodoAVL *x) y rotarDerecha(NodoAVL *y): Métodos para realizar rotaciones simples en el árbol y mantener el balance.
rebalancear(NodoAVL *nodo): Rebalancea el árbol después de una inserción o eliminación.
Interacción con el Main:

El main() crea una instancia de la clase Almacen, que a su vez carga los productos desde un archivo CSV y los almacena en un vector de productos.
Luego, crea una instancia de la clase ArbolAVL y, mediante un bucle, inserta cada producto en el árbol AVL utilizando el método insertar.
Durante la ejecución del programa, el usuario puede seleccionar la opción para buscar, agregar, eliminar o modificar productos. Estas operaciones se realizan utilizando métodos específicos de la clase ArbolAVL y afectan tanto al árbol como al vector de productos y al archivo CSV.
La opción para mostrar productos ordenados utiliza los métodos de ordenamiento de la clase Almacen y no interactúa directamente con el árbol AVL.
Al finalizar el programa, los cambios realizados en el vector de productos se reflejan en el archivo CSV para persistir la información.

### Cambios sobre el segundo avance
1. Escribe la lista de cambios realizados sobre el planteamiento pasado: Argumenta la razón por la que decidiste el cambio. Estos argumentos puedes retomarlos más adelante en tu argumentación de competencias.
2. Cambio 2: Razón del cambio
3. Cambio 3: Razón del cambio
4. etc...: etc...

## Entrega final
Impleta todas las opciones del menu y hace funcional todo el programa en su totalidad corrigiendo y agregando la mayoria de metodos utilizados en el programa.

### Cambios sobre el tercer avance avance
1. Escribe la lista de cambios realizados sobre el planteamiento pasado: Argumenta la razón por la que decidiste el cambio. Estos argumentos puedes retomarlos más adelante en tu argumentación de competencias.
2. Cambio 2: Razón del cambio
3. Cambio 3: Razón del cambio
4. etc...: etc...

## Instrucciones para compilar el proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp Almacen.cpp ArbolAVL.cpp -o nombre_ejecutable
` 

## Instrucciones para ejecutar el proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance` 

## Descripción de las entradas del avance de proyecto
Archivo de Productos (CSV):

Formato: El archivo de productos es un archivo CSV (Comma-Separated Values) que contiene la información de los productos almacenados. Cada línea representa un producto y contiene campos separados por comas, como ID, nombre, precio, categoría y stock.

Ejemplo:
ID,Nombre,Precio,Categoría,Stock
3087,MacBookAirM2,1.199,Computadoras,150
2035,MacBookAiM2,1.199,Electrónica,60
8734,MacBookProM2,1.999,Computadoras,450


Entradas del Usuario desde la Consola:

El programa interactúa con el usuario a través de la consola, solicitando información como opciones del menú, ID de productos a buscar, modificar o eliminar, así como los datos de nuevos productos a introducir.

Ejemplos:
Menú de opciones:
1. Mostrar todos los productos
2. Mostrar productos ordenados
3. Buscar producto
4. Introducir nuevo producto
5. Eliminar producto
6. Modificar producto
7. Salir

Salida por Consola:

La salida del programa se presenta en la consola e incluye información como la lista de productos, mensajes de éxito o error al realizar operaciones, y la visualización de productos ordenados.

Ejemplo:

ID   Nombre         Precio   Categoría         Stock
3087 MacBookAirM2   1.199    Computadoras     150
2035 MacBookAiM2    1.199    Electrónica      60
8734 MacBookProM2   1.999    Computadoras     450

Actualización del Archivo de Productos (CSV):

Después de realizar operaciones como agregar, eliminar o modificar productos, el programa actualiza el archivo de productos para reflejar los cambios.

Ejemplo:

ID,Nombre,Precio,Categoría,Stock
3087,MacBookAirM2,1.199,Computadoras,150
2035,MacBookAiM2,1.199,Electrónica,60
8734,MacBookProM2,1.999,Computadoras,450

## Descripción de las salidas del avance de proyecto
El programa proporciona una interfaz de línea de comandos para gestionar un almacén de productos. Aquí hay una descripción de los resultados típicos de la ejecución del programa, según las opciones seleccionadas en el menú:

Mostrar todos los productos:
Imprime en la consola toda la información de los productos almacenados, incluyendo ID, nombre, precio, categoría y stock.

Mostrar productos ordenados:
Permite al usuario elegir entre ordenar los productos por ID, nombre o precio.
Imprime en la consola la lista de productos ordenados según la opción seleccionada.

Buscar producto:
Solicita al usuario que ingrese el ID del producto que desea buscar.
Muestra la información completa del producto si se encuentra.
Indica si el producto no existe.

Introducir nuevo producto:
Pide al usuario que ingrese la información del nuevo producto, incluyendo ID, nombre, precio, categoría y stock.
Agrega el nuevo producto al árbol AVL y al vector de productos.
Actualiza el archivo CSV con la nueva información.

Eliminar producto:
Pide al usuario que ingrese el ID del producto que desea eliminar.
Elimina el producto correspondiente del árbol AVL y del vector de productos.
Actualiza el archivo CSV con la información actualizada.

Modificar producto:
Pide al usuario que ingrese el ID del producto que desea modificar.
Muestra la información actual del producto y permite al usuario seleccionar qué atributo modificar (nombre, precio, categoría o stock).
Realiza la modificación tanto en el árbol AVL como en el vector de productos.
Actualiza el archivo CSV con la información actualizada.

Salir:
Finaliza la ejecución del programa.

Resultados Adicionales:
Cada vez que se realiza una operación que afecta al árbol AVL, se puede observar la salida de los productos ordenados según sus ID, gracias al recorrido inorden del árbol.
Se proporcionan mensajes informativos para confirmar el éxito de las operaciones o para indicar si se encuentra algún problema, como un producto no encontrado o un ID duplicado al intentar agregar un nuevo producto.

Ejemplo de Ejecución:
A continuación, se presenta un ejemplo simplificado de cómo podría verse la ejecución del programa:

Bienvenido al sistema de almacenamiento

Menú de opciones:
1. Mostrar todos los productos
2. Mostrar productos ordenados
3. Buscar producto
4. Introducir nuevo producto
5. Eliminar producto
6. Modificar producto
7. Salir

Elija una opción: 1

ID    Nombre      Precio  Categoría   Stock
1234  ApplePencil  8.66    Accesorio    40
1459  AirTag      39.00   Electrónica  200


Menú de opciones:
1. Mostrar todos los productos
2. Mostrar productos ordenados
3. Buscar producto
4. Introducir nuevo producto
5. Eliminar producto
6. Modificar producto
7. Salir

Elija una opción: 4

Ingrese el ID del nuevo producto: 9999
Ingrese el nombre del nuevo producto: NuevoProducto
Ingrese el precio del nuevo producto: 99.99
Ingrese la categoría del nuevo producto: NuevaCategoría
Ingrese el stock del nuevo producto: 10

Nuevo producto agregado con éxito.



## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Si lograste este criterio anteriormente, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Estructuras de Datos
Arbol AVL:

Inserción:
Mejor caso: O(log n)
Promedio caso: O(log n)
Peor caso: O(log n)
Justificación: La inserción en un árbol AVL tiene una complejidad logarítmica ya que se 
equilibra después de cada inserción.

Búsqueda por ID:
Mejor caso: O(log n)
Promedio caso: O(log n)
Peor caso: O(log n)
Justificación: La búsqueda en un árbol AVL también tiene una complejidad logarítmica debido a la estructura balanceada del árbol.

Eliminación:
Mejor caso: O(log n)
Promedio caso: O(log n)
Peor caso: O(log n)
Justificación: La eliminación en un árbol AVL tiene una complejidad logarítmica ya que se equilibra después de cada eliminación.
Vector de Productos:

Acceso y Modificación:
Mejor caso: O(1)
Promedio caso: O(1)
Peor caso: O(1)
Justificación: Los vectores ofrecen acceso y modificación en tiempo constante debido a su estructura de arreglo contiguo.

Operaciones Principales

Mostrar Todos los Productos:
Complejidad: O(n)
Justificación: Necesita iterar a través de todos los productos para mostrarlos.

Ordenar Productos por Nombre (QuickSort):
Mejor caso: O(n log n)
Promedio caso: O(n log n)
Peor caso: O(n^2)
Justificación: QuickSort tiene complejidad O(n log n) en promedio, pero puede degradarse a O(n^2) en el peor caso.

Ordenar Productos por Precio (QuickSort):
Mejor caso: O(n log n)
Promedio caso: O(n log n)
Peor caso: O(n^2)
Justificación: Igual que la ordenación por nombre.

Insertar Nuevo Producto:
Complejidad: O(log n)
Justificación: La inserción en el árbol AVL tiene una complejidad logarítmica.

Eliminar Producto:
Complejidad: O(log n)
Justificación: La eliminación en el árbol AVL tiene una complejidad logarítmica.

Modificar Producto:
Complejidad: O(log n)
Justificación: La modificación implica buscar y actualizar un nodo en el árbol AVL, que tiene una complejidad logarítmica.

Ciclo Principal (Menú) - while (opcion != 7)
Complejidad: O(?)

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
Carga de productos desde el archivo al vector en el constructor de Almacen:

Complejidad: O(n), donde n es el número de productos en el archivo.
Justificación: El constructor de Almacen utiliza un bucle while para leer cada línea del archivo y luego un bucle for para procesar cada producto.

Mostrar todos los productos en mostrarTodosLosProductos():
Complejidad: O(n), donde n es el número de productos.
Justificación: El método recorre todos los productos e imprime su información linealmente.

Ordenar productos por precio (QuickSort) en ordenarPorPrecio():
Complejidad: O(n log n), donde n es el número de productos.
Justificación: El algoritmo QuickSort tiene un tiempo promedio de O(n log n) para ordenar n elementos.

Ordenar productos por nombre (QuickSort) en ordenarPorNombre():
Complejidad: O(n log n) en el mejor caso y O(n^2) en el peor caso.
Justificación: El algoritmo QuickSort tiene un tiempo promedio de O(n log n), pero en el peor caso (cuando la lista ya está ordenada), la complejidad puede llegar a ser O(n^2).

Búsqueda de producto por ID en el árbol AVL en buscarPorID():
Complejidad: O(log n), donde n es el número de nodos en el árbol.
Justificación: La búsqueda en un árbol AVL tiene una complejidad logarítmica en función del número de nodos en el árbol.

Inserción de un nuevo producto en el árbol AVL en insertar():
Complejidad: O(log n), donde n es el número de nodos en el árbol.
Justificación: La inserción en un árbol AVL tiene una complejidad logarítmica en función del número de nodos en el árbol.

Eliminación de un producto en el árbol AVL en eliminar():
Complejidad: O(log n), donde n es el número de nodos en el árbol.
Justificación: La eliminación en un árbol AVL tiene una complejidad logarítmica en función del número de nodos en el árbol.

Rotaciones y rebalanceo en el árbol AVL:
Complejidad: O(1) por rotación y rebalanceo.
Justificación: Cada rotación y rebalanceo en el árbol AVL es una operación constante.

Modificar producto en el árbol AVL y en el vector en main():
Complejidad: O(log n) para buscar el nodo y O(1) para modificar el producto en el vector.
Justificación: La búsqueda en el árbol AVL tiene una complejidad logarítmica y la modificación en el vector es constante.

Inserción de productos en el archivo en main():
Complejidad: O(1) en el mejor caso (cuando el archivo se abre correctamente y se escribe al final del archivo).
Justificación: La apertura y escritura en un archivo generalmente tiene una complejidad constante.

Eliminación de productos del archivo en main():
Complejidad: O(n) en el peor caso (cuando se elimina un producto y se reescribe el archivo).
Justificación: La eliminación implica reescribir el archivo sin el producto eliminado.

Carga de productos desde el archivo en cargarProductosDesdeArchivo():
Complejidad: O(n), donde n es el número de líneas en el archivo.
Justificación: Este método carga los productos desde el archivo y tiene una complejidad lineal.

Métodos rotarDerecha() y rotarIzquierda() en el árbol AVL:
Complejidad: O(1).
Justificación: Estas operaciones son rotaciones simples y tienen una complejidad constante.

Búsqueda del mínimo valor en minimoValor() en el árbol AVL:
Complejidad: O(log n), donde n es el número de nodos en el árbol.
Justificación: La búsqueda del mínimo valor en un árbol AVL tiene una complejidad logarítmica.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
En el proyecto, se han utilizado dos algoritmos de ordenamiento: QuickSort y el algoritmo de ordenamiento AVL. Analicemos cada uno y justifiquemos su elección:

QuickSort:
Justificación:
El QuickSort se utiliza para ordenar productos por precio y por nombre en el almacén. Este algoritmo es eficiente en términos de tiempo y generalmente supera a otros algoritmos de ordenamiento, como el MergeSort y el BubbleSort, en términos de velocidad en la práctica.
La complejidad promedio de QuickSort es O(nlogn), lo que lo hace adecuado para grandes conjuntos de datos, como la lista de productos en un almacén.

Cómo se usa:
La implementación del QuickSort en el programa ordena los productos por precio y nombre. El método ordenarPorPrecio se utiliza para ordenar por precio, mientras que el método ordenarPorNombre se utiliza para ordenar por nombre. Estos métodos son llamados desde el menú de opciones del programa.

Comparación con otros algoritmos:
En comparación con algoritmos como el BubbleSort, que tiene una complejidad de O(n^2), y el MergeSort, que tiene una complejidad promedio de O(n log n), el QuickSort ofrece un rendimiento rápido y es preferido para grandes conjuntos de datos.

Algoritmo de ordenamiento AVL:
Justificación:
Se utiliza para mantener una estructura de datos ordenada (un árbol AVL) que permite búsquedas eficientes y proporciona un mecanismo de inserción y eliminación equilibrado.
El árbol AVL mantiene el equilibrio automáticamente, lo que garantiza que las operaciones de búsqueda, inserción y eliminación tengan una complejidad de tiempo promedio de O(log n).
Cómo se usa:
El árbol AVL se utiliza para la búsqueda de productos por ID, la inserción de nuevos productos y la eliminación de productos existentes. Además, se realiza un recorrido inorden del árbol AVL para mostrar los productos ordenados en ciertas operaciones.
Comparación con otros algoritmos:
En comparación con las listas enlazadas y los arrays, la estructura del árbol AVL garantiza tiempos de búsqueda eficientes, incluso en peores casos, gracias a su estructura balanceada. Las operaciones de búsqueda y modificación son más rápidas que en una lista o un array no ordenado.

Ambos algoritmos seleccionados son apropiados para el problema. QuickSort es eficiente para ordenar grandes conjuntos de datos, como la lista de productos. El algoritmo de ordenamiento AVL se adapta bien a las operaciones de búsqueda, inserción y eliminación, garantizando un rendimiento eficiente en términos de tiempo logarítmico para estas operaciones. La elección de estos algoritmos se basa en la eficiencia y la complejidad de tiempo, ofreciendo un equilibrio adecuado para las operaciones específicas del programa.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.

El proyecto utiliza una estructura de datos central que es fundamental para su funcionamiento: el Árbol AVL. Esta elección de estructura de datos es apropiada y se justifica de la siguiente manera:

Árbol AVL:
Justificación:
El Árbol AVL es una estructura de datos de tipo árbol de búsqueda binaria que garantiza un balanceo automático. Este equilibrio asegura que la altura de las ramas izquierda y derecha de cada nodo no difiera en más de uno, lo que resulta en operaciones eficientes de búsqueda, inserción y eliminación.
En el contexto del proyecto, donde se realizan operaciones frecuentes de búsqueda por ID, inserción y eliminación de productos, el Árbol AVL ofrece un equilibrio óptimo entre eficiencia y complejidad.

Comparación con otras estructuras de datos:
En comparación con una lista enlazada o un array no ordenado, el Árbol AVL garantiza tiempos de búsqueda eficientes incluso en peores casos. Las operaciones de búsqueda, inserción y eliminación tienen una complejidad logarítmica promedio de O(logn), lo que es más eficiente que las operaciones lineales de O(n) en listas y arrays no ordenados.

Contexto del proyecto:
El Árbol AVL se utiliza para buscar productos por su ID, lo cual es una operación crítica en el manejo de productos en un almacén. La estructura equilibrada del Árbol AVL garantiza que estas operaciones se realicen eficientemente incluso a medida que crece el conjunto de datos.

Interacción con el programa:
El Árbol AVL se utiliza en operaciones clave del programa, como la búsqueda por ID, la inserción de nuevos productos y la eliminación de productos existentes. Además, se realiza un recorrido inorden del árbol para mostrar los productos ordenados en ciertas operaciones.


La elección del Árbol AVL como estructura de datos principal es acertada para el contexto del proyecto. Garantiza tiempos de búsqueda eficientes, inserciones y eliminaciones balanceadas, lo que es esencial para operaciones frecuentes en un sistema de gestión de almacén. La complejidad logarítmica de estas operaciones en un Árbol AVL proporciona un equilibrio óptimo entre rendimiento y eficiencia en comparación con otras estructuras de datos disponibles

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.


El proyecto implementa mecanismos adecuados para consultar información de las estructuras, especialmente a través del uso del Árbol AVL. 

Búsqueda de productos por ID:
Implementación:
El proyecto utiliza el Árbol AVL para realizar búsquedas eficientes por ID. La función buscarPorID en la clase ArbolAVL se encarga de realizar esta búsqueda.
Cuando se busca un producto por su ID desde el menú del programa, se invoca la función buscarPorID del Árbol AVL, que realiza la búsqueda y devuelve el nodo correspondiente si el producto está presente.
Eficiencia y Complejidad:

La estructura de Árbol AVL garantiza que la búsqueda por ID tenga una complejidad logarítmica promedio de O(logn), lo que asegura un rendimiento eficiente incluso para grandes conjuntos de productos.

Inserción de nuevos productos:
Implementación:
La inserción de nuevos productos se realiza tanto en el vector de productos como en el Árbol AVL. Se utiliza la función insertar en la clase ArbolAVL para agregar el nuevo producto al árbol.
Eficiencia y Complejidad:
La inserción en el Árbol AVL tiene una complejidad logarítmica promedio de  O(logn), asegurando un rendimiento eficiente al agregar nuevos productos al almacén.

Eliminación de productos existentes:
Implementación:
La eliminación de productos se lleva a cabo tanto en el vector de productos como en el Árbol AVL. La función eliminar en la clase ArbolAVL se encarga de eliminar el producto correspondiente del árbol.

Eficiencia y Complejidad:
La eliminación en el Árbol AVL también tiene una complejidad logarítmica promedio de O(logn), proporcionando un mecanismo eficiente para gestionar la eliminación de productos del almacén.
Recorrido Inorden para mostrar productos ordenados:

Implementación:
El programa utiliza un recorrido inorden del Árbol AVL para mostrar productos ordenados por ID en ciertas operaciones del menú.
Eficiencia y Complejidad:

El recorrido inorden del Árbol AVL tiene una complejidad lineal de O(n), donde n es el número de productos en el almacén. Dado que es una operación ocasional y no afecta directamente la eficiencia de las operaciones principales, es aceptable en este contexto.

El proyecto cumple con la implementación de mecanismos para consultar información de las estructuras de manera adecuada. La elección de utilizar un Árbol AVL para la búsqueda por ID, inserción y eliminación garantiza operaciones eficientes, mientras que el uso de recorridos inorden proporciona una forma ordenada de mostrar la información cuando es necesario. La implementación respeta los principios de eficiencia y complejidad al aprovechar las características inherentes de las estructuras de datos utilizadas.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
El proyecto implementa mecanismos de lectura de archivos de manera adecuada para cargar datos en las estructuras de manera eficiente y precisa. Aquí se detallan las razones por las cuales esta implementación es correcta y beneficia al proyecto:

Uso de Archivos CSV:
Implementación:
La carga de datos se realiza desde un archivo CSV (Productos.csv).
La función cargarProductosDesdeArchivo en la clase Almacen se encarga de leer las líneas del archivo CSV, interpretar los datos y cargarlos en el vector de productos.
Eficiencia y Precisión:

El formato CSV es apropiado para representar datos tabulares como los productos en este contexto. Facilita la lectura y escritura de datos, y es ampliamente compatible con herramientas externas.
La implementación del método considera el formato esperado del archivo y realiza una interpretación precisa de los datos, asegurando que se asignen correctamente a los atributos de la estructura Producto.
Lectura desde el Archivo al Iniciar el Programa:

Implementación:
La carga de productos desde el archivo se realiza en el constructor de la clase Almacen al iniciar el programa.
La función cargarProductosDesdeArchivo se encarga de abrir el archivo, leer las líneas y cargar los productos en el vector.
Eficiencia y Complejidad:

La lectura del archivo al inicio del programa garantiza que los datos estén disponibles en las estructuras de datos desde el principio, evitando la necesidad de cargarlos repetidamente durante la ejecución.
La complejidad de la lectura desde el archivo es lineal (O(n), donde n es el número de líneas en el archivo), pero esto es aceptable ya que se realiza solo una vez al inicio del programa.
Actualización de Estructuras de Datos:

Implementación:
Después de cargar los datos desde el archivo, se insertan en el Árbol AVL para facilitar operaciones eficientes de búsqueda y ordenamiento.

Eficiencia y Utilidad:
La actualización del Árbol AVL con los datos del archivo proporciona un mecanismo eficiente para realizar operaciones como búsqueda, inserción y eliminación durante la ejecución del programa.
La elección de utilizar una estructura de árbol balanceado refuerza la eficiencia en estas operaciones.

El proyecto cumple de manera efectiva con la implementación de mecanismos de lectura de archivos para cargar datos en las estructuras de manera correcta. La elección del formato CSV, la interpretación precisa de los datos y la actualización eficiente de las estructuras de datos garantizan que el programa pueda trabajar de manera efectiva con la información almacenada en el archivo, contribuyendo a la funcionalidad integral del sistema.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
El proyecto implementa mecanismos de escritura de archivos de manera adecuada para guardar los datos de las estructuras de manera correcta. Aquí se detallan las razones por las cuales esta implementación es correcta y beneficia al proyecto:

Escritura en Formato CSV:
Implementación:
La escritura de datos se realiza en un archivo CSV (Productos.csv) para mantener la consistencia en el formato de entrada y salida.
La función de escritura se encuentra en varios lugares del código, como al introducir un nuevo producto, eliminar un producto o modificar un producto.

Consistencia y Claridad:
La elección de utilizar un formato CSV para la escritura de datos proporciona consistencia con el formato de entrada y facilita la interpretación de los datos por parte de otras herramientas.
La implementación asegura que los datos se almacenen de manera ordenada y estructurada en el archivo, lo que contribuye a la legibilidad y comprensión de los datos.
Escritura al Modificar, Eliminar o Introducir Productos:

Implementación:
Después de realizar operaciones de modificación, eliminación o introducción de nuevos productos, se actualiza el archivo CSV con los datos actualizados.
Persistencia de Datos:
La escritura inmediata en el archivo después de realizar cambios en las estructuras de datos garantiza la persistencia de la información.
Esto asegura que los cambios realizados durante la ejecución del programa se reflejen de manera consistente en el archivo, manteniendo la integridad de los datos.
Eficiencia y Complejidad:

Implementación:
La escritura en el archivo se realiza de manera eficiente, evitando la necesidad de recorrer toda la estructura de datos para cada escritura.
Se utiliza el operador de flujo ofstream para escribir directamente en el archivo.

Minimización de Operaciones:
La escritura directa en el archivo después de operaciones específicas minimiza la cantidad de operaciones de escritura, mejorando la eficiencia del programa.
La complejidad de estas operaciones depende de la cantidad de productos afectados, pero en general, sigue siendo eficiente.

La implementación de mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta en formato CSV es adecuada y beneficiosa para el proyecto. La elección de formato, la consistencia en la escritura y la eficiencia en la actualización del archivo contribuyen a la funcionalidad integral del sistema, asegurando que los datos se mantengan persistentes y disponibles para futuras ejecuciones del programa.
