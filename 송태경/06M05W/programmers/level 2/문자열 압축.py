def solution(s):
    length = []
    result = ""
    
    if len(s) == 1:
        return 1
    
    for cut in range(1, len(s) // 2 + 1): 
        count = 1
        cut_s = s[:cut] 
        for i in range(cut, len(s), cut):
            if s[i:i+cut] == cut_s:
                count += 1
            else:
                if count == 1:
                    count = ""
                result += str(count) + cut_s
                cut_s = s[i:i+cut]
                count = 1
        if count == 1:
            count = ""
            
        result += str(count) + cut_s
        length.append(len(result))
        result = ""
    
    return min(length)