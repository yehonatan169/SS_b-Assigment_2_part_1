#include <iostream>
#include <stdexcept>

using namespace std;

#include "Direction.hpp"
#include "Notebook.hpp"

using ariel::Direction;
using ariel::Notebook;

Notebook::Notebook() {
}

void Notebook::write( int page,  int row,  int column, Direction Dir, string const &word) {

}

string Notebook::read( int page,  int row,  int column, Direction Dir, int count) {
    return " ";
}

void Notebook::erase( int page,  int row,  int column, Direction Dir, int count) {

}

void Notebook::show( int page) {
}

