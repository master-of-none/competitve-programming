from typing import List, Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def buildTree(values: List[Optional[int]]) -> Optional[TreeNode]:

    if not values:
        return None

    root = TreeNode(values[0])
    queue = deque([root])

    i = 1
    while queue and i < len(values):
        node = queue.popleft()

        if values[i] is not None:
            node.left = TreeNode(values[i])
            queue.append(node.left)

        i += 1

        if i < len(values) and values[i] is not None:
            node.right = TreeNode(values[i])
            queue.append(node.right)

        i += 1

    return root


def printLevelOrder(root: Optional[TreeNode]):
    if not root:
        return []

    res = []
    q = deque([root])

    while q:
        node = q.popleft()

        res.append(node.val if node else None)

        if node:
            q.append(node.left)
            q.append(node.right)

    return res
