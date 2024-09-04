import sys
from functools import cache
from collections import Counter,defaultdict,deque
from types import GeneratorType
from typing import List
import math
from math import lcm
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

for case in range(1,int(input())+1):
    string=input()
    if string[:5]=="https":
        print(f'Case {case}: '+string)
    else:
        print(f'Case {case}: '+ "https://"+string[7:])
