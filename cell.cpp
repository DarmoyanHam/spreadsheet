#include <iostream>
#include "cell.h"

Cell::Cell() 
: str("") 
, isVector(false)
{}

Cell::Cell(int a) 
: str(std::to_string(a)) 
, isVector(false)
{}

Cell::Cell(double a) 
: str(std::to_string(a)) 
, isVector(false)
{}

Cell::Cell(std::string a) 
: str(a) 
, isVector(false)
{}

Cell::Cell(char a)
: str(std::to_string(a))
, isVector(false)
{}

Cell::Cell(bool a)
: str(std::to_string(a))
, isVector(false)
{}

Cell::Cell(const std::vector<int>& v)
: isVector(true)
{
    for (size_t i = 0; i < v.size(); ++i) 
    {
        if (i != 0) 
        {
            str += " "; 
        }
        str += std::to_string(v[i]); 
    }
}



Cell::Cell(const Cell& rhv) 
: str(rhv.str)
, isVector(rhv.isVector) 
{}

Cell::Cell(Cell&& rhv) 
: str(std::move(rhv.str))
, isVector(rhv.isVector)
{
    rhv.str = "";
    rhv.isVector = 0;
}

Cell::~Cell()
{}

Cell& Cell::operator=(const Cell& rhv)
{
    if (this != &rhv)
    {
        str = rhv.str;
        isVector = rhv.isVector;
    }
    return *this;
}

Cell& Cell::operator=(Cell&& rhv)
{
    if (this != &rhv) 
    {
        str = std::move(rhv.str);
        rhv.str = "";
        isVector = rhv.isVector;
        rhv.isVector = 0;
    }
    return *this;
}

Cell& Cell::operator=(int a)
{
    str = std::to_string(a);
    isVector = 0;
    return *this;
}

Cell& Cell::operator=(double a)
{
    str = std::to_string(a);
    isVector = 0;
    return *this;
}

Cell& Cell::operator=(std::string a)
{
    str = a;
    isVector = 0;
    return *this;
}

Cell& Cell::operator=(char a)
{
    str = std::to_string(a);
    isVector = 0;
    return *this;
}

Cell& Cell::operator=(bool a)
{
    str = std::to_string(a);
    isVector = 0;
    return *this;
}

Cell& Cell::operator=(const std::vector<int>& rhv)
{
    for (size_t i = 0; i < rhv.size(); ++i) 
    {
        if (i != 0) 
        {
            str += " "; 
        }
        str += std::to_string(rhv[i]); 
    }
    isVector = 1;
    return *this;
}

Cell::operator int()
{
    return std::stoi(this->str);
}

Cell::operator double()
{
    return std::stod(this->str);
}

Cell::operator std::string()
{
    return str;
}

Cell::operator char()
{
    if(str.size() != 1)
    {
        throw std::invalid_argument("The cell must have just one character");
    }
    return str[0];
}

Cell::operator bool()
{
    if(str == "true" || str == "1")
    {
        return true;
    }
    else if(str == "false" || str == "0")
    {
        return false;
    }
    throw std::invalid_argument("Cell shouldn't convert to bool");
}

Cell::operator std::vector<int>()
{
    std::vector<int> result;
    std::string numString;
    for (char c : str) 
    {
        if (c == ' ') 
        {
            result.push_back(std::stoi(numString));
            numString.clear();
        } 
        else 
        {
            numString += c;
        }
    }
    if (!numString.empty()) 
    {
        result.push_back(std::stoi(numString));
    }
    return result;
}

std::string Cell::get_cell() const
{
    return str;
}

bool operator==(Cell c1, Cell c2)
{
    return c1.get_cell() == c2.get_cell();
}

bool operator!=(Cell c1, Cell c2)
{
    return !(c1 == c2);
}

std::ostream& operator<<(std::ostream& out, const Cell& cell)
{
    out << cell.get_cell();
    return out;
}

std::istream& operator>>(std::istream& in, Cell& cell)
{
    std::string value;
    in >> value;
    cell = value;
    return in;
}
