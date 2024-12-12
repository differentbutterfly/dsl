#include <iostream>
#include <string.h>
using namespace std;
class SLL;

class node{
    private:
    int div;
    int prn;
    char name[20];
    node *next;
    friend class SLL;
    public:
    node(){
        next=NULL;
        div=0;
        prn=0;
        }
    node(int d,int p,char Name[]){
        next=NULL;
        div=d;
        prn=p;
        strcpy(name,Name);
    }    

};
 class SLL{
node* head, *last_mem, *tail;
public:
    SLL(){
    head=NULL;
    tail=NULL;
    last_mem=NULL;
    }
    void create();
    void addmember();
    void remove_member();
    void count();
    void merge();
    void display();
};

void SLL::create(){
    int num,div,prn;
    char name[20];

    cout<<"Enter noo.of students\n";
    cin>>num;

    cout<<"Enter details for president  (name,div,prn)\n";
    cin>>name>>div>>prn;
    head=tail=new node(div,prn,name);

    for(int i=0;i<num-1;i++){
        cout<<"Enter details for members (name,div,prn) \n";
        cin>>name>>div>>prn;
        tail->next= new node(div,prn,name);
        tail=tail->next;
        
    }

    last_mem=tail;

    cout<<"Enter details for secretary(name,div,prn)\n";
     cin>>name>>div>>prn;
     tail=tail->next=new node(div,prn,name);
}

void SLL::addmember(){
        int div,prn;
        char name[20];
        cout<<"Enter name,div,prn for new mamber \n";
        cin>>name,div,prn;
        last_mem->next= new node(div,prn,name);
        last_mem=last_mem->next;
        last_mem->next=tail;
}


void SLL:: remove_member(){
    int searchPRN;
    cout<<"enter prn of member to be removed\n";
    cin>>searchPRN;
    node *temp;
    node *remove;
    
    if(searchPRN==head->prn){
        temp=head;
        head=head->next;
        delete temp;
    }

    else if(searchPRN==tail->prn){
        temp=tail;
        last_mem->next=NULL;
        tail=last_mem;
        delete temp;
    }

    else{
        for (node *temp = head; temp != last_mem; temp = temp->next)
        {
            if (temp->next->prn == searchPRN)
            {
                if (temp->next == last_mem)
                    last_mem = temp;
                remove = temp->next;
                temp->next = temp->next->next;
                delete remove;

                if (temp == last_mem)
                    break;
            }
        }
    }

    cout<<"member removed\n";
}

void SLL::count (){
    node *temp=head;
    int cnt=0;
    while(temp->next!=NULL){
        temp=temp->next;
        cnt++;
    }
    cout<<"There are " <<cnt<<" members in club\n";
}

void SLL::display(){
    node *temp=head;
    cout<<"\n\nNAME\tDIV\tPRN\n";
    while(temp!=NULL){
        cout<<temp->name<<"\t"<<temp->div<<"\t"<<temp->prn<<"\n";
        temp=temp->next;
    }
    cout<<"PRESIDENT NAME : "<<head->name<<"\n";
    cout<<"SECRETORY NAME : "<<tail->name<<"\n";

}
void SLL::merge(){
    SLL list2;
    cout<<"enter details for list2\n";
    list2.create();
    tail->next=list2.head;
    tail=list2.tail;
}

int main() {

SLL list1;
int choice;

    do{

        cout<<"1.create list\n2.add member\n3.remove member\n4.total members\n5.display members\n6.merge members of two divisions\n7.exit\n" ;
        cout<<"enter choice"<<endl;
        cin>>choice;

        switch(choice){

            case 1:
            list1.create();
            break;

            case 2:
            list1.addmember();
            break;

            case 3:
            list1.remove_member();
            break;

            case 4:
            list1.count();
            break;

            case 5:
            list1.display();
            break;

            case 6:
            list1.merge();
            break;

            case 7:
            cout<<"EXITING PROGRAM \n";
            break;
            


        }


    }while(choice!=7);
   return 0;
}