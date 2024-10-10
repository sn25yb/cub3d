#ifndef INVENTORY_H
# define INVENTORY_H
# include "../../../queue/queue.h"

typedef struct s_inventory
{
    void        *image[2];
    t_queues    inventory;
    int         isopen;
}   t_inventory;


#endif