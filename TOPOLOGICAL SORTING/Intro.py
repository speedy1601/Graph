# Topological Sort is used in a Directed Graph to detect cycle.
# The given code based on leetcode 207 https://leetcode.com/problems/course-schedule/description/
from typing import List
from collections import deque

class Solution:
    def topSort(self, numCourses: int, prerequisites: List[List[int]]) -> None:
        adjList = [set() for _ in range(numCourses)]
        inDegree = [0] * numCourses
        ordering = []

        for (to, fromm) in prerequisites:
            adjList[fromm].add(to)
            inDegree[to] += 1 # for every (to, fromm), the in-degree of 'to' increases
        
        q = deque([subject for subject, indegree in enumerate(inDegree) if indegree == 0]) # Traversing starts from subject with 0 in degree
        
        while q:
            for _ in range(len(q)):
                cur_subject = q.popleft()

                for next_subject in adjList[cur_subject]:
                    inDegree[next_subject] -= 1
                    if inDegree[next_subject] == 0: # if a subject's all pre-requisite is finished 
                        q.append(next_subject)

                ordering.append(cur_subject)
        
        
        print("\nIn the order we should take course : ", end="")
        print(*ordering)

        print("\nIs every course's pre-requisite finished ? ", end="")
        print( "NO" if any(inDegree) == True else "YES!")

def main():
    numCourses = 7
    prerequisites = [[1,0], [2,1], [3,2], [5,0], [5,6], [2,5], [3,5], [4,5]]
    s = Solution()
    s.topSort(numCourses, prerequisites)

if __name__ == '__main__':
    main()
    