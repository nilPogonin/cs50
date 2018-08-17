from cs50 import get_string
import sys


if(len(sys.argv) != 2):
    print("Usage: python file key")
    exit(1)
#get the key
key = int(sys.argv[1])
#get the plain text
print("Enter the text: ", end="")
plain_text = get_string()

ciphertext = ""
for c in plain_text:
    if(c.isalpha()):
        if(c.islower()):
            ciphertext+=chr(((ord(c) - 97 + key) % 26) + 97)
        else:
            ciphertext+=chr(((ord(c) - 65 + key) % 26) + 65)
    else:
        ciphertext+=c
#cyphertext = "A"
print("ciphertext:", ciphertext)