from decimal import Decimal

a,b,c=input().split()
a=Decimal(a)
b=Decimal(b)
c=Decimal(c)


s=Decimal('-1')
e=Decimal('200000')
m=Decimal('0')

Tau=Decimal('6.283185307179586476925286766559005768394338798750211641949889184615632812572417997256069650684234135964296173026564613294187689219101164463450718816256')


def sin(x):
    x=x+Tau-Tau*int((x+Tau)/Tau)
    ret=Decimal('0')
    now=Decimal(x)
    for i in range(1000):
        ret+=now
        now*=-x*x
        now/=(2*i+3)*(2*i+2)    
    return ret
    
def f(x):
    return Decimal(a*x+b*sin(x)-c)    

while(e-s>=Decimal('1e-20')):
    m=Decimal((s+e)/2)
    #print(float(e-s))
    now=f(m)
    if now>0:
        e=m
    elif now<0:
        s=m
    else:
        break 
    
print(round(m,6))