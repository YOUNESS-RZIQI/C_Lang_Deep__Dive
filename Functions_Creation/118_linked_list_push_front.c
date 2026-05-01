/*

                                ~ Linked list ~

       push_front : add a node to the head of if so the new one be came the first one 
       and the head be came the second.
      

 */


 #include <stdio.h>
 #include <stdlib.h>

 struct s_node{

         int val;
         struct s_node *next;

 };

 struct s_node * Creat_3_nodes()
 {
    struct s_node *node0 = malloc(sizeof(struct s_node));
    struct s_node *node1 = malloc(sizeof(struct s_node));
    struct s_node *node2 = malloc(sizeof(struct s_node));

    node0->val  = 10;
    node0->next = node1;

    node1->val  = 20;
    node1->next = node2;

    node2->val  = 30;
    node2->next = NULL;

    return node0;
 }

 void Print_list(struct s_node  * head)
 {
      struct s_node *curent;

      curent = head;
      while (curent != NULL)
      {
         printf(" %d ", curent->val );
         curent = curent->next;
         if (curent != NULL)
            printf("-> ");
      }
      printf("\n\n");
   }

   struct s_node *push_front(struct s_node *head, int value)
{
   struct s_node *new_node = malloc(sizeof(struct s_node));

   new_node->val = value;
   new_node->next = head;
   return new_node;
}


 int main(void)
 {

   struct s_node *list = Creat_3_nodes();

   // print the list befor
   Print_list(list);

   list = push_front(list , 0);

   // print the list after the push_front
   Print_list(list);

    return 0;
 }