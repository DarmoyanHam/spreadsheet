#ifndef cell_h
#define cell_h

#include <iostream>
#include <string>
#include <vector>

class Cell {
public:
    Cell();
    Cell(int a);
    Cell(double a);
    Cell(std::string a);
    Cell(char a);
    Cell(bool a);
    Cell(const std::vector<int>& v);
    Cell(const Cell& rhv);
    Cell(Cell&& rhv);
    ~Cell();
public:
    Cell& operator=(const Cell& rhv);
    Cell& operator=(Cell&& rhv);
    Cell& operator=(int a);
    Cell& operator=(double a);
    Cell& operator=(std::string a);
    Cell& operator=(char a);
    Cell& operator=(bool a);
    Cell& operator=(const std::vector<int>& rhv);
    operator int();
    operator double();
    operator std::string();
    operator char();
    operator bool();
    operator std::vector<int>();
    std::string get_cell() const;
private:
    std::string str;
    bool isVector;
};

bool operator==(Cell c1, Cell c2);
bool operator!=(Cell c1, Cell c2);

std::ostream& operator<<(std::ostream& out, const Cell& cell);
std::istream& operator>>(std::istream& in, Cell& cell);

#endif