
# Online Python - IDE, Editor, Compiler, Interpreter

def sum(a, b):
    d = a / b
    r = a + b*d
    return r

print("Знакомство с функциями")

a = int(input('Enter 1st number: '))
b = int(input('Enter 2nd number: '))

s = sum(a,b)
print(f'Sum of {a} and {b} is {s}')


age = int(input())

def agt(age = 1):
    if age < 10:
        print (f'Ваш возраст{age} - это одна цифра :')
    elif age < 15:
        print ('Удачи с геометрией :):):)')
    else:
        print ('Совсем взрослый уже :(')
    
agt()
