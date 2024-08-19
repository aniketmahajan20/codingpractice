delimiters = [",", "!", ";", "?", ".", " "]

class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        maxcount = 0
        bestword = ""
        dict_ = {}
        array = paragraph.split()
        for word in array:
            word = word.lower()
            for delimiter in delimiters:
                if delimiter in word:
                    word = word[0:-2]
            if word in banned:
                continue
            if word in dict_:
                dict_[word] += 1
            else:
                dict_.update({
                    word: 1
                })
            if dict_[word] > maxcount:
                maxcount = dict_[word]
                bestword = word
        return bestword
            

if __name__ ==  "__main__":
    a = Solution()
    print(a.mostCommonWord("aniket is the best person in the worl", []))
    