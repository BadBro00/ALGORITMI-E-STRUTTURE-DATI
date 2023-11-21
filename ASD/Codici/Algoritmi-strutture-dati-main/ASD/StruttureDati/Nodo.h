#ifndef NODO_H
#define NODO_H

template <class T>
class Nodo{
    private:
        Nodo<T>* next;
        T* obj;

    public:
        Nodo(Nodo<T>* next,T* info);
        ~Nodo();

        //setter
        void setNext(Nodo<T>* next){this->next = next;}
        void setObj(T* info){this->obj = info;}

        //getter
        Nodo<T> *getNext(){return next;}
        T *getObj(){return this->obj;}
};

template <class T>
Nodo<T>::Nodo(Nodo<T>* next,T* info){
    this->next = next;
    this->obj = info;
}

template <class T>
Nodo<T>::~Nodo(){
    delete next;
    delete obj;
}

#endif // NODO_H