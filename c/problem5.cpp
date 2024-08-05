#include <iostream>
#include <cstring> 

using namespace std;

class STRING {
private:
    char *str;   
    int length;  

public:
    STRING(const char *s = "") {
        length = strlen(s);
        str = new char[length + 1];  
        strcpy(str, s);
    }

    STRING(const STRING &other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    
    ~STRING() {
        delete[] str;
    }

    
    STRING operator+(const STRING &other) const {
        STRING temp;
        temp.length = length + other.length;
        temp.str = new char[temp.length + 1];
        strcpy(temp.str, str);
        strcat(temp.str, other.str);
        return temp;
    }

    STRING& operator=(const STRING &other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    
    bool operator==(const STRING &other) const {
        return (length == other.length) && (strcmp(str, other.str) == 0);
    }

  
    void display() const {
        cout << str << endl;
    }
};

int main() {
    STRING s1("HI");
    STRING s2("Hello");
    STRING s3 = s1 + s2;  

    cout << "s1: ";
    s1.display();  
    cout << "s2: ";
    s2.display();  
    cout << "s3: ";
    s3.display();  

    if (s1 == s2) {
        cout << "s1 and s2 are equal\n";
    } else {
        cout << "s1 and s2 are not equal\n";
    }

    s1 = s2;  
    cout << "After assignment s1: ";
    s1.display();  

    return 0;
}
