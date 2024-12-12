#include <iostream>
using namespace std;

class Queue{
private:
    int *queue;
    int front;
    int rear;
    int size;

public:
    Queue(int max_size){
        size=max_size;
        queue=new int[size];
        front=0;
        rear=-1;
        
    }


    ~Queue(){
        delete [] queue;
        }

    bool isfull(){
        return rear==size-1;
    }
    bool isempty(){
        return front>rear;

    }

    void addjob(int jobID){
        if(isfull()){
            cout<<"JOB QUEUE IS FULL"<<endl;
            return;

        }
        rear++;
        queue[rear]=jobID;
        cout<<"JOB : "<<jobID<<"Added to the queue"<<endl;

    }

    void deletejob(){
        if(isempty()){
            cout<<"JOB QUEUE IS EMPTY"<<endl; 
            return;
        }
        int removed_job=queue[front];
        front++;
        if(front>rear){
            rear=-1;
            front=0;

        }

    }

    void display(){
        
        if(isempty()){
        cout<<"JOB QUEUE IS EMPTY"<<endl; 
        return;
        }

        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<" ";
        }
        cout<<"\n ";
    }

};


int main() {

int max_size;
cout<<"enter max size for job queue\n";
cin>>max_size;


Queue obj(max_size);

int choice;
do{

    cout<<"\n1)add jobs \n2)delete job \n3)display jobs \n4)exit \n";
    cin>>choice;


    switch(choice){

        case 1:
        int jobID;
        cout<<"Enter jobID to add\n";
        cin>>jobID;
        obj.addjob(jobID);
        break;

        case 2:
        
        obj.deletejob();
        break;

        case 3:
        obj.display();
        break;

        case 4:
        cout<<"Exiting the program";
        break;


        default:
        cout<<"INVALID CHOICE";



    }



}while (choice!=4);


   return 0;
}