#include <iostream>
using namespace std;
 
class pizza{

    private:
        int *queue;
        int front;
        int rear;
        int size;
        int count;

    public:
    pizza(int maxcount){
        size=maxcount;
        queue=new int[size];
        front=-1;
        rear=-1;
        count=0;
    }
    ~pizza() {
        delete[] queue;
    }
    

bool isfull(){
    
        return (rear+1)%size==front;
    
}

bool isempty(){
 
    return front==-1;
}

void placeOrders(int orderId){
    if(isfull()){
        cout<<"CANNOT PLACE ORDER ,QUEUE IS FULL";
        return;

    }
    if(front==-1){
        front=0;
    }

    rear=(rear+1)%size;
    queue[rear]=orderId;
    count++;
    cout<<"Order "<<orderId<<" has been placed ";

}

void serverOder(){
    if(isempty()){
        cout<<"NO ORDERS TO SERVE ";
        return;

    }
    cout<<"Order "<<queue[front]<<"served";
    front=(front+1)%size;
    count--;

    if(front==0){
        front=rear=-1;

    }
}

void displayOrders(){
    if(isempty()){
        cout<<"NO ORDERS TO DISPLAY";
        return;

    }
    cout<<"CURRENT ORDERS : ";
    int i=front;
    for (int j = 0; j < count; j++)
    {
        cout<<queue[i]<<" ";
        i=(i+1)%size;

    }
    cout<<"\n";

    
}

};


int main() {
 int maxorders;
 cout<<"ENTER MAX NO.OF ORDERS FOR PIZZA PARLOUR : ";
 cin>>maxorders;

 pizza pizza_obj(maxorders);
 int choice;

 do
 {
    
    cout<<"1) Place Order"<<endl;
    cout<<"2) serve Order"<<endl;
    cout<<"3) Display Orders"<<endl;
    cout<<"4) EXIT";
    cout<<"\n";
    cout<<"ENTER CHOICE"<<endl;
    cin>>choice;

    switch(choice){

        case 1:
        int orderID;
        cout<<"Enter order ID to be placed ";
        cin>>orderID;
        pizza_obj.placeOrders(orderID);
        break;

        case 2:
        
        pizza_obj.serverOder();
        break;

        case 3:
        
        pizza_obj.displayOrders();
        break;

        case 4:
        cout<<"EXITING THE PROGRAM";
        break;

        default:
        cout<<"INVALID CHOICE ";

    }
    
 } while (choice!=4);
 
   return 0;
}