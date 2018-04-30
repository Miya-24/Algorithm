INSERTION-SORT(A)
for j = 2 to A.length
    key = A[j]
    //A[j]をソート済みの列A[1..j-1]に挿入する
    i = j - 1
    while i > 0 かつ A[i] > key
        A[i+1] = A[i]
        i = i-1
    A[i+1] = key
