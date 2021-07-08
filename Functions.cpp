#include<iostream>
#include <ctime>
#include <vector>
#include <Windows.h>
#include <string>
#include "Functions.h"
#include <fstream>
using namespace std;


string cin16()
{
    string x;
    do
    {
        getline(cin, x);
    } while (x.size() == 0);

    if (x.size() <= 16)
    {
        return x;
    }
    else
    {
        cout << "Вы ввели слишком длинное слово" << endl << "Введите новое: ";
        return cin16();
    }
}

void print16(string x)
{
    cout << "|" + x;
    for (int i = 0; i < 16 - x.size(); i++)
    {
        cout << ' ';
    }
}

void print3(string x)
{
    cout << "|" + x;
    for (int i = 0; i < 3 - x.size(); i++)
    {
        cout << ' ';
    }
}

void out3(string x, string f)
{
    ofstream out;
    out.open(f, ios_base::app);
    if (out.is_open())
    {
        out << "|" + x;
        for (int i = 0; i < 3 - x.size(); i++)
        {
            out << ' ';
        }
    }
}

void out16(string x, string f)
{
    ofstream out;
    out.open(f, ios_base::app);
    if (out.is_open())
    {
        out << "|" + x;
        for (int i = 0; i <  16 - x.size(); i++)
        {
            out << ' ';
        }
    }
}

int cinInt()
{
    string x;
    cin >> x;
    if (x.find_first_not_of("0123456789") == string::npos)
    {
        return stoi(x);
    }
    else
    {
        cout << "Вы ввели не число!" << endl << "Введите число: ";
        return cinInt();
    }
}

bool op_del()
{
    system("cls");
    int choice;
    cout << "Вы действительно хотите произвести удаление\n1. Да, продолжить\n2. Нет, вернуться назад"; 
    cout << "\n\nВаш выбор: "; choice = cinInt();
    switch (choice)
    {
    case 1: return true;
    case 2: return false;
    default: return op_del();
    }
}


Service::Service(string service, int cost, string master)
{
    c_service = service;
    c_cost = cost;
    c_master = master;
}

Service::Service()
{
    cout << "Введите услугу: "; c_service = cin16();
    cout << "Введите цену: "; c_cost = cinInt();
    cout << "Введите имя мастера: "; c_master = cin16();
}

void Service::change()
{
    cout << endl;
    int choice;
    cout << "Что вы желаете изменить\n1. Услуга\n2. Цена\n3. Имя мастера\n"; 
    cout << "Ваш выбор: ";  choice = cinInt();
    switch (choice)
    {
    case 1:
        cout << "\nВведите новое наименование услуги: "; c_service = cin16();
        break;
    case 2:
        cout << "\nВведите новую цену: "; c_cost = cinInt();
        break;
    case 3:
        cout << "\nВведите новое имя мастера: "; c_master = cin16();
        break;
    default:
        change();
    }
}

void Service::print()
{
    print16(c_service);
    print16(to_string(c_cost));
    print16(c_master);
    cout << '|' << endl;
}

void print_service(vector<Service> adm)
{
    cout << "________________________________________________________\n";
    cout << "| № |     Услуга     |    Цена ($)    |     Мастер     |\n";
    for (int i = 0; i < adm.size(); i++)
    {
        print3(to_string(i + 1));
        adm[i].print();
    }
}

