if __name__ == '__main__':
    n = int(input())
    list = []
    maxi = 0
    mini = 2134567890
    for i in range(n):
        m = int(input())
        list.append(m)
        if m > maxi: maxi=m
        if m < mini: mini=m
    flag=0
    cnt=0
    tmpmini = 2134567890
    tmpmaxi = 0
    for i in range(n):
        flag = 0
        if tmpmaxi < list[i]:
            tmpmaxi = list[i]
        if tmpmini > list[i]:
            tmpmini = list[i]
        if i!=n-1 and list[i] > list[i+1]:
            flag = 1
            cnt += list[i] - tmpmini
            tmpmini = 2134567890
        if i == n-1 and flag == 0:
            cnt += tmpmaxi - tmpmini
    print(cnt)