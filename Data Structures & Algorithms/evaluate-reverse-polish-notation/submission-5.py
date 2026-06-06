class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        result = 0
        tokens_size = len(tokens)
        s = []

        for i in range(tokens_size):
            if tokens[i] == "+":
                a = s.pop()
                b = s.pop()
                result = b + a
                s.append(result)
            elif tokens[i] == "-":
                a = s.pop()
                b = s.pop()
                result = b - a
                s.append(result)
            elif tokens[i] == "*":
                a = s.pop()
                b = s.pop()
                result = b * a
                s.append(result)
            elif tokens[i] == "/":
                a = s.pop()
                b = s.pop()
                result = int(b / a)
                s.append(result)
            else:
                t = int(tokens[i])
                result = t
                s.append(t)

        return result
