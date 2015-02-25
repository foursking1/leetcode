class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        if node == None:
            return None
        start = UndirectedGraphNode(node.label)
        map, current = {node: start}, [node]
        while len(current) > 0:
            next = []
            for x in current:
                for neighbor in x.neighbors:
                    if neighbor not in map:
                        neighbor_copy = UndirectedGraphNode(neighbor.label)
                        next.append(neighbor)
                        map[x].neighbors.append(neighbor_copy)
                        map[neighbor] = neighbor_copy
                    else:
                        map[x].neighbors.append(map[neighbor])
            current = next
        
        return start