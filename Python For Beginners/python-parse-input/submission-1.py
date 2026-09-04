from typing import List


def read_integers() -> List[int]:
    result = input()
    return [int(r) for r in result.split(",")]


# do not modify the code below
print(read_integers())
print(read_integers())
print(read_integers())
