#ifndef ALMACEN_H
#define ALMACEN_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Producto {
  int id;
  std::string nombre;
  double precio;
  std::string categoria;
  int stock;
};

class Almacen {
public:
  // Constructor que carga los datos de productos desde un archivo en el vector
  // Complejidad: O(n), donde n es el número de productos en el archivo
  Almacen(const std::string &archivoProductos) {
    cargarProductosDesdeArchivo(archivoProductos);
  }

  // Obtiene una referencia mutable al vector de productos
  std::vector<Producto> &getProductos() { return productos; }

  // Obtiene una referencia constante al vector de productos
  const std::vector<Producto> &getProductos() const { return productos; }

  // Imprime toda la información de los productos
  // Complejidad: O(n), donde n es el número de productos
  void mostrarTodosLosProductos() {
    std::cout << "ID\tNombre\t\tPrecio\tCategoria\tStock\n";
    for (const auto &producto : productos) {
      std::cout << producto.id << "\t" << producto.nombre << "\t"
                << producto.precio << "\t" << producto.categoria << "\t"
                << producto.stock << "\n";
    }
  }

  // Ordena productos por precio utilizando el algoritmo QuickSort
  // Complejidad: O(n log n), donde n es el número de productos
  void ordenarPorPrecio(int inicio, int fin) {
    if (inicio < fin) {
      int pivote = particionPorPrecio(inicio, fin);
      ordenarPorPrecio(inicio, pivote - 1);
      ordenarPorPrecio(pivote + 1, fin);
    }
  }

  // Ordena productos por nombre utilizando el algoritmo QuickSort
  // Complejidad: O(n log n), donde n es el número de productos
  void ordenarPorNombre(int inicio, int fin);

private:
  // Método auxiliar para la partición en el algoritmo QuickSort por precio
  // Complejidad: O(n), donde n es el tamaño del rango a ordenar
  int particionPorPrecio(int inicio, int fin);

  // Vector que almacena los productos
  std::vector<Producto> productos;

  // Método privado para cargar los productos desde un archivo
  // Complejidad: O(n), donde n es el número de líneas en el archivo
  void cargarProductosDesdeArchivo(const std::string &archivoProductos) {
    std::ifstream archivo(archivoProductos);
    if (!archivo.is_open()) {
      std::cerr << "Error al abrir el archivo: " << archivoProductos << "\n";
      return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
      std::istringstream ss(linea);
      Producto producto;
      char comma;

      ss >> producto.id >> comma;
      std::getline(ss, producto.nombre, ',');
      ss >> producto.precio >> comma;
      std::getline(ss, producto.categoria, ',');
      ss >> producto.stock;

      productos.push_back(producto);
    }

    archivo.close();
  }

  // Método auxiliar para intercambiar dos productos
  // Complejidad: O(1)
  void intercambiarProductos(Producto &a, Producto &b) {
    Producto temp = a;
    a = b;
    b = temp;
  }

  // Método auxiliar para la partición en el algoritmo QuickSort por nombre
  // Complejidad: O(n), donde n es el tamaño del rango a ordenar
  int particionPorNombre(int inicio, int fin);
};

// Implementación del método para la partición por nombre en QuickSort
int Almacen::particionPorNombre(int inicio, int fin) {
  std::string pivote = productos[fin].nombre;
  int i = inicio - 1;

  for (int j = inicio; j <= fin - 1; j++) {
    if (productos[j].nombre < pivote) {
      i++;
      intercambiarProductos(productos[i], productos[j]);
    }
  }

  intercambiarProductos(productos[i + 1], productos[fin]);
  return i + 1;
}

// Implementación del método para ordenar por nombre en QuickSort
// Complejidad: O(n log n) mejor caso
// Complejidad: O(n^2) peor caso
void Almacen::ordenarPorNombre(int inicio, int fin) {
  if (inicio < fin) {
    int pivote = particionPorNombre(inicio, fin);
    ordenarPorNombre(inicio, pivote - 1);
    ordenarPorNombre(pivote + 1, fin);
  }
}

#endif // ALMACEN_H
