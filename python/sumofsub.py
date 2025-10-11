def sum_of_subsets(arr, n, target, subset=[], index=0):
    current_sum = sum(subset)
    
   
    if current_sum == target:
        print(subset)
        return
    

    if current_sum > target or index == n:
        return
    
   
    sum_of_subsets(arr, n, target, subset + [arr[index]], index + 1)
    
   
    sum_of_subsets(arr, n, target, subset, index + 1)


arr = list(map(int, input("Enter the elements (space-separated): ").split()))
target = int(input("Enter the target sum: "))
print(f"Subsets with sum {target}:")
sum_of_subsets(arr, len(arr), target)
