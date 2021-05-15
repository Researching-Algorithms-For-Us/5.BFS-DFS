'''
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

4 5 1
1 2
1 3
1 4
2 4
3 4

1 2 4 3
1 2 3 4
'''
#number = list(map(int, input().split()))
from collections import deque

def set_input():
    size, number, start = map(int, input().split())
    graph = [[] for _ in range(size+1)]
    graph[0] = [0,0]

    for _ in range(number):
        s, e = map(int,input().split())
        graph[s].append(e)
        graph[e].append(s)
        graph[s].sort()
        graph[e].sort()
        
    return number, size, start, graph

def main(): 
    _, _, start, graph = set_input()
        
    def dfs(graph, start):

        output = []
        stack = list([start])

        while stack:
            value = stack.pop()
            if value not in output:
                output.append(value)
                stack.extend(sorted(graph[value], reverse=True))

        #output[1:].reverse()
        return output

    def bfs(graph, start):
        queue = deque([start])
        output = []
        while queue:
            value = queue.popleft()
            
            if value not in output:
                output.append(value)
                queue.extend(sorted(graph[value], reverse=False))
            
        return output

    print(*dfs(graph, start))
    print(*bfs(graph, start))

if __name__ == '__main__':
    main()
