#ifndef NODOABR_H
#define NODOABR_H

/*
    • Ogni nodo di un ABR contiene:
    • la chiave (o key);
    • il puntatore al PADRE
    • il puntatore al FIGLIO DESTRO
    • il puntatore al FIGLIO SINISTRO
    • Eventuali dati satelliti
*/

template <typename T>
class NodoAbr {
    private:
        T key;
        NodoAbr<T>* parent;
        NodoAbr<T>* right;
        NodoAbr<T>* left;
    public:
        NodoAbr(T*,NodoAbr<T>*,NodoAbr<T>*,NodoAbr<T>*);
        NodoAbr(T);
        ~NodoAbr();

        void setKey(T* key){this->key = key;}
        void setParent(NodoAbr<T>* parent){this->parent = parent;}
        void setRight(NodoAbr<T>* right){this->right = right;}
        void setLeft(NodoAbr<T>* left){this->left = left;}

        T getKey(){return this->key;}
        NodoAbr<T> *getParent(){return this->parent;}
        NodoAbr<T> *getRight(){return this->right;}
        NodoAbr<T> *getLeft(){return this->left;}
};

template <typename T>
NodoAbr<T>::NodoAbr(T* key, NodoAbr<T>* parent, NodoAbr<T>* right, NodoAbr<T>* left){
    this->key = key;
    this->parent = parent;
    this->right = right;
    this->left = left;
}

template <typename T>
NodoAbr<T>::NodoAbr(T key){
    this->key = key;
    this->parent = nullptr;
    this->right = nullptr;
    this->left = nullptr;
}

template <typename T>
NodoAbr<T>::~NodoAbr(){
    // delete parent;
    // delete right;
    // delete left;
}

#endif // NODOABR_H