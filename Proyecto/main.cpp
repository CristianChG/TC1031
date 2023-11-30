#include "Almacen.h"
#include "ArbolAVL.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  Almacen almacen("Productos.csv");
  ArbolAVL arbol;

  for (const auto &producto : almacen.getProductos()) {
    arbol.insertar(producto);
  }

  int opcion, opcion2, opcion3;
  std::cout << "Bienvenido al sistema de almacenamiento\n";

  while (opcion != 7) {
    std::cout << "\nMenú de opciones:\n";
    std::cout << "1. Mostrar todos los productos\n";
    std::cout << "2. Mostrar productos ordenados\n";
    std::cout << "3. Buscar producto\n";
    std::cout << "4. Introducir nuevo producto\n";
    std::cout << "5. Eliminar producto\n";
    std::cout << "6. Modificar producto\n";
    std::cout << "7. Salir\n";
    std::cout << "Elija una opción: ";
    std::cin >> opcion;

    switch (opcion) {
    case 1:
      almacen.mostrarTodosLosProductos();
      break;
    case 2:
      while (opcion2 != 4) {
        std::cout << "\nOrdenar por:\n";
        std::cout << "1. ID\n";
        std::cout << "2. Nombre\n";
        std::cout << "3. Precio\n";
        std::cout << "4. Volver al menú principal\n";
        std::cout << "Elija una opción: ";
        std::cin >> opcion2;

        switch (opcion2) {
        case 1:
          for (const auto &producto : almacen.getProductos()) {
            arbol.insertar(producto);
          }
          std::cout << "Productos ordenados por ID:\n";
          arbol.recorridoInorden();
          break;
        case 2:
          almacen.ordenarPorNombre(0, almacen.getProductos().size() - 1);
          std::cout << "Productos ordenados por nombre:\n";
          almacen.mostrarTodosLosProductos();
          break;
        case 3:
          almacen.ordenarPorPrecio(0, almacen.getProductos().size() - 1);
          std::cout << "Productos ordenados por precio:\n";
          almacen.mostrarTodosLosProductos();
          break;
        case 4:
          std::cout << "Volviendo al menú principal\n";
          break;
        default:
          std::cout << "Opción no válida. Intente de nuevo.\n";
        }
      }
      break;
    case 3: {
      int idBuscado;
      std::cout << "Ingrese el ID del producto a buscar: ";
      std::cin >> idBuscado;

      NodoAVL *nodoEncontrado = arbol.buscarPorID(idBuscado);

      if (nodoEncontrado != nullptr) {
        std::cout << "Producto encontrado:\n";
        std::cout << "ID: " << nodoEncontrado->producto.id << "\n";
        std::cout << "Nombre: " << nodoEncontrado->producto.nombre << "\n";
        std::cout << "Precio: " << nodoEncontrado->producto.precio << "\n";
        std::cout << "Categoría: " << nodoEncontrado->producto.categoria
                  << "\n";
        std::cout << "Stock: " << nodoEncontrado->producto.stock << "\n";
      } else {
        std::cout << "Producto no encontrado.\n";
      }
      break;
    }
    case 4: {
      Producto nuevoProducto;

      std::cout << "Ingrese el ID del nuevo producto: ";
      std::cin >> nuevoProducto.id;

      if (arbol.buscarPorID(nuevoProducto.id) != nullptr) {
        std::cout << "Error: El ID ya existe. Intente con un ID diferente.\n";
        break;
      }

      std::cout << "Ingrese el nombre del nuevo producto: ";
      std::cin.ignore();
      std::getline(std::cin, nuevoProducto.nombre);

      std::cout << "Ingrese el precio del nuevo producto: ";
      std::cin >> nuevoProducto.precio;

      std::cout << "Ingrese la categoría del nuevo producto: ";
      std::cin.ignore();
      std::getline(std::cin, nuevoProducto.categoria);

      std::cout << "Ingrese el stock del nuevo producto: ";
      std::cin >> nuevoProducto.stock;

      arbol.insertar(nuevoProducto);
      almacen.getProductos().push_back(nuevoProducto);

      std::ofstream archivo("Productos.csv", std::ios::app);
      archivo << nuevoProducto.id << "," << nuevoProducto.nombre << ","
              << nuevoProducto.precio << "," << nuevoProducto.categoria << ","
              << nuevoProducto.stock << "\n";
      archivo.close();

      std::cout << "Nuevo producto agregado con éxito.\n";
      break;
    }

    case 5: {
      int idEliminar;
      std::cout << "Ingrese el ID del producto que desea eliminar: ";
      std::cin >> idEliminar;

      NodoAVL *nodoEliminar = arbol.buscarPorID(idEliminar);

      if (nodoEliminar != nullptr) {
        arbol.eliminar(idEliminar);

        auto it = std::remove_if(almacen.getProductos().begin(),
                                 almacen.getProductos().end(),
                                 [idEliminar](const Producto &producto) {
                                   return producto.id == idEliminar;
                                 });
        almacen.getProductos().erase(it, almacen.getProductos().end());

        std::ofstream archivo("Productos.csv");
        for (const auto &producto : almacen.getProductos()) {
          archivo << producto.id << "," << producto.nombre << ","
                  << producto.precio << "," << producto.categoria << ","
                  << producto.stock << "\n";
        }
        archivo.close();

        std::cout << "Producto eliminado con éxito.\n";
      } else {
        std::cout << "Producto no encontrado.\n";
      }
      break;
    }

    case 6: {
      int idModificar;
      std::cout << "Ingrese el ID del producto que desea modificar: ";
      std::cin >> idModificar;

      NodoAVL *nodoModificar = arbol.buscarPorID(idModificar);

      if (nodoModificar != nullptr) {
        std::cout << "Producto encontrado:\n";
        std::cout << "ID: " << nodoModificar->producto.id << "\n";
        std::cout << "Nombre: " << nodoModificar->producto.nombre << "\n";
        std::cout << "Precio: " << nodoModificar->producto.precio << "\n";
        std::cout << "Categoría: " << nodoModificar->producto.categoria << "\n";
        std::cout << "Stock: " << nodoModificar->producto.stock << "\n";

        int opcionModificar;
        std::cout << "Seleccione el atributo a modificar:\n";
        std::cout << "1. Nombre\n";
        std::cout << "2. Precio\n";
        std::cout << "3. Categoría\n";
        std::cout << "4. Stock\n";
        std::cout << "5. Cancelar\n";
        std::cout << "Elija una opción: ";
        std::cin >> opcionModificar;

        switch (opcionModificar) {
        case 1:
          std::cout << "Ingrese el nuevo nombre: ";
          std::cin.ignore();
          std::getline(std::cin, nodoModificar->producto.nombre);
          break;
        case 2:
          std::cout << "Ingrese el nuevo precio: ";
          std::cin >> nodoModificar->producto.precio;
          break;
        case 3:
          std::cout << "Ingrese la nueva categoría: ";
          std::cin.ignore();
          std::getline(std::cin, nodoModificar->producto.categoria);
          break;
        case 4:
          std::cout << "Ingrese el nuevo stock: ";
          std::cin >> nodoModificar->producto.stock;
          break;
        case 5:
          std::cout << "Operación cancelada. Volviendo al menú principal\n";
          break;
        default:
          std::cout << "Opción no válida. Volviendo al menú principal\n";
        }

        for (auto &productoAlmacen : almacen.getProductos()) {
          if (productoAlmacen.id == idModificar) {
            productoAlmacen = nodoModificar->producto;
            break;
          }
        }

        std::ofstream archivo("Productos.csv");
        for (const auto &producto : almacen.getProductos()) {
          archivo << producto.id << "," << producto.nombre << ","
                  << producto.precio << "," << producto.categoria << ","
                  << producto.stock << "\n";
        }
        archivo.close();

        std::cout << "Producto modificado con éxito.\n";
      } else {
        std::cout << "Producto no encontrado.\n";
      }
      break;
    }

    case 7:
      std::cout << "Saliendo del programa\n";
      break;
    default:
      std::cout << "Opción no válida. Intente de nuevo.\n";
    }
  }

  return 0;
};
