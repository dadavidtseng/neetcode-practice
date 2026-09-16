class Animal:
    def __init__(self, name: str):
        self.name = name

    def make_sound(self) -> None:
        print("Animal makes a sound")


class Dog(Animal):
    def make_sound(self) -> None:
        print(f"{self.name} is barking")


class Cat(Animal):
    def make_sound(self) -> None:
        print(f"{self.name} is meowing")


# Do not modify the code below
animal = Animal("Cow")
animal.make_sound()  # Output: Animal makes a sound
dog = Dog("Max")
dog.make_sound()  # Output: Max is barking
cat = Cat("Luna")
cat.make_sound()  # Output: Luna is meowing
