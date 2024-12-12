def accept_arr(A):
    n = int(input("Enter the number of students: "))
    for i in range(n):
        x = float(input(f"Enter the FE percentage for student {i + 1}: "))
        A.append(x)
    print("DATA ACCEPTED")
    return n

def display(A, n):
    if n == 0:
        print("No data")
    else:
        print("Array of marks: ", end=' ')
        for i in range(n):
            print(f"{A[i]:.2f}", end=' ')
        print("\n")

def selection_sort(A, n):
    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if A[j] < A[min_index]:
                min_index = j
        # Swap the elements
        A[i], A[min_index] = A[min_index], A[i]

def bubble_sort(A, n):
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if A[j] < A[j + 1]:  # Descending order
                # Swap the elements
                A[j], A[j + 1] = A[j + 1], A[j]

def main():
    A = []
    n = 0  # Initialize n to avoid scope issues
    while True:
        print("\n1: Accept & Display Marks of FE students")
        print("2: Ascending order (selection sort)")
        print("3: Descending order (bubble sort) and display top five scores")
        print("4: Exit")
        ch = int(input("Enter your choice: "))

        if ch == 1:
            A = []
            n = accept_arr(A)
            display(A, n)

        elif ch == 2:
            if n == 0:
                print("No data to sort. Please accept marks first.")
            else:
                print("Marks before sorting:")
                display(A, n)
                print("Marks after performing selection sort:")
                selection_sort(A, n)
                display(A, n)

        elif ch == 3:
            if n == 0:
                print("No data to sort. Please accept marks first.")
            else:
                print("Marks before sorting:")
                display(A, n)
                print("Marks after performing bubble sort:")
                bubble_sort(A, n)
                display(A, n)

                print("Top scores:")
                for i in range(6):
                    print(f"\t{A[i]:.2f}")

        elif ch == 4:
            print("Exiting program.")
            break

        else:
            print("Wrong choice, try again.")

main()
