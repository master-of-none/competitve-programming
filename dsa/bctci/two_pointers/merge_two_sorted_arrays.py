def merge(arr1: list[int], arr2: list[int]) -> list[int]:
    m = len(arr1)
    n = len(arr2)

    l1 = 0
    l2 = 0
    res = []

    while l1 < m and l2 < n:
        if arr1[l1] < arr2[l2]:
            res.append(arr1[l1])
            l1 += 1
        else:
            res.append(arr2[l2])
            l2 += 1

    while l1 < m:
        res.append(arr1[l1])
        l1 += 1

    while l2 < n:
        res.append(arr2[l2])
        l2 += 1

    return res


def test1():
    arr1 = [1, 3, 4, 5]
    arr2 = [2, 4, 4]

    res = [1, 2, 3, 4, 4, 4, 5]

    assert merge(arr1, arr2) == res


def test2():
    arr1 = [-1]
    arr2 = []
    res = [-1]

    assert merge(arr1, arr2) == res


if __name__ == "__main__":
    test1()
    test2()
