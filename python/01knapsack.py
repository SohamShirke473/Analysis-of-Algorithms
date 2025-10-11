def print_selected(keep, w, v, W):
    print("Selected items (index, value, weight):")
    n = len(w)
    i = n
    selected = []
    
    while i > 0 and W > 0:
        if keep[i][W] == "✅":
            selected.append((i, v[i-1], w[i-1]))
            W -= w[i-1]
        i -= 1


    for item in reversed(selected):
        print(f"Item {item[0]}: Value = {item[1]}, Weight = {item[2]}")


def knapsack(v, w, W):
    n = len(v)
    dp = [[0] * (W + 1) for _ in range(n + 1)]
    keep = [[""] * (W + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        for j in range(1, W + 1):
            if w[i - 1] <= j:
                if v[i - 1] + dp[i - 1][j - w[i - 1]] > dp[i - 1][j]:
                    dp[i][j] = v[i - 1] + dp[i - 1][j - w[i - 1]]
                    keep[i][j] = "✅"
                else:
                    dp[i][j] = dp[i - 1][j]
                    keep[i][j] = "❌"
            else:
                dp[i][j] = dp[i - 1][j]
                keep[i][j] = "❌"

    print_selected(keep, w, v, W)

    print("\nDP Table (Value(Keep)):")
    for i in range(n + 1):
        row = []
        for j in range(W + 1):
            row.append(f"{dp[i][j]}({keep[i][j]})")
        print("\t".join(row))
    
    print(f"\nMaximum value that can be obtained: {dp[n][W]}")



v = list(map(int, input("Enter the values: ").split()))
w = list(map(int, input("Enter the weights: ").split()))
W = int(input("Enter the capacity: "))

knapsack(v, w, W)
