s = input()
a = list(s)
result = ''

def error(msg = ''):
    # print(result)
    # if msg: print(msg)
    print('ERROR')
    exit(0)

n = len(a)

if n < 4:
    error('n < 4')

k = n-1
while s[k] == ' ': k-= 1
if a[k] != ';':
    error('not end with ;')

i = 0
while i < n and a[i] == ' ': i += 1

if s[i:i+4] != 'cout':
    error('not begin with cout')

if s.count('"') % 2 == 1 or a.count('<') % 2 == 1:
    error('" or < is even')

shift = False
while i <= k-1:
    if a[i] == ' ': pass
    
    elif a[i] == '<':
        if a[i] == '<':
            if shift:
                error('double shift')
            shift = True
            i += 1
        else:
            error('not two <')
    
    elif a[i] == '"':
        if not shift:
            error('not shift open on chars')
        
        j = i+1
        while a[i+1] != '"': i += 1
        result += s[j : i+1]
        i += 1

        shift = False
    
    elif '0' <= a[i] <= '9':
        if not shift:
            error('not shift on numbers')
        
        tmp = ''
        while a[i] == '0': i += 1
        while '0' <= a[i] <= '9':
            tmp += a[i]
            i += 1
        i -= 1

        if tmp == '':
            result += '0'
        else:
            result += tmp

        shift = False
    
    elif i+3 < n and s[i:i+4] == 'endl':
        if not shift:
            error('not shift on end of line')
        result += '\n'
        shift = False



    i += 1

print(result)