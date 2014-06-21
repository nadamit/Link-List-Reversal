//
//  main.cpp
//  ReverseLinkList
//
//  Created by Amit Nadkarni on 6/20/14.
//  Copyright (c) 2014 Amit Nadkarni. All rights reserved.
//

#include <iostream>
using namespace std;

class Node{
    
public:
    Node *next;
    int data;
    
public:
    Node(){}
    
    Node(int data){
        
        this->data=data;
        this->next=NULL;
    }
};

class LinkList{
    
public:
    
    LinkList(){}
    
    Node *head=NULL;
    
    bool insertElementinList(int data){
        
        Node *node=new Node(data);
        
        if(head==NULL)
        {
            head=node;
            return true;
        }
        
        else{
            
            
            Node *current=head;
            
            while(current->next!=NULL){
                
                current=current->next;
            }
            
            current->next=node;
            
            return true;
            
        }
        
    }
    
    void print(){
        
        if(head==NULL){
            cout<<"List is empty"<<endl;
        }
        else{
            
            Node *current;
            current=head;
            
            while(current!=NULL){
                cout<<current->data<<" ";
                current=current->next;
            }
        }
        cout<<endl;
        
    }
    
    void ReverseList()
    {
        Node *prev=NULL;
        Node *current=head;
        
        while(current)
            
        {
            Node *next=current->next;
            current->next=prev;
            prev=current;
            head=current;
            current=next;
            
        }
        
        
    }
};

int main()
{
    
    int choice;
    
    std::cout<<"**Operations on Link List**"<<std::endl;
    
    // insert code here...
    
    LinkList *obj=new LinkList();
    
    cout<<"Enter 1 to insert into LinkList"<<endl;
    cout<<"Anything else to exit"<<endl;
    cin>>choice;
    while(choice==1){
        
        int option;
        std::cout<<"**1. Insert element into the list**"<<std::endl;
        std::cout<<"**2. Reverse the Link List**"<<std::endl;
        cout<<"**Anything else to exit**"<<endl;
        cin>>option;
        
        switch (option) {
                
            case 1: {
                cout<<"Enter an integer to be inserted in the list"<<endl;
                int data;
                cin>>data;
                bool flag= obj->insertElementinList(data);
                if(flag)
                { cout<<"Element added successfully"<<endl;}
                else{
                    cout<<"Error occurred adding an element"<<endl;
                }
                obj->print();
                break;
            }
                
            case 2:{
                
                cout<<"Reverse List"<<endl;
                obj->ReverseList();
                obj->print();
                
                break;
            }
                
            default:{cout<<"sry"<<endl;
                choice=int('a');
                break;
            }
        }
        
    }
    
    
    return 0;
}

