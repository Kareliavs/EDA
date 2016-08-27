#include <iostream>

using namespace std;
template<class en>
class Nodo
{
public:
    en m_dato;
    Nodo* sgt;
    Nodo(en dato)
    {
        m_dato=dato;
        sgt=NULL;
    }
};
template<class Nodo>
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
    bool eliminar(int dato)
    { Nodo* aux = m_head;
      Nodo* aux2=m_head;
        //cout<<"Estoy eliminando"<<endl;
        if(buscar(dato))
        {
            while(aux->m_dato!=dato)//return 1;
            {

                if(aux !=m_head )
                {
                    aux2=aux2->sgt;
                }
                aux=aux->sgt;
            }
            //cout<<"Lo busque"<<aux->m_dato<<" this is su previo"<<aux2->m_dato<<endl;
            //aux->sgt= NULL;
              if(aux==m_head)
                {   //cout<<"es cabeza"<<endl;
                    m_head=aux->sgt;
                    aux=NULL;
                }
              else aux2->sgt=aux->sgt;


        }

        else cout<<"No existe"<<endl;
    }
};

Lista<Nodo<char>> a;
int x;
char num;
int main()
{   //stem("clear");


    cout<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"\t Seleccione Accion"<<endl;
    cout<<"1 Imprimir"<<endl;
    cout<<"2 Invertir"<<endl;
    cout<<"3 Buscar"<<endl;
    cout<<"4 Insertar"<<endl;
    cout<<"5 Eliminar"<<endl;
    cout<<"----------------------------"<<endl;
     cin>>x;
     if(x==1)
     {  cout<<"----------------------------"<<endl;
        a.imprimir();
     }
     else if(x==2)
        {
            a.invertir();
            system("clear");
        }
     else if(x==3)
        {cout<<"ingrese numero a buscar"<<endl;
        cin>>num;
        if(a.buscar(num))cout<<"si esta"<<endl;
        else cout<<"no esta"<<endl;
        system("clear");
        }
     else if(x==4)
        {cout<<"ingrese numero a insertar"<<endl;
        cin>>num;
        a.insertar(num);
        system("clear");
        }
     else if(x==5)
        {cout<<"ingrese numero a eliminar"<<endl;
        cin>>num;
        a.eliminar(num);
        system("clear");
        }
    else cout<<"Elija opcion valida";
   // a.eliminar(4);

    main();
return 0;
}

