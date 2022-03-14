#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	char name[100];
	char con[100];
};

struct node* head = NULL;
struct node* tail = NULL;

struct node *createNewNode(char name[], char con[]){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	strcpy(temp->name, name);
	strcpy(temp->con, con);
	temp->head = temp->tail = NULL;
	return temp;
}

void pushHead(char name[], char con[]){
	struct Node* toInsert = createNewNode(name, con);
	if(head==NULL){
		head = toInsert;
		tail = toInsert;
	}else{
		toInsert->next = head;
		head = toInsert;
	}
}

void pushTail(char name[], char con[]){
	struct Node* toInsert = createNewNode(name, con);
	if(tail == NULL){
		head = toInsert;
		tail = toInsert;
	}else{
		tail->next = toInsert;
		tail = toInsert;	
	}
	
}

void kondisi(char con[]){
	if(con == 'Critical'){
		return "Emergency Room";
	}else if(con == 'Serious'){
		return "Examination Room";
	}else{
		return "Consultation Room";
	}
}

int main(){
	
	char option[100][100];
	int orang;
	char a[100][100];
	char b[100][100];
	
	scanf("%d", &orang);
	
	for(int i=0; i<orang; i++){
		scanf("[^\n]", option);
		if(option == 'ADD'){
			scanf("%[^\n]", a[i]);
			scanf("%[^\n]", b[i]);
			pushHead(a[i], b[i]);
		}else if(option == 'CALL'){
			if(b[i] == 'Critical'){
				scanf("%s is in the Emergency Room", a[i]);
			}else if(b[i] == 'Serious'){
				scanf("%s is in the Examination Room", a[i]);
			}else{
				scanf("%s is in the Consultation Room", a[i]);
			}
		}else{
			scanf("ERROR");
		}
	}
	
	
	
	
}
