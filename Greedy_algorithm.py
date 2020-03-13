'''

                       Minimum cost to fill given weight in a bag.
    You are given a bag of size W kg and you are provided costs of packets 
    different weights of oranges in array cost[] where cost[i] is basically cost of ‘i’ kg packet of oranges. 
    Find the minimum total cost to buy exactly W kg oranges
'''

print("Hello World")
weight = int(input())
cost = list()
cost_per_weight = list()
for i in range(weight):
    l = int(input())
    cost.append(l)
    cost_per_weight.append(l/(i+1))
cost_per_weight.sort()
j = 0
weight_check = 0    # weight of product added to bag
current_weight = 0
i = 0
while i <weight:
    if (cost[i]/(i+1) == cost_per_weight[j]):
        weight_check += i + 1  
        temp = i + 1
        if (weight_check == weight):
            current_weight += cost[i]
            break
        if (weight_check > weight):  
            temp -= weight_check - weight
            current_weight += int(cost_per_weight[j] * temp) # could've used cost[i] but taking cost of all i oranges may overflow the packet.
            break                                            # so if weight_check goes above original weight, fix temp & take only temp times of cost
        current_weight += cost[i]
        j += 1
        i = 0
    i += 1
print(current_weight)
        
        
        
        
        