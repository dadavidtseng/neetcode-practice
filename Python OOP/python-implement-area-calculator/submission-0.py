import math


class AreaCalc:
    def calculate(self, *args: int) -> float:
        if len(args) == 1:
            return round(args[0] ** 2 * math.pi, 2)
        return args[0] * args[1]


# Don't modify the following code
calc = AreaCalc()
print(calc.calculate(5))
print(calc.calculate(4, 6))
