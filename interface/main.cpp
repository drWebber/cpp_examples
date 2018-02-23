#include <vector>

#include "magazine.h"
#include "document.h"
#include "printable.h"

#include "entity.h"
#include "dao.h"
#include "entitydao.h"
#include "entitydaoimpl.h"

using namespace std;

int main()
{
    Printable *arr[2];
    arr[0] = new Magazine();
    arr[1] = new Document();

    for (uint32_t i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        arr[i]->print();
    }

    /* Dao layer examle */
    EntityDao *entityDao = new EntityDaoImpl();

    entityDao->create(Entity());
    entityDao->read(1);
    entityDao->getLastById(1);

    return 0;
}
