def main():
    char = input()
    text = input()
    row1 = list("qwertyuiop")
    row2 = list("asdfghjkl;")
    row3 = list("zxcvbnm,./")
    shift = 0
    res = ""
    if char == 'R':
        shift = -1
    else:
        shift = 1

    for char in text:
        if char in row1:
            res += row1[row1.index(char) + shift]
        elif char in row2:
            res += row2[row2.index(char) + shift]
        else:
            res += row3[row3.index(char) + shift]
    print(res)



if __name__ == "__main__":
    t = 1
    #t = int(input())
    while t > 0:
        main()
        t -= 1
