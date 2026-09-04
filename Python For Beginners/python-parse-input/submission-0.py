from typing import List


def read_integers() -> List[int]:
    result = input()
    result = result.split(",")
    return [int(r) for r in result]


# do not modify the code below
print(read_integers())
print(read_integers())
print(read_integers())
