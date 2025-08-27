def string_split(s: str, c: str) -> list[str]:
    res: list[str] = []
    temp: list[str] = []

    if not s:
        return res

    for char in s:
        if char == c:
            res.append("".join(temp))
            temp = []

        else:
            temp.append(char)

    res.append("".join(temp))
    return res


def test():
    def test_1():
        s = "split by space"
        c = ' '
        assert string_split(s, c) == ["split", "by", "space"]

    def test_2():
        s = "beekeeper needed"
        c = 'e'
        assert string_split(s, c) == [
            "b", "", "k", "", "p", "r n", "", "d", "d"]

    def test_3():
        s = "/home/./..//Documents/"
        c = '/'
        assert string_split(s, c) == ["", "home",
                                      ".", "..", "", "Documents", ""]

    def test_4():
        s = ""
        c = '?'
        assert string_split(s, c) == []

    test_1()
    test_2()
    test_3()
    test_4()


if __name__ == "__main__":
    test()
