# class Node:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


def is_leaf(root):
    if not root:
        return False
    return not root.left and not root.right


def children(root):
    if not root:
        return []
    res = []

    if root.left:
        res.append(root.left.val)

    if root.right:
        res.append(root.right.val)

    return res


def grandchildren(root):
    if not root:
        return []

    res = []
    for child in [root.left, root.right]:
        if child and child.left:
            res.append(child.left.val)

        if child and child.right:
            res.append(child.right.val)

    return res
