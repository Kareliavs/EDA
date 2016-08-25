#include <iostream>

using namespace std;

class Nodo
{
public:
    int m_dato;
    Nodo* sgt;
    Nodo(int dato)
    {
        m_dato=dato;
        sgt=NULL;
    }
};

class Lista
{
public:
    Nodo* m_head;
    Nodo* m_tail;
    Lista()
    {
        m_head=m_tail=NULL;
    }
    void insertar(int dato)
    {
        if(m_head==NULL)
        {
            m_head=new Nodo(dato);
            m_tail=m_head;
        }
        else
        {
            m_tail->sgt=new Nodo(dato);
            m_tail=m_tail->sgt;
        }
    }
    void imprimir()
    {
        Nodo* aux=m_head;
        while(aux!=NULL)
        {
            cout<<aux->m_dato<<endl;
            aux=aux->sgt;
        }
    }
    void invertir()
    {
        Nodo* aux,*aux2,*aux3;

        aux3=m_head;
        aux=m_head->sgt;
        aux2=aux->sgt;

        m_head->sgt=NULL;

        while(aux2!=NULL)
        {
            aux->sgt=m_head;///|1|<-2->3 voltea el primero // avanza cabeza
            m_head=aux;///1<-|2|->3
            aux=aux2;//aux y aux 2 apuntan a 3
            aux2=aux->sgt;//avanza aux 2
        }
        aux->sgt=m_head;
        m_head=aux;
    }

    bool buscar(int dato)
    {
        Nodo* aux=m_head;
        while(aux->sgt!=NULL)
        {
            if(aux->m_dato==dato)return 1;
            aux=aux->sgt;
        }
        return 0;
    }
};



Lista a;int x, num;
int main()
{


    cout<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"\t Seleccione Accion"<<endl;
    cout<<"1 Imprimir"<<endl;
    cout<<"2 Invertir"<<endl;
    cout<<"3 Buscar"<<endl;
    cout<<"4 Insertar"<<endl;
    cout<<"----------------------------"<<endl;
     cin>>x;
     if(x==1)
     {  cout<<"----------------------------"<<endl;
        a.imprimir();
     }
     else if(x==2)a.invertir();
     else if(x==3)
        {cout<<"ingrese numero a buscar"<<endl;
        cin>>num;
        if(a.buscar(num))cout<<"si esta"<<endl;
        else cout<<"no esta"<<endl;
         }
     else if(x==4)
        {cout<<"ingrese numero a insertar"<<endl;
        cin>>num;
        a.insertar(num);
        }
    else cout<<"Elija opcion valida";
    main();
return 0;
}
