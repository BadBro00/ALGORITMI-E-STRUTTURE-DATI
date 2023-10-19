/*
La blockchain è una struttura dati composta da una lista di
blocchi all'interno dei quali è memorizzato un insieme di
transazioni. Una transazione è costituita da un indirizzo
FROM, un indirizzo TO ed un valore intero QT.
	1. Progettare ed implementare una struttura dati LinkedList mediante template
		 ed utilizzarla per realizzare una blockchain
	2. Dato un indirizzo A, stampare a video/salvare su file tutte le transazioni
		 in cui compare A ed il suo bilancio finale
*/
#include <iostream>
#include <vector>
#include <string>

struct Transaction {
    std::string from;
    std::string to;
    int amount;
};

struct Block {
    std::vector<Transaction> transactions;
    Block* next;
};

class Blockchain {
private:
    Block* head;
public:
    Blockchain() : head(nullptr) {}

    void addBlock(const std::vector<Transaction>& transactions) {
        Block* newBlock = new Block{transactions, nullptr};
        if (head == nullptr) {
            head = newBlock;
        } else {
            Block* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newBlock;
        }
    }

    void printTransactions(const std::string& address) {
        Block* current = head;
        while (current != nullptr) {
            for (const Transaction& transaction : current->transactions) {
                if (transaction.from == address || transaction.to == address) {
                    std::cout << "From: " << transaction.from
                              << ", To: " << transaction.to
                              << ", Amount: " << transaction.amount
                              << std::endl;
                }
            }
            current = current->next;
        }
    }
};

int main() {
    Blockchain blockchain;
    std::vector<Transaction> transactions1 = {
        {"A", "B", 50},
        {"B", "C", 30},
    };
    blockchain.addBlock(transactions1);

    std::vector<Transaction> transactions2 = {
        {"C", "A", 20},
        {"B", "A", 10},
    };
    blockchain.addBlock(transactions2);

    blockchain.printTransactions("A");

    return 0;
}