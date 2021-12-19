#include "Field.h"
#include <ctime>

Field::Field()
{
    _height = 0;
    _width = 0;
    _matrix = NULL;
    _max_lanscape_objects = 0;
    _lanscape_objects = 0;
    _max_neutral_objects = 0;
    _neutral_objects = 0;
}

//Constructor of creating field
Field::Field(int height, int width)
{
    srand(time(0));
    _height = height;
    _width = width;
    _matrix = new char* [height];
    _max_lanscape_objects = ((width - 2) * (height - 2)) / 4;
    _lanscape_objects = 0;
    _max_neutral_objects = ((width - 2) * (height - 2)) / 6;
    _neutral_objects = 0;
    for (int i = 0; i < height; i++) _matrix[i] = new char[width];
    //Making a border of field (at first, only on the first and last lines
    for (int i = 0; i < width; i++)
    {
        _matrix[0][i] = 'X';
        _matrix[height - 1][i] = 'X';
    }
    //Making an array of empty elements with border (first and last elements)
    for (int i = 1; i < height - 1; i++)
    {
        _matrix[i][0] = 'X';
        for (int j = 1; j < width - 1; j++)
        {
            if ((rand() % 10 == 2) and (_lanscape_objects <= _max_lanscape_objects)) _matrix[i][j] = '^';
            else if ((rand() % 6 == 1) and (_lanscape_objects <= _max_lanscape_objects)) _matrix[i][j] = '~';
            else if ((rand() % 15 == 4) and (_neutral_objects <= _max_neutral_objects)) _matrix[i][j] = 'P';
            else if ((rand() % 15 == 0) and (_neutral_objects <= _max_neutral_objects)) _matrix[i][j] = 'J';
            else if ((rand() % 15 == 2) and (_neutral_objects <= _max_neutral_objects)) _matrix[i][j] = 'A';
            else if ((rand() % 15 == 3) and (_neutral_objects <= _max_neutral_objects)) _matrix[i][j] = 'T';
            else _matrix[i][j] = '*';
            if (_matrix[i][j] != '*') _lanscape_objects++;
        }
        _matrix[i][width - 1] = 'X';
    }
    _matrix[1][1] = 'B';
}

Field::Field(const Field& anotherField)
{
    _height = anotherField._height;
    _width = anotherField._width;
    _matrix = new char* [anotherField._height];
    for (int i = 0; i < anotherField._width; i++) _matrix[i] = new char[anotherField._width];
    for (int i = 0; i < anotherField._width; i++)
    {
        _matrix[0][i] = 'X';
        _matrix[anotherField._height - 1][i] = 'X';
    }
    for (int i = 1; i < anotherField._height - 1; i++)
    {
        _matrix[i][0] = 'X';
        for (int j = 1; j < anotherField._width - 1; j++)
        {
            _matrix[i][j] = anotherField._matrix[i][j];
        }
        _matrix[i][anotherField._width - 1] = 'X';
    }
    _max_lanscape_objects = anotherField._max_lanscape_objects;
    _lanscape_objects = anotherField._lanscape_objects;
    _max_neutral_objects = anotherField._max_neutral_objects;
    _neutral_objects = anotherField._neutral_objects;
}

const Field& Field::operator=(const Field&& anotherField)
{
    if (&anotherField == this) return *this;
    _height = anotherField._height;
    _width = anotherField._width;
    _matrix = new char* [anotherField._height];
    for (int i = 0; i < anotherField._width; i++) _matrix[i] = new char[anotherField._width];
    for (int i = 0; i < anotherField._width; i++)
    {
        _matrix[0][i] = 'X';
        _matrix[anotherField._height - 1][i] = 'X';
    }
    for (int i = 1; i < anotherField._height - 1; i++)
    {
        _matrix[i][0] = 'X';
        for (int j = 1; j < anotherField._width - 1; j++)
        {
            _matrix[i][j] = anotherField._matrix[i][j];
        }
        _matrix[i][anotherField._width - 1] = 'X';
    }
    _max_lanscape_objects = anotherField._max_lanscape_objects;
    _lanscape_objects = anotherField._lanscape_objects;
    _max_neutral_objects = anotherField._max_neutral_objects;
    _neutral_objects = anotherField._neutral_objects;
    return *this;
}

void Field::showField()
{
    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _width; j++)
        {
            std::cout << _matrix[i][j];
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void Field::showEmptyPoints()
{
    std::cout << "Empty spaces:\n";
    for (int i = 1; i < _width - 1; i++)
    {
        std::cout << i << ": ";
        for (int j = 1; j < _height - 1; j++)
        {
            if (_matrix[j][i] == ' ') std::cout << j << ' ';
        }
        std::cout << '\n';
    }
}

bool Field::ifElement(int x, int y)
{
    if (_matrix[y][x] == '*' or _matrix[y][x] == '~')
    {
        return 1;
    }
    return 0;
}

void Field::addElement(int x, int y, char symbol)
{
    _matrix[y][x] = symbol;
}

void Field::removeElement(int x, int y, char symbol)
{
    _matrix[y][x] = symbol;
}

void Field::replaceElement(int x, int y, int newX, int newY, char unitSymbol, char floorSymbol)
{
    removeElement(x, y, floorSymbol);
    addElement(newX, newY, unitSymbol);
}

int Field::getWidth()
{
    return _width;
}

int Field::getHeight()
{
    return _height;
}

char Field::getSymbol(int x, int y)
{
    return _matrix[y][x];
}

//Destructor
Field::~Field()
{
    _height = 0;
    _width = 0;
    _matrix = NULL;
}