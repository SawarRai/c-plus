#include <iostream>
#include <cstring>

using namespace std;

class STRING {
private:
    static const int MAX_LENGTH = 100; 
    char str[MAX_LENGTH + 1]; 
    int length; 

public:
    STRING(const char *s = "") {
        length = strlen(s);
        if (length > MAX_LENGTH) {
            cerr << "String exceeds maximum length\n";
            exit(1);
        }
        strcpy(str, s);
    }

    STRING(const STRING &other) {
        length = other.length;
        strcpy(str, other.str);
    }


    ~STRING() { }

  
    STRING operator+(const STRING &other) const {
        STRING temp;
        if (length + other.length > MAX_LENGTH) {
            cerr << "Concatenated string exceeds maximum length\n";
            exit(1); 
        }
        strcpy(temp.str, str);
        strcat(temp.str, other.str);
        temp.length = length + other.length;
        return temp;
    }


    STRING& operator=(const STRING &other) {
        if (this != &other) {
            length = other.length;
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
