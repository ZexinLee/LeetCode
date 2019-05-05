class Solution:
    def toGoatLatin(self, S: str) -> str:
        list = S.split(' ')
        ans = ""
        count = 1
        print(list)
        for word in list:
            if word[0] == 'a' or word[0] == 'e' or word[0] == 'i' or word[0] == 'o' or word[0] == 'u' or word[0] == 'A' or word[0] == 'E' or word[0] == 'I' or word[0] == 'O' or word[0] == 'U':
                ans += (word + 'ma')
                for i in range(count):
                    ans += 'a'
                count += 1
            else:
                ans += (word[1:] + word[0] + 'ma')
                for i in range(count):
                    ans += 'a'
                count += 1
            ans += ' '
        return ans[:-1]
