#include<iostream>
using namespace std;

class probing{
    public:
        int arr[10],flag[10];

    probing(){
        for(int i=0;i<10;i++)
            flag[i]=0;
}

void insert(){
    int x;
    cout<<"Enter Number : ";
    cin>>x;
    int loc=x%10;
    int s=loc;
    if(flag[loc]==0){
        arr[loc]=x;
        flag[loc]=1;
}
    else{
        while(flag[loc]!=0)
            loc=(loc+1)%10;
        arr[loc]=x;
        flag[loc]=1;
}}

void search(){
    int z;
    cout<<"Enter number to search : ";
    cin>>z;
    int loc=z%10;
    int c=0;
    while(c<10){
        if(arr[loc]==z){
            cout<<"NUmber found at location "<<loc+1;
            return;
}
        else{
            loc=(loc+1)%10;
            c=c+1;
}}
    cout<<"Number not Found";
}

void display(){
    for(int i=0;i<10;i++){
        if(flag[i]==1)
            cout<<arr[i]<<" ";
        else
            cout<<"  ";
}}};

class node{
    public:
        int number;
    node *next;
};

class hashtable{
    public:
        node *hash[10];
        
    hashtable(){
        for (int i=0;i<10;i++)
            hash[i] = NULL;
}

void insert(){
    int num;
    cout<<"Enter number to insert : ";
    cin>>num;
    node *p;
    p=new node;
    p->number=num;
    p->next=NULL;
    int address=num%10;
    if (hash[address]==NULL)
        hash[address]=p;
    else{
        node *q=hash[address];
        while(q->next!=NULL)
            q=q->next;
            q->next=p;
}}

void display(){
    for (int i=0;i<10;i++){
        node *r=hash[i];
        while(r!=NULL){
            cout<<r->number<<"  ";
            r=r->next;
}}}

void search(){
    int ele;
    cout<<"Enter number to Search : ";
    cin>>ele;
    int add= ele%10;
    node *s=hash[add];
    while(s!=NULL){
        if(s->number==ele){
		cout<<"Number "<<ele<<" Found \n";
        return;
}
        else
        s=s->next;
}
    cout<<"Number "<<ele<<" Not Found \n";
}};

void linear_probing(){
    probing p;
    while(1){
        cout<<"\n *****MENU****** \n";
        cout<<"1.Insert number \n2.Display numbers \n3.Search number \n4.Exit\n";
        int ch;
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){

            case 1:
            p.insert();
            break;

            case 2:
            p.display();
            break;

            case 3:
            p.search();
            break;

            case 4:
            return;

            default:
            cout<<"Enter valid choice \n";
}}}

void open_hashing(){
    hashtable h;
        while(1){
            cout<<"\n*****Menu******\n";
            cout<<"1.Insert number \n2.Display numbers \n3.Search number \n4.Exit ";
            int ch;
            cout<<"\nEnter your choice : ";
            cin>>ch;
            switch(ch){
                case 1:
                h.insert();
                break;

                case 2:
                h.display();
                break;

                case 3:
                h.search();
                break;

                case 4:
                return;
                
                default:
                cout<<"Enter Valid Choice";
}}}

int main(){
    while(1){
        cout<<"\n************MENU***********\n";
        cout<<"1.Open Hashing \n2.Linear Probing \n3.Exit\n";
        int a;
        cout<<"Enter your choice : ";
        cin>>a;
        switch(a){
            case 1:
            open_hashing();
            break;
    
        case 2:
            linear_probing();
            break;

        case 3:
            exit(0);
            break;

        default:
            cout<<"Enter valid choice ";
    }
}
return 0;
}
