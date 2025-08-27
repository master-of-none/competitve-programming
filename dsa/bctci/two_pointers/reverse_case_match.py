def reverse_case_match(s: str) -> bool:
    l = 0
    r = len(s)-1

    while l < len(s) and r >= 0:
        if s[l].isupper():
            l += 1
        elif s[r].islower():
            r -= 1
        else:
            if s[l] != s[r].lower():
                return False

            l += 1
            r -= 1

    return True


def test_1():
    s = "haDrRAHd"
    assert reverse_case_match(s) == True


def test_2():
    s = "haHrARDd"
    assert reverse_case_match(s) == False


if __name__ == "__main__":
    test_1()
    test_2()