void admin_service(vector<Service> serv, vector<User> users)
{
    system("cls");
    cout << "\t\t\t\t\tАдминистратор (услуги)\n\n";
    cout << "1. Добавить\n2. Удалить\n3. Изменить\n4. Вернуться к окну администратора\n\n";
    print_service(serv);
    int choice;
    cout << "\nВаш выбор: "; choice = cinInt();
    vector<Service>::iterator iter = serv.begin();

    switch (choice)
    {
    case 1:
        system("cls");
        cout << "\t\t\t\t\tДобавление услуги\n\n";
        serv.push_back(Service());
        cout << "Услуга успешно добавлена!" << endl << endl;
        system("pause");
        admin_service(serv, users);
        break;
    case 2:
        if (op_del())
        {
            system("cls");
            cout << "\t\t\t\t\tУдаление услуги\n\n";
            print_service(serv);
            int del_serv;
            cout << endl << "Какой номер услуги желаете удалить: "; del_serv = cinInt();
            if (del_serv > serv.size())
            {
                admin_service(serv, users);
            }
            serv.erase(iter + del_serv - 1);
            cout << "Услуга успешно удалена!" << endl << endl;
            system("pause");
            admin_service(serv, users);
            break;
        }
        else
        {
            admin_service(serv, users);
            break;
        }
    case 3:
        if (serv.empty())
        {
            admin_service(serv, users);
        }
        system("cls");
        cout << "\t\t\t\t\tРедактирование\n\n";
        print_service(serv);
        int n;
        cout << "\nКакой номер услуги вы хотите изменить: "; n = cinInt();
        if (n > serv.size())
        {
            admin_service(serv, users);
        }
        serv[n - 1].change();
        admin_service(serv,users);
        break;
    case 4:
        admin(users, serv);
        break;
    default:
        admin_service(serv, users);
        break;
    }
}

User::User(string login, string password, string date, string tel, string master, string n_date)
{
    u_login = login;
    u_password = password;
    u_date = date;
    u_tel = tel;
    u_master = master;
    un_date = n_date;
}

User::User()
{
    cout << "Введите логин: "; u_login = cin16();
    cout << "Введите пароль: "; u_password = cin16();
    cout << "Введите дату посещения: "; u_date = cin16();
    cout << "Введите телефон пользователя: "; u_tel = cin16();
    cout << "Введите имя мастера: "; u_master = cin16();
    cout << "Введите следующую дату посещения: "; un_date = cin16();
}

void User::change()
{
    cout << endl;
    int choice;
    cout << "Что вы желаете изменить\n1. Логин\n2. Пароль\n3. Дату посещения\n4. Телефон\n5. Имя мастера\n6. Следующую дату посещения\n";
    cout << "Ваш выбор: ";  choice = cinInt();
    switch (choice)
    {
    case 1:
        cout << "\nВведите новый логин: "; u_login = cin16();
        break;
    case 2:
        cout << "\nВведите новый пароль: "; u_password = cin16();
        break;
    case 3:
        cout << "\nВведите новую дату посещения: "; u_date = cin16();
        break;
    case 4:
        cout << "\nВведите новый телефон: "; u_tel = cin16();
        break;
    case 5:
        cout << "\nВведите новое имя мастера: "; u_master = cin16();
        break;
    case 6:
        cout << "\nВведите новую следующую дату посещения: "; un_date = cin16();
        break;
    default:
        change();
    }
}

void User::print()
{
    print16(u_login);
    print16(u_password);
    print16(u_date);
    print16(u_tel);
    print16(u_master);
    print16(un_date);
    cout << '|' << endl;
}

void print_users(vector<User> users)
{
    cout << "___________________________________________________________________________________________________________\n";
    cout << "| № |      Логин     |     Пароль     | Дата посещения | Номер телефона |     Мастер     |Дата след.записи|\n";
    for (int i = 0; i < users.size(); i++)
    {
        print3(to_string(i + 1));
        users[i].print();
    }
}

