def solution(phone_book): 
    answer = True 
    phone_book.sort()
    for i in range(len(phone_book)-1): 
        if phone_book[i] == phone_book[i+1][:len(phone_book[i])]: 
            answer = False 
            break 
    return answer

def solution(phoneBook):
    phoneBook = sorted(phoneBook)

    for p1, p2 in zip(phoneBook, phoneBook[1:]):
        if p2.startswith(p1):
            return False
    return True