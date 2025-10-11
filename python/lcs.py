def lcs_length(X, Y):
    m = len(X)
    n = len(Y)
    c = [[0] * (n + 1) for _ in range(m + 1)]
    b = [[" "] * (n + 1) for _ in range(m + 1)]
    
    for i in range(m):
        for j in range(n):
            if X[i] == Y[j]:
                c[i + 1][j + 1] = c[i][j] + 1
                b[i + 1][j + 1] = "↖"
            elif c[i + 1][j] >= c[i][j + 1]:
                c[i + 1][j + 1] = c[i + 1][j]
                b[i + 1][j + 1] = "←"  
            else:
                c[i + 1][j + 1] = c[i][j + 1]
                b[i + 1][j + 1] = "↑" 
    return c, b

def print_lcs(X, b, i, j):
    if i == 0 or j == 0:
        return
    if b[i][j] == "↖":
        print_lcs(X, b, i - 1, j - 1)
        print(X[i - 1], end="")
    elif b[i][j] == "←":
        print_lcs(X, b, i, j - 1)    
    elif b[i][j] == "↑":
        print_lcs(X, b, i - 1, j)

if __name__ == "__main__":
    X = input("Enter the first string: ")
    Y = input("Enter the second string: ")
    c, b = lcs_length(X, Y)

    print("\nDP Table (c):")
    for row in c:
        print(row)
    
    print("\nDirection Table (b):")
    for row in b:
        print(row)
    
    print("\nLength of LCS:", c[-1][-1])
    print("LCS: ", end="")
    print_lcs(X, b, len(X), len(Y))

                





    