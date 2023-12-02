#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include "Almacen.h"

struct NodoAVL {
  Producto producto;
  NodoAVL *izquierda;
  NodoAVL *derecha;
  int altura;

  NodoAVL(const Producto &p)
      : producto(p), izquierda(nullptr), derecha(nullptr), altura(1) {}
};

class ArbolAVL {
public:
  ArbolAVL() : raiz(nullptr) {}

  void insertar(const Producto &producto);

  void recorridoInorden();

  NodoAVL *buscarPorID(int idBuscado);

  bool isEmpty() const { return raiz == nullptr; }

  void eliminar(int id);

private:
  NodoAVL *raiz;

  int altura(NodoAVL *nodo);
  int factorBalance(NodoAVL *nodo);
  NodoAVL *rotarIzquierda(NodoAVL *x);
  NodoAVL *insertar(NodoAVL *raiz, const Producto &producto);
  void recorridoInorden(NodoAVL *nodo);

  NodoAVL *buscarPorID(NodoAVL *nodo, int idBuscado);

  NodoAVL *eliminar(NodoAVL *raiz, int id);
  NodoAVL *minimoValor(NodoAVL *nodo);
  NodoAVL *rebalancear(NodoAVL *nodo);

  NodoAVL *rotarDerecha(NodoAVL *y);
};

void ArbolAVL::recorridoInorden() { recorridoInorden(raiz); }

void ArbolAVL::recorridoInorden(NodoAVL *nodo) {
  if (nodo != nullptr) {
    recorridoInorden(nodo->izquierda);
    std::cout << nodo->producto.id << "\t" << nodo->producto.nombre << "\t"
              << nodo->producto.precio << "\t" << nodo->producto.categoria
              << "\t" << nodo->producto.stock << "\n";
    recorridoInorden(nodo->derecha);
  }
}

int ArbolAVL::altura(NodoAVL *nodo) {
  if (nodo == nullptr)
    return 0;
  return nodo->altura;
}

int ArbolAVL::factorBalance(NodoAVL *nodo) {
  if (nodo == nullptr)
    return 0;
  return altura(nodo->izquierda) - altura(nodo->derecha);
}
void ArbolAVL::insertar(const Producto &producto) {
  raiz = insertar(raiz, producto);
}

NodoAVL *ArbolAVL::insertar(NodoAVL *nodo, const Producto &producto) {
  if (nodo == nullptr)
    return new NodoAVL(producto);

  if (producto.id < nodo->producto.id)
    nodo->izquierda = insertar(nodo->izquierda, producto);
  else if (producto.id > nodo->producto.id)
    nodo->derecha = insertar(nodo->derecha, producto);
  else
    return nodo;

  nodo->altura = 1 + std::max(altura(nodo->izquierda), altura(nodo->derecha));

  int balance = factorBalance(nodo);

  return nodo;
}

NodoAVL *ArbolAVL::rotarIzquierda(NodoAVL *x) {
  NodoAVL *y = x->derecha;
  NodoAVL *T2 = y->izquierda;

  y->izquierda = x;
  x->derecha = T2;

  x->altura = 1 + std::max(altura(x->izquierda), altura(x->derecha));
  y->altura = 1 + std::max(altura(y->izquierda), altura(y->derecha));

  return y;
}

NodoAVL *ArbolAVL::buscarPorID(int idBuscado) {
  return buscarPorID(raiz, idBuscado);
}

NodoAVL *ArbolAVL::buscarPorID(NodoAVL *nodo, int idBuscado) {
  if (nodo == nullptr) {
    return nullptr;
  }

  if (idBuscado == nodo->producto.id) {
    return nodo;
  } else if (idBuscado < nodo->producto.id) {
    return buscarPorID(nodo->izquierda, idBuscado);
  } else {
    return buscarPorID(nodo->derecha, idBuscado);
  }
}

void ArbolAVL::eliminar(int id) { raiz = eliminar(raiz, id); }

NodoAVL *ArbolAVL::eliminar(NodoAVL *nodo, int id) {

  if (nodo == nullptr) {
    return nodo;
  }

  if (id < nodo->producto.id) {
    nodo->izquierda = eliminar(nodo->izquierda, id);
  } else if (id > nodo->producto.id) {
    nodo->derecha = eliminar(nodo->derecha, id);
  } else {

    if (nodo->izquierda == nullptr || nodo->derecha == nullptr) {
      NodoAVL *temp =
          (nodo->izquierda != nullptr) ? nodo->izquierda : nodo->derecha;

      if (temp == nullptr) {
        temp = nodo;
        nodo = nullptr;
      } else {
        *nodo = *temp;
      }

      delete temp;
    } else {

      NodoAVL *temp = minimoValor(nodo->derecha);

      nodo->producto = temp->producto;

      nodo->derecha = eliminar(nodo->derecha, temp->producto.id);
    }
  }

  if (nodo == nullptr) {
    return nodo;
  }

  nodo->altura = 1 + std::max(altura(nodo->izquierda), altura(nodo->derecha));

  return rebalancear(nodo);
}

NodoAVL *ArbolAVL::minimoValor(NodoAVL *nodo) {
  NodoAVL *actual = nodo;
  while (actual->izquierda != nullptr) {
    actual = actual->izquierda;
  }
  return actual;
}

NodoAVL *ArbolAVL::rebalancear(NodoAVL *nodo) {

  int balance = factorBalance(nodo);

  if (balance > 1 && factorBalance(nodo->izquierda) >= 0) {
    return rotarDerecha(nodo);
  }

  if (balance > 1 && factorBalance(nodo->izquierda) < 0) {
    nodo->izquierda = rotarIzquierda(nodo->izquierda);
    return rotarDerecha(nodo);
  }

  if (balance < -1 && factorBalance(nodo->derecha) <= 0) {
    return rotarIzquierda(nodo);
  }

  if (balance < -1 && factorBalance(nodo->derecha) > 0) {
    nodo->derecha = rotarDerecha(nodo->derecha);
    return rotarIzquierda(nodo);
  }

  return nodo;
}

NodoAVL *ArbolAVL::rotarDerecha(NodoAVL *y) {
  NodoAVL *x = y->izquierda;
  NodoAVL *T2 = x->derecha;

  x->derecha = y;
  y->izquierda = T2;

  y->altura = 1 + std::max(altura(y->izquierda), altura(y->derecha));
  x->altura = 1 + std::max(altura(x->izquierda), altura(x->derecha));

  return x;
}

#endif // ARBOLAVL_H
