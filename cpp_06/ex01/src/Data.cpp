#include "Data.hpp"

//  ==========| CONSTRUCTORS |==========
Data::Data()
{
    number = 42;
    character = '#';
    secret_message = "The secret to cleaner code is more coffee.";
}
    

Data::Data(const Data &other)
{
    *this = other;
}

//  ===========| DESTRUCTOR |===========
Data::~Data() {}

//  =======| OPERATOR OVERLOADS |=======
Data &Data::operator=(const Data &rhs)
{
    this->number = rhs.number;
    this->character = rhs.character;
    this->secret_message = rhs.secret_message;
    return (*this);
}

std::ostream &operator<<(std::ostream &os, const Data &rhs)
{
    os << "== DATA ==\n" << "number: " << rhs.getNumber() << '\n';
    os << "character: " << rhs.getChar() << '\n';
    os << "secret message: " << rhs.getMessage() << std::endl;
}

//  ============| METHODS |=============

int Data::getNumber() const {return number;};

char Data::getChar() const {return character;};

std::string Data::getMessage() const {return secret_message;};
