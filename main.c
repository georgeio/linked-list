#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "l_funcs.h"



int 
main(int argc, char* argv[])
{
	node nod1 = new_node();
	list *n_list = new_list(&nod1);
	node *n = n_list->vt->get_first_node(n_list);

	printf("First node is at: %p Node ID is: %d\n", n, n->id);

	node nod2 = new_node();
	n_list->vt->add_node(n_list, &nod2);
	n = n_list->vt->get_last_node(n_list); 

	printf("Second node is at %p Node ID is: %d\n", n, n->id);

	int ids[n_list->node_count];       
	n_list->vt->get_all_nodes_id(n_list, ids);
 	int i;

	for (i = 0; i < ( sizeof(ids)/ sizeof(typeof(ids[0])) ); ++i)
	{
	    printf("ID for %d   is: %d\n", (i + 1), ids[i]);
	}

	free(n_list);

	return 0;
}
