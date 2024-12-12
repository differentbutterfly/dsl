def longest_word(s):
    words = s.split(' ')  # Split the string into a list of words
    max_len = 0           # Variable to keep track of the longest word length
    longest = ""          # Variable to keep track of the longest word
    for word in words:
        length = 0     # Counter for each word's length
        for char in word:
            length += 1   # Count each character in the word
        if length > max_len:  # If current word is longer than max_len
            max_len = length
            longest = word
    return longest


def palindrome(s):
    start=0
    end=len(s)-1
    while end>start:
        if s[start]!=s[end]:
            return False
    start+=1
    end-=1
    return True


def freq_of_char(s,ch):
    count=0
    for char in s:
        if char==ch:
         count+=1

    return count

def occ_of_each_word(s):
    words=s.split()
    counts={}
    for word in words:
        if word not in counts:
            counts[word]=0
        counts[word]+=1    
    return counts

def first_index_of_substring(s, sub):
    n = len(s)
    m = len(sub)
    for i in range(n - m + 1):   # Loop until there's space for the substring
        found = True
        for j in range(m):       # Check each character in the substring
            if s[i + j] != sub[j]:  # If characters don't match
                found = False
                break
        if found:                # If we found the substring
            return i
    return -1     

  
def main():
    print("Enter a string: ")
    s = input()                   # Get the main string input from the user

    while True:
        # Display menu options
        print("\nMenu:")
        print("1) Display word with the longest length")
        print("2) Determine frequency of occurrence of a character")
        print("3) Check if the string is a palindrome")
        print("4) Find index of first appearance of a substring")
        print("5) Count occurrences of each word")
        print("6) Exit")

        choice = int(input("Enter your choice (1-6): "))  # Get the menu choice

        if choice==1:
            print("longest word is: ",longest_word(s) )

        elif choice==2:
            ch=input("Enter  character  : ") 
            print("Frequency of ", ch, " is:", freq_of_char(s, ch))

        elif choice ==3:
            if palindrome(s):
                print("Given string is palindrome")
            else:
                print("Given string is not palindrome")

        elif choice == 4:
            
            sub = input("Enter the substring: ")
            index = first_index_of_substring(s, sub)
            if index != -1:
                print("Index of first appearance of '", sub, "' is:", index)
            else:
                print("Substring not found.")

        elif choice==5:
            word_counts = occ_of_each_word(s)
            print("Occurrences of each word:")
            for word, count in word_counts.items():
                print(word, ":", count)

        elif choice==6:
            print("Exiting program.")
            break


        else:
            print("wrong choice")

main()

