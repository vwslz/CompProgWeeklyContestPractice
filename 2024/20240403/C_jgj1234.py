import sys
from functools import cache
from collections import Counter,defaultdict,deque
from itertools import combinations
from types import GeneratorType
from typing import List
import math
import heapq
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
    return wrappedfunc
def input():
    return sys.stdin.readline().rstrip('\r\n')
while True:
    n=int(input())
    if n==0: break
    l=int(input())
    nodeMap=defaultdict(list)
    for i in range(l):
        u,v=map(int,input().split())
        nodeMap[u].append(v)
        nodeMap[v].append(u)
    colors=[-1]*n
    ans=False
    for i in range(n):
        if ans:
            break
        if colors[i]==-1:
            q=deque([i])
            colors[i]=0
            while q:
                if ans: break
                node=q.popleft()
                for neighbor in nodeMap[node]:
                    if colors[neighbor]==-1:
                        q.append(neighbor)
                        colors[neighbor]=colors[node]^1
                    elif colors[neighbor]==colors[node] and not ans:
                        print('NOT BICOLORABLE.')
                        ans=True
    if not ans:
        print('BICOLORABLE.')
