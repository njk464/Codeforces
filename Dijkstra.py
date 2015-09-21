#!/usr/bin/env python2.6
from heapq import heappop, heappush

def dijkstra(graph, start, end):
  # q = [(0,start,'')]
  # seen = set()
  # while q:
  #   (cost,v1,path) = heappop(q)
  #   if v1 not in seen:
  #     seen.add(v1)
  #     path = '%s %s' % (path, v1)
  #     if v1 == end: return path[1:]
  #     for v2, c in graph.get(v1, ()):
  #       if v2 not in seen:
  #         heappush(q, (cost+c, v2, path))
  # return -1
  q = [(0,start)]
  while q:
    (cost,v1) = heappop(q)
    if v1 == end: return path_print(path, end)
    for v2, c in graph.get(v1, ()):
      if dist[v2] > cost + c:
        dist[v2] = cost + c
        path[v2] = v1
        heappush(q, (cost+c, v2))
  return -1
def path_print(path, end):
  if path[end] == -1:
    return str(end)
  return path_print(path, path[end]) + " " + str(end)

nums = [int(i) for i in raw_input().split(' ')]
v = nums[0]
e = nums[1]
graph = {}
dist = {}
path = {}
for i in range(1, v+1):
  graph[i] = []
  dist[i] = 1000000000000000
  path[i] = -1
dist[1] = 0
for x in range(e):
  line = [int(i) for i in raw_input().split(' ')]
  graph[line[0]].append((line[1], line[2]))
  graph[line[1]].append((line[0], line[2]))
# for i in range(1, v+1):
#   print graph[i]
print dijkstra(graph, 1, v)
