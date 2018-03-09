#ifndef PRINTABLE_H
#define PRINTABLE_H

#include <iostream>

class Printable
{
public:
    virtual void print() = 0;
    /* В интерфейсах объявление виртуального дестуктора ОБЯЗАТЕЛЬНО.
       Т.к. если его не будет - при обходе дочерних объектов через Printable *
       тип в реализующем классе дестуктор НЕ БУДЕТ вызываться, т.к. интерфейс
       ничего не знает о дестукторе реализующего его класса!!! */
    virtual ~Printable() { }
};

#endif // PRINTABLE_H
