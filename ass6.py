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