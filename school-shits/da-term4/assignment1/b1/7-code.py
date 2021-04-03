def seven(n: int) -> int:
    if n == 1: return 1
    return seven(n-1) + 2 * n - 1 