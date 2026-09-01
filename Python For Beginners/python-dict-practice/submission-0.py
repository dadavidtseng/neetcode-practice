from typing import Dict # this adds type hinting for Dict

def count_characters(word: str) -> Dict[str, int]:
    result = {}
    for w in word:
        result[w] = result.get(w, 0)+1
    return result





# don't modify below this line
print(count_characters("hello"))
print(count_characters("world"))
print(count_characters("hello world"))
print(count_characters("this is a longer sentence"))
