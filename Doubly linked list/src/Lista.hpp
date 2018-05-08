#include "Lista.h"

template <typename T>
Lista<T>::Lista() {
    //Sin el this deberia funcionar igual porque me estoy dirigiendo a la misma instacia
    this->primero = nullptr;
    this->ultimo = nullptr;
    this->Long = 0;
}

// Inicializa una lista vacía y luego utiliza operator= para no duplicar el
// código de la copia de una lista.
template <typename T>
Lista<T>::Lista(const Lista<T>& l) : Lista() { *this = l; } 

template <typename T>
Lista<T>::~Lista() {
    while (primero != nullptr) {
        Nodo* nuevo_prim = primero->siguiente;
        delete primero;
        primero = nuevo_prim;
    }
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& l) {

    while (primero != nullptr) {
        Nodo* nuevo_prim = primero->siguiente;
        delete primero;
        primero = nuevo_prim;
        Long--;
    }

    for (int i = 0; i < l.longitud(); ++i) {
        this->agregarAtras(l.iesimo(i));
    }

    return *this;
}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    Nodo* n = new Nodo(elem, this->primero, nullptr);

    if (this->Long == 0) {
        this->ultimo = n;
    } else {
        this->primero->anterior = n;
    }
    this->primero = n;
    Long++;
}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    Nodo* n = new Nodo(elem, nullptr, this->ultimo);

    if (this->Long == 0) {
        this->primero = n;
    } else {
        this->ultimo->siguiente = n;
    }
    this->ultimo = n;
    Long++;
}

template <typename T>
int Lista<T>::longitud() const {
    return this->Long;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    Nodo* elem_buscado = this->primero;

    while ( i != 0) {
        elem_buscado = elem_buscado->siguiente;
        i--;
    }

    return elem_buscado->elem;
}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    Nodo* elem_buscado = this->primero;

    while ( i != 0) {
        elem_buscado = elem_buscado->siguiente;
        i--;
    }
    if (elem_buscado->siguiente != nullptr) { //si el elemento no es el ultimo
        elem_buscado->siguiente->anterior = elem_buscado->anterior;
    } else {
        this->ultimo = elem_buscado->anterior;
    }

    if (elem_buscado->anterior != nullptr) { //si el elemento no es el primero
        elem_buscado->anterior->siguiente = elem_buscado->siguiente;
    } else {
        this->primero = elem_buscado->siguiente;
    }


    delete elem_buscado;
    Long--;
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    Nodo* elem_buscado = this->primero;

    while ( i != 0) {
        elem_buscado = elem_buscado->siguiente;
        i--;
    }

    return elem_buscado->elem;
}

template <typename T>
void Lista<T>::mostrar(std::ostream& o) {
    for (int i = 0; i < Long; ++i) {
        o << this->iesimo(i);
    }


}
