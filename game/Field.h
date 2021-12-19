#include <iostream>
#include <stdio.h>
#include "FieldObjects.h"
#pragma once

class Field
{
private:
    int _height;
    int _width;
    char** _matrix;
    int _max_lanscape_objects;
    int _lanscape_objects;
    int _max_neutral_objects;
    int _neutral_objects;
public:
    Field();
    Field(int height, int width);
    Field(const Field& anotherField);
    const Field& operator=(const Field&& anotherField);
    void showField();
    void showEmptyPoints();
    bool ifElement(int x, int y);
    void addElement(int x, int y, char symbol);
    void removeElement(int x, int y, char symbol);
    void replaceElement(int x, int y, int newX, int newY, char unitSymbol, char floorSymbol);
    int getWidth();
    int getHeight();
    char getSymbol(int x, int y);
    ~Field();
};