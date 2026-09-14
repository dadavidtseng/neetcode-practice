class BankAccount:
    total_accounts: int = 0
    total_balance: int = 0

    def __init__(self, name: str, balance: int) -> None:
        self.name: str = name
        self.balance: int = balance
        BankAccount.total_accounts += 1
        BankAccount.total_balance += balance


# Create two accounts
alice_account = BankAccount("Alice", 1000)
bob_account = BankAccount("Bob", 2000)

# Print the information using the mentioned format
print(f"{alice_account.name}'s balance: ${alice_account.balance}")
print(f"{bob_account.name}'s balance: ${bob_account.balance}")
print(f"Total Accounts: {BankAccount.total_accounts}")
print(f"Total Balance: ${BankAccount.total_balance}")
