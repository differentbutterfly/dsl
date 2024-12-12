def accept_array(A):
    n = int(input("Enter the number of students: "))
    for i in range(n):
        x = int(input(f"Enter the roll number of student {i+1}: "))
        A.append(x)
    print("Roll numbers accepted.")
    return n


def display(A, n):
    if n == 0:
        print("No records in the database.")
    else:
        for i in range(n):
            print(A[i], end=' ')
        print("\n")


def ternary_search(A, l, r, key):
    if r >= l:
        mid1 = l + (r - l) // 3
        mid2 = r - (r - l) // 3

        if A[mid1] == key:
            return mid1
        if A[mid2] == key:
            return mid2
        if key < A[mid1]:
            return ternary_search(A, l, mid1 - 1, key)
        elif key > A[mid2]:
            return ternary_search(A, mid2 + 1, r, key)
        else:
            return ternary_search(A, mid1 + 1, mid2 - 1, key)

    return -1


def main():
    A = []
    while True:
        print("\t1: Accept student info and display the information")
        print("\t2: Ternary search")
        print("\t3: Exit")
        ch = int(input("Enter choice: "))

        if ch == 1:
            A = []
            n = accept_array(A)
            display(A, n)

        elif ch == 2:
            x = int(input("Enter roll number to be searched: "))
            flag = ternary_search(A, 0, len(A) - 1, x)
            if flag == -1:
                print(f"\t{x} roll number is not part of the member club.")
            else:
                print(f"\t{x} is a member of the club at location {flag}")

        elif ch == 3:
            print("End of the program.")
            quit()

        else:
            print("Enter a valid choice.")


# Run the main function
main()
