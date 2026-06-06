class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        result = int(tokens[0])
        tokens_size = len(tokens)
        s = []

        if tokens_size == 1:
            return result

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
                s.append(int(tokens[i]))

        return result
