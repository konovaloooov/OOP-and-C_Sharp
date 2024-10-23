#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//функции
class employee
{
private:
    string position; 
    int experience;
    int year_hire; 
protected:
    string full_name;
    double average_montly_salary;
    string type;

    //геттеры
    string getName() const {return full_name;}
    string getPos() const {return position;}
    int getExp() const {return experience;}

    //сеттеры
    void setName(string name){full_name = name;}
    void setPos(string pos){position = pos;}
    void setExp(int exp){experience = exp;}
public:
    employee(string name, string pos = " ", int year = 2024)
    {
        full_name = name; 
        position = pos; 
        year_hire = year; 
        experience = 2024 - year;
    }
    employee() : full_name("None"){}
    ~employee() {}

    double get_average_mountly_salary(){return average_montly_salary;}
    void change_position(string pos)
    {
        position = pos;
    }

    //полиморфизм(абстрактная функция, изменим в наследниках)
    virtual void calculate_salary() = 0;
    virtual void change_salary(int new_salary) = 0;

    //переопределение вывода
    bool operator==(employee& x) {
        return (full_name == x.full_name && position == x.position && year_hire == x.year_hire);
    }
    virtual std::ostream& print(ostream& out) 
    {
        return out << left << setw(20) << "Работник: " << full_name 
               << left << setw(15) << "Должность: " << position 
               << left << setw(10) << "Стаж: " << experience 
               << left << setw(10) << "ЗП: " << average_montly_salary 
               << "\n";
    }
        friend ostream& operator<< (ostream& out, employee& x){
        return x.print(out);
    }
};

class hourly_employee : public employee 
{
private:
    int hourly_salary;
public:
    hourly_employee(): hourly_salary(0){type = "почасовая";}
    ~hourly_employee() {}
    hourly_employee(string name, string pos = " ", int year = 2024, int h_s = 0): employee(name, pos, year){
        type = "почасовая";
        hourly_salary = h_s;
        calculate_salary();
    }

    //конструктор копирования
    hourly_employee(const hourly_employee& other) : employee(other)
    {
        setName(other.getName()  + "(copy)");
        setPos(other.getPos());
        setExp(other.getExp());

        cout << "Успешно выполнено копирование данных сотрудника " << getName() << endl;
        cout << endl;
    }
    //переопределили подсчёт месячной ЗП
    virtual void calculate_salary(){
        average_montly_salary = 20.8 * 8 * hourly_salary;
    }
    virtual void change_salary(int new_salary){
        cout << endl;
        cout << "Почасовая оплата сотрудника " << getName() << " была изменена с " << hourly_salary << " на " << new_salary << endl;
        hourly_salary = new_salary;
        calculate_salary();
        cout << "Доход сотрудника в месяц теперь составляет: " << average_montly_salary << endl;
        cout << endl;
    };
    virtual std::ostream& print(ostream& out) {
        return out << "Работник: " << setw(25) << left << getName() 
                    << setw(15) << "Тип оплаты:  " << setw(25) << left << type
                << setw(20) << left << " Должность: " << setw(20) << getPos() 
                << "Стаж: "  << setw(10) << getExp() 
               << setw(5)  << "ЗП: "  << average_montly_salary << "\n";
    }
};

class mountly_employee : public employee
{
private:
    int mountly_salary;
public:
    mountly_employee(): mountly_salary(0){type = "фиксированная";}
    ~mountly_employee() {}
    mountly_employee(string name, string pos = " ", int year = 2024, int m_s = 0): employee(name, pos, year)
    {   
        type = "фиксированная";
        mountly_salary = m_s;
        calculate_salary();
    }
    //конструктор копирования
    mountly_employee(const mountly_employee& other) : employee(other)
    {
        setName(other.getName() + "(copy)");
        setPos(other.getPos());
        setExp(other.getExp());

        cout << "Успешно выполнено копирование данных сотрудника " << getName() << endl;
        cout << endl;
    }

    virtual void calculate_salary()
    {
        average_montly_salary = mountly_salary;
    }
    virtual void change_salary(int new_salary){
        cout << endl;
        cout << "Фиксированная оплата сотрудника " << getName() << " была изменена с " << mountly_salary << " на " << new_salary << endl;
        mountly_salary = new_salary;
        calculate_salary();
        cout << "Доход сотрудника в месяц теперь составляет: " << average_montly_salary << endl;
        cout << endl;
    };
    virtual std::ostream& print(ostream& out) 
    {
        return out << "Работник: " << setw(25) << left << getName() 
                    << setw(15) << "Тип оплаты:  " << setw(29) << left << type
                << setw(20) << left << " Должность: " << setw(20) << getPos() 
                << "Стаж: "  << setw(10) << getExp() 
               << setw(5)  << "ЗП: "  << average_montly_salary << "\n";
    }
};