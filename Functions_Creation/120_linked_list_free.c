void free_list(struct s_node *head)
{
   struct s_node *next ;

   while (head != NULL)
   {
      next = head->next;
      free(head);
      head = next;
   }
   free(head);// node1

}


This function do free the liked list of the previos file " 119 "