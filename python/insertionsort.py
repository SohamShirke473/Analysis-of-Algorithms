def print_array(arr, size):
    for i in range(size):
        print(arr[i], end=" ")
    print()

def insertion_sort(arr, size):
    for i in range(1, size):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j = j - 1
        arr[j + 1] = key
        print_array(arr, size)


size = int(input("Enter the size of array: "))
arr = [0] * size 
    
print(f"Enter {size} elements: ", end="")
elements = input().split()
for i in range(size):
    arr[i] = int(elements[i])
    
print("Original array: ", end="")
print_array(arr, size)
    
insertion_sort(arr, size)
    
print("Sorted array: ", end="")
print_array(arr, size)
