#include <iostream>
#include <vector>
#include <stack>

using namespace std;
template<class T>
struct c_Node{

    T m_data;
    c_Node<T>* m_child[2];

    c_Node(T dato){
        m_data=dato;
        m_child[0]=0;
        m_child[1]=0;
    }
};
template <class T>
class c_Tree_Iterator
{
    public:

        c_Node<T> *m_i;
        stack<pair<c_Node<T>*,int>> pila;

        c_Tree_Iterator operator= (c_Tree_Iterator<T> x){
            m_i=x.m_i;
            return *this;
        }

        bool operator!= (c_Tree_Iterator<T> x){
            return m_i!=x.m_i;
        }

        T operator* (){
            return m_i->m_data;
        }

        c_Tree_Iterator operator++ (int)
        {   c_Node<T> *p;
            int i=0;
            while(p->m_child[0]!=nullptr)
            {
                pila.push(p,i);
                p=p->m_child[0];
            }
            cout<<p->m_data;
            pila.pop();
            while(p->m_child[1]!=nullptr)
            {
                pila.push(p,i);
                p=p->m_child[0];
            }

        }
};

template<class Tr>
class c_BinTRee
{
    public:

        c_BinTRee()
        {
        m_root=nullptr;
        }
        typedef typename Tr::T T;
         typedef c_Tree_Iterator<T> iterator;
        typedef typename Tr::C C;

        bool find(T , c_Node<T>**&);
        bool insert(T);
        bool remove(T);
        void convert(c_Node<T>*);
        void inorden(c_Node<T>*);
        void preorden(c_Node<T>*);
        void posorden(c_Node<T>*);
        void amplitud(c_Node<T>*);
        void print(c_Node<T>*,int);


        C m_cmp;
        c_Node<T>*m_root;
        iterator begin();
        iterator end();

};

template<class Tr>
bool c_BinTRee<Tr>::find(T x, c_Node<T>**&p)
{
    for(p=&m_root; (*p) && (*p)->m_data!=x; p=&(*p)->m_child[ m_cmp((*p)->m_data,x)]);
    return (*p);
}

template<class Tr>
bool c_BinTRee<Tr>::insert(T x)
{
    c_Node<T>**p;
    if(find(x,p)) return 0;
    *p=new c_Node<T>(x);
    return 1;
}

template<class Tr>
bool c_BinTRee<Tr>::remove(T x)
{
    c_Node<T>** p;
    c_Node<T>* temp;

    if(!find(x,p)) return 0;
    temp=(*p);
    if((*p)->m_child[0] && (*p)->m_child[1]){//caso2

        for(p=&((*p)->m_child[0]); (*p)->m_child[1]; p=&((*p)->m_child[1]));
        (*p)->m_data=temp->m_data;//No needed swap
    }
    (*p)=(*p)->m_child[!(*p)->m_child[0]];
    return 1;
}

template<class Tr>
void c_BinTRee<Tr>::convert(c_Node<T> *pp)
{  ///Crear dos punteros uno que recorra hasta el hijo mas izquierdo y lo una con otro hijo del mismo padre,  
///romper el enlace con el padre
  ///mover los punteros y hacer lo mismo con el subarbol
    c_Node<T>** p;
    c_Node<T>** o;
    if(pp!=nullptr)
    {
    for(p=&((*p)->m_child[0]); (*p)->m_child[0]; p=&((*p)->m_child[0]));
        if(((*p)->m_child[1])){}
       // convert(**p);
    }
}

template<class Tr>
void c_BinTRee<Tr>::print(c_Node<T> *p,int n)
{
    if(p!=nullptr){

        print(p->m_child[1],n+1);
        for(int i=0; i<n; i++)
             cout<<"   ";
        cout<<p->m_data<<endl;
        print(p->m_child[0],n+1);
    }
}
template<class Tr>
void c_BinTRee<Tr>::inorden(c_Node<T> *p)
{
    if(p!=nullptr){

        inorden(p->m_child[0]);
        cout<<p->m_data<<",";
        inorden(p->m_child[1]);
    }
}

