#include <vector>

#include "magazine.h"
#include "document.h"
#include "printable.h"

using namespace std;

int main()
{
    Printable *arr[2];
    arr[0] = new Magazine();
    arr[1] = new Document();

    for (uint32_t i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        arr[i]->print();
    }

    return 0;
}
