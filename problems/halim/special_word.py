def replace_word(s: str) -> str:
    s_array = list(s.split(" "))
    res = []
    for word in s_array:
        if word[0].islower() and word[1].isdigit() and word[2].isdigit() and len(word) == 3:
            temp = "***"
            res.append(temp)
            continue
        res.append(word)
    return " ".join(res)


def main():
    s = "line: a70 and z72"
    res = replace_word(s)
    print(f'Replaced: {res}')
    s = "line: aa24 and zz69"
    res = replace_word(s)
    print(f'Not Replaced: {res}')


if __name__ == "__main__":
    main()
