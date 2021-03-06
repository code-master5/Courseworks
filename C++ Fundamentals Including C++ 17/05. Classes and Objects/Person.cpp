#include "Person.h"
#include <iostream>

/*
using keyword basically copies down the whole specified namespace.
Therefore, it is better to copy down only required thing rather than
the whole namespace.
*/
/*
Never use the using keyword in header files because the users including
your header files might not want your copied down data 
*/

using std::cout;
using std::endl;

/*
This is initializer syntax
It is better to initialize variables before constructor body
because if variables are user defined types (say class objects)
then before the control goes to control goes to constructor body
it first initializes the variables and then executes the constructor body.
So if programmer initializes variables inside constructor body, then it is
doing same work twice.
*/
Person::Person(std::string first, std::string last) : firstname(first), lastname(last) {
    std::cout << "Constructing Person: " << getName() << std::endl;
}

Person::Person() {
    std::cout << "Constructing Person: " << getName() << std::endl;
}

Person::~Person() {
    std::cout << "Destructing Person: " << getName() << std::endl;
}

/* 'const' keyword ensures that member function must not change any
data member */
/* A better design is to start by declaring each member function as
const. Then, if the function changes any data member, remove const from
it */
std::string Person::getName() const {
    return this->firstname + " " + this->lastname;
}