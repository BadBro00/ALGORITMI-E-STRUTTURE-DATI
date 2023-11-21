#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack{

    private:
        int Dim; // massima occupazione della pila
        int Top; // ultimo elemento inserito
        T *Vet; // pila di T
    public:
        Stack();
        ~Stack();

        void Push(T);
        bool Pop(T&);
        bool isEmpity();
};

template <typename T>
Stack<T>::Stack(){
    Vet = nullptr; // pila vuota
    Dim = 0;
    Top = -1;
}

template <typename T>
Stack<T>::~Stack(){
    delete Vet;
}

template <typename T>
void Stack<T>::Push(T Elm){
    if (Top == Dim-1) { // se lo Stack è pieno

        T *App;
        App = new T[Dim+10]; // trasloca lo stack

        for (int i=0; i<Dim; i++) 
            App[i] = Vet[i];
        
        Dim += 10;
        delete[] Vet;
        Vet = App; // allunga lo stack
    }
    Vet[++Top] = Elm;
}

template <typename T>
bool Stack<T>::Pop(T& Elm){

    if (Top >= 0) {
        Elm = Vet[Top--];
        return true;
    } else 
        return false; // stack vuoto
    return false;
}

template <typename T>
bool Stack<T>::isEmpity(){
    return Top == -1;
}

#endif // STACK_H