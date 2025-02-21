
# Metodo basado en bitwise and (comparar bit a bit)
# Pensemos en cualquier potencia de 2 en binario
# 8 -> 1000 (un 1 en 2 elevado a 3)
# 7 -> 0111
# bitwise operation en ese devuelve 0
# O(1) en space and time
def bitwiseCheck(n):
    if n == 0:
        return False
    res = n&(n-1) == 0
    return res

print(bitwiseCheck(64))
print(bitwiseCheck(79))

# Segunda opcion. use logarithms: if y = 2 ^ n -> log(y) = int (logaritmo en base 2 de y es entero)
# This can fail in very big numbers due to rounding errors
#  we should set some error 
# O(1)
import math
def isPowerof2Log(n):
    if n <= 0:
        return False
    else:
        # res =  math.log(n,2).is_integer() Opcion simple
        return abs(round(math.log(n,2))-math.log(n,2)) < 1e-10 # better option
    
print(isPowerof2Log(64))
print(isPowerof2Log(79))

# Iterative division. Simply divide by 0. Brute force
def iterativeDiv(n):
    if n <= 0:
        return False
    else:
        # continue while the rest is 0. at some point we should reach n=1 and then we break
        while n % 2 == 0:
            n = n // 2 # integer division in python. Since we have check before that n is divisible by 2, the result will
            # always be integer
        return n == 1
    
print(iterativeDiv(64))
print(iterativeDiv(79))