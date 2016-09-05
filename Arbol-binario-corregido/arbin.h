#include "nodo.h"
#include <iostream>

using namespace std;

class Arbin
{
    private:
        Nodo *raiz;
        int mayorcito;
        Nodo *Insertar(Nodo*,Nodo*);
        Nodo *Borrar(Nodo*, int);
        bool Busqueda(Nodo *, int);
        void Mostrar(Nodo *, int);
        void Transformar(Nodo *);
        int  getInfo_der(Nodo*);
        void mayor(Nodo*);
        Nodo *getInfo_iz(Nodo*);
        Nodo *BuscarPadre_iz(Nodo*,int);
        Nodo *PadreIz(int);
        void preOrden(Nodo*);
        void inOrden(Nodo*);
        void postOrden(Nodo*);
    public:
        Arbin();
        void Crear(Nodo*);
        void Recorridos(int);
        void Eliminar(int);
        void Buscar(int);
        void Imprimir();
        void Convertir();
        ~Arbin();
};

Arbin::Arbin(){
    raiz = NULL;
}

Nodo* Arbin::Insertar(Nodo *p, Nodo *q){
    if(p == NULL){
        p = q;
    }
    else{
        if(q->info < p->info){
            p->Llink = Insertar(p->Llink,q);
        }
        else{
            p->Rlink = Insertar(p->Rlink,q);
        }
    }

    return p;
}

void Arbin::Crear(Nodo *q)
{
    if(!Busqueda(raiz,q->info))
    raiz = Insertar(raiz,q);
}

void Arbin::preOrden(Nodo *p){
    if(p != NULL){
        cout << p->info << ", ";
        //mayorcito=p->info;
        preOrden(p->Llink);
        preOrden(p->Rlink);
    }
}

void Arbin::inOrden(Nodo *p){
    if(p != NULL){
        inOrden(p->Llink);
        cout << p->info << ", ";
        inOrden(p->Rlink);
    }
}

void Arbin::postOrden(Nodo *p){
    if(p != NULL){
        cout << p->info << ", ";
        postOrden(p->Llink);
        postOrden(p->Rlink);
    }
}

void Arbin::Recorridos(int tipo){
    switch(tipo){
        case 1:
            preOrden(raiz);
        break;

        case 2:
            inOrden(raiz);
        break;

        case 3:
            postOrden(raiz);
        break;

        default:
	  cout<<"Opcion invalida"<<endl;
	  break;
    }
}

int Arbin::getInfo_der(Nodo *q){///MAS DERECHO
    if(q->Rlink == NULL){
        return q->info;
    }
    else{
        return getInfo_der(q->Rlink);
    }
}
Nodo * Arbin::getInfo_iz(Nodo *q){///MAS IZQUIERDO
    if(q->Llink == NULL){
        return q;
    }
    else{
        return getInfo_iz(q->Llink);
    }
}
Nodo * Arbin::BuscarPadre_iz(Nodo * r,int info){///papa
    //cout<<"BUSCANDO EL PADRE DE : "<<info;
    while(r->Rlink!=NULL and r->Llink!=NULL)
     {
        //cout<<"aqwui"<<endl;
         if (info==r->Llink->info or info==r->Rlink->info)
            {
          //  cout<<"star"<<endl;
            return r;
            }


         else
         {
             if (info>r->info)
             {
              r=r->Rlink;
            // cout<<".2.1."<<endl;
             }
             else
             {
             //cout<<".2.2."<<endl;
             r=r->Llink;
             }

         }
         //cout<<"saliw"<<endl;
     }
    return NULL;
}
Nodo * Arbin::PadreIz(int info){///papa
return BuscarPadre_iz(raiz,info);

}

void Arbin::mayor(Nodo *p){
    if(p != NULL){
        //cout << p->info << ", ";
        mayorcito=p->info;
        mayor(p->Llink);
        mayor(p->Rlink);
    }
}
Nodo* Arbin::Borrar(Nodo *p, int info)
{
    Nodo *q;

    if(p != NULL)
    {
        if(p->info == info)
        {
            if(p->Llink == NULL && p->Rlink == NULL)///SI ES HOJA
            {
                delete p;
                p = NULL;
            }
            else{
                if(p->Llink == NULL && p->Rlink != NULL)///TIENE HIJO DERECHO
                {
                    q = p->Rlink;
                    delete p;
                    p = q;
                }
                else if(p->Llink != NULL && p->Rlink == NULL)///TIENE HIJO IZQUIERDO
                {
                    q = p->Llink;
                    delete p;
                    p = q;
                }
                else
                {                                    ///TIENE AMBOS
                    info = getInfo_der(p->Llink);
                    p->info = info;
                    p = p->Llink;
                    p->Rlink = Borrar(p->Rlink, info);
                }
            }
        }
        else{
            if(info < p->info){
                p->Llink = Borrar(p->Llink, info);
            }
            else{
                p->Rlink = Borrar(p->Rlink, info);
            }
        }
    }

    return p;
}

void Arbin::Eliminar(int info){
    raiz = Borrar(raiz, info);
}
bool Arbin::Busqueda(Nodo *k, int info)
{
     while(k)
     {
         if (info==k->info)
         {  cout << info << "  Encontrado";
            return 1;
         }
         else
         {
             if (info>k->info)
             k=k->Rlink;
             else
             k=k->Llink;
         }
     }
     cout<<"No encontrado"<<endl;
     return 0;


}
void Arbin::Buscar(int info){
   Busqueda(raiz, info);
}


void Arbin::Mostrar(Nodo *p, int n){
    if(p != NULL)
    {
        Mostrar(p->Rlink,n+1);
        for(int i=0; i<n; i++)
         cout<<"   ";

        cout<< p->info <<endl;
        Mostrar(p->Llink,n+1);
    }
}
void Arbin::Imprimir(){
    Mostrar(raiz, 0);

}


void Arbin::Transformar(Nodo *p){
Nodo * aux;
Nodo * papa;
aux=getInfo_iz(p);
mayor(raiz);
//cout<<"ALERTa"<<aux->info<<endl;
if(aux->info!=mayorcito)
 { if(aux->Rlink)
    {
     //cout <<"IF"<<endl;
     Transformar(aux->Rlink);
    }
    else
    {  // cout<<"else"<<aux->info<<endl;
        papa=PadreIz(aux->info);
        //cout<<"ELSE papa"<<papa->info<<endl;
        if(papa->Rlink)
        {
        aux->Rlink=papa->Rlink;
        //cout<<"1El nodo"<<aux->info<<"apunta a"<<papa->Rlink->info<<endl;

        }
        else
        {
             while(!papa->Rlink)
             {
                papa=PadreIz(papa->info);
             }
         aux->Rlink=papa->Rlink;
        //cout<<"2El nodo"<<aux->info<<"apunta a"<<papa->Rlink->info<<endl;

        }
        Transformar(papa->Rlink);
        papa->Rlink=NULL;
    }
}
}
void Arbin::Convertir(){
   //cout<<PadreIz(3)<<endl;
   Transformar(raiz);
}

Arbin::~Arbin(){}





