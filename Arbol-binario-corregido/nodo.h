#include <stdlib.h>

class Nodo
{
    public:
        int info;
        Nodo *Llink; //enlace izquierdo
        Nodo *Rlink; //enlace derecho
        Nodo(int);
        ~Nodo();
};

Nodo::Nodo(int info)
{
    this->info = info;
    Llink = NULL;
    Rlink = NULL;
}

Nodo::~Nodo()
{ }
