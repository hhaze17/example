#include<iostream>
#include <ctime>
#include <vector>
#include <Windows.h>
#include <string>
#include "Functions.h"
#include <fstream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Service> serv;
    serv.push_back(Service("Маникюр", 25, "Валерия"));
    serv.push_back(Service("Укладка", 54, "Евгения"));
    serv.push_back(Service("Косметология", 65, "Татьяна"));
    serv.push_back(Service("Педикюр", 23, "Дарья"));
    serv.push_back(Service("Стрижка", 45, "Екатерина"));
    serv.push_back(Service("Окрашивание", 77, "Ксения"));
    serv.push_back(Service("Ресницы", 35, "Оксана"));
    serv.push_back(Service("Наращивание", 45, "Оксана"));
    serv.push_back(Service("Тонирование", 30, "Ксения"));
    serv.push_back(Service("Прическа", 27, "Евгения"));
    serv.push_back(Service("Окрашивание", 57, "Ксения"));
    serv.push_back(Service("Педикюр", 25, "Валерия"));
    serv.push_back(Service("Маникюр", 30, "Жанна"));
    serv.push_back(Service("Брови", 35, "Оксана"));
    serv.push_back(Service("Косметология", 100, "Оксана"));
    serv.push_back(Service("Маникюр", 45, "Ирина"));
    serv.push_back(Service("Косметология", 120, "Людмила"));

    vector<User> users;
    users.push_back(User("user1", "user11", "22.12.21", "66-33-12", "Ирина", "22.01.21"));
    users.push_back(User("Арина", "arina", "13.05.21", "54-41-53", "Жанна", "13.06.21"));
    users.push_back(User("Анастасия", "nastya", "15.10.21", "18-28-53", "Евгения", "15.11.21"));
    users.push_back(User("Евгения", "jenya", "16.05.21", "53-12-28", "Валерия", "16.06.21"));
    users.push_back(User("Катерина", "katya", "30.01.21", "10-93-47", "Валерия", "30.02.21"));
    users.push_back(User("Жанна", "janna", "16.10.21", "55-32-13", "Людмила", "18.11.21"));
    users.push_back(User("Диана", "diana", "11.06.21", "52-34-53", "Жанна", "13.01.21"));
    users.push_back(User("Полина", "polya", "18.11.21", "19-12-43", "Ксения", "31.07.21"));
    users.push_back(User("Алина", "alina", "03.05.21", "51-43-64", "Оксана", "12.09.21"));
    users.push_back(User("Елизавета", "liza", "16.04.21", "92-99-56", "Оксана", "27.05.21"));

    enter(users, serv);
    return 0;
}
