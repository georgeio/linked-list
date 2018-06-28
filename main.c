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
	printf("Last node is at %p Node ID is: %d\n", n, n->id);

	int ids[n_list->node_count]; 

	printf("Size of Ids is: %ld with %ld elements\n", sizeof(ids), ( sizeof(ids) / sizeof(typeof(ids[0])) ) );

	n_list->vt->get_all_nodes_id(n_list, ids);

	printf("ID for 1   is: %d\n", ids[0]);

	// for (int i = 0; i < ( sizeof(ids)/ sizeof(typeof(ids[0])) ); ++i)
	// {
	// 	printf("ID for %0003d   is: %d\n", i, ids[i]);
	// }

	free(n_list);

	return 0;
}