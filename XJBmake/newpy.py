import py_module as pym


class person(object):
    def __init__(self, name, age, height, sex):
        self.name = name
        self.age = age
        self.height = height
        self.sex = sex

    def show(self):
        print("my name is %s, and I am a person." % self.name)


class student(person):
    def __init__(self, name, age, height, sex, grade, work):
        super().__init__(name, age, height, sex)
        self.grade = grade
        self.work = work
    
    def show_work(self):
        print("My name is %s, and I am a %s." % (self.name, self.work))


class teacher(person):
    def __init__(self, name, age, height, sex, teach_age, work):
        super().__init__(name, age, height, sex)
        self.teach_age = teach_age
        self.work = work
    
    def show_self(self):
        print("My name is %s, and I am a %s, and I already teaching for %d years." % (self.name, self.work, self.teach_age))


def main():
    '''
    stu = [student('David', 30, 178, 'man', 130, 'student'), student('Tom', 21, 179, 'boy', 120, 'student')]
    for i in range(len(stu)):
        print('第%d位同学：' % (i+1))
        print("---------------------")
        stu[i].show()
        stu[i].show_work()
        print('---------------------')
        print('\n')
        
    teacher1 = teacher('Fantasy', 35, 175, 'man', 10, 'taach AI')
    teacher1.show_self()
    '''
    print(pym.show())

if __name__ == '__main__':
    main()

