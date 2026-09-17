class TextProcessor:
    def format_text(self, text1: str, text2: str = "") -> str:
        if text2 == "":
            return text1.upper()
        return text1 + text2

    
        


# Don't modify the code below
processor = TextProcessor()
print(processor.format_text("hello"))
print(processor.format_text("hello", "world"))
