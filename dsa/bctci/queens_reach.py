def safe_cells(board):
    n = len(board)

    res = [[0] * n for _ in range(n)]

    for r in range(n):
        for c in range(n):
            if board[r][c] == 1:
                res[r][c] = 1
                mark_queens_reach(board, r, c, res)
    return res


def mark_queens_reach(board, r, c, res):
    directions = [
        [-1, 0], [1, 0], [0, -1], [0, 1], [1, 1], [-1, -1], [1, -1], [-1, 1]
    ]

    for dr, dc in directions:
        nr, nc = r + dr, c+dc

        while is_valid(board, nr, nc):
            res[nr][nc] = 1
            nr += dr
            nc += dc


def is_valid(board, r, c):
    return 0 <= r < len(board) and 0 <= c < len(board) and board[r][c] != 1


def main():
    board = [[0] * 6 for _ in range(6)]
    board[1][1] = 1
    board[3][4] = 1
    board[4][4] = 1

    res = safe_cells(board)
    print(res)


if __name__ == "__main__":
    main()
