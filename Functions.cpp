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
        cout << "�� ����� ������� ������� �����" << endl << "������� �����: ";
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
        cout << "�� ����� �� �����!" << endl << "������� �����: ";
        return cinInt();
    }
}

bool op_del()
{
    system("cls");
    int choice;
    cout << "�� ������������� ������ ���������� ��������\n1. ��, ����������\n2. ���, ��������� �����"; 
    cout << "\n\n��� �����: "; choice = cinInt();
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
    cout << "������� ������: "; c_service = cin16();
    cout << "������� ����: "; c_cost = cinInt();
    cout << "������� ��� �������: "; c_master = cin16();
}

void Service::change()
{
    cout << endl;
    int choice;
    cout << "��� �� ������� ��������\n1. ������\n2. ����\n3. ��� �������\n"; 
    cout << "��� �����: ";  choice = cinInt();
    switch (choice)
    {
    case 1:
        cout << "\n������� ����� ������������ ������: "; c_service = cin16();
        break;
    case 2:
        cout << "\n������� ����� ����: "; c_cost = cinInt();
        break;
    case 3:
        cout << "\n������� ����� ��� �������: "; c_master = cin16();
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
    cout << "| � |     ������     |    ���� ($)    |     ������     |\n";
    for (int i = 0; i < adm.size(); i++)
    {
        print3(to_string(i + 1));
        adm[i].print();
    }
}

void admin_service(vector<Service> serv, vector<User> users)
{
    system("cls");
    cout << "\t\t\t\t\t������������� (������)\n\n";
    cout << "1. ��������\n2. �������\n3. ��������\n4. ��������� � ���� ��������������\n\n";
    print_service(serv);
    int choice;
    cout << "\n��� �����: "; choice = cinInt();
    vector<Service>::iterator iter = serv.begin();

    switch (choice)
    {
    case 1:
        system("cls");
        cout << "\t\t\t\t\t���������� ������\n\n";
        serv.push_back(Service());
        cout << "������ ������� ���������!" << endl << endl;
        system("pause");
        admin_service(serv, users);
        break;
    case 2:
        if (op_del())
        {
            system("cls");
            cout << "\t\t\t\t\t�������� ������\n\n";
            print_service(serv);
            int del_serv;
            cout << endl << "����� ����� ������ ������� �������: "; del_serv = cinInt();
            if (del_serv > serv.size())
            {
                admin_service(serv, users);
            }
            serv.erase(iter + del_serv - 1);
            cout << "������ ������� �������!" << endl << endl;
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
        cout << "\t\t\t\t\t��������������\n\n";
        print_service(serv);
        int n;
        cout << "\n����� ����� ������ �� ������ ��������: "; n = cinInt();
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
    cout << "������� �����: "; u_login = cin16();
    cout << "������� ������: "; u_password = cin16();
    cout << "������� ���� ���������: "; u_date = cin16();
    cout << "������� ������� ������������: "; u_tel = cin16();
    cout << "������� ��� �������: "; u_master = cin16();
    cout << "������� ��������� ���� ���������: "; un_date = cin16();
}

void User::change()
{
    cout << endl;
    int choice;
    cout << "��� �� ������� ��������\n1. �����\n2. ������\n3. ���� ���������\n4. �������\n5. ��� �������\n6. ��������� ���� ���������\n";
    cout << "��� �����: ";  choice = cinInt();
    switch (choice)
    {
    case 1:
        cout << "\n������� ����� �����: "; u_login = cin16();
        break;
    case 2:
        cout << "\n������� ����� ������: "; u_password = cin16();
        break;
    case 3:
        cout << "\n������� ����� ���� ���������: "; u_date = cin16();
        break;
    case 4:
        cout << "\n������� ����� �������: "; u_tel = cin16();
        break;
    case 5:
        cout << "\n������� ����� ��� �������: "; u_master = cin16();
        break;
    case 6:
        cout << "\n������� ����� ��������� ���� ���������: "; un_date = cin16();
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
    cout << "| � |      �����     |     ������     | ���� ��������� | ����� �������� |     ������     |���� ����.������|\n";
    for (int i = 0; i < users.size(); i++)
    {
        print3(to_string(i + 1));
        users[i].print();
    }
}

void admin_users(vector<User> users, vector<Service> serv)
{
    system("cls");
    cout << "\t\t\t\t\t������������� (������������)\n\n";
    cout << "1. �������� ������������\n2. ������� ������������\n3. ������������� ������������\n4. ������� �������� �������\n5. ��������� � ���� ��������������\n";
    cout << "\t\t\t\t\t���� ��������\n";
    print_users(users);

    int choice, del_user, number = 0;
    string o_master;
    vector<User>::iterator iter = users.begin();
    cout << "��� �����: "; choice = cinInt();
    switch (choice)
    {
    case 1:
        system("cls");
        cout << "\t\t\t\t\t���������� ������������\n\n";
        users.push_back(User());
        cout << "������������ ������� ��������!" << endl << endl;
        system("pause");
        admin_users(users, serv);
        break;
    case 2:
        if (op_del())
        {
            system("cls");
            cout << "\t\t\t\t\t�������� ������������\n\n";
            print_users(users);
            cout << endl << "����� ����� ������������ ������� �������: "; del_user = cinInt();
            if (del_user > users.size())
            {
                admin_users(users, serv);
            }
            users.erase(iter + del_user - 1);
            cout << "������������ ������� ������!" << endl << endl;
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
        cout << "\t\t\t\t\t��������������\n";
        print_users(users);
        int n;
        cout << "\n����� ����� ������������ ������ ��������: "; n = cinInt();
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
        cout << "\n�������� ������ ������� �� ������� �������: "; cin >> o_master;
        cout << "\n___________________________________________________________________________________________________________\n";
        cout << "| � |      �����     |     ������     | ���� ��������� | ����� �������� |     ������     |���� ����.������|\n";
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
            cout << "\n�� ������ ������� ������ �� �������\n\n";
        }
        else
        {
            cout << "\n����� ���������� �������� �������: " << number << endl << endl;
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
    cout << "������� ��� �����, � ������� ������ �������� ������: "; cin >> f;
    out.open(f);
    if (out.is_open())
    {
        out << "\t\t\t\t������ � ���� �������������\n\n";
        out << "| � |      �����     |     ������     | ���� ��������� | ����� �������� |     ������     |���� ����.������|\n";
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
        out << "\n\n\t\t\t\t������ � ���� �������\n\n";
        out << "________________________________________________________\n";
        out << "| � |     ������     |    ���� ($)    |     ������     |\n";
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
    cout << "������ � ���� ������� ��������\n";
    system("pause");
}

void admin(vector<User> users, vector<Service> serv)
{
    int choice;
    string name;
    system("cls");
    cout << "\t\t\t\t\t�������������\n\n";
    cout << "1. ���� �������������\n2. ���� �����\n3. �������� ��� ������ � ������������� � ������� � ����\n4. ������� ����\n5. ��������� �� ��������� ����";
    cout << "\n��� �����: "; choice = cinInt();
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
            cout << "������� ��� �����, ������� ������ �������: ";
            cin >> name;
            if (remove(name.c_str()) != 0)
            {
                cout << "\n������ �������� �����\n\n";
            }
            else
            {
                cout << "\n���� ������� �����\n\n";
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
    cout << "\t\t\t\t\t������������\n\n";
    cout << "1. ������������� �� ���� (�����������)\n2. ������������� �� ���� (��������)\n";
    cout << "3. ������������� �� �������\n4. ������������� �� ������������ ������\n5. ��������� � ���������� ����\n\n";
    print_service(serv);

    string name;
    int choice, number = 0;
    cout << "��� �����: "; choice = cinInt();
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
        cout << "��� �������, ������ �������� �� ������ �������: "; cin >> name;
        cout << "________________________________________________________\n";
        cout << "| � |     ������     |    ���� ($)    |     ������     |\n";
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
            cout << "\n�� ������ ������� ������ �� �������\n\n";
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
        cout << "������������ ������, �� ������� ������ �������������: "; cin >> name;
        cout << "________________________________________________________\n";
        cout << "| � |     ������     |    ���� ($)    |     ������     |\n";
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
            cout << "\n�� ������ ������� ������ �� �������\n\n";
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

        cout << "������������, ������� ����� � ������\n";
        cout << "�����: "; login = cin16();
        cout << "������: "; password = cin16();
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
            cout << "������ ������������ �� ����������.\n�������� �������: " << 2 - i << endl << endl;
        }
    }
    system("pause");
}
