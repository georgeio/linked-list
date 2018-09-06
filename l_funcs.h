#ifndef L_FUNCS_H
#define L_FUNCS_H

#define MAX_DATA_LEN 512

typedef struct node node;
typedef struct list list;
typedef struct list_operations l_ops;

struct node{
	int id;
	char data[MAX_DATA_LEN];
    node *previous;
	node *next;
};

struct list {
	node *first_node;
	node *last_node;
	int node_count;
    l_ops *vt;
};

struct list_operations {
	node* (*get_first_node)(list*);
	node* (*get_last_node)(list*);
	int (*add_node)(list*, node*);
	int (*remove_node_byadr)(list*, node*);
	void (*get_all_node_ids)(list* l, int*);
};

//Methods for operating on nodes
node new_node();

//Methods for operating on list
list* new_list(node*);
node* get_first_node(list*);
node* get_last_node(list*);
int add_node(list*, node*);
void get_all_node_ids(list*, int*);

#endif
