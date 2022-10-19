#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node{
    int coeff;
    int exp;
    struct node *next;
};

void makePol(node *head){
    node *temp=head;
    node *newNode;
    newNode=(node *)malloc(sizeof(node));
    newNode->next=NULL;
    int choice=1,coeff,exp;
    while(choice){
        printf("Enter the coefficient:");
        scanf("%d",&coeff);
        printf("Enter the exponent:");
        scanf("%d",&exp);
        if(head==NULL){
            newNode->coeff=coeff;
            newNode->exp=exp;
            head=temp=newNode;
            return;
        }
        do{
            if(temp->exp==exp){
                temp->coeff+=coeff;
                return;
            }
            temp=temp->next;
        }while(temp->next->exp>=exp);
        newNode->coeff=coeff;
        newNode->exp=exp;
        newNode->next=temp->next;
        temp->next=newNode;
        printf("Do you want to continue?(1/0)");
        scanf("%d,&choice");
    }
}


void traverse(node *head){
    node *temp=head;
    int count=0;
    do{
        printf("%dx^%d",temp->coeff,temp->exp);
        temp=temp->next;
        count++;
    }while(temp!=NULL);
}

node* multiply(node *p1, node *p2){
    node *temp1=p1,*temp2=p2;
    node *newNode;
    newNode=(node *)malloc(sizeof(node));
    newNode->next=NULL;
    while(temp1!=NULL){
        while(temp2!=NULL){
            newNode->coeff=temp1->coeff*temp2->coeff;
            newNode->exp=temp1->exp+temp2->exp;
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return newNode;
}

int count(node *head){
    int count = 0;
    node *temp=head;
    if(head==NULL){
        return 0;
    }
    do{
        count++;
        temp=temp->next;
    }while(temp->next !=head);
    return count;
}

int main(){
    node *p1=NULL,*p2=NULL,*p3=NULL;
    printf("Enter the first polynomial:");
    makePol(p1);
    traverse(p1);
    makePol(p2);
    p3=multiply(p1,p2);
    traverse(p3);
    return 0;
}