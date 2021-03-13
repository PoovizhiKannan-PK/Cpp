#include <iostream>
#include <list>
using namespace std;

class graph{
        int v;
        list<int> *vertices;

    public:
        graph(int v){
            this->v = v;
            vertices = new list<int>[v];

        }

        void addEdge(int x, int y){
            vertices[x].push_back(y);
            vertices[y].push_back(x);
        }

        void printAdjecencyList(){
            for(int i=0; i<v; i++){
                cout << "Vertex " << i << "--> ";
                for(int links:vertices[i]){
                    cout << links << " ";
                }
                cout << endl;
            }
        }


};


int main(){

    graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);
    
    g.printAdjecencyList();

    return 0;
}