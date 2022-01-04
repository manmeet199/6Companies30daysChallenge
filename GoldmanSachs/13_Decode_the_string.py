

class Solution:
    def decodedString(self, s):
        # code here
        stack=[]
        for i in range(len(s)):
            if(s[i]!=']'):
                stack.append(s[i])
            else:
                str=""
                while(stack and stack[-1]!='['):
                    str=stack.pop()+str
                stack.pop() #For popping [
                k=""
                while(stack and stack[-1].isdigit()):
                    k=stack.pop()+k
                stack.append(int(k)*str)
                    
        return ''.join(stack)


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input()
        
        ob = Solution()
        print(ob.decodedString(s))
