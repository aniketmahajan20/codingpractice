class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        # Select the bigger string as the starting point
        # Then keep going one down as you try to compare. 
        # Whatever substring you select. Length has to be divisible with the bigger string
        flag = False
        if len(str1) < len(str2):
            min_str = str1
            max_str = str2
        else:
            min_str = str2
            max_str = str1
        # If the min string is not equal to max string upto the length of the min_string, there is not GCD
        if min_str != max_str[:len(min_str)]:
            return ""
        for i in range(len(min_str), 0, -1):
            comp_str1 = min_str[:i]
            # print(comp_str1)
            if len(max_str) % len(comp_str1) == 0 and len(min_str) % len(comp_str1) == 0:
                for j_ in range(0, len(max_str), len(comp_str1)):
                    comp_str2 = max_str[j_:len(comp_str1)+j_]
                    # print(comp_str2)
                    # breakpoint()
                    if comp_str1 == comp_str2:
                        flag = True
                        continue
                    else:
                        flag = False
                        break
                if flag == True:
                    return comp_str1
        return ""
    
if __name__ == "__main__":
    a = Solution()
    a.gcdOfStrings("ABCABC", "ABC")