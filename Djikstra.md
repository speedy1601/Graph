```py
from heapq import heapify, heappush, heappop

class Solution:
    def djikstra(self, adjList: list[list[int]], n: int, sourceNode: int) -> int:
        visited, cost, parentOf = [False] * n, [float('inf')] * n, [-1] * n
        cost[sourceNode] = 0
        numberOfVisitedNodes, maxCost = 0, float('-inf')
        
        while True:
            startNode, prevMinCost = -1, float('inf')
            for node in range(n): # find the unvisited node with minimum cost
                if not visited[node] and cost[node] < prevMinCost:
                    prevMinCost = cost[node]
                    startNode = node
            
            if startNode == -1:  # means either every node visited or the graph is disconncted
                break
            
            for adjNode, weight in enumerate(adjList[startNode]): # update cost for all the connected node of startNode
                curCost = cost[startNode] + weight
                if weight != -1 and not visited[adjNode] and curCost < cost[adjNode]:
                    cost[adjNode] = curCost
                    parentOf[adjNode] = startNode
            
            visited[startNode] = True
            numberOfVisitedNodes += 1
            maxCost = max(maxCost, cost[startNode])
        
        if numberOfVisitedNodes == n: # print the final graph if we could reach to End from Source Node
            for to, fromm in enumerate(parentOf):
                print('From', fromm, 'To', to)
        print()
        return maxCost if numberOfVisitedNodes == n else -1
    
    # using min heap
    def djikstra1(self, adjList: list[list[int]], n: int, sourceNode: int) -> int:
        visited, cost, parentOf = [False] * n, [float('inf')] * n, [-1] * n
        cost[sourceNode] = 0
        pq = [(0, sourceNode)]
        heapify(pq)
        numberOfVisitedNodes, maxCost = 0, float('-inf')

        while len(pq) != 0:
            startNode = heappop(pq)[1]
            if visited[startNode] == True:
                continue

            for adjNode, weight in enumerate(adjList[startNode]):
                curCost = cost[startNode] + weight
                if weight != -1 and not visited[adjNode] and curCost < cost[adjNode]:
                    cost[adjNode] = curCost
                    parentOf[adjNode] = startNode
                    heappush(pq, (cost[adjNode], adjNode))
            
            visited[startNode] = True
            numberOfVisitedNodes += 1
            maxCost = max(maxCost, cost[startNode])
        
        if numberOfVisitedNodes == n: # print the final graph if we could reach to End from Source Node
            for to, fromm in enumerate(parentOf):
                print('From', fromm, 'To', to)
        print()
        return maxCost if numberOfVisitedNodes == n else -1

    def makeGraphFromInput(self, inputList, adjList: list[list[int]]) :
        for (fromm, to, cost) in inputList:
            adjList[fromm][to] = cost
    
    def minCost(self, inputList: list[list[int]], n: int, sourceNode: int):
        adjList = [[-1] * n for _ in range(n)]
        self.makeGraphFromInput(inputList, adjList)
        return self.djikstra1(adjList, n, sourceNode)


def main():
    si = Solution()
    inputList = [[0,1,1],[0,2,3],[1,2,1], [1,3,2],[2,3,2],[3,4,3]]
    print(si.minCost(inputList, 5, 0))
 
if __name__ == '__main__':
    main()
```