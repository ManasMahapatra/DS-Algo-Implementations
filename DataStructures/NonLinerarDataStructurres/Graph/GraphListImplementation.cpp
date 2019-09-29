#include <stdio.h>
//List library for using Linked lists. We can use our own self made linked list as well.
#include <list>
#include <iostream>
using namespace std;
//This variable contains the number of nodes thatthe graph contains. 
//Can be made dynamic using constructor as well.
int const totalNodes = 5;
class GraphList {
    private:
    //The implementation will create an array of linkedlists
    list <int> container[totalNodes];
    public:
    void setPath(int source, int destination) {
        if (source < totalNodes && destination < totalNodes) {
            container[source].push_back(destination);
        } else {
            cout<<"[-] Invalid source or destination";
        }
    }
    void traverseGraph() {
        for (int i = 0;i < totalNodes; i++) {
            cout<<"["<<i<<"]";
            for (auto j = container[i].cbegin();j != container[i].cend(); j ++) {
                //cbegin() and cend() returns an iterator which points to linked nodes. These iterators can't be used to modify 
                //the element.
                cout <<" -----> "<<*j;
            }
            cout<<"\n";
        }
    }
};
int main() {
    GraphList graph;
    graph.setPath(0,4);
    graph.setPath(2,1);
    graph.setPath(3,3);
    graph.setPath(4,2);
    graph.setPath(3,2);
    graph.setPath(1,0);
    graph.setPath(0,3);
    graph.setPath(4,0);
    graph.setPath(3,1);
    graph.setPath(2,3);
    graph.setPath(0,2);
    graph.setPath(0,0);
    graph.setPath(0,1);
    graph.setPath(1,3);
    graph.traverseGraph();
}