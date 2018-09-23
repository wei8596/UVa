/**
*  Author: ≠SØuﬁ≥
*  Date: May. 12, 2017
*  Purpose: You are given a person°¶s life stages in graph form.
*           There are n nodes in the graph. Nodes represent stages, numbered from 0 to n - 1,
*           and edges represents that he can move from one stage to another.
*           0th node is the node where he starts his journey.
*           If the person is in node u, he only knows the nodes that have an edge from u.
*           The person wants to learn more, that°¶s why, he always takes the stage that looks better,
*           i.e. has maximum value.
*/
#include <iostream>
#include <vector>
using namespace std;

const int N = 100;  //2 <= (# nodes) <= 100

class Node {
public:
    int id;         //node id
    int unit;       //learning units
    vector<int> v;  //store edge
};

int main() {
    /*
    * @t: # test cases
    * @n: # nodes
    * @m: # edges
    * @unit: learning units
    * @c: counting
    */
    int t, n, m, unit, u, v, c = 1;

    cin >> t;
    while(t--) {
        Node node[N];
        cin >> n >> m;
        for(int i = 0; i < n; ++i) {
            node[i].id = i;  //node id
            cin >> unit;
            node[i].unit = unit;  //learning units
        }
        for(int i = 0; i < m; ++i) {
            //there is a directed edge from u to v
            cin >> u >> v;
            node[u].v.push_back(v);
        }
        int id = 0, value = 0, total = 0;
        int id1, id2;
        //takes the stage that looks better (maximum learning units)
		while(!node[id].v.empty()) {
            id1 = node[id].v[0];
			node[id].v.erase(node[id].v.begin());
            if(node[id1].unit > value) {
                value = node[id1].unit;
				id2 = id1;
            }
			if(node[id].v.empty()) {
				total += value;  //total learning units
				id = id2;
				value = 0;
			}
        }
        cout << "Case " << c << ": " << total << " " << id << endl;
        ++c;
    }

    return 0;
}
