#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//метод поиска с динамик
//класс список(универсальный)
template <typename T>
class List {
private:
    struct node {
        T* inf;
        node* next;
        node* prev;
    };
    node* head;
    node* tail;
public:
    List() { head = NULL; tail = NULL; }
    void push(T* p) {
        node* r = new node;
        if (find(p)) { //без одинаковых(исключение - копии)
            return;
        }
        r->inf = p;
        r->next = NULL;
        if (!head && !tail) {
            r->prev = NULL;
            head = r;
        }
        else {
            tail->next = r;
            r->prev = tail;
        }
        tail = r;
    }

    void print() {
        cout << "========================================= База данных какой-то интересной IT компании =========================================" << endl;
        node* r = head;
        while (r != NULL) {
            cout << *(r->inf);
            r = r->next;
        }
        cout << '\n';
    }
    bool find(T* p) {
        node* r = head;
        while (r != NULL) {
            if (*(r->inf) == *p)
                return true;
            r = r->next;
        }
        return false;
    } 
    bool findAll(bool condition(T& p1)) {
        node* r = head;
        while (r != NULL) {
            if (condition(*(r->inf)))
            {
                cout << *(r->inf);
            }
            r = r->next;
        }
        return (r != NULL);
    }
    void insertAfter(T* p, T* ins) {
        node* r = head;

        while (r != NULL && *(r->inf) != p) {
            r = r->next;
        }
        if (r == NULL) {
            return;
        }

        node* insNode = new node;
        insNode->inf = ins;

        insNode->next = r->next;
        insNode->prev = r;

        if (r->next != NULL) {
            r->next->prev = insNode;
        }
        else {
            tail = insNode;
        }

        r->next = insNode;
    }
    void del(T* p) {
        node* r = head;
        while (r != NULL && (r->inf) != p) {
            r = r->next;
        }

        if (r == NULL) {
            return;
        }
        if (r == head && r == tail) {
            head = tail = NULL;
        }
        else if (r == head) {
            head = head->next;
            head->prev = NULL;
        }
        else if (r == tail) {
            tail = tail->prev;
            tail->next = NULL;
        }
        else {
            r->prev->next = r->next;
            r->next->prev = r->prev;
        }
        delete r; 

    }
};