//-----------------------------------------FUNCTIONS----------------------------
//
// Created by Eugenio on 28/12/2021.
//
#include <cmath>
int m = 197;//Intero per gestire l'Hashing
// ||----------------Function per la Lista-------------||
void Lista::addNodo(int k,string v) {
    auto *x = new NodoRB(k,v);
    if(head == nullptr){
        head = x;
        curr = tail = x;
        x->prev = nullptr;
    }else{
        tail->next = x;
        x->prev = tail;
        tail = curr = x;
        x->next = nullptr;
    }
}
NodoRB *Lista::trovaNodo(string v) {
    curr = getHead();
    while(curr && curr->GetVal() != v){
        curr = curr->next;
    }
    if(curr){return curr;}else{return nullptr;}
}
void Lista::delNodo(string v){
    NodoRB *x = trovaNodo(v);
    if(x == nullptr){
        return;
    }
    if(x == getHead()){
        head = x->next;
        curr = head;
        curr->prev = nullptr;
    }else if(x == getTail()){
        tail = x->prev;
        curr = tail;
        curr->next = nullptr;
    }else{
        curr = x->prev;
        curr->next = x->next;
    }
    delete x;
}
void Lista::PrintList(NodoRB *h) {
    while(h){
        cout << h->GetVal() << ">";
        h = h->next;
    }
}
// ||==========Function per l'AlberoRB==============||
int AlbRB::HashFunction(int k) {
    return (k % m);
}
void AlbRB::Insert(int k,string &v){
    int key = HashFunction(k);
    //cout << "KEY: " << key << endl;
    auto *z = new NodoRB(key,v);
    NodoRB *y = nullptr;
    NodoRB *x = root;
    while(x != nullptr){
        y = x;
        if (z->GetKey() == x->GetKey()){
            x->L.addNodo(z->GetKey(),z->GetVal());
        }else if(z->GetKey() < x->GetKey()){
            x = x->GetL();
        }else{
            x = x->GetR();
        }
    }
    z->SetP(y);
    if(y == nullptr){
        root = z;
    }else if(z->GetKey() < y->GetKey()){
        y->SetL(z);
    }else{
        y->SetR(z);
    }
    z->SetR(nullptr);z->SetL(nullptr);
    fixUp(z);
}
void AlbRB::fixUp(NodoRB *z){
    z->SetColor('r');
    while(z->GetP()!= nullptr && z->GetP()->GetColor() == 'r'){
        if(z->GetP() == z->GetP()->GetP()->GetR()){
            NodoRB *y = z->GetP()->GetP()->GetL();
            if(y->GetColor() == 'r'){
                y->SetColor('b');
                z->GetP()->SetColor('b');
                z->GetP()->GetP()->SetColor('r');
                z = z->GetP()->GetP();
            }else if(z == z->GetP()->GetL()){
                z = z->GetP();
                LeftRotate(z);
            }
            z->GetP()->SetColor('b');
            z->GetP()->GetP()->SetColor('r');
            RightRotate(z->GetP()->GetP());
        }else{
            NodoRB *y = z->GetP()->GetP()->GetR();
            if(y->GetColor() == 'r'){
                y->SetColor('b');
                z->GetP()->SetColor('b');
                z->GetP()->GetP()->SetColor('r');
                z = z->GetP()->GetP();
            }else if(z == z->GetP()->GetR()){
                z = z->GetP();
                RightRotate(z);
            }
            z->GetP()->SetColor('b');
            z->GetP()->GetP()->SetColor('r');
            LeftRotate(z->GetP()->GetP());
        }
    }
    root->SetColor('b');
}
void AlbRB::Delete(int ID) {
    NodoRB *x = SearchNodo(getRoot(),ID);
    if(x->GetL() == nullptr){
        RBTransplant(x,x->GetR());
    }else if(x->GetR() == nullptr){
        RBTransplant(x,x->GetL());
    }else{
        NodoRB *y = x->GetR();
        if(y->GetP() != x){
            RBTransplant(y,y->GetR());
            y->SetR(x->GetR());
            y->GetR()->SetP(y);
        }
        RBTransplant(x,y);
        y->SetL(x->GetL());
        y->GetL()->SetP(y);
    }
    fixUp(x);
}
//Function per la LeftRotate e RightRotate
void AlbRB::LeftRotate(NodoRB *x){
    NodoRB *y = x->GetR();
    x->SetR(y->GetL());
    if(y->GetL() != nullptr){
        y->GetL()->SetP(x);
    }
    y->SetP(x->GetP());
    if(x->GetP() == nullptr){
        root = y;
    }else if( x == x->GetP()->GetL()){
        x->GetP()->SetL(y);
    }else{
        x->GetP()->SetR(y);
    }
    y->SetL(x);
    x->SetP(y);
};
void AlbRB::RightRotate(NodoRB* x){
    NodoRB *y = x->GetL();
    x->SetL(y->GetR());
    if(y->GetR() != nullptr){
        y->GetR()->SetP(x);
    }
    y->SetP(x->GetP());
    if(x->GetP() == nullptr){
        root = y;
    }else if( x == x->GetP()->GetR()){
        x->GetP()->SetR(y);
    }else{
        x->GetP()->SetL(y);
    }
    y->SetR(x);
    x->SetP(y);
}
//Function per la Search
NodoRB *AlbRB::SearchNodo(NodoRB *rad,int ID) {
    if(rad->GetKey() == ID){
        return rad;
    }
    if(rad->GetKey() > ID){
        SearchNodo(rad->GetL(),ID);
    }else{
        SearchNodo(rad->GetR(),ID);
    }
    return rad;
}
//Visite dell'albero
void AlbRB::inorder(NodoRB *x) {
    if(x != nullptr){
        inorder(x->GetL());
        cout << "V:" << x->GetVal() << ", K:" << x->GetKey() << ">>" <<x->GetColor() << endl;
        if(x->L.getHead() != nullptr){
            NodoRB *h = x->L.getHead();
            x->L.PrintList(h);
        }
        inorder(x->GetR());
    }
}
void AlbRB::preorder(NodoRB *x) {
    if(x != nullptr){
        cout << "V:" << x->GetVal() << ", K:" << x->GetKey() << ">>" <<x->GetColor() << endl;
        preorder(x->GetL());
        preorder(x->GetR());
    }
}
void AlbRB::postorder(NodoRB *x) {
    if(x != nullptr){
        postorder(x->GetL());
        postorder(x->GetR());
        cout << "V:" << x->GetVal() << ", K:" << x->GetKey() << ">>" <<x->GetColor() << endl;
    }
}
//Metodi Get per i puntatori a Max e Min del RBTree
NodoRB *AlbRB::minim(NodoRB *rad){
    while(rad->GetL()){
        rad = rad->GetL();
    }
    return rad;
}
NodoRB *AlbRB::maxi(NodoRB *rad) {
    while(rad->GetR()){
        rad = rad->GetR();
    }
    return rad;
}
//Function Per Transplant
void AlbRB::RBTransplant(NodoRB *u,NodoRB *v){
    getRoot()->SetP(nullptr);
    if(u->GetP() == nullptr){
        root = v;
    }else if(u == u->GetP()->GetL()){
        u->GetP()->SetL(v);
    }else{
        u->GetP()->SetR(v);
    }
    v->SetP(u->GetP());
}
void AlbRB::PrintTree(NodoRB *rad, int  space){
    //Function per Printare l'albero in Orizzontale
    int i;
    if(rad != nullptr){
        space = space + 10;
        PrintTree(rad->GetR(), space);
        cout <<  "\n";
        for (i=10;i<space;i++){
            cout << " ";
        }
        cout << rad->GetVal() << ",color: " << rad->GetColor() << endl;
        cout << "\n";
        PrintTree(rad->GetL(), space);
    }
}
