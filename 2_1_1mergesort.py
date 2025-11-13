def merge(larr,rarr):
   merged,i,j=[],0,0
   while(i<len(larr) and j<len(rarr)):
      if larr[i] <= rarr[j]:
         merged.append(larr[i])
         print("larr",merged)
         i+=1
      else:# r[j] <= l[i]:
         merged.append(rarr[j])
         print("rarr",merged)
         j+=1
   while i<len(larr):
      merged.append(larr[i])
      i+=1
   while j<len(rarr):
      merged.append(rarr[j])
      j+=1

   return merged

def mergebad(l1,l2):

  (lmerged,i,j) = ([],0,0)

  while i+j < len(l1) + len(l2):
    if i == len(l1):
      lmerged.append(l2[j])
      j = j+1
    elif j == len(l2):
      lmerged.append(l1[i])
      i = i+1
    elif l1[i] < l2[j]:
      lmerged.append(l1[i])
      i = i+1
    elif l2[j] < l1[i]:
      lmerged.append(l2[j])
      j = j+1
    else:
      lmerged.append(l1[i])
      i = i+1
      j = j+1
    
  return(lmerged) 

def mergesort(arr):#partition
   n=len(arr)
   print(arr)
   if n<2: return arr
   mid=n//2
   larr=mergesort(arr[:mid])
   rarr=mergesort(arr[mid:])
   return mergebad(larr,rarr)
   return merge(larr,rarr)

List=[3,3,5,6,4,2,1,0]
print("before",List)
List=mergesort(List)
print("After",List)
