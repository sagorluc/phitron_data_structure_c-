    #include<bits/stdc++.h>
    using namespace std;

    // structure
    class node{
     public:
        int data;
        node *next;


    };
class LinkedList{

public:

    node *head; //1st pointer ta creat kora holo
    int sz;

    //constructor
    LinkedList()
    {
        head = NULL; //initially head NULL e point kore thakbe.

        sz = 0;
    }

    //creat a new node with data = value and next = NULL
    // time complexity- O(1).
    node* CreatNewNode(int value)
    {
        node *newnode = new node;

        newnode->data = value;
        newnode->next = NULL;

        return newnode;
    }

    // insert new value at head
    // time complexity- O(1).
    void InsertAtHead(int value)
    {
        sz++; //  jokhone new value insert korbo size barbe.

        node *a = CreatNewNode(value); // new node a creat kora holo.jate kore head e value insert kora jay.

        if(head == NULL)
        {
             head = a; // head a te point kore ace.
             return;
        }
        //if head is not NULL
        a->next = head; // a er next ke porer head er shatha connect korbe.
        head = a; // porer head take ager a er shthe connect korte hobe.


    }

    // print the linked list
    // time complexity- O(n).
    void Travers()
    {
        node* a = head; // a head e point kora holo.
        if(head == NULL)
           cout<<a;
        while(a != NULL) // a null na houya porjonto loop cholbe.
        {
            cout<<a->data<<" "; // a er vitore je data/value ace setake read kora holo.
            a = a->next; // ek ek kore a er next ke update kora holo.

        }
        cout<<"\n";


    }

    //search for a single value
    // time complexity - O(n).
    int SearchDistinctValue(int value)
    {
        node *a = head; // a ke head e point kora holo.
        int index = 0;
        while(a != NULL)
        {
            if(a->data == value) // frist node a er index  er data and value == hole porer index e jaoyar jonno index return kora holo.
                return index;

            a = a->next; // frist node a er next ke porer node er next e jaoyer jonno index++ kora holo.
            index++;
        }
        return -1; // er node e kicu na paile -1 return korbe.

    }

    //search all possible occurrence
    // time complexity - O(n).
    void SearchAllValue(int value)
    {
        node *a = head;
        int index = 0;
        while(a != NULL)
        {
            if(a->data == value)
               cout<<value<<" value is found at "<<index<<"\n";

            a = a->next;
            index++;
        }
    }

    // linked list length print korbe.
    // time complexity- O(1).
    int getSize()
    {
        // time complexity - O(1).

        return sz;
    }


    // new node create kore any index e insert korbe.
    // time complexity- O(n).
    void InsertValueAtAnyIndex(int index, int value)
    {
        if(index < 0 || index > sz) // cornar case. index 0 er choto hole OR index size er boro hole return kore dibe.kono kaj korbe nah.
            return;
        if(index == 0) // index 0 hole.
        {
            InsertAtHead(value); // heat e insert hobe.
            return;
        }

        // if index is not 0; tahole new node creat korbe.

        sz++;
        node *a = head; // new node a create kore head e point kora holo.
        int current_index = 0; // current index decleare kore take 0 diye initialize kora holo.

        while(current_index != index-1) // current index gurte gurte index-1 na asa projonto loop cholte thakbe.
        {
            a = a->next; // loop er vitore a next ke point korbe.
            current_index++; // current index ++ hote thakbe.

        }

        node *NewNode = CreatNewNode(value); // new dynamic ekta node creat kora holo.

        NewNode->next = a->next; // newnode er next ke a er next e point kora holo.
        a->next = NewNode; // a er next ke newnode e point kora holo.

    }

    // time complexity - O(1).
    void DeleteAtHead()
    {
        // corner case
        if(head == NULL)
            return;

        // head jodi null na hoy

        sz--; // value delete korle size kome jabe.
        node *a = head; // new a head e point kore ace.
        head = a->next; // head ke a er next e point kora holo.

        delete a; // new node a ke delete kore deoya holo.
    }

    // time complexity- O(n).
    void DeleteAnyIndex(int index)
    {
        // corner case
        if(index < 0 || index > sz-1) // index 0 er choto hole OR index size-1 hole kaj korbe nah. return kore dibe.
            return;
        if(index == 0)
        {
            DeleteAtHead(); // index 0 holo.head the delete korbee.
            return;
        }

        // if index is not null

        // O(1).
        sz--; // any index delete hole length -- hobe.
        node *a = head; // new node a create kora holo.
        int current_index = 0; // current index 0 diya initialize kora holo.

        // time complexity - O(n).
        while( current_index != index-1) // current index (index-1) na houya porjonto loop cholbe.
        {
            a = a->next; // loop er vitor dhukle a next node point korbe.
            current_index++; // current index ++ hobe.

        }

        // O(1).
        node *b = a->next; // new node b create kore a er next e  b er vitore hold kora holo.
        a->next = b->next; // tar por b er next ke a er next er restore kora holo.

        delete b; // and b ke delete kora holo.
    }

};
int main()
{
    LinkedList l;

    cout<<"linked list length or size = "<<l.getSize()<<"\n";
    l.InsertAtHead(10);
    l.InsertAtHead(20);
    l.InsertAtHead(30);

    l.Travers();

    l.InsertValueAtAnyIndex(1, 100); // 1 number index e 100 insert korbe.
    l.Travers();

    l.InsertValueAtAnyIndex(3, 75); // 3 number index e 100 insert korbe.
    l.Travers();

    l.InsertValueAtAnyIndex(4, 65); // 4 number index e 100 insert korbe.
    l.Travers();


     cout<<"linked list length or size = "<<l.getSize()<<"\n";

      l.DeleteAtHead();
      l.Travers();

      cout<<"linked list length or size = "<<l.getSize()<<"\n";

      l.DeleteAnyIndex(4); // 4 number index ke delete kora holo.
      l.Travers();
      cout<<"linked list length or size = "<<l.getSize()<<"\n";





    return 0;
}




