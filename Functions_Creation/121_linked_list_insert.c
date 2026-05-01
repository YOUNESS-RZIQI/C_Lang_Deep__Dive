/*

                                ~ Linked list ~

       push_in_any_place_in_list : 
       
            This funsction i creat hes mession is to add a node in a positon you gave to it in the linked list

      

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

void free_list(struct s_node *head)
{
   struct s_node *next ;

   while (head != NULL)
   {
      next = head->next;
      free(head);
      head = next;
   }

}

struct s_node * push_in_any_place_in_list(int pos ,struct s_node * head , int value)
{
   short i = 0;
   struct s_node * new_node = malloc (sizeof(struct s_node));
   struct s_node * befor_node ;
   struct s_node * node ;
   
   if (pos > (1 + Count_nodes(head)))
      return (free(new_node),free_list(head),NULL);
   befor_node = head;
   node = head;
   if (pos == 1 || head == NULL)
      return (free(new_node),push_front(head , value));
   while (++i < pos  && befor_node != NULL)
   {
      node = node->next;
      if (i < (pos - 1))
         befor_node = node;
   }
   befor_node->next = new_node;

   new_node->val = value;
   new_node->next = node;

   return (head);
}

 int main(void)
 {

   struct s_node *list = Creat_3_nodes();

   list = push_in_any_place_in_list(3,list,444);

   Print_list(list);

   free_list(list);

    return 0;
 }