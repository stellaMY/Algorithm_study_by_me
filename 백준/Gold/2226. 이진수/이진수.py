n = int(input())

list = []
list.append(0)
list.append(0)
list.append(1)
list.append(1)
list.append(3)
for i in range(5, n+1):
    if i % 2 ==1:
        num = list[i-1]*2-1;
        list.append(num)
       
    else:
        num = list[i-1] * 2 +1
        list.append(num)
        
print(list[n])