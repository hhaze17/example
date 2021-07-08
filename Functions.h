#pragma once
using namespace std;

string cin16();
void print16(string);
void print3(string);
void out3(string, string);
void out16(string, string);
int cinInt();
bool op_del();

class Service
{
public:
    int c_cost, c_n;
    string c_service, c_master;
    Service(string, int, string);
    Service();
    void change();
    void print();
};
void print_service(vector<Service>);

class User
{
public:
    string u_login, u_password, u_date, u_tel, u_master, un_date;
    User(string, string, string, string, string, string);
    User();
    void change();
    void print();
};

void print_users(vector<User>);
void admin_users(vector<User>, vector<Service>);
void toFile(vector<User>, vector<Service>);
void admin(vector<User>, vector<Service>);
void user(vector<User>, vector<Service>);
bool is_user(vector<User>, string, string);
void enter(vector<User>, vector<Service>);
void admin_service(vector<Service>, vector<User>);
