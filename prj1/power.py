def power(a, b):
   # a = 2 , b = 8
   
    if b == 0: 
        return 1 
    else: 
        return a * power(a, b-1) 
 # O(n)    
    #2,8=>  2* power(2,7) => 2*(2* power(2,6)) =>2*(2*(2* power (2,5))) => ... =>2*(2*(2*(2*(2*(2*(2*(2*1)))))) = 256
    