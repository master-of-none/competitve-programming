def convert(num_str: str, base_x: int, base_y: int) -> str:
    num = int(num_str, base_x)

    digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    if num == 0:
        return "0"

    res = []

    while num > 0:
        res.append(digits[num % base_y])
        num //= base_y

    return "".join(reversed(res))


print(convert("FF", 16, 10))  # "255"
print(convert("FF", 16, 2))   # "11111111"
print(convert("255", 10, 16))  # "FF"
print(convert("1010", 2, 36))  # "A"
