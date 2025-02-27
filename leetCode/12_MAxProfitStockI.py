def maxProfit( prices):
    minPrice = float("Inf")
    maxPrice = 0

    maxProfit = 0

    for price in prices:
        if price < minPrice:
            minPrice = price
        else:
            maxProfit = max(maxProfit,price - minPrice)
    return maxProfit

        


price = [1,8,0,1,2,5,20]

print(maxProfit(price))