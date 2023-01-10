k_centimeters = int(input())
arr = list(map(int, input().split()))
arr.sort()
def calculate(arr):
    if k_centimeters == 0:
        return 0
    if sum(arr) < k_centimeters:
        return -1
    else:
        count = 0
        total = 0
        index = len(arr) - 1
        while total < k_centimeters:
            total += arr[index]
            index -= 1
            count += 1
        return count
print(calculate(arr=arr))