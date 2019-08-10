import re

class Test():
    def __init__(self):
        self.test = 0

    def printer(self):
        print("test = {}".format(self.test))

    def parser(self, file_path):
        with open(file_path) as f:
            content = f.readline()
            content = re.sub(r'<[^>]*>',' ',content)
            content = re.sub(r'&nbsp;',' ',content)
            # print(content)
            temp_string = content.split(' ')
            # print(temp_string)
            ans = ""
            needline = True
            keep = False
            first = True
            for element in temp_string:
                if element != '':
                    try:
                        if(int(element)):
                            ans += "|"
                            ans += "\n"
                            needline = True
                            keep = False
                            first = True
                            ans += element
                    except:
                        if needline == True:
                            ans += "|"
                        if keep == False:
                            needline = False
                        res = re.match(r'^(100|[1-9]?\d(\.\d\d?\d?)?)%$|0$', element)
                        if res != None:
                            ans += "|"
                            needline = True
                            keep = True
                        elif keep == False:
                            if first == False:
                                ans += " "
                            else:
                                first = False
                        ans += element
                        # print("Not number")
            print(ans)

if __name__ == "__main__":
    print("hello world")
    test = Test()
    # test.printer()
    test.parser('Category.txt')