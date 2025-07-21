# @JUDGE_ID: 1709779 10038 Python "Jolly"*/

#!
#! Solved By: Shrikrishna Bhat
#!

import sys

def jolly(input):
    hashmap = set()
    n = input[0]
    input = input[1:]
    for i in range(1, n):
        hashmap.add(i)
    
    
    for i in range(1, len(input)):
        diff = abs(input[i] - input[i-1])
        if diff in hashmap:
            hashmap.remove(diff)
        else:
            return False

    return len(hashmap) == 0

if __name__ == "__main__":
    for line in sys.stdin:
        if not line.strip():
            continue  # skip empty lines
        tokens = list(map(int, line.strip().split()))
        # print(tokens)
        # n = tokens[0]
        # sequence = tokens[1:]
        # if len(sequence) != n:
        #     print("Not jolly")  # or raise an error if input is malformed
        #     continue
        print("Jolly" if jolly(tokens) else "Not jolly")