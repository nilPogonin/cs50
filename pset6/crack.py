import cs50
import crack
import sys

def main():
    if len(sys.argv) != 2:
        print("Usage: crack hash")
        exit(1)
    if brute_force(sys.argv[1]) == False:
        exit(2)
def brute_force(given_hash):
    all_letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKELMNOPQRSTUVWXYZ"
    collect=""
    salt=""
    salt += given_hash[0] + given_hash[1]

    for i in range(52):
        collect += all_letters[i]
        new_hash = crypt.crypt(collect, salt)


if __name__ == "__main__":
    main()