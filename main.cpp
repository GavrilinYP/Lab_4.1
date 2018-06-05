#include <iostream>
#include <cstring>
using namespace std;

char nible_to_hex(uint8_t i) {
    char symbols[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C',
            'D', 'E', 'F'};
    return symbols[i];
}

void print_byte (uint8_t byte){
    uint8_t low=byte & 0b00001111;
    uint8_t high=(byte & 0b11110000)>>4;
    cout<<nible_to_hex(high)<<nible_to_hex(low);
}

char bit_digit(uint8_t byte, uint8_t bit) {
    if (byte & (0x1 << bit)) {
        return '1';
    }
    return '0';
}

void print_in_binary(uint8_t byte) {
    for (uint8_t bit = 7; bit > 0; bit--) {
        cout << bit_digit(byte, bit);
    }
    cout << bit_digit(byte, 0);
}

const uint8_t*  as_bytes(const void *data){
return reinterpret_cast<const uint8_t*>(data);}

void print_in_bin(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_binary(bytes[i]);


        if ((i + 1) % 4 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}



void  print_in_hex (const void* data, size_t size){
    const char* p= reinterpret_cast<const char*>(data);
    for (size_t i=0; i<size; i++){
        print_byte(p[i]);
        if ((i + 1) % 16 == 0) {
            cout << "\n";
        }
        else {
            cout << " ";
        }
    }}

struct student{
    char name[17];
    int year;
    float srbal;
    int sex:1;
    int courses;
    student* str;
};

int
main() {
    student s[3];
    int i, x, z, rez, key;
    char  v;
    cout<<" Calc[1] or Students[2]\n";
    cin>>key;
    if (key<2) {
        cout << "Calc\n-----------------------------------------------\n";
        cin >> x;
        cin >> v;
        cin >> z;
        cout << x <<" "<< v <<" "<< z << "\n";

        if (v == '&') {
            print_in_hex(&x, 2);
            cout << "& ";
            print_in_hex(&z, 2);
            cout << "= ";
            rez = x & z;
            print_in_hex(&rez, 2);
            cout << "\n";
            print_in_bin(&x, 2);
            cout << " & ";
            print_in_bin(&z, 2);
            cout << "= ";
            print_in_bin(&rez, 2);
            cout << "\n\n";
        }
        else {
            if (v == '|') {
                print_in_hex(&x, 2);
                cout << "| ";
                print_in_hex(&z, 2);
                cout << "= ";
                rez = x | z;
                print_in_hex(&rez, 2);
                cout << "\n";
                print_in_bin(&x, 2);
                cout << " | ";
                print_in_bin(&z, 2);
                cout << "= ";
                print_in_bin(&rez, 2);
                cout << "\n\n";
            }
            else {
                if (v == '^') {
                    print_in_hex(&x, 2);
                    cout << "^ ";
                    print_in_hex(&z, 2);
                    cout << "= ";
                    rez = x ^ z;
                    print_in_hex(&rez, 2);
                    cout << "\n";
                    print_in_bin(&x, 2);
                    cout << " ^ ";
                    print_in_bin(&z, 2);
                    cout << "= ";
                    print_in_bin(&rez, 2);
                    cout << "\n\n";

                }
                else
                    cout << "error";
            }
        }
    }
    else {
        cout << "Students\n-----------------------------------------------\n";

        strcpy(s[0].name, "Ivan");
        s[0].year = 1989;
        s[0].srbal = 5;
        s[0].sex = 1;
        s[0].courses = 5;
        s[0].str = &s[1];
        strcpy(s[1].name, "Nikolay");
        s[1].year = 2014;
        s[1].srbal = 2;
        s[1].sex = 1;
        s[1].courses = 2;
        s[1].str = nullptr;
        strcpy(s[2].name, "Yuriy");
        s[2].year = 2000;
        s[2].srbal = 3;
        s[2].sex = 1;
        s[2].courses = 5;
        s[2].str = &s[1];
        cout << "-----------------------------------------------\n";
        cout << "address of array = " << &s << "\n";
        cout << "size of array = " << sizeof(s) << "\n\n";
        cout << "-----------------------------------------------\n";
        cout << "N Adress    Size\n";
        for (i = 0; i <= 2; i++)
            cout << i+1 << " " << &s[i] << "  " << sizeof(s[i]) << "\n";
        cout << "-----------------------------------------------\n";
        cout<<"for the fist element:\n";
        cout<<"Addres of field:"<<"\tsize of field:"<<"\toffset:\n";
        cout<<"NAME:\t"<<&s[0].name<<"\t";
        cout<<sizeof(s[0].name)<<"\t\t"<<offsetof(struct student, name)<<"\n";
        cout<<"YEAR:\t"<<&s[0].year<<"\t";
        cout<<sizeof(s[0].year)<<"\t\t"<<offsetof(struct student, year)<<"\n";
        cout<<"SRBL:\t"<<&s[0].srbal<<"\t";
        cout<<sizeof(s[0].srbal)<<"\t\t"<<offsetof(struct student, srbal)<<"\n";
        cout<<"CURS:\t"<<&s[0].courses<<"\t";
        cout<<sizeof(s[0].courses)<<"\t\t"<<offsetof(struct student, courses)<<"\n";
        cout<<"STAR:\t"<<&s[0].str<<"\t";
        cout<<sizeof(s[0].str)<<"\t\t"<<offsetof(struct student, str)<<"\n";
        cout << "-----------------------------------------------\n";
        cout<<"Hex:\n";
        cout<<"NAME:";
        print_in_hex(&s[0].name, sizeof s[0].name);
        cout << "\n";
        cout<<"YEAR:";
        print_in_hex(&s[0].year, sizeof s[0].year);
        cout << "\n";
        cout<<"CURS:";
        print_in_hex(&s[0].courses, sizeof s[0].courses);
        cout << "\n";
        cout<<"STAR:";
        print_in_hex(&s[0].str, sizeof s[0].str);
        cout << "\n";
        cout << "-----------------------------------------------\n";
        cout<<"Binary:\n";
        print_in_bin(&s[0], sizeof s[0].name);
        cout << "\n";
        cout << "-----------------------------------------------\n";
        cout<<"All elements in Hex:\n";
        for (i = 0; i <= 2; i++){
            cout<<"N["<<i+1<<"]\n";
            cout<<"NAME:";
            print_in_hex(&s[i].name, sizeof s[i].name);
            cout << "\n";
            cout<<"YEAR:";
            print_in_hex(&s[i].year, sizeof s[i].year);
            cout << "\n";
            cout<<"CURS:";
            print_in_hex(&s[i].courses, sizeof s[i].courses);
            cout << "\n";
            cout<<"STAR:";
            print_in_hex(&s[i].str, sizeof s[i].str);
            cout << "\n";
        cout << "\n";
    }}

    return 0;
}