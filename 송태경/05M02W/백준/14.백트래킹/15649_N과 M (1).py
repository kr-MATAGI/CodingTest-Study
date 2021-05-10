'''
백트래킹(퇴각검색)
DFS(깊이 우선 탐색) 방식 기반으로, 불필요한 경우를 배제하며
원하는 해답에 도달할 때까지 탐색하는 전략
'''

n, m = map(int, input().split())
num_list = [i for i in range(1, n+1)]