def moves(seq):
    if len(seq) == 0:
        return ""

    if seq[0] == '2':
        return moves(seq[1:]) + moves(seq[2:])

    else:
        return seq[0] + moves(seq[1:])


def main():
    seq = input().strip()
    res = moves(seq)
    print(f'The Result is \n{res}')


if __name__ == "__main__":
    main()
