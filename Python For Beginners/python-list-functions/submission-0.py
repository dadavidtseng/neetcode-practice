from typing import List  # this is used to add type hints for List type


def get_sum(nums: List[int]) -> int:
    result = 0
    for num in nums:
        result += num
    return result


def get_min(nums: List[int]) -> int:
    result = float("inf")
    for num in nums:
        if num < result:
            result = num
    return result


def get_max(nums: List[int]) -> int:
    result = float("-inf")
    for num in nums:
        if num > result:
            result = num
    return result


# do not modify below this line
print(get_sum([1, 2, 3, 4, 5]))
print(get_sum([5, 4, 5, 6]))

print(get_min([7, 3, 4, 5]))
print(get_min([5, 4, 5, 6]))

print(get_max([7, 3, 4, 5]))
print(get_max([5, 4, 5, 6]))
