// Topological Sort is used in a Directed Graph to detect cycle.
// The given code based on leetcode 207 https://leetcode.com/problems/course-schedule/description/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void topoSort(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<unordered_set<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0), ordering;
        queue<int> q;
        int cur_subject;

        for(auto &p: prerequisites)
            adjList[p[1]].insert(p[0]), // p[1] need to be completed first, so we go from p[1] to p[0]
            inDegree[p[0]]++; // From p[1] we go to p[0], so in degree of p[0] increasing

        for(int i = 0; i < inDegree.size(); i++)
            if(inDegree[i] == 0) q.push(i); // Traversing starts from subject with 0 in degree
        
        for(int size = q.size(); !q.empty(); size = q.size())
        {
            while(size--)
            {
                cur_subject = q.front(); q.pop();
                for(auto &next_subject: adjList[cur_subject])
                {
                    inDegree[next_subject]--;
                    if(inDegree[next_subject] == 0) // if a subject's all pre-requisite is finished 
                        q.push(next_subject);
                }
                ordering.push_back(cur_subject);
            }
        }
        
        cout << "In the order we should take course : ";
        for(auto &v: ordering)
            cout << v << " ";
        cout << endl << endl;
        
        cout << "Is every course's pre-requisite finished ? ";
        cout << (any_of(begin(inDegree), end(inDegree), [](int x) { return x > 0; }) == true? "NO" : "YES") << endl;
    }
};

int main()
{
    int numCourses = 7;
    vector<vector<int>> prerequisites = {{1,0}, {2,1}, {3,2}, {5,0}, {5,6}, {2,5}, {3,5}, {4,5}};
    Solution s;
    s.topoSort(numCourses, prerequisites);
    return 0;
}