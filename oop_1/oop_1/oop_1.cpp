#include <iostream>
#include <string.h>

using namespace std;

class Complex {
public:
    Complex() {};// конструктор по умолчанию - понадобится при создании динамического массива

    Complex(float r, float i = 0) {
        Re = r;
        Im = i;
    };

    ~Complex() {};

    float getRe() { return Re; } //геттеры
    float getIm() { return Im; }


    float mod(); //а вдруг кому-то пригодится?...
    Complex conjugate();

    void operator = (Complex a); //перегрузка
    Complex operator + (Complex a);
    Complex operator - (Complex a);
    Complex operator * (Complex a);
    Complex operator / (Complex a);
    bool operator != (Complex a);
    bool operator == (Complex a);

    friend ostream& operator << (ostream& out, Complex a) //перегрузка вывода (очень классная штука, теперь буду знать)
    {
        if (!a.getIm())
            out << a.getRe() << endl;
        else if (a.getIm() > 0)
            out << a.getRe() << " + " << a.getIm() << "i" << endl;
        else
            out << a.getRe() << " - " << -a.getIm() << "i" << endl;
        return out;
    }


private:
    float Re;
    float Im;
};

//перегрузка(арифметические операции, сравнение)

void Complex::operator = (Complex a){
    Re = a.getRe();
    Im = a.getIm();
}
Complex Complex::operator + (Complex a) {
    return Complex(Re + a.getRe(), Im + a.getIm());
}

Complex Complex::operator - (Complex a) {
    return Complex(Re - a.getRe(), Im - a.getIm());
}

Complex Complex::operator * (Complex a) {
    return Complex(Re * a.getRe() - Im * a.getIm(), Re * a.getIm() + Im * a.getRe());
}

Complex Complex::operator / (Complex a) { //a = Re; b = Im; c = a.getRe(); d = a.getIm();
    float div = a.getRe() * a.getRe() + a.getIm() * a.getIm();
    if (!div)
        return Complex();
    return Complex((Re * a.getRe() + Im * a.getIm()) / div, (Im * a.getRe() - Re * a.getIm()) / div);
}

bool Complex::operator == (Complex a) {
    return Re == a.getRe() && Im == a.getIm();
}

bool Complex::operator != (Complex a) {
    return Re != a.getRe() || Im != a.getIm();
}

//функции(модуль, сопряженное)


float Complex::mod() {
    return sqrt(Re * Re + Im * Im);
}

Complex Complex::conjugate() {
    return Complex(Re, -Im);
}
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
    //добавления+, удаления+, вставки, поиска в списке+, выполнения заданной операции над каждым элементом списка+
    void push(T* p) {
        node* r = new node;
        if (find(&p)) {
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
        node* r = head;
        while (r != NULL) {
            cout << *(r->inf);
            r = r->next;
        }
        cout << '\n';
    }
    bool find(T p) {
        node* r = head;
        while (r != NULL) {
            if (*(r->inf) == p)
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
    void insertAfter(T p, T* ins) {
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

//условие findall
bool ImPositive(Complex& a) {
    return (a.getIm() > 0);
}

int main(){
    setlocale(LC_ALL, "Russian");
    List<Complex> spisok;

    Complex x(1, 1);
    Complex c(1, 1);
    Complex y(2, 7);
    Complex a(2, -7);
    Complex test(5);
    
    Complex z = x + y;
    Complex z1 = x * test;
    
    spisok.push(&x);
    spisok.push(&c);
    spisok.push(&y);
    spisok.push(&a);
    spisok.push(&test);
    spisok.push(&z);
    spisok.push(&z1);

    Complex z2(10, 14);
    spisok.print();
    cout << "Вставка после: " << endl;
    Complex b(3, 3);
    spisok.insertAfter(z2, &b);
    spisok.print();

    cout << "Удалили: " << endl;
    spisok.del(&y);
    spisok.print();

    cout << "Мнимая часть положительная: " << endl;
    spisok.findAll(ImPositive);
    return 0;
}