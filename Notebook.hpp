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
        void write( int page,  int row,  int column, Direction Dir, string const &word);
        static string read( int page,  int row,  int column, Direction Dir, int count);
        void erase( int page,  int row,  int column, Direction Dir, int count);
        void show( int page);
    };
}
#endif