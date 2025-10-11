def print_array(arr, size):
    for i in range(size):
        print(arr[i], end=" ")
    print()

def selection_sort(arr, size):
    for i in range(size - 1):
        min_index = i
        for j in range(i + 1, size):
            if arr[j] < arr[min_index]:
                min_index = j
        if min_index != i:
            temp = arr[i]
            arr[i] = arr[min_index]
            arr[min_index] = temp
        print_array(arr, size)


size = int(input("Enter the size of array: "))
arr = [0] * size 
    
print(f"Enter {size} elements: ", end="")
elements = input().split()
for i in range(size):
    arr[i] = int(elements[i])
    
print("Original array: ", end="")
print_array(arr, size)
    
selection_sort(arr, size)
    
print("Sorted array: ", end="")
print_array(arr, size)
