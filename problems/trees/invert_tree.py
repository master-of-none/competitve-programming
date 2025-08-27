import tree_util


def invertTree(root):
    if not root:
        return None

    root.left, root.right = root.right, root.left

    invertTree(root.left)
    invertTree(root.right)

    return root


def main():
    root = tree_util.buildTree([4, 2, 7, 1, 3, 6, 9])
    print("Original: ", tree_util.printLevelOrder(root))

    inverted = invertTree(root)
    print("Inverted: ", tree_util.printLevelOrder(inverted))


if __name__ == "__main__":
    main()
