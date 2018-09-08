#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "l_funcs.h"



int 
main(int argc, char* argv[])
{
	char* smp_txt = "Some sample data to store in the node";
	size_t smp_digit = 39282;

	node nod1 = ll_new_node(smp_txt);
	list* n_list = ll_new_list(&nod1);
	node* n = ll_get_first_node(n_list);

	printf("First node is at: %p Node ID is: %d Data: %s\n", n, n->id, n->data);

	node nod2 = ll_new_node(&smp_digit);
	ll_add_node(n_list, &nod2);
	n = ll_get_last_node(n_list); 

	printf("Second node is at: %p Node ID is: %d Data: %d\n", n, n->id, (*(int*) n->data));

	int ids[ ll_node_count(n_list) ];       
	ll_get_all_node_ids(n_list, ids);
 	int i;

	for (i = 0; i < ( sizeof(ids) / sizeof(ids[0]) ); ++i) {
	    printf("ID for %d   is: %d\n", (i + 1), ids[i]);
	}

	free(n_list);

	return 0;
}
