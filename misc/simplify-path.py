class Solution:
    def simplifyPath(self, path: str) -> str:
        paths = path.split("/")
        newPaths = []
        for i in paths:
            if i == "" or i == '.':
                continue
            elif i == '..':
                if(len(newPaths) != 0): newPaths.pop()
            else:
                newPaths.append(i)
        return "/" + "/".join(newPaths)