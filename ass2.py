def input_matrix(rows,cols):
    matrix=[]
    print(f"Enter elements for a [{rows}x{cols}] matrix")
    for i in range(rows):
        rows=[]
        for j in range(cols):
            y=int(input(f"Enter element for [{i}x{j}]: "))
            rows.append(y)
        matrix.append(rows)

    return matrix

def display(matrix,rows,cols):
    if not  matrix:
        print("matrix is empty")


    print("matrix is: ")
    for i in range(rows):
        for j in range(cols):
            print(matrix[i][j],end=" ")
        print()

    
    
def saddle_pt(matrix,rows,cols):
    if not  matrix:
        print("matrix is empty")


    #min element in row
    for i in range(rows):
        row_value=matrix[i][0]
        min_col_index=0
        for j in range(cols):
            if matrix[i][j]<row_value:
                row_value=matrix[i][j]
                min_col_index=j

        #should be max in its column
        is_saddle=True
        for k in range(cols):
            if matrix[k][min_col_index]> row_value:
                is_saddle=False
                break

        if is_saddle:
            return(i,min_col_index,row_value)
        
        return None

def main():
    matrix=[]
    rows=0
    cols=0
    while True:
        print("1. Create Matrix")
        print("2.Display matrix")
        print("3.To Find the saddle point of the matrix")
        print("4.EXIT THE PROGRAM")

        choice=int(input("ENTER YOUR CHOICE"))

        if choice==1:
            rows=int(input("Enter the no.of rows"))
            cols =int(input("Enter the no.of cols"))
            matrix=input_matrix(rows,cols)

        elif choice==2:
            display(matrix,rows,cols)

        elif choice==3:
            res=saddle_pt(matrix,rows,cols)
            if res:
                print(f"saddle poiint of the matrix is ({res[0]+1},{res[1]+1}) having value {res[2]}")
            else:
                print("NO SADDLE POINT IN MATRIX ")
        elif choice==4:
            print("EXITING THE PROGRAM")
            break
        else:
            print("ENTER VALID CHOICE")

main()