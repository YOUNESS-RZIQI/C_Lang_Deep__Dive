🇨 

/*

                                ~ Linked list ~

What is : 

        * dynamic data structure ? it is the way you deail with the data and there is many ways.
        * dynamic memory ? it is the != of automatique .(hard coded)
        * struct ? it is a data type , a way how to deail wiht data .
        * why in the struct we do have typedef and two names the s_node and the t_node ?
          & is the loop of struct not inf , it should because we always call her self ? 
          & why struct s_node not just t_node ?
            {
                typedef struct s_node
                {
                    int val;
                    struct s_node * next;
                } t_node;
            }

What is Linked list ?

        Essentially, linked lists function as an array that can grow and shrink as needed, from any point in the array.

Try : 

 1) do void insted of struct and without the casting and see if it will gave error ?
 2) printf("Size of t_node: %zu bytes\n", sizeof(t_node));
 3) can we do strunct without the typedef ?
 4) use : __attribute__((packed)) 

    struct __attribute__((packed)) no_padding {
        char a;   // 1 byte
        int b;    // 4 bytes (no alignment)
        char c;   // 1 byte
    };
    printf("%zu bytes\n", sizeof(struct no_padding));  // 6 bytes

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

 void Print_list(struct s_node  * list)
 {
      struct s_node *curent;

      printf("%d", list->val);
      curent = list->next;
      printf(" %d", curent->val );
      curent = curent->next;
      printf(" %d", curent->val);
      free(list->next->next);
      free(list->next);
      free(list);

   }

 int main(void)
 {

   Print_list(Creat_3_nodes());

    return 0;
 }