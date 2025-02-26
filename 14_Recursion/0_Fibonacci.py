#  Fibonacci
# f(0) 0
# f(1) 1
# f(n) f(n-1) + f(n-2)

def getNthFib(n):
    # Base case
    if n == 1:
        return 0
    if n == 2:
        return 1
        
    return getNthFib(n - 1) + getNthFib(n - 2)