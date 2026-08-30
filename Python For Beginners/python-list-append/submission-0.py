from typing import List  # this is used to add type hints for List type


def append_to_list(my_list: List[int], elements: List[int]) -> List[int]:
    return my_list + elements


# do not modify below this line
print(append_to_list([1, 2, 3], [4, 5]))
print(append_to_list([], [1, 2, 3, 4]))
