# https://gongybable.medium.com/meta-interview-question-leetcode-1136-a421f0651584 https://leetcode.ca/all/1136.html
# This is exactly the same as the Intro.py
from typing import List
from collections import deque

class Solution:
    def minimumSemesters(self, n: int, relations: List[List[int]]) -> int:
        adjList = [set() for _ in range(n+1)]
        inDegree = [0] * (n+1)

        for (fromm, to) in relations:
            adjList[fromm].add(to)
            inDegree[to] += 1 # for every (to, fromm), the in-degree of 'to' increases
        
        q = deque([course for course, indegree in enumerate(inDegree) if indegree == 0]) # Traversing starts from subject with 0 in degree
        semester = 0

        while q:
            for _ in range(len(q)):
                cur_course = q.popleft()

                for next_course in adjList[cur_course]:
                    inDegree[next_course] -= 1 # in-degree of next_course decreases
                    if inDegree[next_course] == 0: # if a subject's all pre-requisite is finished 
                        q.append(next_course)

            semester += 1

        return -1 if any(inDegree) == True else semester
        

def main():
    n = 3
    relations = [[1,3], [2,3]]
    s = Solution()
    print(s.minimumSemesters(n, relations))

if __name__ == '__main__':
    main()