#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_LEN  80

struct link_node {
char node_str[ MAX_STR_LEN ];
struct link_node *next;
};

void link_node_Create(struct link_node* thisNode, char strin[MAX_STR_LEN], struct link_node* nextLoc) {
   thisNode->node_str[MAX_STR_LEN] = strin[MAX_STR_LEN];
   thisNode->next = nextLoc;
}
void link_node_InsertAfter(struct link_node* thisNode, struct link_node* newNode) {
   struct link_node* tmpNext = NULL;
   tmpNext = thisNode->next;
   thisNode->next = newNode;
   newNode->next = tmpNext;
}

char link_node_GetVal(struct link_node* thisNode) {
   return thisNode->node_str;
}

struct link_node* link_node_GetNext(struct link_node* thisNode) {
   return thisNode->next;
}

int compare_node( struct link_node *n1, struct link_node *n2 ){
        if(strcmp(n1->node_str, n2->node_str)>0){
            return 1;
        }
        if(strcmp(n1->node_str, n2->node_str)==0){
            return 0;
        }
        if(strcmp(n1->node_str, n2->node_str)<0){
            return -1;
        }
}
struct link_node *add_node( struct link_node *list, struct link_node *node ){
    node = list->next;
};

void display_list( struct link_node *head );

int main(){
    char userString[MAX_STR_LEN];
    struct link_node *headNode;
    struct link_node *currNode;
    struct link_node *tailNode=NULL;

    headNode = malloc(sizeof(struct link_node));

    link_node_Create(headNode,"a", NULL);
    tailNode=headNode;

     printf("Please enter strings. When you are done, enter a blank line.\n");
     do{
        currNode = malloc(sizeof(struct link_node));
        fgets(userString, MAX_STR_LEN, stdin);
        link_node_Create(currNode,userString, NULL);
        if (compare_node(currNode, tailNode)) {
            link_node_InsertAfter(tailNode, currNode);
        }
        else link_node_InsertAfter(currNode, tailNode);
        tailNode=currNode;
     } while (userString[0]!="b");

     currNode = headNode;                // Print the list
      while (currNode != NULL) {
      printf("%d, ", link_node_GetVal(currNode));
      currNode = link_node_GetNext(currNode);
   }
   printf("\n");
    return 0;
}


