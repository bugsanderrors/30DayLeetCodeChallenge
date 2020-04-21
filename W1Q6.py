"""
    Grouped Anagrams

    Given an array of strings, group anagrams together.

    Example:
    Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
    Output:
    [
        ["ate","eat","tea"],
        ["nat","tan"],
        ["bat"]
    ]

    Note:
        *All inputs will be in lowercase.
        *The order of your output does not matter.
"""


from collections import defaultdict
def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        groupedWords = defaultdict(list) 
        
        for word in strs: 
            groupedWords["".join(sorted(word))].append(word) 
            
        return list(groupedWords.values())