#include "doctest.h"

using namespace doctest;

#include <iostream>
#include <stdexcept>

using namespace std;

#include "Direction.hpp"
#include "Notebook.hpp"

using ariel::Direction;
using ariel::Notebook;
TEST_CASE ("Test read and erase")
{
    Notebook notebook;
    CHECK(notebook.read(1, 3, 5, Direction::Horizontal, 10) == string("__________"));
    CHECK_NOTHROW(notebook.write(100, 100, 50, Direction::Horizontal, "abcde"));
    CHECK_THROWS(notebook.write(100, 100, 50, Direction::Horizontal, "xyz"));
    CHECK(notebook.read(100, 100, 50, Direction::Horizontal, 10) == string("abcde_____"));

    notebook.erase(100, 100, 50, Direction::Horizontal, 5);

    CHECK_THROWS(notebook.write(100, 100, 50, Direction::Horizontal, "xyz"));
    CHECK(notebook.read(100, 100, 50, Direction::Horizontal, 5) == string("~~~~~"));
    CHECK_THROWS(notebook.write(100, 100, 99, Direction::Horizontal, "xyz"));

    CHECK_NOTHROW(notebook.write(5, 5, 5, Direction::Horizontal, "abcde"));
    CHECK_THROWS(notebook.write(5, 5, 5, Direction::Vertical, "xyz"));
    notebook.erase(5, 5, 5, Direction::Horizontal, 1);
    CHECK(notebook.read(5, 5, 5, Direction::Vertical, 2) == string("~-"));
}

TEST_CASE ("Test write")
{
    Notebook notebook;
    CHECK_NOTHROW(notebook.write(0, 0, 0, Direction::Horizontal, "a"));
    CHECK_THROWS(notebook.write(0, 50, 0, Direction::Vertical, "a"));

    CHECK_THROWS(notebook.write(1, -1, 1, Direction::Horizontal, "a"));

    notebook.erase(0, 50, 0, Direction::Horizontal, 1);

    CHECK_THROWS(notebook.write(0, 50, 0, Direction::Horizontal, "a"));
    CHECK_NOTHROW(notebook.write(10, 50, 0, Direction::Vertical, "aaaaaaaa"));

    notebook.erase(10, 51, 0, Direction::Horizontal, 1);

    CHECK_THROWS(notebook.write(10, 51, 0, Direction::Horizontal, "afs"));
    CHECK(notebook.read(10, 51, 0, Direction::Horizontal, 1) == string("~"));

    CHECK_NOTHROW(notebook.write(15, 50, 9, Direction::Vertical, "sdfsdfsdfsdf"));
    CHECK_THROWS(notebook.write(15, 50, 0, Direction::Horizontal, "eeerrrooorrr"));

    notebook.erase(15, 51, 9, Direction::Vertical, 2);
    CHECK(notebook.read(15, 50, 9, Direction::Horizontal, 2) == string("~~"));
    CHECK_NOTHROW(notebook.write(15, 50, 0, Direction::Horizontal, "aaaaaaaa"));
}