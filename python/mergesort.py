def print_array(arr, size):
    for i in range(size):
        print(arr[i], end=" ")
    print()

def merge(arr, left, mid, right, b):
    i = left
    j = mid + 1
    k = left
    
    while i <= mid and j <= right:
        if arr[i] < arr[j]:
            b[k] = arr[i]
            i += 1
        else:
            b[k] = arr[j]
            j += 1
        k += 1
    
    while i <= mid:
        b[k] = arr[i]
        i += 1
        k += 1
    
    while j <= right:
        b[k] = arr[j]
        j += 1
        k += 1
    
    for i in range(left, right + 1):
        arr[i] = b[i]

def merge_sort(arr, s, e, b):
    if s >= e:
        return
    mid = s + (e - s) // 2
    merge_sort(arr, s, mid, b)
    merge_sort(arr, mid + 1, e, b)
    merge(arr, s, mid, e, b)
    print_array(arr, size)

if __name__ == "__main__":
    size = int(input("Enter the size of array: "))
    arr = [0] * size
    b = [0] * size    
    
    print(f"Enter {size} elements: ", end="")
    elements = input().split()
    for i in range(size):
        arr[i] = int(elements[i])
    
    print("Original array: ", end="")
    print_array(arr, size)
    
    merge_sort(arr, 0, size - 1, b)
    
    print("Sorted array: ", end="")
    print_array(arr, size)
