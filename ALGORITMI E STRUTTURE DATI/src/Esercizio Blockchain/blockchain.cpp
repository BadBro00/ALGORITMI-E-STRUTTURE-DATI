#include <iostream>
//#include <vector>
#include <string>
using namespace std;
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T data, Node* next = nullptr) : data(data), next(next) {}
};

class Transaction {
public:
    std::string from;
    std::string to;
    int amount;

    Transaction(std::string from, std::string to, int amount) : from(from), to(to), amount(amount) {}
};

template <typename T>
class LinkedList {
protected:
    Node<T>* head;
public:
    LinkedList() : head(nullptr) {}

    void addNode(T data) {
        Node<T>* newNode = new Node<T>(data, head);
        head = newNode;
    }
	Nodo<T> *getHead(){return head;}
};

class Block : public LinkedList<Transaction> {
public:
    void printTransactions(const std::string& address) {
        Node<Transaction>* current = head;
        while (current != nullptr) {
            if (current->data.from == address || current->data.to == address) {
                std::cout << "From: " << current->data.from
                          << ", To: " << current->data.to
                          << ", Amount: " << current->data.amount
                          << std::endl;
            }
            current = current->next;
        }
    }
};

class Blockchain : public LinkedList<Block> {
public:
	Nodo<Block> getHead(){return head;}
    void printTransactions(const std::string& address) {
        Node<Block>* current = head;
        while (current != nullptr) {
            current->data.printTransactions(address);
            current = current->next;
        }
    }
	void AddValues(string A){
		float sum = 0;
		Block *c = this->getHead();
		while(c){
			Node<Transaction> *t = c->head;
			while(t){
				if(t->data.from == A){
					sum += t->data.amount;
				}
				t = t->next;
			}
			c = c->next;
		}
	}

};

int main() {
    Blockchain blockchain;
    Block block1;
    block1.addNode(Transaction("A", "B", 50));
    block1.addNode(Transaction("B", "C", 30));
    blockchain.addNode(block1);

    Block block2;
    block2.addNode(Transaction("C", "A", 20));
    block2.addNode(Transaction("B", "A", 10));
    blockchain.addNode(block2);

    blockchain.printTransactions("A");

    return 0;
}