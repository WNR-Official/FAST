#include<iostream>
#include"Hashtable_code01.h"
using namespace std;
int main()
{
int num_of_identifiers;
cout<<"Enter maximum number of keys that need to be stored in the hashtable:";
cin>>num_of_identifiers;
int size_hashtable;
cout<<"Enter size of hashtable needed to store these many identifiers (hint: use prime number): ";
cin>>size_hashtable;
//create a hashtable of this size
Hashtable<int>* ht=new Hashtable<int>(size_hashtable);
for (int i=0; i<num_of_identifiers; i++)
{
int key=rand()%1000;
bool was_stored = ht->store(key);
if(!was_stored)
cout<<key<<" could not be stored as it already exists or table is full"<<endl;
}
int find_key;
cout<<"Enter the key to search for "<<endl;
cin>>find_key;
 clock_t start, end;//measure time
start= clock();
bool found= ht->search(find_key);
end= clock();
double cpu_time_used = end - start;
if(found)
cout<<"it was found in "<<cpu_time_used<<" milliseconds"<<endl;
else
cout<<"not found in "<<cpu_time_used<<" milliseconds"<<endl;
return 0;
}
