// https://gongybable.medium.com/meta-interview-question-leetcode-1136-a421f0651584 https://leetcode.ca/all/1136.html
// This is exactly the same as the Intro.cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minimumSemesters(int n, vector<vector<int>> &relations)
    {
        vector<unordered_set<int>> adjList(n+1);
        vector<int> inDegree(n+1);
        queue<int> q;
        int cur_course, size, semester;

        for(auto &p: relations)
            adjList[p[0]].insert(p[1]), // As we go from p[0] to p[1]
            inDegree[p[1]]++; // from p[0] to p[1], means in-degree of p[1] increases
        
        for(int i = 0; i < inDegree.size(); i++)
            if(inDegree[i] == 0) q.push(i); // Traversing starts from courses with 0 in degree
        
        for(size = q.size(), semester = 0; !q.empty(); size = q.size(), semester++)
        {
            while(size--)
            {
                cur_course = q.front(); q.pop();
                for(auto &next_course: adjList[cur_course])
                {
                    inDegree[next_course]--;
                    if(inDegree[next_course] == 0)
                        q.push(next_course);
                }
            }
        }

        return any_of(begin(inDegree), end(inDegree), [](int x){ return x > 0; }) == true? -1 : semester;
    }
};

int main()
{
    int n = 3;
    vector<vector<int>> relations = {{1,3}, {2,3}};
    Solution s;
    cout << s.minimumSemesters(n, relations);
}