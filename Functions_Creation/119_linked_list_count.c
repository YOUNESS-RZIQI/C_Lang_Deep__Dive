/*

                                ~ Linked list ~

       Count_nodes : count the number of nodes in a list.
      

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
      while (head != NULL)
      {
         printf(" %d ", head->val );
         head = head->next;
         if (head != NULL)
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


 int Count_nodes(struct s_node  * head)
 {
      int counter = 0;

      while (head != NULL)
      {
         counter++;
         head = head->next;
      }
      return (counter);
   }


 int main(void)
 {

   struct s_node *list = Creat_3_nodes();

   // print the list befor
   Print_list(list);
   printf("Number of Node is ->%d\n\n",Count_nodes(list));

   list = push_front(list , 0);

   // print the list after the push_front
   Print_list(list);
   printf("Number of Node is ->%d\n",Count_nodes(list));

    return 0;
 }