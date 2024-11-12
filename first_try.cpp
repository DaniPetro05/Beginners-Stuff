#include <iostream>
#include <vector>

int greetings(std::string &name, int &age){ //Completely passing by reference instead of by pointer.
    std::cout << "Please type in your name: \n";
    std::cin >> name;
    std::cout << "Greetings " << name <<"!";
        std::cout << " Type in your age: \n";
        std::cin >> age;
        if (age <= 18) {
            std::cout << "Apologies, but no minors are allowed. You are " << age << " years old.\n";
        } else if (age >= 65) {
            std::cout << "You sure are old for a " << age << " year old.\n";
        } else {
            std::cout << "You are " << age << " years old!\n";
    }
    return 0;
}

int main() {
    std::string name;
    int age;
    greetings(name, age); //Standalone data type variables as arguments.
    return 0;
}