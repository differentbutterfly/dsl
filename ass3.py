def input_matirx(rows,cols):
    matrix=[]
    print(f"Enter element for {rows}x{cols} of matrix: ")
    for i in range (rows):
        row=[]
        for j in range(cols):
            x=int(input(f"Enter element for matrix at position ({i+1},{j+1}): "))
            row.append(x)
        matrix.append(row)
    return matrix

def display(matrix,rows,cols):
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            print(matrix[i][j],end=" ")
        print()





def add_matrix(A,B):
    result=[]
    for i in range(len(A)):
        row=[]
        for j in range(len(A[0])):
            row.append(A[i][j]+B[i][j])
        result.append(row)

    return result

def sub_mat(A,B):
    result=[]
    for i in range(len(A)):
        row=[]
        for j in range(len(A[0])):
            row.append(A[i][j]-B[i][j])
        result.append(row)

    return result

def multiply_mat(A,B):
    result=[]
    for i in range(len(A)):
        row=[]
        for j in range(len(B[0])):
            sum=0
            for k in range(len(B)):
                sum+=A[i][k]*B[k][j]
            row.append(sum)

        result.append(row)
    return result


def tranpose_mat(A):
    result=[]
    for i in range(len(A[0])):
        row=[]
        for j in range(len(A)):
            row.append(A[j][i])
        result.append(row)
    return result

def main():
    print("Enter dimensions of matrix")
    rows=int(input("\nEnter row"))
    cols=int(input("\nEnter column"))
    
    print("ENter elements for matrix A")
    A=input_matirx(rows,cols)
    display(A,rows,cols)

    print("ENter elements for matrix B")
    B=input_matirx(rows,cols)
    display(B,rows,cols)

    while True:
        # Display menu options
        print("\nMenu:")
        print("1) Add matrices")
        print("2) Subtract matrices")
        print("3) Multiply matrices")
        print("4) Transpose a matrix")
        print("5) Exit")

        choice=int(input("Enter your choice"))

        if choice==1:
            print("Addition of matrix")
            if len(A)==len(B) and len(A[0])==len(B[0]):
                res=add_matrix(A,B)
                for row in res:
                    print(row)

            else:
                print("matrices must have same dimensions")

        elif choice==2:
            print("substraction of matrix")
            if len(A)==len(B) and len(A[0])==len(B[0]):
                res=sub_mat(A,B)
                for row in res:
                    print(row)

            else:
                print("matrices must have same dimensions")

        elif choice==3:
            print("multiplication of matrix")
            print("columns of A should match rows of B")
            if len(A[0])!=len(B):
                print("ERROR COLS AND ROWS DO NOT MATCH")
            else:
                res=multiply_mat(A,B)
                for row in res:
                    print(row)

        elif choice==4:
            print("transpose of matrix")
            mat_choice=int(input("A(1) or B(2) ?"))
            if mat_choice==1:

                res=tranpose_mat(A)
                for row in res:
                    print(row)
            else:
                res=tranpose_mat(B)
                for row in res:
                    print(row)
        elif choice == 5:
            print("EXITINT program")
            break

        else:
            print("Invalid choice")


        
main()

