#include<bits/stdc++.h>
using namespace std;
class Max_Heap
{

public:
    vector<int> nodes;

    // constructor
    Max_Heap()
    {


    }
    // time complexity- O(log n)
    void up_heapify(int index)
    {
        while(index > 0 && nodes[index] > nodes[(index - 1)/2])
        {
            swap(nodes[index], nodes[(index - 1)/2]);
            index = (index - 1)/2;
        }

    }
    // time complexity- O(logn)
    void INSERT(int x)
    {
        nodes.push_back(x); // time complexity- O(1)
        up_heapify(nodes.size() - 1); // time complexity- O(log n)
    }
    // time complexity- O(n)
    void print_heap()
    {
        for(int i=0; i<nodes.size(); i++)
        {
            cout<<nodes[i]<<" ";
        }
        cout<<"\n";
    }

    // time complexity- O(logn)
    void down_heapify(int index)
    {
        while(1)
        {
            int largest = index;
            int left = 2*index + 1;
            int right = 2*index + 2;

            if(left < nodes.size() && nodes[largest] < nodes[left])
            {
                largest = left;
            }
            if(right < nodes.size() && nodes[largest] < nodes[right])
            {
                largest = right;
            }
            if(largest == index)
                break;
            swap(nodes[index], nodes[largest]);
            index = largest;

        }
    }

    // time complexity- O(logn)
    void delete_index(int index)
    {
        // corner case
        if(index >= nodes.size())
            return;

        swap(nodes[index], nodes[nodes.size() - 1]);
        nodes.pop_back();
        down_heapify(index);
    }

    // time complexity- O(1)
    int get_max()
    {
        // corner case
        if(nodes.empty())
        {
            cout<<"heap is empty\n";
            return -1;
        }
        return nodes[0];
    }

    // time complexity- O(logn)
    int extract_max()
    {
        // corner case
        if(nodes.empty())
        {
            cout<<"heap is empty\n";
            return -1;
        }

        int ret = nodes[0];
        delete_index(0);
        return ret;

    }

    // time complexity- O(n)
    void build_heap_from_array(vector<int> v)
    {
        nodes = v;
        int leaf = nodes.size();
        int non_leaf = leaf / 2 - 1;

        for(int i=non_leaf; i>=0; i--)
            down_heapify(i);

    }

    int get_size()
    {
        return nodes.size();
    }


};

class build_priority_queue
{
public:

    Max_Heap h;

    build_priority_queue()
    {

    }

    void PUSH(int x)
    {
       h.INSERT(x);
    }

    void POP()
    {
       h.delete_index(0);
    }

    int TOP()
    {
       return h.get_max();
    }

    int SIZE()
    {
       return h.get_size();

    }

};


int main()
{
    build_priority_queue pq;

    pq.PUSH(5);
    pq.PUSH(7);
    pq.PUSH(10);
    pq.PUSH(1);
    pq.PUSH(2);

    while(pq.SIZE() != 0)
    {
        cout<<pq.TOP()<<" ";
        pq.POP();
    }


    return 0;
}





