from typing import List
import os


def subset(n) -> List[List[int]]:
    nums = [i for i in range(1, n+1)]
    res = []
    path = []

    def dfs(i):
        if i >= len(nums):
            res.append(path.copy())
            return

        path.append(nums[i])
        dfs(i+1)

        path.pop()
        dfs(i+1)

    dfs(0)
    return res


def main():
    n = 20
    res = subset(n)
    script_dir = os.path.dirname(os.path.abspath(__file__))
    output_path = os.path.join(script_dir, "subsets.txt")

    with open(output_path, "w") as f:
        for r in res:
            f.write(str(r) + "\n")


if __name__ == "__main__":
    main()
