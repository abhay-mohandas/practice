def fun(a,b,c,d,e):
    if (c>b and c>a) or (c>a and c>d) or (c>b and c>d):
        if d>a and d>b:
            pass
        elif a>b:
            a,d=d,a
        else:
            b,d=d,b
    elif d<c:
        a,b,c,d=c,d,a,b
    elif a>b and d>b:
        a,c=c,a
    else:
        b,c=c,b
    if e<c and e<d:
        if e>a and e>b:
            print(e)
        if a>e and e>b:
            print(a)
        else:
            print(b)
    elif c<e and c<d:
        print(c)
    else:
        print(d)




fun(52,11,34,53,25)

