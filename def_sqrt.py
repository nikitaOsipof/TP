'''
target = 50
x = 1
while True:
    oldx = x
    x = (x + target / x) / 2
    if (oldx == x):
        break

print(x, x*x, sep = '; ')
'''

'''
def my_sqrt0():
    target = int(input("Введите число: "))
    x = 1
    while True:
        oldx = x
        x = (x + target / x) / 2
        if (oldx == x):
            break
    print(f"Квадратный корень из {target} равен {x}")


my_sqrt0()

'''
def my_sqrt(tar):
    x = 1
    while True:
        oldx = x
        x = (x + tar / x) / 2
        if (oldx == x):
            break
    return x


if __name__ == "__main__":
    target = int(input("Введите число: "))
    r = my_sqrt(target)
    print(r, r*r, sep = '; ')

