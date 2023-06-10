def add_neighbours(graph:list[list[int]], m:int, n:int):
    v = 0
    for r in range(1, m+1):
        for c in range(1, n+1):
            if c != 1 : graph[v].append(v-1)     # left
            if c != n : graph[v].append(v+1)    # right
            if r != 1 : graph[v].append(v-n)   # top
            if r != m : graph[v].append(v+n)  # bottom
            v += 1

def print_neighbours(graph:list[list[int]]):
    for i in range(len(graph)):
        print(f"Node {i} has neighbours : ", end = "")
        for v in graph[i]:
            print(v, end = " ")
        print()

def main():
    m, n = map(int, input().split())
    graph = [[] for _ in range(m*n)]

    add_neighbours(graph, m, n)
    print_neighbours(graph)

if __name__ == '__main__':
    main()