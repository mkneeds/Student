#include "proverki.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
using namespace std;
class Learner {
protected:
    string FIO;
    int mark;
    int age;
public:
    Learner() {
        FIO = '\0';
        age = 0;
        mark = 0;
    }
    virtual ~Learner() {
        cout << "Деструктор Учащегося" << endl;
    }
    virtual void set() {
        cout << "\nВведите Фамилию: ";
        cin >> FIO;
        cout << "\nВведите возраст: ";
        age = checkInt();
        cout << "\nВведите оценку:";
        mark = checkInt();
    }
    virtual void show() {
        cout << "\tФамилия:" << FIO << endl;
        cout << "\tВозраст:" << age << endl;
        cout << "\tОценка:" << mark << endl;
    }
};
class CollegeStudent : public Learner {
    string college;
public:
    CollegeStudent();
    ~CollegeStudent() {
        cout << "Деструтор учащегося колледжа";
    };
 
    void set() {
        cout << "\nВведите Фамилию: ";
        cin >> FIO;
        cout << "\nВведите возраст: ";
        cin >> age;
        cout << "\nВведите оценку:";
        cin>>mark;
        cout << "\nВведите название Колледжа: ";
        cin >> college;
    }
    void show() {
        cout << "\tФамилия:" << FIO << endl;
        cout << "\tВозраст:" << age << endl;
        cout << "\tОценка:" << mark << endl;
        cout << "\tСтатус: Участник Колледжа"<<endl;
        cout << "\tНазвание Колледжа:" << college << endl;
    }
};

CollegeStudent::CollegeStudent() : Learner() {

    college = '\0';
}

class SchoolBoy : public Learner {
    string college;
public:
    SchoolBoy();
    ~SchoolBoy() {
        cout << "Деструтор учащегося школы ";
    };
   
    void set() {
        cout << "\nВведите Фамилию: ";
        cin >> FIO;
        cout << "\nВведите возраст: ";
        age = checkInt();
        cout << "\nВведите оценку:";
        mark = checkInt();
        cout << "\nВведите название школы: ";
        cin >> college;
    }
    void show() {
        cout << "\tФамилия:" << FIO << endl;
        cout << "\tВозраст:" << age << endl;
        cout << "\tОценка:" << mark << endl;
        cout << "\tСтатус: Учащийся Школы" << endl;
        cout << "\tНазвание Школы:" << college << endl;
    }
};
SchoolBoy::SchoolBoy():Learner() {

    college = '\0';
}
class Student : public Learner {
    
    string college;
public:
    Student();
    ~Student() {
        cout << "Деструтор учащегося ВУЗа";
    };

    void set() {
        cout << "\nВведите Фамилию: ";
        cin >> FIO;
        cout << "\nВведите возраст: ";
        age = checkInt();
        cout << "\nВведите оценку:";
        mark = checkInt();
        cout << "\nВведите название ВУЗа: ";
        cin >> college;
    }
    void show() {
        cout << "\tФамилия:" << FIO << endl;
        cout << "\tВозраст:" << age << endl;
        cout << "\tОценка:" << mark << endl;
        cout << "\tСтатус: Учащийся ВУЗа" << endl;
        cout << "\tНазвание ВУЗа" << college << endl;
    }
};
Student::Student() :Learner(){

    college = '\0';
}
char menu()
{
    char c;
    cout << "\t\t===Меню===" << endl
        << " 1)Добавить учащегося(Колледжа)" << endl
        << " 2)Добавить учащегося(универа)" << endl
        << " 3)Добавить учащегося(школьник)" << endl
        << " 4)Вывод всех данных на экран" << endl
        << " 5)Выход из программы";
    do
    {
        c = _getch();
    } while (!(c >= '1' && c <= '5'));
    return c;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    Learner** p = new Learner * [3];
    p[0] = new CollegeStudent[5];
    p[1] = new SchoolBoy[5];
    p[2] = new Student[5];
    Learner* uk;
    int i = 0;
    int b = 0;
    int c = 0;
    while (1) {
        switch (menu()) {
        case '1': {
            system("cls");
            uk = &p[0][i];
            uk->set();
            i++;
            break; }

        case '2': {
            system("cls");
            uk = &p[2][b];
            uk->set();
            b++;
            break;
        }
        case '3': {
            system("cls");
            uk = &p[1][c];
            uk->set();
            c++;
            break;
        }
        case '4': {
            system("cls");
            if (i)
            {
                for (int a = 0; a < i; a++)
                {
                    uk = &p[0][a];
                    uk->show();
                }
            }
            if (b)
            {
                for (int a = 0; a < b; a++)
                {
                    uk = &p[2][a];
                    uk->show();
                }
            }
            if (c)
            {
                for (int a = 0; a < c; a++)
                {
                    uk = &p[1][a];
                    uk->show();
                }
            }
            break;
        }
        case '5': {
            system("cls");
            cout << "Работа программы завершена!";
            return 0;
        }
        }
    }
}

