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

  //
  Almacen(const std::string &archivoProductos) { 
    cargarProductosDesdeArchivo(archivoProductos);
  }

  std::vector<Producto> &getProductos() { return productos; }
  const std::vector<Producto> &getProductos() const { return productos; }

  void mostrarTodosLosProductos() {
    std::cout << "ID\tNombre\t\tPrecio\tCategoria\tStock\n";
    for (const auto &producto : productos) {
      std::cout << producto.id << "\t" << producto.nombre << "\t"
                << producto.precio << "\t" << producto.categoria << "\t"
                << producto.stock << "\n";
    }
  }

  void ordenarPorPrecio(int inicio, int fin) {
    if (inicio < fin) {
      int pivote = particionPorPrecio(inicio, fin);
      ordenarPorPrecio(inicio, pivote - 1);
      ordenarPorPrecio(pivote + 1, fin);
    }
  }

  void ordenarPorNombre(int inicio, int fin);

private:
  int particionPorNombre(int inicio, int fin);

  std::vector<Producto> productos;

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

  void intercambiarProductos(Producto &a, Producto &b) {
    Producto temp = a;
    a = b;
    b = temp;
  }

  int particionPorPrecio(int inicio, int fin) {
    double pivote = productos[fin].precio;
    int i = inicio - 1;

    for (int j = inicio; j <= fin - 1; j++) {
      if (productos[j].precio < pivote) {
        i++;
        intercambiarProductos(productos[i], productos[j]);
      }
    }

    intercambiarProductos(productos[i + 1], productos[fin]);
    return i + 1;
  }
};

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

void Almacen::ordenarPorNombre(int inicio, int fin) {
  if (inicio < fin) {
    int pivote = particionPorNombre(inicio, fin);
    ordenarPorNombre(inicio, pivote - 1);
    ordenarPorNombre(pivote + 1, fin);
  }
}

#endif // ALMACEN_H
