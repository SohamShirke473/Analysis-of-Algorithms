                
n=int(input("enter number for n qeen:"))
x=[0]*n
z=0

def print_board(x, n):
    board = [["."] * n for _ in range(n)]
    for row in range(n):
        board[row][x[row]] = "Q"
    for row in board:
        print(row)
def place(k,i):
    for j in range(k):
        if x[j]==i or abs(x[j]-i)==abs(j-k):
            return False
    return True
def NQeen(k,n):
    global z
    for i in range(n):
        if place(k,i):
            z+=1
            x[k]=i
            if k==n-1:
                print(x)
                print_board(x,n)
            else:
                NQeen(k+1,n)        
NQeen(0,n)
print("total iterations",z)


