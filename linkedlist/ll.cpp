#include <stdio.h>
// for malloc
#include <stdlib.h>
//for bool
#include <stdbool.h>

struct node {
	int data;
	struct node* next;
};
//typedef node* list;
void append(struct node** head_ref, int new_data);
void addfirst(struct node** head_ref, int new_data);
void display(struct node* head_ref);
void addafter(struct node* head_ref, int new_data);
void Insertafterpos(struct node** head_ref, int pos, int new_data);
void deleteFirstNode(struct node **head_ref);
void deleteNodewithKey(struct node** head_ref, int key);
int listLengthItr(struct node* head_ref);
int listLengthRec(struct node* head_ref);
int noOfTimesKeyoccure(struct node* head_ref, int key);
struct node* reverseLinkedList(struct node** head_ref);
struct node* recursiveReverseLinkList(struct node* head_ref);
//find the loop with in linked list
bool findLoop(struct node* head_ref);
void deleteLinklist(struct node** head_ref);

struct node* mergeSortedLists(struct node* list1, struct node* list2);
/**********************************Main**************************************************************/
int main() {
	struct node* head = NULL;
	//Add the node at last
	append(&head, 5);
	append(&head, 4);
	append(&head, 6);
	display(head);
	//Add the node at Beginning
	addfirst(&head, 7);
	addfirst(&head, 9);
	display(head);
	addafter(head->next, 9);
	display(head);
	//Insert node at given pos
	Insertafterpos(&head, 3, 10);
	display(head);
	//delete first node
	deleteFirstNode(&head);
	display(head);
	//delete the node with given key
	deleteNodewithKey(&head, 10);
	display(head);
	//find the no of nodes in list iteratively
	int noOfNode = listLengthItr(head);
	printf("No of Node is =%d\n", noOfNode);
	int noOfNodeR = listLengthRec(head);
	//find the no of nodes in list iteratively
	printf("No of Node is =%d\n", noOfNodeR);
	//Find out the number of counts the occurrence of a given int
	//NO of times occurence of a given key
	int count = noOfTimesKeyoccure(head, 7);
	printf("no of times %d\n", count);
	//recursively reverse*/
	printf("Recursive Reverse \n");

	/*struct node* headRR = recursiveReverseLinkList(head);
	display(headRR);
	*head=Restorehead;*/
	//reverse The Linked List Iteratively
	printf("Reverse\n");
	struct node* temp = reverseLinkedList(&head);
	display(head);

	//find if loop with in the linked list exit ot not

	printf("head is at data %d\n", head->data);
	append(&head, 16);
	append(&head, 17);
	append(&head, 18);
	display(head);
	bool loop1 = findLoop(head);
	printf("%s", loop1 ? "true" : "false");
	printf("\n");
	//make a loop in the list then call the findLoop(head)
	printf("head is at data %d\n", head->data);
	// Insert a loop to test
	//head->next->next->next = head;
	printf("head is at data %d\n", head->data);
	bool loop2 = findLoop(head);
	printf("%s", loop2 ? "true" : "false");
	printf("\n");
	//merging two sorted link  list
	// list one as list1 and list 2 as list2
	struct node* list1=NULL;
	struct node* list2=NULL;
	append(&list1,1);
	append(&list1,2);
	append(&list1,3);
	append(&list2,3);
	append(&list2,4);
	append(&list2,5);
	display(list1);
	display(list2);
	struct node* result=mergeSortedLists(list1,list2);
	//print the merged link list
	display(result);
	///delete the link list
	//deleteLinklist(&head);


}
struct node* mergeSortedLists(struct node* list1, struct node* list2) {

	struct node* result = NULL;
	if (list1 == NULL)
		return (list2);
	else if (list2 == NULL)
		return (list1);

	if (list1->data <= list2->data) {
		result = list1;
		result->next = mergeSortedLists(list1->next, list2);
	} else {
		result = list2;
		result->next = mergeSortedLists(list1, list2->next);
	}

	return (result);

}
void deleteLinklist(struct node** head) {
	struct node* current= *head;
	struct node* temp;
	while(current!=NULL){
		 temp=current->next;
		 free(current);
		 current=temp;
	}
	*head=NULL;

}
bool findLoop(struct node* head) {
	struct node* slowPtr = head;
	struct node* fastPtr = head;

	while (slowPtr && fastPtr && fastPtr->next) {
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if (slowPtr == fastPtr) {
			return true;
		}
	}
	return false;
}

struct node* recursiveReverseLinkList(struct node* head) {
	if ((head) == NULL || (head)->next == NULL) {
		return head;
	}
	struct node* Rnode = recursiveReverseLinkList((head)->next);
	(head)->next->next = (head);
	(head)->next = NULL;
	return Rnode;
}
struct node* reverseLinkedList(struct node** head) {
	struct node* current_node = *head;
	struct node* previous_node = NULL;
	struct node* next_node = NULL;

	while (current_node != NULL) {
		next_node = current_node->next;
		current_node->next = previous_node;
		previous_node = current_node;
		current_node = next_node;

	}
	*head = previous_node;
	return *head;
}

int noOfTimesKeyoccure(struct node* head, int key) {
	int count = 0;
	struct node* current = head;
	while (current != NULL) {
		if (current->data == key) {
			count++;
		}
		current = current->next;
	}
	return count;
}
int listLengthRec(struct node* head_ref) {
	if (head_ref == NULL)
		return 0;
	return 1 + listLengthRec(head_ref->next);
}
int listLengthItr(struct node* head_ref) {
	int count = 0;
	struct node* temp = head_ref;
	if (head_ref == NULL) {
		return count;
	}
	while (temp != NULL) {
		temp = temp->next;
		count++;
	}
	return count;
}
void deleteNodewithKey(struct node **head_ref, int key) {
	struct node* temp = *head_ref, *previous;
	if (temp != NULL && temp->data == key) {
		*head_ref = temp->next;
		free(temp);
	}
	if (temp == NULL) {
		return;
	}
	while (temp != NULL && temp->data != key) {
		previous = temp;
		temp = temp->next;
	}
	previous->next = temp->next;
	free(temp);

}
void deleteFirstNode(struct node** head_ref) {
	struct node* temp = *head_ref;
	if (*head_ref == NULL) {
		printf("Nothing To Delete\n");
	}
	*head_ref = temp->next;
	free(temp);

}
void Insertafterpos(struct node** head, int pos, int new_data) {
	if (*head == NULL) {
		printf("Not a great Choice\n");
	}
	struct node* temp = *head;
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = NULL;
	if (pos == 0) {
		addfirst(&temp, new_data);
	}
	while (pos--)
		temp = temp->next;
	new_node->next = temp->next;
	temp->next = new_node;
}
void addafter(struct node* previous_node, int new_data) {
	if (previous_node == NULL) {
		printf("Previous Node Should Not Be Null\n");
	}
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = previous_node->next;
	previous_node->next = new_node;

}
void addfirst(struct node** head, int new_data) {
	struct node* new_node = (struct node *) malloc(sizeof(struct node));
	struct node* first = new_node;
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	new_node->next = *head;
	*head = new_node;

}

void append(struct node** head_ref, int new_data) {
	struct node* last = *head_ref;
	struct node* new_node = (struct node*) malloc(sizeof(struct node));

	new_node->data = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
	return;

}
void display(struct node* node) {
	while (node != NULL) {
		printf(" %d ", node->data);
		node = node->next;
	}
	printf("\n");
}

