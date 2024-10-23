#include <iostream>
#include <iomanip>
#include <string>
#include "hierarchy.h"
#include "list.h"

using namespace std;

bool salary(employee& a) {
    mountly_employee* a_montly = dynamic_cast<mountly_employee*>(&a);
    if (a_montly) {
        return (a_montly->get_average_mountly_salary() > 10000);
    }
    return false;
}

int main(){
    setlocale(LC_ALL, "Russian");
    
    List<employee> database;
    mountly_employee p1("Aleksandr Konovalov", "DevOps", 2020, 220000);
    hourly_employee p2("Sultan Zhumagaliev", "Backend engineer", 2016, 1930);
    hourly_employee p3("Khariton Pitsik", "ML - engineer", 2019, 1500);
    mountly_employee p4("Igor Tsoy");
    hourly_employee p5("Alina Ilina", "Project Manager", 2017, 1250);
    mountly_employee p6("Artem Drozhdev", "Tester", 2022, 194380);
    hourly_employee p7;
    

    database.push(&p1);
    database.push(&p2);
    database.push(&p3);
    database.push(&p4);
    database.push(&p5);
    database.push(&p6);
    database.push(&p7);

    database.print();


    cout << "-Копирование объектов:" << endl;
    mountly_employee p8 = p1;
    cout << p8;

    cout << "-Функции внутри объектов(полиморфизм):" << endl;
    mountly_employee p9 = p4;
    p4.change_position("asd");
    cout << p9;
    cout << p4;

    p6.change_salary(123456);
    database.print();
    
    //найти всех по условию
    cout << "-Найти всех из БД по условию 'Работник с фикс. оплатой, месячная ЗП больше 200000':" << endl;
    database.findAll(salary);

    return 0;
}