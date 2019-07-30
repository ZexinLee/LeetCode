#### Approach #1: Ad-Hoc [Accepted]

**Intuition**

The question can be summarized as "What is the smallest `k` for which `B` is a substring of `A * k`?" We can just try every `k`.

**Algorithm**

Imagine we wrote `S = A+A+A+...`. If `B` is to be a substring of `S`, we only need to check whether some `S[0:], S[1:], ..., S[len(A) - 1:]` starts with `B`, as `S` is long enough to contain `B`, and `S` has period at most `len(A)`.

Now, suppose `q` is the least number for which `len(B) <= len(A * q)`. We only need to check whether `B` is a substring of `A * q` or `A * (q+1)`. If we try `k < q`, then `B` has larger length than `A * q` and therefore can't be a substring. When `k = q+1`, `A * k` is already big enough to try all positions for `B`; namely, `A[i:i+len(B)] == B` for `i = 0, 1, ..., len(A) - 1`

**Complexity Analysis**

- Time Complexity: O(N*(N+M))*O*(*N*∗(*N*+*M*)), where M, N*M*,*N* are the lengths of strings `A, B`. We create two strings `A * q`, `A * (q+1)` which have length at most `O(M+N)`. When checking whether `B` is a substring of `A`, this check takes naively the product of their lengths.
- Space complexity: As justified above, we created strings that used O(M+N)*O*(*M*+*N*) space.

------

#### Approach #2: Rabin-Karp (Rolling Hash) [Accepted]

**Intuition**

As in *Approach #1*, we've reduced the problem to deciding whether B is a substring of some `A * k`. Using the following technique, we can decide whether `B` is a substring in O(len(A) * k)*O*(*l**e**n*(*A*)∗*k*) time.

**Algorithm**

For strings S*S*, consider each S[i]*S*[*i*] as some integer ASCII code. Then for some prime p*p*, consider the following function modulo some prime modulus \mathcal{M}M:

\text{hash}(S) = \sum_{0 \leq i < len(S)} p^i * S[i]hash(*S*)=∑0≤*i*<*l**e**n*(*S*)*p**i*∗*S*[*i*]

Notably, \text{hash}(S[1:] + x) = \frac{(\text{hash}(S) - S[0])}{p} + p^{n-1} xhash(*S*[1:]+*x*)=*p*(hash(*S*)−*S*[0])+*p**n*−1*x*. This shows we can get the hash of every substring of `A * q` in time complexity linear to it's size. (We will also use the fact that p^{-1} = p^{\mathcal{M}-2} \mod \mathcal{M}*p*−1=*p*M−2modM.)

However, hashes may collide haphazardly. To be absolutely sure in theory, we should check the answer in the usual way. The expected number of checks we make is in the order of 1 + \frac{s}{\mathcal{M}}1+M*s* where s*s* is the number of substrings we computed hashes for (assuming the hashes are equally distributed), which is effectively 1.



**Complexity Analysis**

- Time Complexity: O(M+N)*O*(*M*+*N*) (at these sizes), where M, N*M*,*N* are the lengths of strings `A, B`. As in *Approach #1*, we justify that `A * (q+1)` will be of length O(M + N)*O*(*M*+*N*), and computing the rolling hashes was linear work. We will also do a linear O(N)*O*(*N*) final check of our answer 1 + O(M) / \mathcal{M}1+*O*(*M*)/M times. In total, this is O(M+N + N(1 + \frac{M}{\mathcal{M}}))*O*(*M*+*N*+*N*(1+M*M*)) work. Since M \leq 10000 < \mathcal{M} = 10^9 + 7*M*≤10000<M=109+7, we can consider this to be linear behavior.
- Space complexity: O(1)*O*(1). Only integers were stored with additional memory.