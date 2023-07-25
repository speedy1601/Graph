// https://leetcode.ca/2016-09-11-286-Walls-and-Gates/
/* 
From the each gate the nearest empty room is the room with distance 1 from that gate that's for sure! To do that first we
have to inlude all the gate in queue..Now each time after marking 1 of all the empty room from a gate, push all the 1
marked room in the queue, why? From each 1 marked room if we can reach ANOTHER EMPTY ROOM, that means THERE WAS NO GATE
WHO COULD REACH THOSE "ANOTHER EMPTY ROOM" WITH 1 DISTANCE, so it's safe to mark those "another empty room" as 2. Now from
those 2 marked rooms mark all the unvisited room as 3 as no gate could reach them with distance less than 3 and so on....

No need any visited vector, once we find a empty room we are marking it instant! So iff the room is empty, we'll visit it
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void wallsAndGates(vector<vector<int>> &rooms)
    {
        int rows = rooms.size(), cols = rooms[0].size(), pr, pc, r, c;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(rows, vector<bool> (cols));
        vector<vector<int>> diff = {{0,-1}, {-1,0}, {0,1}, {1,0}};

        for(int r = 0; r < rows; r++)
            for(int c = 0; c < cols; c++)
                if(rooms[r][c] == 0) // if we find a gate
                    q.push({r, c});

        for(int level = 1, size = q.size(); !q.empty(); size = q.size(), level++)
        {
            while(size--)
            {
                pr = q.front().first, pc = q.front().second; q.pop();
                for(auto &d: diff)
                {
                    r = pr + d[0], c = pc + d[1];
                    if(r<0 || r>=rows || c<0 || c>=cols || rooms[r][c] != INT_MAX)
                        continue;
                    rooms[r][c] = level;
                    q.push({r, c}); // these are the empty room(INT_MAX)
                }
            }
        }       
    }
};

int main()
{
    vector<vector<int>> rooms = {{-1}};
    Solution s;
    s.wallsAndGates(rooms);
    for(auto &arr: rooms)
    {
        for(auto v: arr)
            cout << v << " ";
        cout << endl;
    }
}