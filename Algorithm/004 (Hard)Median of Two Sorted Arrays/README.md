# BruTe-force

Very straightforward merge and quicksort

Time Complexity: O((m+n)log(m+n))



# Round-Robin

Time Complexity: O(m+n)



# Best-Solution

Time Complexity: O(log(m+n))

To solve this problem, we need to understand "What is the use of median". In statistics, the median is used for:

> Dividing a set into two equal length subsets, that one subset is always greater than the other.

If we understand the use of median for dividing, we are very close to the answer.

First let's cut \text{A}A into two parts at a random position i*i*:

```
          left_A             |        right_A
    A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
```

Since \text{A}A has m*m* elements, so there are m+1*m*+1 kinds of cutting (i = 0 \sim m*i*=0∼*m*).

And we know:

> \text{len}(\text{left\_A}) = i, \text{len}(\text{right\_A}) = m - ilen(left_A)=*i*,len(right_A)=*m*−*i*.
>
> Note: when i = 0*i*=0, \text{left\_A}left_A is empty, and when i = m*i*=*m*, \text{right\_A}right_A is empty.

With the same way, cut \text{B}B into two parts at a random position j*j*:

```
          left_B             |        right_B
    B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
```

Put \text{left\_A}left_A and \text{left\_B}left_B into one set, and put \text{right\_A}right_A and \text{right\_B}right_B into another set. Let's name them \text{left\_part}left_partand \text{right\_part}right_part:

```
          left_part          |        right_part
    A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
    B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
```

If we can ensure:

> 1. \text{len}(\text{left\_part}) = \text{len}(\text{right\_part})len(left_part)=len(right_part)
> 2. \max(\text{left\_part}) \leq \min(\text{right\_part})max(left_part)≤min(right_part)

then we divide all elements in \{\text{A}, \text{B}\}{A,B} into two parts with equal length, and one part is always greater than the other. Then

\text{median} = \frac{\text{max}(\text{left}\_\text{part}) + \text{min}(\text{right}\_\text{part})}{2}median=2max(left_part)+min(right_part)

To ensure these two conditions, we just need to ensure:

> 1. i + j = m - i + n - j*i*+*j*=*m*−*i*+*n*−*j* (or: m - i + n - j + 1*m*−*i*+*n*−*j*+1)
>    if n \geq m*n*≥*m*, we just need to set: i = 0 \sim m, j = \frac{m + n + 1}{2} - i \\*i*=0∼*m*,*j*=2*m*+*n*+1​−*i*
> 2. \text{B}[j-1] \leq \text{A}[i]B[*j*−1]≤A[*i*] and \text{A}[i-1] \leq \text{B}[j]A[*i*−1]≤B[*j*]

ps.1 For simplicity, I presume \text{A}[i-1], \text{B}[j-1], \text{A}[i], \text{B}[j]A[*i*−1],B[*j*−1],A[*i*],B[*j*] are always valid even if i=0*i*=0, i=m*i*=*m*, j=0*j*=0, or j=n*j*=*n*. I will talk about how to deal with these edge values at last.

ps.2 Why n \geq m*n*≥*m*? Because I have to make sure j*j* is non-negative since 0 \leq i \leq m0≤*i*≤*m* and j = \frac{m + n + 1}{2} - i*j*=2*m*+*n*+1−*i*. If n < m*n*<*m*, then j*j* may be negative, that will lead to wrong result.

So, all we need to do is:

> Searching i*i* in [0, m][0,*m*], to find an object i*i* such that:
>
> \qquad \text{B}[j-1] \leq \text{A}[i]B[*j*−1]≤A[*i*] and \ \text{A}[i-1] \leq \text{B}[j], A[*i*−1]≤B[*j*], where j = \frac{m + n + 1}{2} - i*j*=2*m*+*n*+1−*i*

And we can do a binary search following steps described below:

1. Set \text{imin} = 0imin=0, \text{imax} = mimax=*m*, then start searching in [\text{imin}, \text{imax}][imin,imax]
2. Set i = \frac{\text{imin} + \text{imax}}{2}*i*=2imin+imax, j = \frac{m + n + 1}{2} - i*j*=2*m*+*n*+1−*i*
3. Now we have \text{len}(\text{left}\_\text{part})=\text{len}(\text{right}\_\text{part})len(left_part)=len(right_part). And there are only 3 situations that we may encounter:
   - \text{B}[j-1] \leq \text{A}[i]B[*j*−1]≤A[*i*] and \text{A}[i-1] \leq \text{B}[j]A[*i*−1]≤B[*j*]
     Means we have found the object i*i*, so stop searching.
   - \text{B}[j-1] > \text{A}[i]B[*j*−1]>A[*i*]
     Means \text{A}[i]A[*i*] is too small. We must adjust i*i* to get \text{B}[j-1] \leq \text{A}[i]B[*j*−1]≤A[*i*].
     Can we increase i*i*?
           Yes. Because when i*i* is increased, j*j* will be decreased.
           So \text{B}[j-1]B[*j*−1] is decreased and \text{A}[i]A[*i*] is increased, and \text{B}[j-1] \leq \text{A}[i]B[*j*−1]≤A[*i*] may
           be satisfied.
     Can we decrease i*i*?
           No! Because when i*i* is decreased, j*j* will be increased.
           So \text{B}[j-1]B[*j*−1] is increased and \text{A}[i]A[*i*] is decreased, and \text{B}[j-1] \leq \text{A}[i]B[*j*−1]≤A[*i*] will
           be never satisfied.
     So we must increase i*i*. That is, we must adjust the searching range to [i+1, \text{imax}][*i*+1,imax].
     So, set \text{imin} = i+1imin=*i*+1, and goto 2.
   - \text{A}[i-1] > \text{B}[j]A[*i*−1]>B[*j*]:
     Means \text{A}[i-1]A[*i*−1] is too big. And we must decrease i*i* to get \text{A}[i-1]\leq \text{B}[j]A[*i*−1]≤B[*j*].
     That is, we must adjust the searching range to [\text{imin}, i-1][imin,*i*−1].
     So, set \text{imax} = i-1imax=*i*−1, and goto 2.

