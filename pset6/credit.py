import cs50
from array import array
print("Number: ", end="")
number = cs50.get_int()
digits = array('i')
n = number
x = number
counter = 0
c = 0
s = 0
z = 1
while n > 0:
    n = n // 10
    counter += 1
# print(counter)
for i in range(counter):
    z *= 10
z /= 10
# print(z)
v = number
v = v // z
# print(v)
if v == 3:
    stat = 1
elif v == 5:
    stat = 2
elif v == 4:
    stat = 3
else:
    stat = 4
# print(stat)
while c < counter // 2:
    temp = ((x % 100) // 10) * 2
    # print(temp)
    if temp // 10 > 0:
        digits.append(temp // 10)
        # print(temp//10)
        digits.append(temp % 10)
        # print(temp%10)
    else:
        digits.append(temp)
    x = x // 100
    # print(x)
    c += 1
    # print(c)
for n in digits:
    s += n
c = 0
if counter % 2 == 1:
    a = counter // 2 + 1
else:
    a = counter // 2
d = array('i')
while c < a:
    temp = number % 10
    d.append(temp)
    number = number // 100
    c += 1
for n in d:
    s += n
# print(s)
if s % 10 == 0:
    # print(1)
    if stat == 1:
        print("AMEX")
    elif stat == 2:
        print("MASTERCARD")
    elif stat == 3:
        print("VISA")
    else:
        print("INVALID")
else:
    #print (2)
    print("INVALID")