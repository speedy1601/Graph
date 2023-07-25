# https://leetcode.ca/2016-09-11-286-Walls-and-Gates/
'''
From the each gate the nearest empty room is the room with distance 1 from that gate that's for sure! To do that first we
have to inlude all the gate in queue..Now each time after marking 1 of all the empty room from a gate, push all the 1
marked room in the queue, why? From each 1 marked room if we can reach ANOTHER EMPTY ROOM, that means THERE WAS NO GATE
WHO COULD REACH THOSE "ANOTHER EMPTY ROOM" WITH 1 DISTANCE, so it's safe to mark those "another empty room" as 2. Now from
those 2 marked rooms mark all the unvisited room as 3 as no gate could reach them with distance less than 3 and so on....

No need any visited vector, once we find a empty room we are marking it instant! So iff the room is empty, we'll visit it
'''
from collections import deque

class Solution:
    def wallsAndGates(self, rooms: list[list[int]]) -> None :
        rows, cols, level = len(rooms), len(rooms[0]), 1
        q = deque([(r,c) for r in range(rows) for c in range(cols) if rooms[r][c] == 0]) # if rooms[r][c] == gate
        
        while q:
            for _ in range(len(q)):
                pr, pc = q.popleft()
                for (x,y) in ((0,-1), (-1,0), (0,1), (1,0)):
                    r, c = pr + x, pc + y
                    if r<0 or r>=rows or c<0 or c>=cols or rooms[r][c] != 2147483647: # if room != an empty room
                        continue
                    rooms[r][c] = level
                    q.append((r,c))
            level += 1

def main():
    rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
    s = Solution()
    s.wallsAndGates(rooms)
    print( '\n'.join( ' '.join(map(str, arr)) for arr in rooms) )

if __name__ == '__main__':
    main()