When the object i*i* is found, the median is:

> \max(\text{A}[i-1], \text{B}[j-1]),max(A[*i*−1],B[*j*−1]), when m + n*m*+*n* is odd

> \frac{\max(\text{A}[i-1], \text{B}[j-1]) + \min(\text{A}[i], \text{B}[j])}{2},2max(A[*i*−1],B[*j*−1])+min(A[*i*],B[*j*]), when m + n*m*+*n* is even

Now let's consider the edges values i=0,i=m,j=0,j=n*i*=0,*i*=*m*,*j*=0,*j*=*n* where \text{A}[i-1],\text{B}[j-1],\text{A}[i],\text{B}[j]A[*i*−1],B[*j*−1],A[*i*],B[*j*] may not exist. Actually this situation is easier than you think.

What we need to do is ensuring that \text{max}(\text{left}\_\text{part}) \leq \text{min}(\text{right}\_\text{part})max(left_part)≤min(right_part). So, if i*i* and j*j* are not edges values (means \text{A}[i-1], \text{B}[j-1],\text{A}[i],\text{B}[j]A[*i*−1],B[*j*−1],A[*i*],B[*j*] all exist), then we must check both \text{B}[j-1] \leq \text{A}[i]B[*j*−1]≤A[*i*] and \text{A}[i-1] \leq \text{B}[j]A[*i*−1]≤B[*j*]. But if some of \text{A}[i-1],\text{B}[j-1],\text{A}[i],\text{B}[j]A[*i*−1],B[*j*−1],A[*i*],B[*j*] don't exist, then we don't need to check one (or both) of these two conditions. For example, if i=0*i*=0, then \text{A}[i-1]A[*i*−1] doesn't exist, then we don't need to check \text{A}[i-1] \leq \text{B}[j]A[*i*−1]≤B[*j*]. So, what we need to do is:

> Searching i*i* in [0, m][0,*m*], to find an object i*i* such that:
>
> (j = 0(*j*=0 or i = m*i*=*m* or \text{B}[j-1] \leq \text{A}[i])B[*j*−1]≤A[*i*]) and
> (i = 0(*i*=0 or j = n*j*=*n* or \text{A}[i-1] \leq \text{B}[j]),A[*i*−1]≤B[*j*]), where j = \frac{m + n + 1}{2} - i*j*=2*m*+*n*+1​−*i*

And in a searching loop, we will encounter only three situations:

> 1. (j = 0(*j*=0 or i = m*i*=*m* or \text{B}[j-1] \leq \text{A}[i])B[*j*−1]≤A[*i*]) and
>    (i = 0(*i*=0 or j = n*j*=*n* or \text{A}[i-1] \leq \text{B}[j])A[*i*−1]≤B[*j*])
>    Means i*i* is perfect, we can stop searching.
> 2. j > 0*j*>0 and i < m*i*<*m* and \text{B}[j - 1] > \text{A}[i]B[*j*−1]>A[*i*]
>    Means i*i* is too small, we must increase it.
> 3. i > 0*i*>0 and j < n*j*<*n* and \text{A}[i - 1] > \text{B}[j]A[*i*−1]>B[*j*]
>    Means i*i* is too big, we must decrease it.

Thanks to [@Quentin.chen](https://leetcode.com/Quentin.chen) for pointing out that: i < m \implies j > 0*i*<*m*⟹*j*>0 and i > 0 \implies j < n*i*>0⟹*j*<*n*. Because:

> m \leq n, i < m \implies j = \frac{m+n+1}{2} - i > \frac{m+n+1}{2} - m \geq \frac{2m+1}{2} - m \geq 0*m*≤*n*,*i*<*m*⟹*j*=2*m*+*n*+1−*i*>2*m*+*n*+1−*m*≥22*m*+1−*m*≥0
>
> m \leq n, i > 0 \implies j = \frac{m+n+1}{2} - i < \frac{m+n+1}{2} \leq \frac{2n+1}{2} \leq n*m*≤*n*,*i*>0⟹*j*=2*m*+*n*+1−*i*<2*m*+*n*+1≤22*n*+1≤*n*

So in situation 2. and 3. , we don't need to check whether j > 0*j*>0 and whether j < n*j*<*n*.