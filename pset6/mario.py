import cs50 as cs

while True:
    print("Please enter the height: ", end="")
    size = cs.get_int()
    if size >= 0 and size < 24:
     break
if size > 0 and size < 24 :
    for i in range(size):
        print(" " * (size - i -1), end="")
        print("#" *(i + 1), end="")
        print(" " * 2, end="")
        print("#" *(i + 1))
if size == 0:
    print("", end ="");