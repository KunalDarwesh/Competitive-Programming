MAX = 1000

def findDuplicate(arr, n, k): 
    # Since arr[] has numbers in  
    # range from 1 to MAX 
    res = MAX + 1
    for i in range(0, n):  
        if (arr[i] > 0): 
            # set count to 1 as number  
            # is present once 
            count = 1
            for j in range(i + 1, n): 
                if (arr[i] == arr[j]): 
                    count += 1
            # If frequency of number is equal to 'k' 
            if (count == k): 
                res = min(res, arr[i]) 
    return res 

# Driver code 
arr = [3,2,3,4,4]#[2,5,2,4,2,1,6]  
k = 2
n = len(arr) 
print(findDuplicate(arr, n, k))
