#ifndef L_FUNCS_H
#define L_FUNCS_H

#define NAME_MAX_LEN 50

typedef struct node node;
typedef struct list list;
typedef struct list_operations l_ops;

struct node{
	int id;
	char fullname[NAME_MAX_LEN];
	int age;
    node *previous;
	node *next;
};

struct list {
	node *first_node;
	node *last_node;
	int node_count;
    l_ops *_;
};

struct list_operations {
	node* (*get_first_node)(list*);
	node* (*get_last_node)(list*);
	int (*add_node)(list*, node*);
	int (*remove_node_byadr)(list*, node*);
};

//Methods for operating on nodes
node create_node(int*, char*, int*, node*, node*);

//Methods for operating on list
list* new_list(node*);
node* get_first_node(list*);
node* get_last_node(list*);
int add_node(list*, node *);

#endif
