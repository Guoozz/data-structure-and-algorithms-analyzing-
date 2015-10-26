/*
  0-1 背包
  m[i,w] = 0 if i = 0 or w = 0
  m[i,w] = m[i-1,W] if w[k] > W
  m[i,w] = max(m[k,W-w[k]] + w[k]) 1<=k<=i and W>=w[k]
 */
