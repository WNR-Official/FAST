#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node (int value){
        data=value;
        next =nullptr;
    }
};

const int table_size=10;
node * hashtables[table_size];
void initialize_hash(){
    for(int i=0;i<table_size;i++){
        hashtables[i]=nullptr;
    }
}

int hash_func(int key){
    return key % table_size;
}

void insert (int key){
    node* newnode = new node (key);
    int index = hash_func(key);
    if (hashtables[index]==nullptr){
        hashtables[index]=newnode;
    }
    else{
        newnode->next=hashtables[index];
        hashtables[index]=newnode;
    }
}
bool search (int key){
    int index = hash_func(key);
    node* temp = hashtables[index];
    while (temp!=nullptr){
        if (temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
void diplay_hash(){
    for(int i=0; i<table_size;i++){
        cout<<i<<" : ";
        node* temp = hashtables[i];
        while (temp!=nullptr){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"nullptr"<<endl;
    }
}

int main (){
    initialize_hash();
    insert(10);
    insert(20);
    insert(15);
    insert(25);
    insert(30);
    insert(5);

    diplay_hash();

    int key_to_search = 15;
    if (search(key_to_search)){
        cout<<key_to_search<<" found in hash table."<<endl;
    }
    else{
        cout<<key_to_search<<" not found in hash table."<<endl;
    }

    return 0;
}
