def chess_board(board, peice, r, c):
    moves = []
    king_directions = [
        [-1, 0], [1, 0], [0, -1], [0, 1], [1, 1], [-1, -1], [1, -1], [-1, 1]
    ]

    knight_directions = [
        [-2, 1], [-1, 2], [1, 2], [2, 1], [2, -1], [1, -2], [-1, -2], [-2, -1]
    ]

    if peice == "knight":
        directions = knight_directions

    else:
        directions = king_directions

    for dr, dc in directions:
        nr, nc = r+dr, c+dc

        if peice == "queen":
            while is_valid(board, nr, nc):
                moves.append([nr, nc])
                nr += dr
                nc += dc

        elif is_valid(board, nr, nc):
            moves.append([nr, nc])

    return moves


def is_valid(board, r, c):
    return 0 <= r < len(board) and 0 <= c < len(board[0]) and board[r][c] != 1


def main():
    board = [[0 for _ in range(6)] for _ in range(6)]
    board[0][3] = 1
    board[1][1], board[1][2], board[1][3] = 1, 1, 1
    board[2][1], board[2][3], board[2][4] = 1, 1, 1
    board[3][0], board[3][1], board[3][2], board[3][3] = 1, 1, 1, 1
    board[5][1] = 1

    # print(board)
    piece = input("Enter piece (king/queen/knight): ").strip().lower()
    r = int(input("Enter row (0-5): "))
    c = int(input("Enter column (0-5): "))

    moves = chess_board(board, piece, r, c)

    print(f"Possible moves for {piece} at ({r}, {c}):")
    for move in moves:
        print(move)


if __name__ == "__main__":
    main()
