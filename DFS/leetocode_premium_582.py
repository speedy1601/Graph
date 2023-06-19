'''
leetocode premium 582
Question : Given pid (child nodes), ppid(parent nodes) and a node to kill. Kill the node and if you kill that node
           the node's child node will also get killed.

Input : 
pid = [1, 3, 10, 5, 7, 4], ppid = [3, 0, 5, 3, 10, 7], kill = 5

                0
              /
            3 ----- 5
           /         \
          1           10
                        \
                         7
                          \
                           4

Output : [5, 10, 7, 4] (in any order even tho I used OrderedSet())

                0
              /
            3 
           /         
          1           
    
    
Explanation : Now If I kill 5, along 5 5's children 10 will also get killed and if 10 get killed then 10's children
will also get killed. So from 5 whatever nodes are able to be visited they all are killed and we've tp return these
kill able nodes. 
'''
from collections import defaultdict
from ordered_set import OrderedSet 
class Solution:
    def dfs(self, graph, visited, parent_node):
        visited.add(parent_node)
        for child in graph[parent_node]:
            if visited.count(child) == 0:
                self.dfs(graph, visited, child)

    def killProcess(self, pid:list[int], ppid:list[int], kill:int):
        graph = defaultdict(list)
        for i in range(len(ppid)):
            graph[ppid[i]].append(pid[i])

        visited = OrderedSet()
        self.dfs(graph, visited, kill)
        return list(visited)

def main():
    pid = [1, 3, 10, 5, 7, 4] 
    ppid = [3, 0, 5, 3, 10, 7]
    kill = 5
    s = Solution()
    ans = s.killProcess(pid, ppid, kill)
    print('KIll has killed : ', end = "")
    for v in ans: print(v, end = " ")

if __name__ == '__main__':
    main()