void admin_users(vector<User> users, vector<Service> serv)
{
    system("cls");
    cout << "\t\t\t\t\tАдминистратор (пользователи)\n\n";
    cout << "1. Добавить пользователя\n2. Удалить пользователя\n3. Редактировать пользователя\n4. Вывести клиентов мастера\n5. Вернуться к окну администратора\n";
    cout << "\t\t\t\t\tБаза клиентов\n";
    print_users(users);

    int choice, del_user, number = 0;
    string o_master;
    vector<User>::iterator iter = users.begin();
    cout << "Ваш выбор: "; choice = cinInt();
    switch (choice)
    {
    case 1:
        system("cls");
        cout << "\t\t\t\t\tДобавление пользователя\n\n";
        users.push_back(User());
        cout << "Пользователь успешно добавлен!" << endl << endl;
        system("pause");
        admin_users(users, serv);
        break;
    case 2:
        if (op_del())
        {
            system("cls");
            cout << "\t\t\t\t\tУдаление пользователя\n\n";
            print_users(users);
            cout << endl << "Какой номер пользователя желаете удалить: "; del_user = cinInt();
            if (del_user > users.size())
            {
                admin_users(users, serv);
            }
            users.erase(iter + del_user - 1);
            cout << "Пользователь успешно удален!" << endl << endl;
            system("pause");
            admin_users(users, serv);
            break;
        }
        else
        {
            admin_users(users, serv);
            break;
        }
        
    case 3:
        if (users.empty())
        {
            admin_users(users, serv);
        }
        system("cls");
        cout << "\t\t\t\t\tРедактирование\n";
        print_users(users);
        int n;
        cout << "\nКакой номер пользователя хотите изменить: "; n = cinInt();
        if (n > users.size())
        {
            admin_users(users, serv);
        }
        users[n - 1].change();
        admin_users(users, serv);
        break;
    case 4:
        system("cls");
        print_users(users);
        cout << "\nКлиентов какого мастера вы желаете увидеть: "; cin >> o_master;
        cout << "\n___________________________________________________________________________________________________________\n";
        cout << "| № |      Логин     |     Пароль     | Дата посещения | Номер телефона |     Мастер     |Дата след.записи|\n";
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].u_master == o_master)
            {
                print3(to_string(i + 1));
                users[i].print();
                number++;
            }
        }
        if (number == 0)
        {
            cout << "\nПо Вашему запросу ничего не найдено\n\n";
        }
        else
        {
            cout << "\nОбщее количество клиентов мастера: " << number << endl << endl;
        }
        system("pause");
        admin_users(users, serv);
        break;
    case 5:
        admin(users, serv);
        break;
    default:
        admin_users(users,serv);
        break;
    }
}

void toFile(vector<User> users, vector<Service> serv)
{
    string f;
    ofstream out;
    cout << "Введите имя файла, в который хотите записать данные: "; cin >> f;
    out.open(f);
    if (out.is_open())
    {
        out << "\t\t\t\tДанные о всех пользователях\n\n";
        out << "| № |      Логин     |     Пароль     | Дата посещения | Номер телефона |     Мастер     |Дата след.записи|\n";
        out.close();
        for (int i = 0; i < users.size(); i++)
        {
            out3(to_string(i + 1), f);
            out16(users[i].u_login, f);
            out16(users[i].u_password, f);
            out16(users[i].u_date, f);
            out16(users[i].u_tel, f);
            out16(users[i].u_master, f);
            out16(users[i].un_date, f);
            out3("  \n", f);
        }

        out.open(f, ios_base::app);
        out << "\n\n\t\t\t\tДанные о всех услугах\n\n";
        out << "________________________________________________________\n";
        out << "| № |     Услуга     |    Цена ($)    |     Мастер     |\n";
        out.close();
        for (int i = 0; i < serv.size(); i++)
        {
            out3(to_string(i + 1), f);
            out16(serv[i].c_service, f);
            out16(to_string(serv[i].c_cost), f);
            out16(serv[i].c_master, f);
            out3("  \n", f);
        }
    }
    out.close();
    cout << "Данные в файл успешно записаны\n";
    system("pause");
}

void admin(vector<User> users, vector<Service> serv)
{
    int choice;
    string name;
    system("cls");
    cout << "\t\t\t\t\tАдминистратор\n\n";
    cout << "1. База пользователей\n2. База услуг\n3. Записать все данные о пользователях и услугах в файл\n4. Удалить файл\n5. Вернуться на начальное окно";
    cout << "\nВаш выбор: "; choice = cinInt();
    switch (choice)
    {
    case 1:
        admin_users(users, serv);
        break;
    case 2:
        admin_service(serv, users);
        break;
    case 3:
        toFile(users, serv);
        admin(users, serv);
        break;
    case 4:
        if (op_del())
        {
            system("cls");
            cout << "Введите имя файла, который хотите удалить: ";
            cin >> name;
            if (remove(name.c_str()) != 0)
            {
                cout << "\nОшибка удаления файла\n\n";
            }
            else
            {
                cout << "\nФайл успешно удалён\n\n";
            }
            system("pause");
            admin(users, serv);
            break;
        }
        else
        {
            admin(users, serv);
            break;
        }
    case 5:
        system("cls");
        enter(users, serv);
        break;
    default:
        admin(users, serv);
        break;
    }
}

