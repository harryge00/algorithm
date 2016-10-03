/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
  // set<DirectedGraphNode*> visited;
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        // visited.insert(s);
        map<DirectedGraphNode*, bool> visited;
        visited[s] = 1;
        queue<DirectedGraphNode*> q;
        while(!q.empty()) {
          DirectedGraphNode* tmp = q.pop();
          if()
          for(vector<DirectedGraphNode*>::iterator it = tmp->neighbors.begin();
          it != tmp->neighbors.end(); it++) {
            q.push(*it);


        }
          if((*it)->label == t->label) return true;

          if(hasRoute(graph, *it, t)) return true;
        }
        visited.remove(visited.find(s));
        return false;
    }
};
