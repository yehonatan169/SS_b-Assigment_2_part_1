#ifndef NOTEBOOK_H
#define NOTEBOOK_H
#include <iostream>
#include <stdexcept>
using namespace std;
#include "Direction.hpp"
namespace ariel{

    class Notebook{

    public:
        Notebook();
        void write(unsigned int page, unsigned int row, unsigned int column, Direction Dir, string const &word);
        static string read(unsigned int page, unsigned int row, unsigned int column, Direction Dir, int count);
        void erase(unsigned int page, unsigned int row, unsigned int column, Direction Dir, int count);
        void show(unsigned int page);
    };
}
#endif