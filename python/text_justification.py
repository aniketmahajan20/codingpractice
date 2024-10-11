from typing import List
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        result = []
        line = []
        size = 0
        i = 0
        while(i<len(words)):
            if (size + len(line) + len(words[i]) > maxWidth):
                spaces = (maxWidth - size) // max(1, len(line)-1)
                remainder = (maxWidth - size) % max(1, len(line)-1)
                for j in range(max(1, len(line)-1)):
                    line[j] += " " * spaces
                    if (remainder):
                        line[j] += " "
                        remainder -= 1
                result.append("".join(line))
                line = []
                size = 0
            line.append(words[i])
            size = size + len(words[i])
            i += 1

        end_spaces = (maxWidth - size - (len(line) - 1))
        last_line = " ".join(line)
        last_line += " " * end_spaces
        result.append(last_line)

        return result