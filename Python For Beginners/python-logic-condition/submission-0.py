def discount_applies(age: int) -> bool:
    return True if age < 18 or age >= 65 else False


# don't modify this code below this line
print(discount_applies(17))
print(discount_applies(18))
print(discount_applies(40))
print(discount_applies(65))
print(discount_applies(70))
