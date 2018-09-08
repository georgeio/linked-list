#ifndef L_FUNCS_H
#define L_FUNCS_H

#define MAX_DATA_LEN 512

typedef struct node node;
typedef struct list list;

struct node{
	int id;
	void* data;
    node* previous;
	node* next;
};

struct list {
	node* first_node;
	node* last_node;
	int node_count;
};

//Methods for operating on nodes
node ll_new_node();

//Methods for operating on list
list* ll_new_list(node*);
node* ll_get_first_node(list*);
node* ll_get_last_node(list*);
int ll_add_node(list*, node*);
void ll_get_all_node_ids(list*, int*);
int ll_node_count(list*);

#endif
