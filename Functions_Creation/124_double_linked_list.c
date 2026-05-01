/*

                                ~ Double Linked list ~

       
             The  mession is to uderstand the Double Linked List (DLL) . Done 👌

      
      
         1) Creat_N_nodes  👌
         2) Print_list      ! ! forward  & backward ! ! 👌
         3) free_list 👌
         4) push_front 👌
         5) push_back 👌
         6) Count_nodes 👌
         7) reverse_dll 👌
         8) tail_node 👌
         9) delete_node 👌
      


*/


 #include <stdio.h>
 #include <stdlib.h>

 typedef struct s_node 
 {
   int val;
   struct s_node *previos;
   struct s_node *next;

 } t_node;


int DLL_length(t_node *head)
{
   int counter = 0;

   while (head != NULL)
   {
      counter++;
      head = head->next;
   }
   return (counter);
}

void free_DLL(t_node *head)
{
   t_node *next;

   while (head != NULL)
   {
      next = head->next;
      free(head);
      head = next;
   }
}

t_node * insert_at_beginning_of_DLL(t_node *head , int value)
{
   t_node *new_node = malloc(sizeof(t_node));
   if (!new_node)
      return (NULL);

   new_node->val = value;
   new_node->previos = NULL;
   new_node->next = head;

   head->previos = new_node;
   return (new_node);
}

t_node * insert_at_end_of_DLL(t_node *head , int value)
{
   t_node *new_node = malloc(sizeof(t_node));
   if (!new_node)
      return NULL;

   t_node *last_node;
   t_node *next;

   if ( head == NULL)
         return NULL;
   next = head;
   last_node = head;
   while (1)
   {
      next = next->next;
      if (next != NULL)
         last_node = next;
      else if (next == NULL)
         break;
   }
   new_node->val = value;
   new_node->previos = last_node;
   new_node->next = NULL;
   last_node->next = new_node;
   return (head);
}

void display_DLL_forward(t_node *head)
{
   if (!head)
      return;
   while (head != NULL)
   {
      printf("%d -> ",head->val);
      head = head->next;
   }
}

void display_DLL_backward(t_node *head)
{
   t_node *next;
   if (!head)
      return ;
   next = head;
   while (1)
   {
      next = next->next;
      if (next)
         head = head->next;
      else
         break;
   }
   while (head != NULL)
   {
      printf("%d -> ",head->val);
      head = head->previos;
   }
}

t_node *delete_current_node(t_node *list ,t_node *node_to_del)
{
   t_node *to_free;
   t_node *new_head;
   
   if (node_to_del->previos != NULL)
   {
      to_free = node_to_del;
      node_to_del->previos->next = node_to_del->next;
      free(to_free);
      return (list);
   }
   else if (node_to_del->previos == NULL)
   {
      new_head = node_to_del->next;
      free(node_to_del);
      new_head->previos = NULL;
      return (new_head);
   }
   return (NULL);
}

t_node *delete_node(t_node *head , int pos)
{
   t_node *node_to_del;
   int i;

   if ( pos < 0 || head == NULL || pos > DLL_length(head))
      return (free(head),NULL);
   if (pos == 0)
         return (head);
   if (head->next == NULL)
      return (free(head),NULL);
   i = 1;
   node_to_del = head;
   while (node_to_del != NULL && i < pos)
   {
      node_to_del = node_to_del->next;
      i++;
   }
   return (delete_current_node(head ,node_to_del));
}
t_node * tail_node(t_node *head)
{
   t_node *tail;

   if (head == NULL)
      return (NULL);
   
   tail = head;
   while (head != NULL)
   {
      head = head->next;
      if (head != NULL)
         tail = head;
   }
   return (tail);
}

t_node *reverse_dll(t_node *head)
{
   t_node *part1;
   t_node *part2;
   int     temp_val;
   int i;
   int j;

   if (!head)
      return (NULL);
   part1 = head;
   part2 = tail_node(head);
   i = -1;
   while (++i < DLL_length(head) / 2)
   {
      j = 0;
      while (++j <= i)
      {
         part1 = part1->next;
         part2 = part2->previos;
      }
      temp_val = part1->val;
      part1->val = part2->val;
      part2->val = temp_val;
   }
   return (head);
}

t_node *Creat_one_node(int a)
{
   t_node *node = malloc(sizeof(t_node));
   if (!node)
      return NULL;
   node->val = a;
   node->previos = NULL;
   node->next = NULL;

   return (node);
}

t_node *Creat_N_nodes(int N_nodes)
{
   t_node *head = malloc(sizeof(t_node));
   if (!head || N_nodes < 1)
         return (free(head),NULL);
   
   t_node *prev;
   prev = head;

   head->previos = NULL;
   head->val = 1;

   int i = 1;
   while (i < N_nodes)
   {
      // if (!Creat_one_node())
      //    return (free_DLL(head),NULL);

      prev->next = Creat_one_node(i+1);
      prev->next->previos = prev;
      prev = prev->next;
      i++;
   }
   return (head);
}


 int main(void)
{

   t_node *list ;

   if ( !( list = Creat_N_nodes(1)))// Null check
   {
      printf("Error 1\n");
      return 1;
   }

   list = delete_node(list , 0);
   if (!list)// Null check
   {
      printf("Error 2\n");
      return 1;
   }

   display_DLL_forward(list);
   free_DLL(list);

   return 0;
}

