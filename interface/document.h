#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "printable.h"

class Document : public Printable
{
public:

    // Printable interface
public:
    void print();
};

#endif // DOCUMENT_H
