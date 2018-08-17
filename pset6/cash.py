from cs50 import get_float

while True:
    print("Enter the charge: ", end="")
    charge = get_float()
    if charge >= 0:
        break


counter = 0
while charge > 0:
    if charge >= 0.25:
        charge = charge - 0.25
        counter = counter + 1
        print("0.25 ", end="")
    elif charge >= 0.10:
        charge = charge - 0.10
        counter = counter + 1
        print("0.10 ", end="")
    elif charge >= 0.05:
        charge = charge - 0.05
        counter = counter + 1
        print("0.05 ", end="")
    else:
        charge = charge - 0.01
        counter = counter + 1
        print("0.01 ", end="")
print(counter)