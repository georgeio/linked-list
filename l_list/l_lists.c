#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "l_lists.h"

#define SUCCESS 1
#define FAILURE 0

// Create new node
node 
ll_new_node(char s[])
{
   if( strlen(s) > LL_MAX_DATA_LEN ) {
      perror("ll_new_node(): String length is too long");
      exit();
   }

   static int id = 1;
   return (node) {id++, s, NULL, NULL}; 
}

//Get id of a passed node
int 
ll_get_node_id(node *n)
{
   return n->id;
}

//Get data of a passed node
char *
ll_get_node_data(node *n)
{
   return n->data;
}

// Return first node on the list
node *
ll_get_first_node(list *l)
{
	return l->first_node;
}

// Return last node on list
node *
ll_get_last_node(list *l)
{
	return l->last_node;
}

// Return an array of all the id of existing nodes
int 
ll_get_all_node_ids(list *l, int *id)
{
   if( ! l->first_node )
      return FAILURE;

   node *tmp_node_ptr = l->first_node;

   for (size_t i = 0; i < l->node_count; ++i) {
      *id = tmp_node_ptr->id;

      if(tmp_node_ptr->next) {
         tmp_node_ptr = tmp_node_ptr->next;
         id++;
      }
   }

   return SUCCESS;
}

// Get total count of nodes present in the list
int 
ll_node_count(list *l)
{
   return l->node_count;
}

// Add new node to list
int 
ll_add_node(list *l, node *_node)
{
   _node->previous = l->last_node;
   l->last_node->next = _node;
   l->last_node = _node;
   l->node_count++;

   return SUCCESS;
}

//Remove a node from the list by the node address
int 
ll_remove_node_byadr(list *l, node *_node)
{

   if(_node->previous == NULL) {
      _node->next->previous = NULL;
      return SUCCESS;
   }

   _node->previous->next = _node->next;
   _node->next->previous = _node->previous;

   return SUCCESS;
}

//Create a new list, with the passed param as first node
list *
ll_new_list(node *node)
{
   list *n_list = malloc(sizeof(*n_list));

   n_list->node_count = 1;
   n_list->first_node = node;
   n_list->last_node = node;

   return n_list;
	
}
