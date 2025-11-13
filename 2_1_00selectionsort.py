def selection_sort(arr):
   for i in range(len(arr)):
      imin=i
      for j in range(i+1,len(arr)):
         if arr[j]<arr[imin]:
            imin=j
      temp=arr[i]
      arr[i]=arr[imin]
      arr[imin]   =temp
   return arr
   
array=[5,8,1,3,9,1,6]
print(array)
selection_sort(array)
print(array)
