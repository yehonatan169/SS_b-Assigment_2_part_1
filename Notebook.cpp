#include <iostream>
#include <stdexcept>

using namespace std;

#include "Direction.hpp"
#include "Notebook.hpp"

using ariel::Direction;
using ariel::Notebook;

Notebook::Notebook() {
}

void Notebook::write(unsigned int page, unsigned int row, unsigned int column, Direction Dir, string const &word) {

}

string Notebook::read(unsigned int page, unsigned int row, unsigned int column, Direction Dir, int count) {
    return " ";
}

void Notebook::erase(unsigned int page, unsigned int row, unsigned int column, Direction Dir, int count) {

}

void Notebook::show(unsigned int page) {
}

