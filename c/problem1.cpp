#include<iostream>
using namespace std;

class Num2; 

class Num1 {
private:
    int num;
public:
    Num1(int x) : num(x) {}

    friend void swap(Num1&, Num2&); 
    friend void display(Num1&, Num2&);
};

class Num2 {
private:
    int num;
public:
    Num2(int x) : num(x) {}

    friend void swap(Num1&, Num2&);
    friend void display(Num1&, Num2&);
};

void swap(Num1 &n1, Num2 &n2) {
    int temp = n1.num;
    n1.num = n2.num;
    n2.num = temp;
}

void display(Num1 &n1, Num2 &n2) {
    cout << "Num1 = " << n1.num << ", Num2 = " << n2.num << endl;
}

int main() {
    int Num1_val, Num2_val;
    cout << "Enter Num1: ";
    cin >> Num1_val;
    cout << "Enter Num2: ";
    cin >> Num2_val;

    Num1 n1(Num1_val);
    Num2 n2(Num2_val);
    swap(n1, n2);

    cout << "After swapping:" << endl;
    display(n1, n2);

    return 0;
}
