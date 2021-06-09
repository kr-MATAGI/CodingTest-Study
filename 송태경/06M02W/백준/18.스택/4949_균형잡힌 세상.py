while True:
    istr = input()
    st_stack = []
    tf = True
    if istr == '.':
        break
    for cc in istr:
        if cc == '(' or cc == '[':
            st_stack.append(cc)
        elif cc == ')':
            if st_stack and st_stack[-1] == '(':
                st_stack.pop()
            else:
                tf = False
                break
        elif cc == ']':
            if st_stack and st_stack[-1] == '[':
                st_stack.pop()
            else:
                tf = False
                break
    if tf == True and not(st_stack):
        print('yes')
    else:
        print('no')