void user(vector<User> users, vector<Service> serv)
{
    system("cls");
    cout << "\t\t\t\t\tПользователь\n\n";
    cout << "1. Отсортировать по цене (возрастание)\n2. Отсортировать по цене (убывание)\n";
    cout << "3. Отсортировать по мастеру\n4. Отсортировать по наименованию услуги\n5. Вернуться к начальному окну\n\n";
    print_service(serv);

    string name;
    int choice, number = 0;
    cout << "Ваш выбор: "; choice = cinInt();
    switch (choice)
    {
    case 1:
        if (serv.empty())
        {
            user(users, serv);
        }
        for (int i = 0; i < serv.size() - 1; ++i)
        {
            int smallest = i;
            for (int j = i + 1; j < serv.size(); ++j)
            {
                if (serv[j].c_cost < serv[smallest].c_cost)
                    smallest = j;
            }
            swap(serv[i], serv[smallest]);
        }
        user(users, serv);
        break;
    case 2:
        if (serv.empty())
        {
            user(users, serv);
        }
        for (int i = 0; i < serv.size() - 1; ++i)
        {
            int biggest = i;
            for (int j = i + 1; j < serv.size(); ++j)
            {
                if (serv[j].c_cost > serv[biggest].c_cost)
                    biggest = j;
            }
            swap(serv[i], serv[biggest]);
        }
        user(users, serv);
        break;
    case 3:
        if (serv.empty())
        {
            user(users, serv);
        }
        system("cls");
        print_service(serv);
        cout << "Имя мастера, услуги которого вы хотите увидеть: "; cin >> name;
        cout << "________________________________________________________\n";
        cout << "| № |     Услуга     |    Цена ($)    |     Мастер     |\n";
        for (int i = 0; i < serv.size(); i++)
        {
            if (name == serv[i].c_master)
            {
                print3(to_string(i + 1));
                serv[i].print();
                number++;
            }
        }
        if (number == 0)
        {
            cout << "\nПо Вашему запросу ничего не найдено\n\n";
        }
        system("pause");
        user(users, serv);
        break;
    case 4:
        if (serv.empty())
        {
            user(users, serv);
        }
        system("cls");
        print_service(serv);
        cout << "Наименование услуги, по которой хотите отсортировать: "; cin >> name;
        cout << "________________________________________________________\n";
        cout << "| № |     Услуга     |    Цена ($)    |     Мастер     |\n";
        for (int i = 0; i < serv.size(); i++)
        {
            if (name == serv[i].c_service)
            {
                print3(to_string(i + 1));
                serv[i].print();
                number++;
            }
        }
        if (number == 0)
        {
            cout << "\nПо Вашему запросу ничего не найдено\n\n";
        }
        system("pause");
        user(users, serv);
        break;
    case 5:
        system("cls");
        enter(users, serv);
        break;
    default:
        user(users, serv);
        break;
    }
}

bool is_user(vector<User> users, string login, string password)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].u_login == login && users[i].u_password == password)
        {
            return true;
        }
    }
    return false;
}

void enter(vector<User> users, vector<Service> serv)
{
    string login, password;

    for(int i = 0; i < 3; i++)
    {

        cout << "Здравствуйте, введите логин и пароль\n";
        cout << "Логин: "; login = cin16();
        cout << "Пароль: "; password = cin16();
        if (login == "admin" && password == "123")
        {
            admin(users, serv);
            return;
        }
        else if (is_user(users, login, password))
        {
            user(users, serv);
            return;
        }
        else
        {
            system("cls");
            cout << "Такого пользователя не существует.\nОсталось попыток: " << 2 - i << endl << endl;
        }
    }
    system("pause");
}
