#include <iostream>

using namespace std;

int main() {
    int x = 100;
    int *px = &x;
    cout << "Hello, World!" << std::endl;

    cout << "x = " << x << " , px = " << *px;

    return 0;
}

class Animal{
private:
    string name;
    int weight;
public:
    Animal(const string &name, int weight) : name(name), weight(weight) {

    }

};