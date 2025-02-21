

def findComplement(n):
    # find bits
    num_bits = n.bit_length()

    # create mask
    mask = (1 << num_bits) - 1
    # think in biary to understand this expresion, Imagine 8 bits
    #  1 -> 00000001
    # shift the 1 to the left number of bits(8)
    # Now you have 100000000 -> 1 * 2 elevado 7
    # ahora restas 1y tienes 011111111

    # exclusive XOR
    return n ^ mask