template<class Tr>
void c_BinTRee<Tr>::preorden(c_Node<T> *p)
{
    if(p!=nullptr){
        cout<<p->m_data<<",";
        preorden(p->m_child[0]);
        preorden(p->m_child[1]);
    }
}
template<class Tr>
void c_BinTRee<Tr>::posorden(c_Node<T> *p)
{
    if(p!=nullptr){

        posorden(p->m_child[0]);
        posorden(p->m_child[1]);
        cout<<p->m_data<<",";
    }
}
template<class Tr>
void c_BinTRee<Tr>::amplitud(c_Node<T> *q)
{   vector<c_Node<T>*> cola;
    cola.push_back(q);
    while(cola.size()>0)
    {
        c_Node<T>*p=cola[0];
        cola.erase(cola.begin());
        cout<<p->m_data<<", ";
        if(p->m_child[0]!=nullptr)
            cola.push_back(p->m_child[0]);
        if(p->m_child[1]!=nullptr)
            cola.push_back(p->m_child[1]);    }
}

template <class T>
struct c_less
{   inline bool operator() (T a,T b)
    {return a<b;}
};

template <class T>
struct c_greater
{   inline bool operator() (T a,T b)
    {return a>b;}
};
template <class T>
struct c_order
{   c_order(int type)
    {switch(type)
        {
        case 1:
                break;
        case 2:
                break;
        case 3:
                break;
        case 4:
                break;
        }
    }
};

struct traits{
    typedef int T;
    typedef c_less<T> C;
    typedef c_order<T> O;
};
 c_BinTRee<traits> arbol;
 int n,num,x,op;
int main()
{
    cout << "\t\t Arbol Binario\n\n";
    cout<<"----------------------------"<<endl;
    cout<<"\t Seleccione Accion"<<endl;
    cout<<"1 Imprimir"<<endl;
    cout<<"2 Convertir"<<endl;
    cout<<"3 Buscar"<<endl;
    cout<<"4 Insertar"<<endl;
    cout<<"5 Eliminar"<<endl;
    cout<<"6 Recorridos"<<endl;
    cout<<"----------------------------"<<endl;
    cin>>op;
    if(op==1)
    {   cout << "\n Mostrando arbol \n\n";
        arbol.print(arbol.m_root,0);
   }
    if(op==2)
    {   arbol.print(arbol.m_root,0);
        arbol.convert(arbol.m_root);
        cout<<"---------CONVERTIDO-----------"<<endl;
        arbol.print(arbol.m_root,0);
        //system("clear");
    }
    if(op==3)
    {   cout<<"ingrese numero a buscar"<<endl;
        cin>>num;c_Node<int>** p;
        cout<<"buscando"<<endl;
        if(arbol.find(num,p)) cout<<"Encontrado"<<endl;
        else cout<<"No encontrado"<<endl;
        //system("clear");

    }
     if(op==4)
    {
        cout << " Numero de nodos del arbol:  ";
        cin >> n;
        cout << endl;

        for(int i=0; i<n; i++)
        {
            cout << " Numero del nodo " << i+1 << ": ";
            cin >> x;
            arbol.insert(x);
        }
        system("clear");
    }
     if(op==5)
    {   cout<<"ingrese numero a eliminar"<<endl;
        cin>>num;
        if(arbol.remove(num)) cout<<"Eliminado"<<endl;
        system("clear");
    }

    if(op==6)
    {
        cout << "\n Recorridos del Arbol binario";

        cout << "\n\n En orden   :  ";   arbol.inorden(arbol.m_root);
        cout << "\n\n Pre Orden  :  ";   arbol.preorden(arbol.m_root);
        cout << "\n\n Post Orden :  ";   arbol.posorden(arbol.m_root);
        cout << "\n\n Post Orden :  ";   arbol.amplitud(arbol.m_root);
        system("clear");
    }

    main();
    return 0;

    
    return 0;
}
