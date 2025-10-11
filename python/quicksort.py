def print_array(arr, size):
    for i in range(size):
        print(arr[i], end=" ")
    print()

def partition(arr, low, high, size):
    pivot = arr[high]
    print("pivot:", pivot)
    i = low - 1
    
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            
            temp = arr[i]
            arr[i] = arr[j]
            arr[j] = temp
    
    
    temp = arr[i + 1]
    arr[i + 1] = arr[high]
    arr[high] = temp
    
    print_array(arr, size)
    return i + 1

def quick_sort(arr, low, high, size):
    if low >= high:
        return
    q = partition(arr, low, high, size)
    quick_sort(arr, low, q - 1, size)
    quick_sort(arr, q + 1, high, size)



size = int(input("Enter the size of array: "))
arr = [0] * size  
print(f"Enter {size} elements: ", end="")
elements = input().split()
for i in range(size):
    arr[i] = int(elements[i])
    
print("Original array: ", end="")
print_array(arr, size)
    
quick_sort(arr, 0, size - 1, size)
    
print("Sorted array: ", end="")
print_array(arr, size)
