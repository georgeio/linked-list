#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "l_funcs.h"

#define _SUCCESS 1

/*
  Create new node
*/
node new_node()
{
   static int id = 1;
   return (node) {id++, "", NULL, NULL}; 
}

/*
   Return first node on the list
*/
node* get_first_node(list* l)
{
	return l->first_node;
}

/*
   Return last node on list
*/
node* get_last_node(list* l)
{
	return l->last_node;
}

/*
   Return an array of all the id of existing nodes
*/
void get_all_nodes_id(list* l, int* id)
{
   node* temp_node_ptr = malloc(sizeof(node));
   memcpy(temp_node_ptr, l->first_node, sizeof(node));

   int i;

   for (i = 0; i < l->node_count; ++i) {
      *id = temp_node_ptr->id;

      if( temp_node_ptr->next ) {
         memcpy(temp_node_ptr, temp_node_ptr->next, sizeof(node));
         id++;
      }
   }

   free(temp_node_ptr);
}

/*
   Add new node to list
*/
int add_node(list* l, node* _node)
{
   _node->previous = l->last_node;
   l->last_node->next = _node;
   l->last_node = _node;
   l->node_count++;

   return _SUCCESS;
}

/*
   Remove a node from the list by the node address
*/
int remove_node_byadr(list* l, node* _node)
{

   if(_node->previous == NULL) {
      _node->next->previous = NULL;
      return _SUCCESS;
   }

   _node->previous->next = _node->next;
   _node->next->previous = _node->previous;

   return _SUCCESS;
}

/*
   Create a new list, with the passed param as first node
*/
list* new_list(node* data)
{
   list *n_list = malloc(sizeof(list));
   l_ops *list_ops = malloc(sizeof(l_ops));

   n_list->node_count = 1;
   n_list->first_node = data;
   n_list->last_node = data;
      
   *list_ops = (l_ops){    
         &get_first_node, 
         &get_last_node, 
         &add_node,
         &remove_node_byadr,
         &get_all_nodes_id
   };  //initialise ops struct for managing methods

   n_list->vt = list_ops;

   return n_list;
	
}
