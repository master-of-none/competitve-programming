from typing import List
import os


def permutations(s: str) -> List[List[str]]:
    res = []
    path = []
    used = [False] * len(s)

    def dfs(j, path):
        if j == len(s):
            res.append(path.copy())
            return

        for i, c in enumerate(s):
            if used[i]:
                continue

            path.append(c)
            used[i] = True
            dfs(j+1, path)

            path.pop()
            used[i] = False

    dfs(0, [])
    return res


def main():
    s = "ABCDEFGHIJ"
    res = permutations(s)

    script_dir = os.path.dirname(os.path.abspath(__file__))
    output_path = os.path.join(script_dir, "permutations.txt")
    with open(output_path, "w") as f:
        for p in res:
            f.write("".join(p) + "\n")


if __name__ == "__main__":
    main()
