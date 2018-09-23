#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "l_list/l_lists.h"

int 
main(int argc, char* argv[])
{
	char smp_txt[] = "Some sample data to store in the node";
	char smp_txt2[] = "Another set of sample data for node 2";
	int ids[12]; 

	list* n_list = ll_new_list(); //create new list

	node nod1 = ll_new_node(smp_txt);
	ll_add_node(n_list, &nod1); //add node to list

	node* n = ll_first_node(n_list); //get first node from list

	puts("[--] First node [--]");
	printf("Node Address: %p\nNode ID: %d\nNode Data: %s\n\n", n, ll_node_id(n), ll_node_data(n));

	node nod2 = ll_new_node(smp_txt2);
	ll_add_node(n_list, &nod2);

	n = ll_last_node(n_list); //get last node from list

	puts("[--] Last node [--]");
	printf("Node Address: %p\nNode ID: %d\nNode Data: %s\n\n", n, ll_node_id(n), ll_node_data(n));

	//Get IDs of all nodes in the list      
	ll_all_ids(n_list, ids);

 	//iterate through list of node IDs
	for (size_t i = 0; i < ll_node_count(n_list); ++i) {
	    printf("ID for %zu   is: %d\n", (i + 1), ids[i]);
	}

	//delete a node from list by node address
	ll_remove_node_byadr(n_list, &nod2);

	//Get remaining set of node IDs in the list    
	ll_all_ids(n_list, ids);
 	
 	//iterate through list of remaining node IDs
	for (size_t i = 0; i < ll_node_count(n_list); ++i) {
	    printf("ID for %zu   is: %d\n", (i + 1), ids[i]);
	}

	free(n_list);

	return 0;
}
