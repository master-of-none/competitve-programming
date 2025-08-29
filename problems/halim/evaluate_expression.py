def evaluate(s: str) -> float:
    ops = []
    vals = []

    tokens = s.replace("(", " ( ").replace(")", " ) ").split()

    for token in tokens:
        if token == "(":
            continue
        elif token in {"+", "-", "*", "/"}:
            ops.append(token)
        elif token == ")":
            op = ops.pop()
            v = vals.pop()
            if op == "+":
                vals.append(vals.pop() + v)
            elif op == "-":
                vals.append(vals.pop() - v)
            elif op == "*":
                vals.append(vals.pop() * v)
            elif op == "/":
                vals.append(vals.pop() / v)
        else:
            vals.append(float(token))

    return vals[0]


def main():
    s = "( ( 3 + ( ( 8 - 7.5 ) * ( 10 / 5 ) ) ) - ( 2 + ( 5 * 7 ) ) )"
    print(evaluate(s))


if __name__ == "__main__":
    
    main()
