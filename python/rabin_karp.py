def rabin_karp(text, pattern, d=256, q=101):
   n = len(text)
   m = len(pattern)
   h = pow(d, m-1) % q  
   p = 0  
   t = 0  
   result = []
 
   for i in range(m):
       p = (d * p + ord(pattern[i])) % q
       t = (d * t + ord(text[i])) % q

   for s in range(n - m + 1):     
       if p == t:
           if text[s:s+m] == pattern:
               result.append(s)
       if s < n - m:
           t = (d * (t - ord(text[s]) * h) + ord(text[s + m])) % q
           if t < 0:
               t += q
   return result

text = input("Enter the main string: ")
pattern = input("Enter the pattern to search: ")
indices = rabin_karp(text, pattern)
if indices:
   print(f"Pattern found {len(indices)} times at indices: {indices}")
else:
   print("Pattern not found")

