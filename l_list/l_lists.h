#ifndef L_LISTS_H
#define L_LISTS_H

#define LL_MAX_DATA_LEN 512
#define LL_MAX_NODE_LIMIT 10

typedef struct node node;
typedef struct list list;

struct node{
	int id;
	char* data;
	node* next;
	node* previous;
};

struct list {
	node* first_node;
	node* last_node;
	int node_count;
};

//Methods for operating on nodes
node ll_new_node(char s[]);
int ll_node_id(node*);
char *ll_node_data(node*);

//Methods for operating on list
list *ll_new_list();
node *ll_first_node(list*);
node *ll_last_node(list*);
int ll_add_node(list*, node*);
int ll_all_ids(list*, int*);
int ll_node_count(list*);
int ll_remove_node_byadr(list*, node*);

#endif
